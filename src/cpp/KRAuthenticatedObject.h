//
//  KRAuthenticatedObject.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/25/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__KRAuthenticatedObject__
#define __KrakenKit__KRAuthenticatedObject__

#include "KRServer.h"

struct jsonz_object_t;

namespace KrakenKit {
	class AuthenticatedObject {
		AuthenticatedObject();
		
	public:
		Server &server() { return mServer; }
		virtual AuthenticatedObject deserialize(jsonz_object_t *object);
		
	private:
		Server mServer;
	};
}

#endif /* defined(__KrakenKit__KRAuthenticatedObject__) */
