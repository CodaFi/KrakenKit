//
//  KRAClient+KRAGist.h
//  KrakenKit
//
//  Created by IDA WIDMANN on 8/24/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAClient.h"

@class KRAGist;

@interface KRAClient (KRAGist)

- (void)publicGistsWithCompletion:(KRAClientCompletionBlock)completionHandler;
- (void)createGist:(KRAGist *)gist completion:(KRAClientCompletionBlock)completionHandler;

- (void)starGist:(KRAGist *)gist completion:(KRAClientCompletionBlock)completionHandler;
- (void)unstarGist:(KRAGist *)gist completion:(KRAClientCompletionBlock)completionHandler;


@end
