//
//  KRARepository.m
//  KrakenKit
//
//  Created by Robert Widmann on 4/30/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRARepository.h"

@implementation KRARepository

+ (NSDictionary *)JSONKeyPathsByPropertyKey {
	return @{
		@"repoID" : @"id",
		@"name" : @"name",
		@"fullName" : @"full_name",
		@"owner" : @"owner",
		@"isPrivateRepo" : @"private",
		@"repoDescription" : @"description",
		@"isFork" : @"fork",
		@"url" : @"url",
		@"createdAt" : @"created_at",
		@"updatedAt" : @"updated_at",
		@"pushedAt" : @"pushed_at",
		@"size" : @"size",
		@"watchersCount" : @"watchers_count",
		@"language" : @"language",
		@"hasIssues" : @"has_issues",
		@"hasDownloads" : @"has_downloads",
		@"hasWiki" : @"has_wiki",
		@"forksCount" : @"forks_count",
		@"openIssuesCount" : @"open_issues_count",
		@"masterBranch" : @"master_branch",
		@"defaultBranch" : @"default_branch"
	};
}

+ (NSValueTransformer *)urlJSONTransformer {
	return [MTLValueTransformer valueTransformerForName:MTLURLValueTransformerName];
}

+ (NSValueTransformer *)hasIssuesJSONTransformer {
	return [MTLValueTransformer valueTransformerForName:MTLBooleanValueTransformerName];
}

+ (NSValueTransformer *)isForkJSONTransformer {
	return [MTLValueTransformer valueTransformerForName:MTLBooleanValueTransformerName];
}

+ (NSValueTransformer *)hasDownloadsJSONTransformer {
	return [MTLValueTransformer valueTransformerForName:MTLBooleanValueTransformerName];
}

+ (NSValueTransformer *)hasWikiJSONTransformer {
	return [MTLValueTransformer valueTransformerForName:MTLBooleanValueTransformerName];
}

+ (NSValueTransformer *)isPrivateRepoJSONTransformer {
    return [NSValueTransformer valueTransformerForName:MTLBooleanValueTransformerName];
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
