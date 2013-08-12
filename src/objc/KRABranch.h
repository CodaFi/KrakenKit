//
//  KRABranch.h
//  KrakenKit
//
//  Created by Robert Widmann on 8/11/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import <Mantle/Mantle.h>

@class KRACommit;

@interface KRABranch : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy) KRACommit *commit;
@property (nonatomic, copy) NSString *name;

@end
