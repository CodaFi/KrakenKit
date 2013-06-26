//
//  KRAPIResponse.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/25/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__KRAPIResponse__
#define __KrakenKit__KRAPIResponse__

#include <string>
#include "KRError.h"

namespace KrakenKit {
	class APIResponse {
		
	public:
		APIResponse();
		~APIResponse();
		
		const void *data() const { return mData; }
		const size_t length() const { return mLength; }
		const std::string &contentType() const { return mContentType; }
		const Error &error() const { return mErr; }

		void Realloc(size_t len);
		
	private:
		void *mData;
		size_t mLength;
		std::string mContentType;
		Error mErr;
	};
}

#endif /* defined(__KrakenKit__KRAPIResponse__) */
