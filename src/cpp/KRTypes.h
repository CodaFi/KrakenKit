//
//  KRTypes.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/25/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef KrakenKit_KRTypes_h
#define KrakenKit_KRTypes_h

struct jsonz_object_t;

namespace KrakenKit {
	class HTTPOperation;
	
	typedef void(*KRHTTPOperationSuccessCallback)(const HTTPOperation *request, const APIResponse *response, jsonz_object_t *json);
	typedef void(*KRHTTPOperationFailureCallback)(const HTTPOperation *request, const Error &error);
	
#if __has_feature(blocks)
	typedef void(^KRHTTPOperationSuccessBlock)(const HTTPOperation *request, const APIResponse *response, jsonz_object_t *json);
	typedef void(^KRHTTPOperationFailureBlock)(const HTTPOperation *request, const Error &error);
#endif
}

#endif
