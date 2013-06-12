//
//  KRAPullRequest.m
//  KrakenKit
//
//  Created by Robert Widmann on 5/13/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAPullRequest.h"
#import "KRAUser.h"

@implementation KRAPullRequest

+ (NSDictionary *)JSONKeyPathsByPropertyKey {
	return @{
		@"url" : @"url",
		@"pullRequestID" : @"id",
		@"issueNumber" : @"number",
		@"state" : @"state",
		@"title" : @"title",
		@"body" : @"body",
		@"createdAt" : @"created_at",
		@"updatedAt" : @"updated_at",
		@"closedAt" : @"closed_at",
		@"mergedAt" : @"merged_at",
		@"mergeCommitSHA" : @"merge_commit_sha",
		@"assignee" : @"assignee",
		@"user" : @"user",
		@"milestone" : @"milestone",
		@"isMerged" : @"merged",
		@"mergedBy" : @"merged_by",
		@"commentsCount" : @"comments",
		@"reviewCommentsCount" : @"review_comments",
		@"commitsCount" : @"commits",
		@"additionsCount" : @"additions",
		@"deletionsCount" : @"deletions",
		@"changedFilesCount" : @"changed_files",
	};
}

+ (NSValueTransformer *)stateJSONTransformer {
	NSDictionary *actionTypes = @{
		@"open" : @(KRAIssueStateOpen),
		@"closed" : @(KRAIssueStateClosed),
	};
	
    return [MTLValueTransformer reversibleTransformerWithForwardBlock:^(NSString *str) {
        return actionTypes[str];
    } reverseBlock:^(NSNumber *state) {
        return [actionTypes allKeysForObject:state].lastObject;
    }];
}

+ (NSValueTransformer *)isMergedJSONTransformer {
    return [MTLValueTransformer valueTransformerForName:MTLBooleanValueTransformerName];
}

+ (NSValueTransformer *)assigneeJSONTransformer {
    return [NSValueTransformer mtl_JSONDictionaryTransformerWithModelClass:KRAUser.class];
}

+ (NSValueTransformer *)userJSONTransformer {
    return [NSValueTransformer mtl_JSONDictionaryTransformerWithModelClass:KRAUser.class];
}

+ (NSValueTransformer *)mergedByJSONTransformer {
    return [NSValueTransformer mtl_JSONDictionaryTransformerWithModelClass:KRAUser.class];
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

+ (NSValueTransformer *)updatedAtJSONTransformer {
    return [MTLValueTransformer reversibleTransformerWithForwardBlock:^(NSString *str) {
        return [self.dateFormatter dateFromString:str];
    } reverseBlock:^(NSDate *date) {
        return [self.dateFormatter stringFromDate:date];
    }];
}

+ (NSValueTransformer *)closedAtJSONTransformer {
    return [MTLValueTransformer reversibleTransformerWithForwardBlock:^(NSString *str) {
        return [self.dateFormatter dateFromString:str];
    } reverseBlock:^(NSDate *date) {
        return [self.dateFormatter stringFromDate:date];
    }];
}

+ (NSValueTransformer *)mergedAtAtJSONTransformer {
    return [MTLValueTransformer reversibleTransformerWithForwardBlock:^(NSString *str) {
        return [self.dateFormatter dateFromString:str];
    } reverseBlock:^(NSDate *date) {
        return [self.dateFormatter stringFromDate:date];
    }];
}



@end
