//
//  KRAClient+KRARepository.m
//  KrakenKit
//
//  Created by Robert Widmann on 8/11/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAClient+KRARepository.h"
#import "KRAClient+KRAHandlerBlocks.h"
#import "KRARepository.h"
#import "KRARepositoryContent.h"
#import "KRARepositoryTree.h"
#import "KRABranch.h"
#import "KRACommit.h"

@implementation KRAClient (KRARepository)

- (void)fetchRepository:(KRARepository *)repository completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"repos/%@", repository.fullName]
	   parameters:nil
		  success:[self successHandlerForResourceClass:KRARepository.class clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)fetchCommit:(KRACommit *)commit fromRepository:(KRARepository *)repository completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"repos/%@/commits/%@", repository.fullName, commit.sha]
	   parameters:nil
		  success:[self successHandlerForResourceClass:KRACommit.class clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)branches:(KRARepository *)repository completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"repos/%@/branches", repository.fullName]
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:KRABranch.class clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)languageStatistics:(KRARepository *)repository completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"repos/%@/languages", repository.fullName]
	   parameters:nil
		  success:[self successHandlerForRawDictionaryWithClientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)repositoryContents:(KRARepository *)repository atBranch:(KRABranch *)branch completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"repos/%@/git/trees/%@", repository.fullName, branch.commit.sha]
	   parameters:nil
		  success:[self successHandlerForResourceClass:KRARepositoryTree.class clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];

}

- (void)readme:(KRARepository *)repository completion:(KRAClientCompletionBlock)completionHandler {
	[self getPath:[NSString stringWithFormat:@"repos/%@/readme", repository.fullName]
	   parameters:nil
		  success:[self successHandlerForResourceClass:KRARepositoryContent.class clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

@end
