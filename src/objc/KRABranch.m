//
//  KRABranch.m
//  KrakenKit
//
//  Created by Robert Widmann on 8/11/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRABranch.h"
#import "KRACommit.h"

@implementation KRABranch

+ (NSDictionary *)JSONKeyPathsByPropertyKey {
	return @{
		@"name" : @"name",
		@"commit" : @"commit",
	};
}

+ (NSValueTransformer *)commitJSONTransformer {
    return [MTLValueTransformer mtl_JSONDictionaryTransformerWithModelClass:KRACommit.class];
}

@end
