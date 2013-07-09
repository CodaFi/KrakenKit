//
//  KRAClient+KRAUser.h
//  KrakenKit
//
//  Created by Robert Widmann on 4/30/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAClient.h"

@class KRARepository;

@interface KRAClient (KRAUser)

- (void)fetchUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler;
- (void)fetchUserWithID:(NSString *)userID completion:(KRAClientCompletionBlock)completionHandler;

- (void)repositoriesForCurrentUserWithCompletion:(KRAClientCompletionBlock)completionHandler;
- (void)repositoriesForUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler;

- (void)eventsForUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler;

- (void)notificationsForUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler;

- (void)starredRepositoriesForUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler;

- (void)starRepository:(KRARepository *)repo completion:(KRAClientCompletionBlock)completionHandler;
- (void)unstarRepository:(KRARepository *)repo completion:(KRAClientCompletionBlock)completionHandler;

- (void)issuesForCurrentUserWithCompletion:(KRAClientCompletionBlock)completionHandler;
- (void)issuesForUser:(KRAUser *)user completion:(KRAClientCompletionBlock)completionHandler;

@end
