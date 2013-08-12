//
//  KRARepositoryContent.h
//  KrakenKit
//
//  Created by Robert Widmann on 8/11/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import <Mantle/Mantle.h>

typedef NS_ENUM(NSUInteger, KRARepositoryContentType) {
	KRARepositoryContentTypeNone,
	KRARepositoryContentTypeFile,
	KRARepositoryContentTypeDirectory
};

@interface KRARepositoryContent : MTLModel <MTLJSONSerializing>

@property (nonatomic, assign) KRARepositoryContentType type;
@property (nonatomic, copy) NSString *encoding;
@property (nonatomic, copy) NSNumber *size;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *path;
@property (nonatomic, copy) NSString *content;
@property (nonatomic, copy) NSString *sha;
@property (nonatomic, copy) NSURL *url;

@end
