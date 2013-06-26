//
//  KRError.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/24/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__KRError__
#define __KrakenKit__KRError__

#include "KRDefines.h"
#include <string>
#include <map>

namespace KrakenKit {
	class Error {
	public:
		Error();
		Error(const std::string &domain, long code, std::map<std::string, std::string> &userInfo);
		
		const std::string &domain() { return mDomain; }
		const long code() { return mCode; }
		const std::map<std::string, std::string> &userInfo() { return mUserInfo; }
		
	private:
		std::string mDomain;
		long mCode;
		std::map<std::string, std::string> mUserInfo;
	};
}

namespace KrakenKit {
	KRAKENKIT_EXPORT const std::string KRErrorDomain;
	
	KRAKENKIT_EXPORT const std::string LocalizedDescriptionKey;
	KRAKENKIT_EXPORT const std::string ErrorFailingURLStringKey;
	KRAKENKIT_EXPORT const std::string FilePathErrorKey;
	KRAKENKIT_EXPORT const std::string StringEncodingErrorKey;
	KRAKENKIT_EXPORT const std::string UnderlyingErrorKey;
	KRAKENKIT_EXPORT const std::string URLErrorKey;
	KRAKENKIT_EXPORT const std::string LocalizedFailureReasonErrorKey;
	KRAKENKIT_EXPORT const std::string LocalizedRecoverySuggestionErrorKey;
	KRAKENKIT_EXPORT const std::string LocalizedRecoveryOptionsErrorKey;
	KRAKENKIT_EXPORT const std::string RecoveryAttempterErrorKey;
	KRAKENKIT_EXPORT const std::string HelpAnchorErrorKey;
	KRAKENKIT_EXPORT const std::string URLErrorFailingURLErrorKey;
	KRAKENKIT_EXPORT const std::string URLErrorFailingURLStringErrorKey;
	KRAKENKIT_EXPORT const std::string URLErrorFailingURLPeerTrustErrorKey;
}

#endif /* defined(__KrakenKit__KRError__) */
