//
//  KRAClient+KRAUser.m
//  KrakenKit
//
//  Created by Robert Widmann on 4/30/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAClient+KRAUser.h"
#import "KRAClient+KRAHandlerBlocks.h"
#import "KRAUser.h"
#import "KRARepository.h"
#import "KRAEvent.h"
#import "KRANotification.h"

@interface KRAClient (KRAUserPrivate)

- (NSString *)endpointPathForUserID:(NSString *)userID endpoint:(NSString *)endpoint;

@end


@implementation KRAClient (KRAUser)

- (void)fetchUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"users/%@", user.login]
	   parameters:nil
		  success:[self successHandlerForResourceClass:[KRAUser class] clientHandler:completionHandler]
		  failure:NULL];
}

- (void)fetchUserWithID:(NSString *)userID completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"users/%@", userID]
	   parameters:nil
		  success:[self successHandlerForResourceClass:[KRAUser class] clientHandler:completionHandler]
		  failure:NULL];
}

- (void)repositoriesForUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"users/%@/repos", user.login]
		parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRARepository class] clientHandler:completionHandler]
		  failure:NULL];
}

- (void)eventsForUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"users/%@/received_events", user.login]
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRAEvent class] clientHandler:completionHandler]
		  failure:NULL];
}

- (void)notificationsForUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:@"notifications"
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRANotification class] clientHandler:completionHandler]
		  failure:NULL];
}

- (void)starredRepositoriesForUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"users/%@/starred", user.login]
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRARepository class] clientHandler:completionHandler]
		  failure:NULL];
}

@end