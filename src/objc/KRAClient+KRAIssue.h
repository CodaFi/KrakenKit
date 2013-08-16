//
//  KRAClient+KRAIssue.h
//  KrakenKit
//
//  Created by Robert Widmann on 8/15/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAClient.h"

@class KRARepository, KRAIssue;

@interface KRAClient (KRAIssue)

- (void)issuesForRepository:(KRARepository *)repository completion:(KRAClientCompletionBlock)completionHandler;
- (void)commentsOnIssue:(KRAIssue *)issue fromRepository:(KRARepository *)repository completion:(KRAClientCompletionBlock)completionHandler;

- (void)commentOnIssue:(KRAIssue *)issue fromRepository:(KRARepository *)repository withBody:(NSString *)body completion:(KRAClientCompletionBlock)completionHandler;

@end
