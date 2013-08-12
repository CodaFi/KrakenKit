//
//  KRARepository.h
//  KrakenKit
//
//  Created by Robert Widmann on 4/30/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import <Mantle/Mantle.h>

//#warning Unfinished KRARepository

@class KRAUser;

@interface KRARepository : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy) KRARepository *parentRepository;
@property (nonatomic, copy) NSString *repoID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *fullName;
@property (nonatomic, copy) KRAUser *owner;
@property (nonatomic) BOOL isPrivateRepo;
@property (nonatomic, copy) NSString *repoDescription;
@property (nonatomic) BOOL isFork;
@property (nonatomic, copy) NSURL *url;
@property (nonatomic, copy) NSDate *createdAt;
@property (nonatomic, copy) NSDate *updatedAt;
@property (nonatomic, copy) NSDate *pushedAt;
@property (nonatomic, copy) NSNumber *size;
@property (nonatomic, copy) NSNumber *watchersCount;
@property (nonatomic, copy) NSString *language;
@property (nonatomic, copy) NSNumber *hasIssues;
@property (nonatomic, copy) NSNumber *hasDownloads;
@property (nonatomic, copy) NSNumber *hasWiki;
@property (nonatomic, copy) NSNumber *forksCount;
@property (nonatomic, copy) NSNumber *openIssuesCount;
@property (nonatomic, copy) NSString *masterBranch;
@property (nonatomic, copy) NSString *defaultBranch;

@end
