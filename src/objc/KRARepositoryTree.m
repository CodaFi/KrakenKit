//
//  KRARepositoryTree.m
//  KrakenKit
//
//  Created by Robert Widmann on 8/11/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRARepositoryTree.h"
#import "KRARepositoryContent.h"

@implementation KRARepositoryTree

+ (NSDictionary *)JSONKeyPathsByPropertyKey {
	return @{
		@"sha" : @"sha",
		@"nodes" : @"tree",
	};
}

+ (NSValueTransformer *)nodesJSONTransformer {
    return [NSValueTransformer mtl_JSONArrayTransformerWithModelClass:KRARepositoryContent.class];
}

@end
