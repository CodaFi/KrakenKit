//
//  KRAClient+KRASearch.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/6/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import <KrakenKit/KrakenKit.h>

@interface KRAClient (KRASearch)

- (void)searchRepositories:(NSString *)keyword completion:(KRAClientCompletionBlock)completionHandler;
- (void)searchIssues:(NSString *)keyword completion:(KRAClientCompletionBlock)completionHandler;
- (void)searchUsers:(NSString *)keyword completion:(KRAClientCompletionBlock)completionHandler;

@end
