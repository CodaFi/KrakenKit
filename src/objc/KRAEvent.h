//
//  KRAEvent.h
//  KrakenKit
//
//  Created by Robert Widmann on 4/30/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import <Mantle/Mantle.h>

typedef NS_ENUM(int, KRAGithubEventType) {
	KRAGithubCommitCommentEventType,
	KRAGithubCreateEventType,
	KRAGithubDeleteEventType,
	KRAGithubDownloadEventType,
	KRAGithubFollowEventType,
	KRAGithubForkEventType,
	KRAGithubForkApplyEventType,
	KRAGithubGistEventType,
	KRAGithubGollumEventType,
	KRAGithubIssueCommentEventType,
	KRAGithubIssuesEventType,
	KRAGithubMemberEventType,
	KRAGithubPublicEventType,
	KRAGithubPullRequestEventType,
	KRAGithubPullRequestReviewCommentEventType,
	KRAGithubPushEventType,
	KRAGithubTeamAddEventType,
	KRAGithubWatchEventType,
};

@class KRARepository, KRAEventPayload, KRAUser;

@interface KRAEvent : MTLModel <MTLJSONSerializing>

@property (nonatomic, assign) KRAGithubEventType type;
@property (nonatomic, copy) NSNumber *isPublic;
@property (nonatomic, copy) KRAEventPayload *payload;
@property (nonatomic, strong) KRARepository *repository;
@property (nonatomic, strong) KRAUser *actor;
@property (nonatomic, strong) KRAUser *organization;
@property (nonatomic, copy) NSDate *createdAt;
@property (nonatomic, copy) NSNumber *eventID;

@end
