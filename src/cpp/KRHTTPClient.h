//
//  KRHTTPClient.h
//  KrakenKit
//
//  Created by Robert Widmann on 7/19/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__KRHTTPClient__
#define __KrakenKit__KRHTTPClient__

#include "KROperationQueue.h"
#include "KRURLRequest.h"
#include "KRHTTPOperation.h"
#include <sstream>
#include <iostream>
#include <iosfwd>
#include <string>
#include <map>

namespace KrakenKit {
	class HTTPClient {
		
	public:
		HTTPClient(std::string &baseURL);
		~HTTPClient();
		
		const std::ostringstream &baseURL() { return mBaseURL; }
		
		const OperationQueue &operationQueue() { return mOperationQueue; }
		
		const std::string defaultValueForHeader(std::string &header) { return mDefaultHeaders[header]; }
		void setDefaultHeader(std::string &header, std::string &value) { mDefaultHeaders[header] = value; }

		void setAuthorizationHeader(std::string &token);
		void setAuthorizationHeader(std::string &username, std::string &password);
		void clearAuthorizationHeader();
		
		MutableURLRequest *request(std::string &method, std::string &path, std::map<std::string, std::string> &parameters);
		
		HTTPOperation *operationFromRequest(URLRequest &request);
#if __has_feature(blocks)
		HTTPOperation *operationFromRequest(URLRequest &request, KRHTTPOperationSuccessCallback success);
		HTTPOperation *operationFromRequest(URLRequest &request, KRHTTPOperationSuccessCallback success, KRHTTPOperationFailureCallback failure);
#endif
		void enqueueHTTPOperation(HTTPOperation *operation);
		
		void get(std::string &path, std::map<std::string, std::string> &parameters);
#if __has_feature(blocks)
		void get(std::string &path, std::map<std::string, std::string> &parameters, KRHTTPOperationSuccessCallback success);
		void get(std::string &path, std::map<std::string, std::string> &parameters, KRHTTPOperationSuccessCallback success, KRHTTPOperationFailureCallback failure);
#endif
		
	public:
		HTTPClient(HTTPClient const&);
		HTTPClient &operator=(HTTPClient const&);

	private:
		std::ostringstream mBaseURL;
		OperationQueue mOperationQueue;
		std::map<std::string, std::string> mDefaultHeaders;
		
	private: // For the love of god, don't call this.
		HTTPClient() { throw std::bad_function_call(); }

	};
}

#endif /* defined(__KrakenKit__KRHTTPClient__) */
