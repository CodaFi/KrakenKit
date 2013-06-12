//
//  KRAClient+KRAHandlerBlocks.h
//  KrakenKit
//
//  Created by Robert Widmann on 4/30/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAClient.h"

typedef void (^AFNetworkingSuccessBlock)(AFHTTPRequestOperation *operation, id responseObject);
typedef void (^AFNetworkingFailureBlock)(AFHTTPRequestOperation *operation, NSError *error);

@interface KRAClient (KRAHandlerBlocks)

- (NSArray *)kra_unpackResponseArray:(id)responseJSON withModelClass:(Class)resourceClass;
- (AFNetworkingSuccessBlock)successHandlerForClientHandler:(KRAClientCompletionBlock)handler unboxBlock:(id (^)(id responseJSON, NSError **error))unboxBlock;
- (AFNetworkingSuccessBlock)successHandlerForResourceClass:(Class)resourceClass clientHandler:(KRAClientCompletionBlock)handler;
- (AFNetworkingSuccessBlock)successHandlerForArrayOfModelClass:(Class)resourceClass clientHandler:(KRAClientCompletionBlock)handler;
- (AFNetworkingSuccessBlock)successHandlerForSearchArrayOfModelClass:(Class)resourceClass clientHandler:(KRAClientCompletionBlock)handler;

@end
