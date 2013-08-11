//
//  KRAEventPayload.h
//  KrakenKit
//
//  Created by Robert Widmann on 5/12/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import <Mantle/Mantle.h>

typedef NS_ENUM(int, KRAGithubActionType) {
	KRAGithubActionTypeNone,
	KRAGithubActionTypeOpened,
	KRAGithubActionTypeClosed,
	KRAGithubActionTypeCreated
};

@class KRAIssue, KRAComment, KRAPullRequest, KRAUser;

@interface KRAEventPayload : MTLModel <MTLJSONSerializing>

@property (nonatomic, assign) KRAGithubActionType action;
@property (nonatomic, copy) NSNumber *number;

@property (nonatomic, copy) NSNumber *pushID;
@property (nonatomic, copy) NSNumber *size;
@property (nonatomic, copy) NSNumber *distinctSize;
@property (nonatomic, copy) NSString *ref;
@property (nonatomic, copy) NSString *refType;
@property (nonatomic, copy) NSString *head;
@property (nonatomic, copy) NSString *before;

@property (nonatomic, copy) NSArray *commits;

@property (nonatomic, copy) NSNumber *isPublic;
@property (nonatomic, copy) NSDate *createdAt;

@property (nonatomic, copy) KRAUser *target;
@property (nonatomic, copy) KRAUser *member;
@property (nonatomic, copy) KRAIssue *issue;
@property (nonatomic, copy) KRAComment *comment;
@property (nonatomic, copy) KRAPullRequest *pullRequest;

@end
