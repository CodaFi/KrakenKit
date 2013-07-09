//
//  KRHTTPOperation.cpp
//  KrakenKit
//
//  Created by Robert Widmann on 6/24/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#include "KRHTTPOperation.h"
#include <jsonz/jsonz.h>
#include "KRDefines.h"

using namespace KrakenKit;

KrakenKit::HTTPOperation::HTTPOperation(std::string &access_token) : mCurl(NULL), mResponse(), mResponseLength(0), mAccessToken(access_token) {
	mCurl = curl_easy_init();
	KRAssert(mCurl != NULL);
	
	curl_easy_setopt(mCurl, CURLOPT_VERBOSE, true);
	curl_easy_setopt(mCurl, CURLOPT_WRITEFUNCTION, KrakenKit::HTTPOperation::KRFWrite);
	curl_easy_setopt(mCurl, CURLOPT_WRITEDATA, this);

}

KrakenKit::HTTPOperation::~HTTPOperation() {
	curl_easy_cleanup(mCurl);
}

void KrakenKit::HTTPOperation::getPath(URLRequest &request, KRHTTPOperationSuccessCallback callback) {
	KRAssert(callback != NULL);
	
	curl_easy_setopt(mCurl, CURLOPT_HTTPGET, true);
	curl_easy_setopt(mCurl, CURLOPT_URL, request.url().c_str());
	if (curl_easy_perform(mCurl) == CURLE_OK) {
		jsonz_object_t *json = (jsonz_object_t *)jsonz_parse((const char *)this->mResponse->data());
		if (callback) callback(this, this->mResponse, json);
	}
	
}

void KrakenKit::HTTPOperation::getPath(URLRequest &request, KRHTTPOperationSuccessCallback success, KRHTTPOperationFailureCallback failure) {
	KRAssert(success != NULL);
	KRAssert(failure != NULL);

	curl_easy_setopt(mCurl, CURLOPT_HTTPGET, true);
	curl_easy_setopt(mCurl, CURLOPT_URL, request.url().c_str());
	CURLcode respCode = curl_easy_perform(mCurl);
	if (respCode == CURLE_OK) {
		jsonz_object_t *json = (jsonz_object_t *)jsonz_parse((const char *)this->mResponse->data());
		if (success) success(this, this->mResponse, json);
	} else {
		std::map<std::string, std::string> userInfo;
		userInfo[LocalizedDescriptionKey] = curl_easy_strerror(respCode);
		
		mError = Error(KRErrorDomain, respCode, userInfo);
		if (failure) failure(this, mError);
	}
}

#if __has_feature(blocks)

void KrakenKit::HTTPOperation::getPath(URLRequest &request, KRHTTPOperationSuccessBlock callback) {
	KRAssert(callback != NULL);
	
	curl_easy_setopt(mCurl, CURLOPT_HTTPGET, true);
	curl_easy_setopt(mCurl, CURLOPT_URL, request.url().c_str());
	if (curl_easy_perform(mCurl) == CURLE_OK) {
		jsonz_object_t *json = (jsonz_object_t *)jsonz_parse((const char *)this->mResponse->data());
		if (callback) callback(this, this->mResponse, json);
	}
	
}

void KrakenKit::HTTPOperation::getPath(URLRequest &request, KRHTTPOperationSuccessBlock success, KRHTTPOperationFailureBlock failure) {
	KRAssert(success != NULL);
	KRAssert(failure != NULL);
	
	curl_easy_setopt(mCurl, CURLOPT_HTTPGET, true);
	curl_easy_setopt(mCurl, CURLOPT_URL, request.url().c_str());
	CURLcode respCode = curl_easy_perform(mCurl);
	if (respCode == CURLE_OK) {
		jsonz_object_t *json = (jsonz_object_t *)jsonz_parse((const char *)this->mResponse->data());
		if (success) success(this, this->mResponse, json);
	} else {
		std::map<std::string, std::string> userInfo;
		userInfo[LocalizedDescriptionKey] = curl_easy_strerror(respCode);
		
		mError = Error(KRErrorDomain, respCode, userInfo);
		if (failure) failure(this, mError);
	}
}

#endif

size_t KrakenKit::HTTPOperation::KRFWrite(const char *data, size_t size, size_t count, void *context) {	
	HTTPOperation *request = static_cast<HTTPOperation*>(context);
	KRAssert(request != NULL);
	KRAssert(data);
	if (request == NULL || data == NULL) return 0;

	if(request->mResponseLength + size * count > request->mResponse->length()) {
		static const size_t s_bufferExtension = 4096;
		request->mResponse->Realloc(request->mResponseLength + size * count + s_bufferExtension);
	}
	
	memcpy((char*)request->mResponse->data() + request->mResponseLength, data, size * count);
	request->mResponseLength += size * count;
	return size * count;
}