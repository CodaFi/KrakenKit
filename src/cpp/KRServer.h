//
//  KRServer.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/25/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__KRServer__
#define __KrakenKit__KRServer__

#include <string>
#include "KRDefines.h"

namespace KrakenKit {
	class Server {
		
	public:
		static Server *DotComServer();
		
		Server();
		Server(std::string &baseURL);
		
		bool isEnterprise() { return mBaseURL.length() != 0; }
		
		const std::string &baseURL() { return mBaseURL; }
		const std::string &endPoint();
		const std::string &baseWebURL();
		
	private:
		std::string mBaseURL;
	};
}

namespace KrakenKit {
	KRAKENKIT_EXPORT const std::string DotComAPIEndpoint;
	KRAKENKIT_EXPORT const std::string DotComBaseWebURL;
}


#endif /* defined(__KrakenKit__KRServer__) */
