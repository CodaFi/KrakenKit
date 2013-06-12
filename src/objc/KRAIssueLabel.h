//
//  KRAIssueLabel.h
//  KrakenKit
//
//  Created by Robert Widmann on 5/13/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import <Mantle/Mantle.h>

@interface KRAIssueLabel : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy) NSURL *url;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *colorHex;

@end
