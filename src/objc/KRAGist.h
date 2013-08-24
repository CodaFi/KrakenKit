//
//  KRAGist.h
//  KrakenKit
//
//  Created by IDA WIDMANN on 8/24/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import <Mantle/Mantle.h>

@class KRAUser;

@interface KRAGist : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy) NSURL *url;
@property (nonatomic, copy) NSNumber *ID;
@property (nonatomic, copy) NSString *gistDescription;
@property (nonatomic) BOOL isPublic;
@property (nonatomic, copy) KRAUser *user;
@property (nonatomic, copy) NSArray /*KRAGistFile*/ *files;
@property (nonatomic, copy) NSNumber *commentsCount;
@property (nonatomic, copy) NSDate *createdAt;

@end

@interface KRAGistFile : NSObject <MTLJSONSerializing>

@property (nonatomic, copy) NSNumber *size;
@property (nonatomic, copy) NSString *filename;

@end
