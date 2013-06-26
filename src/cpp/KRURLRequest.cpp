//
//  KRURLRequest.cpp
//  KrakenKit
//
//  Created by Robert Widmann on 6/25/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#include "KRURLRequest.h"
#include <curl/curl.h>
#include <sstream>
#include <iostream>
#include "KRDefines.h"

using namespace KrakenKit;

URLRequest::URLRequest(std::string &baseURL) : mBaseURL(baseURL), mParameters() { }

URLRequest::URLRequest(std::string &baseURL, std::map<std::string, std::string> &params) : mBaseURL(baseURL), mParameters(params) { }

std::string URLRequest::escape(const std::string& str) {
	char *escaped = curl_easy_escape(NULL, str.c_str(), (int)str.length());
	KRAssert(escaped);
	
	std::string escapedStr(escaped);
	curl_free(escaped);
	return escapedStr;
}

const std::string URLRequest::url() {
	KRAssert(!mBaseURL.empty());
	
	std::stringstream builder;
	
	builder << mBaseURL;
	
	if(mParameters.size() > 0) {
		builder << "?";		
		std::map<std::string, std::string>::const_iterator it = mParameters.begin();
		builder << escape(it->first) << "=" << escape(it->second);
		++it;
		
		while(it != mParameters.end()) {
			builder << '&';
			builder << escape(it->first) << "=" << escape(it->second);
			++it;
		}
	}
	
	return builder.str();
}


MutableURLRequest::MutableURLRequest(std::string &baseURL) : URLRequest(baseURL) { }

MutableURLRequest::MutableURLRequest(std::string &baseURL, std::map<std::string, std::string> &params) : URLRequest(baseURL, params) { }
	
void MutableURLRequest::setValueForField(std::string &value, std::string &field) {
	this->mParameters[field] = value;
}
