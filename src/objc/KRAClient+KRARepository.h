//
//  KRAClient+KRARepository.h
//  KrakenKit
//
//  Created by Robert Widmann on 8/11/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAClient.h"

@class KRARepository, KRABranch;

@interface KRAClient (KRARepository)

- (void)fetchRepository:(KRARepository *)repository completion:(KRAClientCompletionBlock)completionHandler;
- (void)branches:(KRARepository *)repository completion:(KRAClientCompletionBlock)completionHandler;
- (void)languageStatistics:(KRARepository *)repository completion:(KRAClientCompletionBlock)completionHandler;
- (void)repositoryContents:(KRARepository *)repository atBranch:(KRABranch *)branch completion:(KRAClientCompletionBlock)completionHandler;
- (void)readme:(KRARepository *)repository completion:(KRAClientCompletionBlock)completionHandler;

@end
