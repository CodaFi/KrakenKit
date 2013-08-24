//
//  KRAClient+KRAHandlerBlocks.m
//  KrakenKit
//
//  Created by Robert Widmann on 4/30/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAClient+KRAHandlerBlocks.h"
#import <Mantle/Mantle.h>

@implementation KRAClient (KRAHandlerBlocks)

- (AFNetworkingSuccessBlock)successHandlerForClientHandler:(KRAClientCompletionBlock)handler unboxBlock:(id(^)(id, NSError **))unboxBlock {
	return ^(AFHTTPRequestOperation *operation, id responseJSON) {
		id finalObject = nil;
		NSDictionary *JSON = [NSJSONSerialization JSONObjectWithData:responseJSON options:0 error:nil];
		NSError *error = nil;
		
		if (unboxBlock) {
			finalObject = unboxBlock(JSON, &error);
		}
		if (handler) {
			handler(finalObject, error);
		}
	};
}

- (AFNetworkingSuccessBlock)successHandlerForResourceClass:(Class)resourceClass clientHandler:(KRAClientCompletionBlock)handler {
	return [self successHandlerForClientHandler:handler unboxBlock: ^id (NSDictionary *responseJSON, NSError *__autoreleasing *error) {
		id unboxedObject = nil;
		if ([resourceClass isSubclassOfClass:MTLModel.class]) {
			unboxedObject = [MTLJSONAdapter modelOfClass:resourceClass fromJSONDictionary:responseJSON error:error];
		}
		return unboxedObject;
	}];
}

- (AFNetworkingSuccessBlock)successHandlerForRawDictionaryWithClientHandler:(KRAClientCompletionBlock)handler {
	return [self successHandlerForClientHandler:handler unboxBlock: ^id (id responseJSON, NSError *__autoreleasing *error) {
		if ([responseJSON isKindOfClass:NSDictionary.class]) {
			return responseJSON;
		}
		return nil;
	}];
}

- (NSArray *)kra_unpackResponseArray:(id)responseJSON withModelClass:(Class)resourceClass {
	id unboxedObject = nil;
	if ([resourceClass isSubclassOfClass:MTLModel.class]) {
		NSValueTransformer *arrayTransformer = [MTLValueTransformer mtl_JSONArrayTransformerWithModelClass:resourceClass];
		unboxedObject = [arrayTransformer transformedValue:responseJSON];
	}
	return unboxedObject;
}

- (AFNetworkingSuccessBlock)successHandlerForArrayOfModelClass:(Class)resourceClass clientHandler:(KRAClientCompletionBlock)handler {
	return [self successHandlerForClientHandler:handler unboxBlock: ^id (id arrayResponse, NSError *__autoreleasing *error) {
		return [self kra_unpackResponseArray:arrayResponse withModelClass:resourceClass];
	}];
}

- (AFNetworkingSuccessBlock)successHandlerForSearchArrayOfModelClass:(Class)resourceClass clientHandler:(KRAClientCompletionBlock)handler {
	return [self successHandlerForClientHandler:handler unboxBlock: ^id (id arrayResponse, NSError *__autoreleasing *error) {
		return [self kra_unpackSearchResponseArray:arrayResponse withModelClass:resourceClass];
	}];
}

- (NSArray *)kra_unpackSearchResponseArray:(id)responseJSON withModelClass:(Class)resourceClass {
	id unboxedObject = nil;
	if ([responseJSON isKindOfClass:NSDictionary.class] && [resourceClass isSubclassOfClass:MTLModel.class]) {
		if (responseJSON[@"users"]) {
			NSValueTransformer *arrayTransformer = [MTLValueTransformer mtl_JSONArrayTransformerWithModelClass:resourceClass];
			unboxedObject = [arrayTransformer transformedValue:responseJSON[@"users"]];
		} else if (responseJSON[@"repositories"]) {
			NSValueTransformer *arrayTransformer = [MTLValueTransformer mtl_JSONArrayTransformerWithModelClass:resourceClass];
			unboxedObject = [arrayTransformer transformedValue:responseJSON[@"repositories"]];
		}

	}
	return unboxedObject;
}

- (AFNetworkingFailureBlock)failureHandlerForClientHandler:(KRAClientCompletionBlock)handler {
	return ^(AFHTTPRequestOperation *operation, NSError *error) {
		if (handler) {
			handler(nil, error);
		}
	};
}

@end