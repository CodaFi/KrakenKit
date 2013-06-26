//
//  KRURLRequest.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/25/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__KRURLRequest__
#define __KrakenKit__KRURLRequest__

#include <string>
#include <map>

namespace KrakenKit {
	class URLRequest {
		
	public:
		URLRequest(std::string &baseURL);
		URLRequest(std::string &baseURL, std::map<std::string, std::string> &mParameters);
		
		virtual const std::string url();
		
		std::map<std::string, std::string> mParameters;

		std::string escape(const std::string& str);
		
	private:
		std::string mBaseURL;
	};
	
	class MutableURLRequest : public URLRequest {
	
	public:
		MutableURLRequest(std::string &baseURL);
		MutableURLRequest(std::string &baseURL, std::map<std::string, std::string> &mParameters);
		
		void setValueForField(std::string &value, std::string &field);
	};
}

#endif /* defined(__KrakenKit__KRURLRequest__) */
