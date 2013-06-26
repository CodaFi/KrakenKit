//
//  KRAPIResponse.cpp
//  KrakenKit
//
//  Created by Robert Widmann on 6/25/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#include "KRAPIResponse.h"
#include "KRDefines.h"
#include <stdlib.h>

using namespace KrakenKit;

APIResponse::APIResponse() : mData(NULL), mLength(0), mErr() { }


APIResponse::~APIResponse() {
	free(mData);
	mData = NULL;
	mLength = 0;
}

void APIResponse::Realloc(size_t len) {
	KRAssert(len >= 0);
	if (len == mLength) return;
	
	void *reallocdData = realloc(mData, len);
	
	if(!reallocdData) throw std::bad_alloc();
	
	mData = reallocdData;
	mLength = len;
}