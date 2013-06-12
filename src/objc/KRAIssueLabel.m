//
//  KRAIssueLabel.m
//  KrakenKit
//
//  Created by Robert Widmann on 5/13/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAIssueLabel.h"

@implementation KRAIssueLabel

+ (NSDictionary *)JSONKeyPathsByPropertyKey {
	return @{
		@"url" : @"url",
		@"name" : @"name",
		@"colorHex" : @"color"
	};
}

+ (NSValueTransformer *)urlJSONTransformer {
    return [MTLValueTransformer valueTransformerForName:MTLURLValueTransformerName];
}

@end
