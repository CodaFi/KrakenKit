//
//  KRAClient+KRANotification.h
//  KrakenKit
//
//  Created by IDA WIDMANN on 8/24/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAClient.h"

@class KRANotification, KRARepository;

@interface KRAClient (KRANotification)

//- (void)markNotificationAsRead:(KRANotification *)notification completion:(KRAClientCompletionBlock)completionHandler;
- (void)markAllNotifcationsInRepositoryAsRead:(KRARepository *)repository completion:(KRAClientCompletionBlock)completionHandler;

@end
