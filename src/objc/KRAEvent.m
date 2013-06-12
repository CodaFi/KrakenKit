//
//  KRAEvent.m
//  KrakenKit
//
//  Created by Robert Widmann on 4/30/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAEvent.h"
#import "KRAUser.h"
#import "KRAEventPayload.h"
#import "KRARepository.h"

@implementation KRAEvent

+ (NSDictionary *)JSONKeyPathsByPropertyKey {
	return @{
		@"type" : @"type",
		@"isPublic" : @"public",
  		@"payload" : @"payload",
		@"repository" : @"repo",
		@"actor" : @"actor",
		@"organization" : @"org",
		@"createdAt" : @"created_at",
		@"eventID" : @"id"
	};
}

+ (NSValueTransformer *)typeJSONTransformer {
    NSDictionary *eventTypes = @{
		@"CommitCommentEvent" : @(KRAGithubCommitCommentEventType),
		@"CreateEvent" : @(KRAGithubCreateEventType),
		@"DeleteEvent" : @(KRAGithubDeleteEventType),
		@"DownloadEvent" : @(KRAGithubDownloadEventType),
		@"FollowEvent" : @(KRAGithubFollowEventType),
		@"ForkEvent" : @(KRAGithubForkEventType),
		@"ForkApplyEvent" : @(KRAGithubForkApplyEventType),
		@"GistEvent" : @(KRAGithubGistEventType),
		@"GollumEvent" : @(KRAGithubGollumEventType),
		@"IssueCommentEvent" : @(KRAGithubIssueCommentEventType),
		@"IssuesEvent" : @(KRAGithubIssuesEventType),
		@"MemberEvent" : @(KRAGithubMemberEventType),
		@"PublicEvent" : @(KRAGithubPublicEventType),
		@"PullRequestEvent" : @(KRAGithubPullRequestEventType),
		@"PullRequestReviewCommentEvent" : @(KRAGithubPullRequestReviewCommentEventType),
		@"PushEvent" : @(KRAGithubPushEventType),
		@"TeamAddEvent" : @(KRAGithubTeamAddEventType),
		@"WatchEvent" : @(KRAGithubWatchEventType),
	};
	
    return [MTLValueTransformer reversibleTransformerWithForwardBlock:^(NSString *str) {
        return eventTypes[str];
    } reverseBlock:^(NSNumber *state) {
        return [eventTypes allKeysForObject:state].lastObject;
    }];
}

+ (NSValueTransformer *)payloadJSONTransformer {
    return [NSValueTransformer mtl_JSONDictionaryTransformerWithModelClass:KRAEventPayload.class];
}

+ (NSValueTransformer *)actorJSONTransformer {
    return [NSValueTransformer mtl_JSONDictionaryTransformerWithModelClass:KRAUser.class];
}

+ (NSValueTransformer *)organizationJSONTransformer {
    return [NSValueTransformer mtl_JSONDictionaryTransformerWithModelClass:KRAUser.class];
}

+ (NSValueTransformer *)repositoryJSONTransformer {
    return [NSValueTransformer mtl_JSONDictionaryTransformerWithModelClass:KRARepository.class];
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
