//
//  KRACommit.m
//  KrakenKit
//
//  Created by Robert Widmann on 5/12/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRACommit.h"
#import "KRAUser.h"

@implementation KRACommit

+ (NSDictionary *)JSONKeyPathsByPropertyKey {
	return @{
		@"sha" : @"sha",
		@"author" : @"author",
		@"message" : @"message",
		@"isDistinct" : @"distinct",
		@"url" : @"url"
	};
}

+ (NSValueTransformer *)authorJSONTransformer {
    return [MTLValueTransformer mtl_JSONDictionaryTransformerWithModelClass:KRAUser.class];
}

+ (NSValueTransformer *)isDistinctJSONTransformer {
    return [MTLValueTransformer valueTransformerForName:MTLBooleanValueTransformerName];
}

+ (NSValueTransformer *)urlJSONTransformer {
    return [MTLValueTransformer valueTransformerForName:MTLURLValueTransformerName];
}

@end
