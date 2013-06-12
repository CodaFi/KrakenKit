//
//  KRAClient.m
//  KrakenKit
//
//  Created by Robert Widmann on 4/30/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAClient.h"
#import "KRAUser.h"
#import "NSData+Base64.h"
#import "FXKeychain.h"
#import "KRAClient+KRAUser.h"

NSString *const KRAUserLoginKey = @"KRAUserLoginKey";
NSString *const KRAUserPasswordKey = @"KRAUserPasswordKey";

@interface KRAClient ()

@property (nonatomic, strong) AFHTTPClient *authHTTPClient;
@property (nonatomic, strong) KRAUser *authenticatedUser;

- (void)initializeHTTPAuthClient;
- (void)HTTPAuthDidCompleteSuccessfully:(BOOL)wasSuccessful error:(NSError *)error handler:(void (^)(BOOL successful, NSError *error))handler;
- (void)authenticateWithParameters:(NSDictionary *)params handler:(void (^)(BOOL successful, NSError *error))handler;

@end

@implementation KRAClient

#pragma mark - Lifecycle

+ (instancetype)sharedClient {
    static KRAClient *sharedObject = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedObject = [[KRAClient alloc] init];
    });
    
    return sharedObject;
}

- (id)init {
    self = [super initWithBaseURL:[NSURL URLWithString:@"https://api.github.com/"]];
	
	self.parameterEncoding = AFJSONParameterEncoding;
	[self setDefaultHeader:@"Accept" value:@"application/json"];
	[self addObserver:self forKeyPath:@"accessToken" options:NSKeyValueObservingOptionNew context:nil];
    
    return self;
}

- (void)dealloc {
	[self removeObserver:self forKeyPath:@"accessToken"];
}

#pragma mark - Authentication

- (void)authenticateStoredCredentialsWithCompletionHandler:(void (^)(BOOL, NSError *))handler {
	if (!self.userDefaults[KRAUserLoginKey] || !self.userDefaults[KRAUserPasswordKey]) {
		if (!handler) return;
		handler(NO, [NSError errorWithDomain:kKRAErrorDomain code:KRAErrorTypeNoStoredCredentials userInfo:nil]);
		return;
	}
	[self authenticateUsername:self.userDefaults[KRAUserLoginKey] password:self.userDefaults[KRAUserPasswordKey] completionHandler:handler];
}

- (void)authenticateUsername:(NSString *)username password:(NSString *)password completionHandler:(void (^)(BOOL, NSError *))handler {
	NSDictionary *parameters = @{
		@"client_id"     : KRAGithubClientID,
		@"client_secret" : KRAGithubClientSecret,
		@"scopes" : @[@"user", @"repo"]
	};
	[self initializeHTTPAuthClient];
	[self.authHTTPClient setAuthorizationHeaderWithUsername:username password:password];
	[self.authHTTPClient postPath:@"authorizations" parameters:parameters success:^(AFHTTPRequestOperation *operation, id responseObject) {
		NSDictionary *responseDictionary = [NSJSONSerialization JSONObjectWithData:responseObject options:0 error:nil];
		if (responseDictionary[@"token"]) {
			self.accessToken = responseDictionary[@"token"];
			[self fetchUserWithID:username completion:^(id responseObject, NSError *error) {
				self.authenticatedUser = responseObject;
				[self HTTPAuthDidCompleteSuccessfully:YES error:nil handler:handler];
				[self setAuthorizationHeaderWithUsername:username password:password];
				self.userDefaults[KRAUserLoginKey] = username;
				self.userDefaults[KRAUserPasswordKey] = password;
			}];
		} else {
			NSError *error = [NSError errorWithDomain:kKRAErrorDomain code:-1 userInfo:@{NSLocalizedDescriptionKey: @"Could not find key token in response", NSLocalizedFailureReasonErrorKey: responseDictionary}];
			[self HTTPAuthDidCompleteSuccessfully:NO error:error handler:handler];
		}
	} failure:^(AFHTTPRequestOperation *operation, NSError *error) {
		[self HTTPAuthDidCompleteSuccessfully:NO error:error handler:handler];
	}];
	[self clearAuthorizationHeader];
}

- (BOOL)isAuthenticated {
	return self.accessToken != nil;
}

