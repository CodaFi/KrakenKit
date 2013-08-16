//
//  KRAIssue.h
//  KrakenKit
//
//  Created by Robert Widmann on 5/12/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import <Mantle/Mantle.h>

typedef NS_ENUM(int, KRAIssueState) {
	KRAIssueStateOpen,
	KRAIssueStateClosed
};

@class KRAUser, KRAPullRequest;

@interface KRAIssue : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSURL *issueURL;
@property (nonatomic, copy) NSURL *labelsURL;
@property (nonatomic, copy) NSURL *commentsURL;
@property (nonatomic, copy) NSURL *eventsURL;
@property (nonatomic, copy) NSURL *HTMLURL;
@property (nonatomic, copy) NSNumber *issueID;
@property (nonatomic, copy) NSNumber *number;
@property (nonatomic, copy) KRAUser *user;
@property (nonatomic, copy) NSArray *labels;
@property (nonatomic, assign) KRAIssueState state;
@property (nonatomic, copy) KRAUser *assignee;
@property (nonatomic, copy) NSString *milestone;
@property (nonatomic, copy) NSNumber *commentsCount;
@property (nonatomic, copy) NSDate *createdAt;
@property (nonatomic, copy) NSDate *updatedAt;
@property (nonatomic, copy) NSDate *closedAt;
@property (nonatomic, copy) KRAPullRequest *pullRequest;
@property (nonatomic, copy) NSString *body;

@end
