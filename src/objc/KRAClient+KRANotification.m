//
//  KRAClient+KRANotification.m
//  KrakenKit
//
//  Created by IDA WIDMANN on 8/24/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAClient+KRANotification.h"
#import "KRAClient+KRAHandlerBlocks.h"
#import "KRANotification.h"
#import "KRARepository.h"

@implementation KRAClient (KRANotification)

- (void)markNotificationAsRead:(KRANotification *)notification completion:(KRAClientCompletionBlock)completionHandler {
//    [self putPath:[NSString stringWithFormat:@"notifications", user.login]
//	   parameters:nil
//		  success:[self successHandlerForClientHandler:completionHandler]
//		  failure:[self failureHandlerForClientHandler:completionHandler]];
    NSAssert(0, @"Unhandled API");
}

- (void)markAllNotifcationsInRepositoryAsRead:(KRARepository *)repository completion:(KRAClientCompletionBlock)completionHandler {
    [self putPath:[NSString stringWithFormat:@"/repos/%@/notifications", repository.fullName]
	   parameters:@{}
		  success:[self successHandlerForClientHandler:completionHandler unboxBlock:NULL]
		  failure:[self failureHandlerForClientHandler:completionHandler]];
}

@end
