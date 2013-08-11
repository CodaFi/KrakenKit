//
//  KRHTTPOperation.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/24/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__KRHTTPOperation__
#define __KrakenKit__KRHTTPOperation__

#include "KROperation.h"
#include "KRError.h"
#include "KRAPIResponse.h"
#include "KRTypes.h"
#if	__IPHONE_OS_VERSION_MIN_REQUIRED
#include "curl.h"
#else
#include <curl/curl.h>
#endif
#include "KRURLRequest.h"

namespace KrakenKit {
	
	class HTTPOperation : public Operation {
			
	public:
		HTTPOperation(URLRequest &request);
		HTTPOperation(URLRequest &request, KRHTTPOperationSuccessCallback callback);
		HTTPOperation(URLRequest &request, KRHTTPOperationSuccessCallback success, KRHTTPOperationFailureCallback failure);
		~HTTPOperation();
		
		virtual void start();
		virtual void main();
		
		virtual void getPath(URLRequest &request, KRHTTPOperationSuccessCallback callback);
		virtual void getPath(URLRequest &request, KRHTTPOperationSuccessCallback success, KRHTTPOperationFailureCallback failure);
#if __has_feature(blocks)
		virtual void getPath(URLRequest &request, KRHTTPOperationSuccessBlock success);
		virtual void getPath(URLRequest &request, KRHTTPOperationSuccessBlock success, KRHTTPOperationFailureBlock failure);
#endif
        
	private:
		CURL *mCurl;
		URLRequest mURLRequest;
		
		APIResponse *mResponse;
		size_t mResponseLength;
		Error mError;
		
#if __has_feature(blocks)
		KRHTTPOperationSuccessCallback mSuccessBlock;
		KRHTTPOperationFailureCallback mFailureBlock;
#endif
		
	private:
//		static size_t HeaderFunction(char *data, size_t size, size_t count, void *context);
        static size_t KRFWrite(const char *data, size_t size, size_t count, void *context);
//        static size_t DebugFunction(curl_infotype type, char *data, size_t size, void *context);
	};
}

#endif /* defined(__KrakenKit__KRHTTPOperation__) */
