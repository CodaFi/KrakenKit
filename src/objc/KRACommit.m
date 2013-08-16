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
		@"url" : @"url",
		@"date" : @"commit.author.date",
		@"commitMessage" : @"commit.message"
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

+ (NSDateFormatter *)dateFormatter {
    static NSDateFormatter *dateFormatter = nil;
	if (dateFormatter == nil) {
		dateFormatter = [[NSDateFormatter alloc] init];
		dateFormatter.locale = [[NSLocale alloc] initWithLocaleIdentifier:@"en_US_POSIX"];
		dateFormatter.dateFormat = @"yyyy-MM-dd'T'HH:mm:ss'Z'";
	}
    return dateFormatter;
}

+ (NSValueTransformer *)dateJSONTransformer {
    return [MTLValueTransformer reversibleTransformerWithForwardBlock:^(NSString *str) {
        return [self.dateFormatter dateFromString:str];
    } reverseBlock:^(NSDate *date) {
        return [self.dateFormatter stringFromDate:date];
    }];
}

@end
