//
//  KRAClient+KRAGist.m
//  KrakenKit
//
//  Created by IDA WIDMANN on 8/24/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAClient+KRAGist.h"
#import "KRAClient+KRAHandlerBlocks.h"
#import "KRAGist.h"

@implementation KRAClient (KRAGist)

- (void)publicGistsWithCompletion:(KRAClientCompletionBlock)completionHandler {
    [self getPath:@"gists/public"
	   parameters:nil
		  success:[self successHandlerForArrayOfModelClass:KRAGist.class clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)createGist:(KRAGist *)gist completion:(KRAClientCompletionBlock)completionHandler {
    NSParameterAssert(gist != nil);
    
    [self postPath:@"gists/public"
	   parameters:[gist dictionaryValue]
		  success:[self successHandlerForResourceClass:KRAGist.class clientHandler:completionHandler]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)starGist:(KRAGist *)gist completion:(KRAClientCompletionBlock)completionHandler {
    NSParameterAssert(gist != nil);
    
    [self putPath:[NSString stringWithFormat:@"/gists/%lu/star", (unsigned long)gist.ID.unsignedIntegerValue]
        parameters:nil
          success:[self successHandlerForClientHandler:completionHandler unboxBlock:NULL]
           failure:[self failureHandlerForClientHandler:completionHandler]];
}

- (void)unstarGist:(KRAGist *)gist completion:(KRAClientCompletionBlock)completionHandler {
    NSParameterAssert(gist != nil);
    
    [self deletePath:[NSString stringWithFormat:@"/gists/%lu/star", (unsigned long)gist.ID.unsignedIntegerValue]
        parameters:nil
           success:[self successHandlerForClientHandler:completionHandler unboxBlock:NULL]
           failure:[self failureHandlerForClientHandler:completionHandler]];
}

@end
