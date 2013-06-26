//
//  KREntity.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/25/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__KRAEntity__
#define __KrakenKit__KRAEntity__

#include "KRAuthenticatedObject.h"
#include <string>

namespace KrakenKit {
	class Entity : public AuthenticatedObject {
		
	public:
		virtual const std::string &login() { return mLogin; }
		virtual void setLogin(std::string &login) { mLogin = login; }
		
		virtual const std::string &name() { return mLogin; }
		virtual void setName(std::string &login) { mLogin = login; }
		
	private:
		std::string mLogin;
		std::string mName;
	};
}

#endif /* defined(__KrakenKit__KRAEntity__) */
