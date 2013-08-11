//
//  KRHTTPClient.cpp
//  KrakenKit
//
//  Created by Robert Widmann on 7/19/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#include "KRHTTPClient.h"
#include <sstream>

using namespace KrakenKit;

HTTPClient::HTTPClient(HTTPClient const&) {
	
}

HTTPClient &HTTPClient::operator=(HTTPClient const&other) {
	if (this == &other) return *this;
	
	mBaseURL.swap(other.mBaseURL);
	mOperationQueue = other.mOperationQueue;
	mDefaultHeaders = other.mDefaultHeaders;
	return *this;
}

HTTPClient::~HTTPClient() {
	
}

HTTPClient::HTTPClient(std::string &baseURL) {
	mBaseURL << baseURL;
}

void HTTPClient::setAuthorizationHeader(std::string &token) {
	std::string authHeader = "Authorization";
	std::ostringstream tokenStream;
	tokenStream << "Token token =\"" << token.c_str() << "\"";
	std::string tokenString = tokenStream.str();
	this->setDefaultHeader(authHeader, tokenString);
}

void HTTPClient::setAuthorizationHeader(std::string &username, std::string &password) {
	std::string authHeader = "Authorization";
	std::ostringstream credentialStream;
	credentialStream << "Basic " << username.c_str() << ":" << password.c_str();
	std::string credentialsString = credentialStream.str();
	this->setDefaultHeader(authHeader, credentialsString);
}

void HTTPClient::clearAuthorizationHeader() {
	mDefaultHeaders.erase("Authorization");
}

MutableURLRequest *HTTPClient::request(std::string &method, std::string &path, std::map<std::string, std::string> &parameters) {
	std::ostringstream completePathStream;
	completePathStream << mBaseURL.str() << path;
	
	std::string completePathString = completePathStream.str();
	return new MutableURLRequest(completePathString, parameters);
}

HTTPOperation *HTTPClient::operationFromRequest(URLRequest &request) {
	return new HTTPOperation(request);
}

#if __has_feature(blocks)
HTTPOperation *HTTPClient::operationFromRequest(URLRequest &request, KRHTTPOperationSuccessCallback success) {
	return new HTTPOperation(request, success);
}

HTTPOperation *HTTPClient::operationFromRequest(URLRequest &request, KRHTTPOperationSuccessCallback success, KRHTTPOperationFailureCallback failure) {
	return new HTTPOperation(request, success, failure);
}
#endif

void HTTPClient::enqueueHTTPOperation(HTTPOperation *operation) {
	mOperationQueue.addOperation(operation);
}


