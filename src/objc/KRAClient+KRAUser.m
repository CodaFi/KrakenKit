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
#import "KRAIssue.h"
#import "KRAGist.h"

@interface KRAClient (KRAUserPrivate)

- (NSString *)endpointPathForUserID:(NSString *)userID endpoint:(NSString *)endpoint;

@end


@implementation KRAClient (KRAUser)

- (void)fetchUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"users/%@", user.login]
	   parameters:nil
		  success:[self successHandlerForResourceClass:[KRAUser class] clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)fetchUserWithID:(NSString *)userID completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"users/%@", userID]
	   parameters:nil
		  success:[self successHandlerForResourceClass:[KRAUser class] clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)repositoriesForUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"users/%@/repos", user.login]
		parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRARepository class] clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)eventsForUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"users/%@/events", user.login]
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRAEvent class] clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)recievedEventsForUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"users/%@/received_events", user.login]
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRAEvent class] clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)notificationsForUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:@"notifications"
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRANotification class] clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)starredRepositoriesForUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"users/%@/starred", user.login]
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRARepository class] clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)starRepository:(KRARepository *)repo completion:(KRAClientCompletionBlock)completionHandler {
	[self postPath:[NSString stringWithFormat:@"user/starred/%@", repo.fullName]
		parameters:nil
		   success:completionHandler
		   failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)unstarRepository:(KRARepository *)repo completion:(KRAClientCompletionBlock)completionHandler {
	[self deletePath:[NSString stringWithFormat:@"user/starred/%@", repo.fullName]
		parameters:nil
		   success:completionHandler
			 failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)repositoriesForCurrentUserWithCompletion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"user/repos"]
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRARepository class] clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)issuesForCurrentUserWithCompletion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"user/issues"]
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRAIssue class] clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)issuesForUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"users/%@/issues", user.name]
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRAIssue class] clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)gistsForCurrentUserWithCompletion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:@"gists"
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRAGist class] clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)gistsForUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler {
    [self getPath:[NSString stringWithFormat:@"users/%@/gists", user.name]
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRAGist class] clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)starredGistsForCurrentUserWithCompletion:(KRAClientCompletionBlock)completionHandler {
    [self getPath:@"gists/starred"
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRAGist class] clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

@end