- (BOOL)isLoggedIn {
	return self.isAuthenticated && self.authenticatedUser != nil;
}

- (void)logOut {
	self.accessToken = nil;
	self.authenticatedUser = nil;
	self.userDefaults[KRAUserLoginKey] = nil;
	self.userDefaults[KRAUserPasswordKey] = nil;
}

#pragma mark - User Defaults

- (FXKeychain *)userDefaults {
	return [FXKeychain defaultKeychain];
}

- (NSDictionary *)authenticatedUserDefaults {
	return self.isAuthenticated ? [self.userDefaults objectForKey:[NSString stringWithFormat:@"KRAUser%@", self.authenticatedUser.userID]] : nil;
}

- (void)setObject:(id)object forDefaultedKey:(NSString *)key {
	if (self.isAuthenticated) {
		NSDictionary *settings = [self authenticatedUserDefaults] ?: @{};
		NSMutableDictionary *modifiedSettings = [NSMutableDictionary dictionaryWithDictionary:settings];
		
		if (object) {
			modifiedSettings[key] = object;
		} else {
			[modifiedSettings removeObjectForKey:key];
		}
		
		[self.userDefaults setObject:modifiedSettings forKey:[NSString stringWithFormat:@"KRAUser%@", self.authenticatedUser.userID]];
	}
}


- (id)objectForKeyInDefaults:(NSString *)key {
	return self.authenticatedUserDefaults[key];
}

#pragma mark - Internal API

- (void)initializeHTTPAuthClient {
	self.authHTTPClient = [AFHTTPClient clientWithBaseURL:[NSURL URLWithString:@"https://api.github.com/"]];
	self.authHTTPClient.parameterEncoding = AFJSONParameterEncoding;
	[self.authHTTPClient registerHTTPOperationClass:[AFJSONRequestOperation class]];
}

- (void)authenticateWithParameters:(NSDictionary *)params handler:(void (^)(BOOL successful, NSError *error))handler {
	[self initializeHTTPAuthClient];
	[self.authHTTPClient postPath:@"authorizations" parameters:params success:^(AFHTTPRequestOperation *operation, id responseObject) {
		NSDictionary *responseDictionary = [NSJSONSerialization JSONObjectWithData:responseObject options:0 error:nil];
		if (responseDictionary[@"token"]) {
			self.accessToken = responseDictionary[@"token"];
			[self HTTPAuthDidCompleteSuccessfully:YES error:nil handler:handler];
		} else {
			NSError *error = [NSError errorWithDomain:kKRAErrorDomain code:-1 userInfo:@{NSLocalizedDescriptionKey: @"Could not find key token in response", NSLocalizedFailureReasonErrorKey: responseDictionary}];
			[self HTTPAuthDidCompleteSuccessfully:NO error:error handler:handler];
		}
	} failure:^(AFHTTPRequestOperation *operation, NSError *error) {
		[self HTTPAuthDidCompleteSuccessfully:NO error:error handler:handler];
	}];
}

- (void)HTTPAuthDidCompleteSuccessfully:(BOOL)wasSuccessful error:(NSError *)error handler:(void (^)(BOOL successful, NSError *error))handler {
	if (error.localizedRecoverySuggestion) {
		NSDictionary *errorDictionary = [NSJSONSerialization JSONObjectWithData:[error.localizedRecoverySuggestion dataUsingEncoding:NSUTF8StringEncoding] options:0 error:nil];
		if (errorDictionary) {
			NSError *modifiedError = [NSError errorWithDomain:kKRAErrorDomain code:0 userInfo:@{NSLocalizedDescriptionKey: errorDictionary[@"message"]}];
			error = modifiedError;
		}
	}
	if (handler) {
		handler(wasSuccessful, error);
	}
	
	self.authHTTPClient = nil;
}

#pragma mark - NSCopying

- (id)copyWithZone:(NSZone *)zone {
	KRAClient *copy = [[KRAClient alloc] init];
	copy.accessToken = self.accessToken;
	return copy;
}

#pragma mark - KVO

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context {
	if ([keyPath isEqualToString:@"accessToken"]) {
		[self setDefaultHeader:@"Authorization" value:self.accessToken ? [@"bearer " stringByAppendingString:self.accessToken] : nil];
	}
}

@end
