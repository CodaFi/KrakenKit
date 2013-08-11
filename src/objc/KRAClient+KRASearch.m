//
//  KRAClient+KRASearch.m
//  KrakenKit
//
//  Created by Robert Widmann on 6/6/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAClient+KRASearch.h"
#import "KRAClient+KRAHandlerBlocks.h"
#import "KRAUser.h"
#import "KRARepository.h"
#import "KRAIssue.h"

@implementation KRAClient (KRASearch)

- (void)searchRepositories:(NSString *)keyword completion:(KRAClientCompletionBlock)completionHandler {
	NSParameterAssert(keyword != nil);
	[self getPath:@"search/repositories"
	   parameters:@{ @"q" : keyword }
		  success:[self successHandlerForArrayOfModelClass:[KRARepository class] clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)searchIssues:(NSString *)keyword completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"legacy/issues/search/%@", keyword]
	   parameters:nil
		  success:[self successHandlerForSearchArrayOfModelClass:[KRAIssue class] clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)searchUsers:(NSString *)keyword completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"legacy/user/search/%@", keyword]
	   parameters:nil
		  success:[self successHandlerForSearchArrayOfModelClass:[KRAUser class] clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

@end
