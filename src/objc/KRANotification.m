//
//  KRANotification.m
//  KrakenKit
//
//  Created by Robert Widmann on 6/6/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRANotification.h"
#import "KRARepository.h"

@implementation KRANotification

+ (NSDictionary *)JSONKeyPathsByPropertyKey {
	return @{
		@"notificationID" : @"id",
		@"lastReadAt" : @"last_read_at",
		@"reason" : @"reason",
		@"repository" : @"repository",
		@"subject" : @"subject",
		@"unread" : @"unread",
		@"updatedAt" : @"updated_at"
	};
}

+ (NSValueTransformer *)reasonJSONTransformer {
	NSDictionary *reasonTypes = @{
		@"subscribed" : @(KRANotificationReasonSubscribed),
		@"mention" : @(KRANotificationReasonMention),
	};
	
    return [MTLValueTransformer reversibleTransformerWithForwardBlock:^(NSString *str) {
        return reasonTypes[str];
    } reverseBlock:^(NSNumber *state) {
        return [reasonTypes allKeysForObject:state].lastObject;
    }];
}

+ (NSValueTransformer *)repositoryJSONTransformer {
    return [NSValueTransformer mtl_JSONDictionaryTransformerWithModelClass:KRARepository.class];
}

+ (NSValueTransformer *)subjectJSONTransformer {
    return [NSValueTransformer mtl_JSONDictionaryTransformerWithModelClass:KRANotificationSubject.class];
}

+ (NSValueTransformer *)unreadJSONTransformer {
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

+ (NSValueTransformer *)lastReadAtJSONTransformer {
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


@end

@implementation KRANotificationSubject

+ (NSDictionary *)JSONKeyPathsByPropertyKey {
	return @{
		@"lastCommentURL" : @"latest_comment_url",
		@"title" : @"title",
		@"type" : @"type",
		@"url" : @"url",
	};
}

+ (NSValueTransformer *)typeJSONTransformer {
	NSDictionary *types = @{
		@"PullRequest" : @(KRANotificationSubjectTypePullRequest),
		@"Issue" : @(KRANotificationSubjectTypeIssue),
	};
	
    return [MTLValueTransformer reversibleTransformerWithForwardBlock:^(NSString *str) {
        return types[str];
    } reverseBlock:^(NSNumber *state) {
        return [types allKeysForObject:state].lastObject;
    }];
}

+ (NSValueTransformer *)urlJSONTransformer {
    return [MTLValueTransformer valueTransformerForName:MTLURLValueTransformerName];
}

+ (NSValueTransformer *)lastCommentURLJSONTransformer {
    return [MTLValueTransformer valueTransformerForName:MTLURLValueTransformerName];
}

@end
