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
	[self getPath:[NSString stringWithFormat:@"legacy/repos/search/%@", keyword]
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRARepository class] clientHandler:completionHandler]
		  failure:NULL];
}

- (void)searchIssues:(NSString *)keyword completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"legacy/issues/search/%@", keyword]
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:[KRAIssue class] clientHandler:completionHandler]
		  failure:NULL];
}

- (void)searchUsers:(NSString *)keyword completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"legacy/user/search/%@", keyword]
	   parameters:nil
		  success:[self successHandlerForSearchArrayOfModelClass:[KRAUser class] clientHandler:completionHandler]
		  failure:NULL];
}

@end
