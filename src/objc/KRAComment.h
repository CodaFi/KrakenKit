//
//  KRAComment.h
//  KrakenKit
//
//  Created by Robert Widmann on 5/12/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import <Mantle/Mantle.h>

@class KRAUser;

@interface KRAComment : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy) NSURL *commentURL;
@property (nonatomic, copy) NSURL *HTMLURL;
@property (nonatomic, copy) NSURL *issueURL;
@property (nonatomic, copy) NSNumber *commentID;
@property (nonatomic, copy) KRAUser *user;
@property (nonatomic, copy) NSDate *createdAt;
@property (nonatomic, copy) NSDate *updatedAt;
@property (nonatomic, copy) NSString *body;

@end
