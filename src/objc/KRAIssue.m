//
//  KRAIssue.m
//  KrakenKit
//
//  Created by Robert Widmann on 5/12/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAIssue.h"
#import "KRAIssueLabel.h"
#import "KRAUser.h"
#import "KRAComment.h"
#import "KRAPullRequest.h"

@implementation KRAIssue

+ (NSDictionary *)JSONKeyPathsByPropertyKey {
	return @{
		@"title" : @"title",
		@"issueURL" : @"url",
		@"labelsURL" : @"labels_url",
		@"commentsURL" : @"comments_url",
		@"eventsURL" : @"events_url",
		@"HTMLURL" : @"html_url",
		@"issueID" : @"id",
		@"number" : @"number",
		@"user" : @"user",
		@"labels" : @"labels",
		@"state" : @"state",
		@"assignee" : @"assignee",
		@"milestone" : @"milestone",
		@"commentsCount" : @"comments",
		@"createdAt" : @"created_at",
		@"updatedAt" : @"updated_at",
		@"closedAt" : @"closed_at",
		@"pullRequest" : @"pull_request",
		@"body" : @"body"
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

+ (NSValueTransformer *)issueURLJSONTransformer {
    return [MTLValueTransformer valueTransformerForName:MTLURLValueTransformerName];
}

+ (NSValueTransformer *)commentsURLJSONTransformer {
    return [MTLValueTransformer valueTransformerForName:MTLURLValueTransformerName];
}

+ (NSValueTransformer *)eventsURLJSONTransformer {
    return [MTLValueTransformer valueTransformerForName:MTLURLValueTransformerName];
}

+ (NSValueTransformer *)HTMLURLJSONTransformer {
    return [MTLValueTransformer valueTransformerForName:MTLURLValueTransformerName];
}

+ (NSValueTransformer *)labelsURLJSONTransformer {
    return [MTLValueTransformer valueTransformerForName:MTLURLValueTransformerName];
}

+ (NSValueTransformer *)userJSONTransformer {
    return [MTLValueTransformer mtl_JSONDictionaryTransformerWithModelClass:KRAUser.class];
}

+ (NSValueTransformer *)asigneeJSONTransformer {
    return [MTLValueTransformer mtl_JSONDictionaryTransformerWithModelClass:KRAUser.class];
}

+ (NSValueTransformer *)commentJSONTransformer {
    return [MTLValueTransformer mtl_JSONArrayTransformerWithModelClass:KRAComment.class];
}

+ (NSValueTransformer *)labelsJSONTransformer {
    return [MTLValueTransformer mtl_JSONArrayTransformerWithModelClass:KRAIssueLabel.class];
}

+ (NSValueTransformer *)pullRequestJSONTransformer {
    return [MTLValueTransformer mtl_JSONDictionaryTransformerWithModelClass:KRAPullRequest.class];
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


@end
