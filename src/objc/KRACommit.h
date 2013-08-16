//
//  KRACommit.h
//  KrakenKit
//
//  Created by Robert Widmann on 5/12/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import <Mantle/Mantle.h>

@class KRAUser;

@interface KRACommit : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy) NSString *sha;
@property (nonatomic, copy) KRAUser *author;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, copy) NSString *commitMessage;
@property (nonatomic) BOOL isDistinct;
@property (nonatomic, copy) NSURL *url;
@property (nonatomic, copy) NSDate *date;

@end
