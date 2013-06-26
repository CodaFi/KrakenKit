//
//  KRHTTPOperation.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/24/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__KRHTTPOperation__
#define __KrakenKit__KRHTTPOperation__

#include "KRError.h"
#include "KRAPIResponse.h"
#include "KRTypes.h"
#include <curl/curl.h>
#include <string>
#include <map>

namespace KrakenKit {
	
	class HTTPOperation {
			
	public:
		HTTPOperation(std::string &access_token);
		~HTTPOperation();
		
		void getPath(std::string &path, std::map<std::string, std::string> &params, KRHTTPOperationSuccessCallback callback);
		void getPath(std::string &path, std::map<std::string, std::string> &params, KRHTTPOperationSuccessCallback success, KRHTTPOperationFailureCallback failure);
#if __has_feature(blocks)
		void getPath(std::string &path, std::map<std::string, std::string> &params, KRHTTPOperationSuccessBlock success);
		void getPath(std::string &path, std::map<std::string, std::string> &params, KRHTTPOperationSuccessBlock success, KRHTTPOperationFailureBlock failure);
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
