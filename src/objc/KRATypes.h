//
//  KRATypes.h
//  KrakenKit
//
//  Created by Robert Widmann on 4/30/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef KrakenKit_KRATypes_h
#define KrakenKit_KRATypes_h

#include "metamacros.h"
#import <Foundation/Foundation.h>

#if defined(__cplusplus)
#define KRAKENKIT_EXTERN extern "C"
#else
#define KRAKENKIT_EXTERN extern
#endif


typedef NS_ENUM(NSUInteger, KRAErrorType) {
	KRAErrorTypeUnknown = 0,
	KRAErrorTypeInvalidToken,
	KRAErrorTypeNotAuthorized,
	KRAErrorTypeTokenExpired,
	KRAErrorTypeNoStoredCredentials,
	KRAErrorTypeRedirectURIRequired
};


typedef NS_ENUM(NSUInteger, KRAHTTPStatus) {
	KRAHTTPStatusOK = 200,
	KRAHTTPStatusBadRequest = 400,
	KRAHTTPStatusForbidden = 403,
	KRAHTTPStatusNotAllowed = 405,
	KRAHTTPStatusCLAccountOnly = 419,
	KRAHTTPStatusInternalServerError = 500,
};


KRAKENKIT_EXTERN NSString *const kKRAErrorDomain;
KRAKENKIT_EXTERN NSString *const kKRAErrorTypeKey;
KRAKENKIT_EXTERN NSString *const kKRAErrorIDKey;

//#error A client ID and a client secret must be specified
#define KRAGithubClientID @""
#define KRAGithubClientSecret @""

#endif
