//
//  KRAClient+KRAIssue.m
//  KrakenKit
//
//  Created by Robert Widmann on 8/15/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAClient+KRAIssue.h"
#import "KRAClient+KRAHandlerBlocks.h"
#import "KRARepository.h"
#import "KRAIssue.h"
#import "KRAComment.h"

@implementation KRAClient (KRAIssue)

- (void)issuesForRepository:(KRARepository *)repository completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"repos/%@/issues", repository.fullName]
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:KRAIssue.class clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)commentsOnIssue:(KRAIssue *)issue fromRepository:(KRARepository *)repository completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"repos/%@/issues/%lu/comments", repository.fullName, issue.number.unsignedLongValue]
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:KRAComment.class clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)commentOnIssue:(KRAIssue *)issue fromRepository:(KRARepository *)repository withBody:(NSString *)body completion:(KRAClientCompletionBlock)completionHandler {
	NSParameterAssert(body != nil);
	[self postPath:[NSString stringWithFormat:@"repos/%@/issues/%lu/comments", repository.fullName, issue.number.unsignedLongValue]
		parameters:@{ @"body" : body }
			success:[self successHandlerForResourceClass:KRAComment.class clientHandler:completionHandler]
			failure:[self failureHandlerForClientHandler:completionHandler]];
}

@end
