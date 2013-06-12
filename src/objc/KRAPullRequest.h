//
//  KRAPullRequest.h
//  KrakenKit
//
//  Created by Robert Widmann on 5/13/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import <Mantle/Mantle.h>
#import "KRAIssue.h"

@class KRAUser;

@interface KRAPullRequest : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy) NSURL *url;
@property (nonatomic, copy) NSNumber *pullRequestID;
@property (nonatomic, copy) NSURL *htmlURL;
@property (nonatomic, copy) NSURL *diffURL;
@property (nonatomic, copy) NSURL *patchURL;
@property (nonatomic, copy) NSURL *issueURL;
@property (nonatomic, copy) NSNumber *issueNumber;
@property (nonatomic) KRAIssueState state;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *body;
@property (nonatomic, copy) NSDate *createdAt;
@property (nonatomic, copy) NSDate *updatedAt;
@property (nonatomic, copy) NSDate *closedAt;
@property (nonatomic, copy) NSDate *mergedAt;
@property (nonatomic, copy) NSString *mergeCommitSHA;
@property (nonatomic, copy) KRAUser *assignee;
@property (nonatomic, copy) KRAUser *user;
@property (nonatomic, copy) NSString *milestone;
@property (nonatomic) BOOL isMerged;
@property (nonatomic, copy) KRAUser *mergedBy;
@property (nonatomic, copy) NSNumber *commentsCount;
@property (nonatomic, copy) NSNumber *reviewCommentsCount;
@property (nonatomic, copy) NSNumber *commitsCount;
@property (nonatomic, copy) NSNumber *additionsCount;
@property (nonatomic, copy) NSNumber *deletionsCount;
@property (nonatomic, copy) NSNumber *changedFilesCount;

@end
