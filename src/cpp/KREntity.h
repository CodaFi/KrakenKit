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
		
		AuthenticatedObject *deserialize(jsonz_object_t *object);

		const std::string &login() { return mLogin; }
		void setLogin(std::string &login) { mLogin = login; }
		
		const std::string &name() { return mName.length() ? mName : mLogin; }
		void setName(std::string &login) { mLogin = login; }

		const std::string &email() { return mEmail; }
		void setEmail(std::string &email) { mEmail = email; }

		const unsigned long publicRepoCount() { return mPublicRepoCount; }
		const unsigned long privateRepoCount() { return mPrivateRepoCount; }

		const std::string &avatarURL() { return mAvatarURL; }
		
		const unsigned long diskUsage() { return mDiskUsage; }

	private:
		void setAvatarURL(std::string &avatarURL) { mAvatarURL = avatarURL; }
		void setDiskUsage(unsigned long diskUsage) { mDiskUsage = diskUsage; }
		void setPublicRepoCount(unsigned long publicRepoCount) { mPublicRepoCount = publicRepoCount; }
		void setPrivateRepoCount(unsigned long privateRepoCount) { mPrivateRepoCount = privateRepoCount; }
		
	private:
		std::string mLogin;
		std::string mName;
		std::string mAvatarURL;
		std::string mEmail;
		unsigned long mDiskUsage;
		unsigned long mPublicRepoCount;
		unsigned long mPrivateRepoCount;
	};
}

#endif /* defined(__KrakenKit__KRAEntity__) */
