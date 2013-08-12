//
//  KRARepositoryTree.h
//  KrakenKit
//
//  Created by Robert Widmann on 8/11/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import <Mantle/Mantle.h>

@interface KRARepositoryTree : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy) NSArray *nodes;
@property (nonatomic, copy) NSString *sha;

@end
