//
//  KRAGist.m
//  KrakenKit
//
//  Created by IDA WIDMANN on 8/24/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAGist.h"
#import "KRAUser.h"

@implementation KRAGist

+ (NSDictionary *)JSONKeyPathsByPropertyKey {
	return @{
        @"url" : @"url",
        @"ID" : @"id",
        @"gistDescription" : @"description",
        @"isPublic" : @"public",
        @"user" : @"user",
        @"files" : @"files",
        @"commentsCount" : @"comments",
        @"createdAt" : @"created_at"
    };
}

+ (NSValueTransformer *)userJSONTransformer {
    return [MTLValueTransformer mtl_JSONDictionaryTransformerWithModelClass:KRAUser.class];
}

+ (NSValueTransformer *)isPublicJSONTransformer {
    return [MTLValueTransformer valueTransformerForName:MTLBooleanValueTransformerName];
}

+ (NSValueTransformer *)urlJSONTransformer {
    return [MTLValueTransformer valueTransformerForName:MTLURLValueTransformerName];
}

+ (NSValueTransformer *)filesJSONTransformer {
    return [MTLValueTransformer mtl_JSONArrayTransformerWithModelClass:KRAGistFile.class];
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

+ (NSValueTransformer *)createdAtJSONTransformer {
    return [MTLValueTransformer reversibleTransformerWithForwardBlock:^(NSString *str) {
        return [self.dateFormatter dateFromString:str];
    } reverseBlock:^(NSDate *date) {
        return [self.dateFormatter stringFromDate:date];
    }];
}

@end

@implementation KRAGistFile

+ (NSDictionary *)JSONKeyPathsByPropertyKey {
	return @{
        @"size" : @"size",
        @"filename" : @"filename"
    };
}

@end