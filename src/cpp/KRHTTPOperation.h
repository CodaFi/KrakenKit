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
#include <curl/curl.h>
#include "KRURLRequest.h"

namespace KrakenKit {
	
	class HTTPOperation : public Operation {
			
	public:
		HTTPOperation(std::string &access_token);
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
		std::string mAccessToken;
		
		APIResponse *mResponse;
		size_t mResponseLength;
		Error mError;
		
	private:
//		static size_t HeaderFunction(char *data, size_t size, size_t count, void *context);
        static size_t KRFWrite(const char *data, size_t size, size_t count, void *context);
//        static size_t DebugFunction(curl_infotype type, char *data, size_t size, void *context);
	};
}

#endif /* defined(__KrakenKit__KRHTTPOperation__) */
