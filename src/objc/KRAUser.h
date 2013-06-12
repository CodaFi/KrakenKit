//
//  KRAUser.h
//  KrakenKit
//
//  Created by Robert Widmann on 4/30/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Mantle/Mantle.h>

typedef NS_ENUM(NSUInteger, KRAUserType) {
    KRAUserTypeUser,
    KRAUserTypeOrganization
};

@interface KRAUser : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy) NSString *login;
@property (nonatomic, copy) NSString *userID;
@property (nonatomic, copy) NSURL *avatarURL;
@property (nonatomic, copy) NSString *gravatarID;
@property (nonatomic, copy) NSURL *userURL;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *company;
@property (nonatomic, copy) NSURL *blogURL;
@property (nonatomic, copy) NSString *location;
@property (nonatomic, copy) NSString *email;
@property (nonatomic, copy) NSNumber *hirable;
@property (nonatomic, copy) NSString *bio;
@property (nonatomic, strong) NSDate *createdAt;
@property (nonatomic, assign) KRAUserType type;
@property (nonatomic, copy) NSNumber *publicReposCount;
@property (nonatomic, copy) NSNumber *publicGistsCount;
@property (nonatomic, copy) NSNumber *followersCount;
@property (nonatomic, copy) NSNumber *followingCount;

@end