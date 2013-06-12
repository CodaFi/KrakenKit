//
//  KRANotification.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/6/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import <Mantle/Mantle.h>

@class KRARepository;

typedef NS_ENUM(NSUInteger, KRANotificationSubjectType) {
	KRANotificationSubjectTypeIssue,
	KRANotificationSubjectTypePullRequest
};

@interface KRANotificationSubject : MTLModel <MTLJSONSerializing>

@property (nonatomic, strong) NSURL *lastCommentURL;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, assign) KRANotificationSubjectType type;
@property (nonatomic, strong) NSURL *url;

@end

typedef NS_ENUM(NSUInteger, KRANotificationReason) {
	KRANotificationReasonSubscribed,
	KRANotificationReasonMention
};

@interface KRANotification : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy) NSNumber *notificationID;
@property (nonatomic, assign) KRANotificationReason reason;
@property (nonatomic, assign) BOOL unread;
@property (nonatomic, copy) KRANotificationSubject *subject;
@property (nonatomic, strong) KRARepository *repository;
@property (nonatomic, copy) NSDate *lastReadAt;
@property (nonatomic, copy) NSDate *updatedAt;

@end
