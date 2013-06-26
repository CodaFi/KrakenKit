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
		Entity();
		
		virtual const std::string &login() { return mLogin; }		
		virtual const std::string &name() { return mName.length() ? mName : mLogin; }		
		virtual const std::string &email() { return mEmail; }
		virtual const std::string &avatarURL() { return mAvatarURL; }
		virtual const unsigned long diskUsage() { return mDiskUsage; }

		AuthenticatedObject *deserialize(jsonz_object_t *object);

	private:
		virtual void setLogin(std::string &login) { mLogin = login; }
		virtual void setName(std::string &login) { mLogin = login; }
		virtual void setEmail(std::string &email) { mEmail = email; }
		virtual void setAvatarURL(std::string &avatarURL) { mAvatarURL = avatarURL; }
		virtual void setDiskUsage(unsigned long diskUsage) { mDiskUsage = diskUsage; }

	private:
		std::string mLogin;
		std::string mName;
		std::string mAvatarURL;
		std::string mEmail;
		unsigned long mDiskUsage;
	};
}

#endif /* defined(__KrakenKit__KRAEntity__) */
