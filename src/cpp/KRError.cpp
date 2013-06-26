//
//  KRError.cpp
//  KrakenKit
//
//  Created by Robert Widmann on 6/24/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#include "KRError.h"

using namespace KrakenKit;

Error::Error() : mDomain(NULL), mCode(0) { }

Error::Error(const std::string &domain, long code, std::map<std::string, std::string> &userInfo) {
	mDomain = domain;
	mCode = code;
	mUserInfo = userInfo;
}

namespace KrakenKit {
	const std::string KRErrorDomain = "KRErrorDomain";
	
	const std::string LocalizedDescriptionKey             = "KRLocalizedDescriptionKey";
	const std::string ErrorFailingURLStringKey            = "KRErrorFailingURLStringKey";
	const std::string FilePathErrorKey                    = "KRFilePathErrorKey";
	const std::string StringEncodingErrorKey              = "KRStringEncodingErrorKey";
	const std::string UnderlyingErrorKey                  = "KRUnderlyingErrorKey";
	const std::string URLErrorKey                         = "KRURLErrorKey";
	const std::string LocalizedFailureReasonErrorKey      = "KRLocalizedFailureReasonErrorKey";
	const std::string LocalizedRecoverySuggestionErrorKey = "KRLocalizedRecoverySuggestionErrorKey";
	const std::string LocalizedRecoveryOptionsErrorKey    = "KRLocalizedRecoveryOptionsErrorKey";
	const std::string RecoveryAttempterErrorKey           = "KRRecoveryAttempterErrorKey";
	const std::string HelpAnchorErrorKey                  = "KRHelpAnchorErrorKey";
	const std::string URLErrorFailingURLErrorKey          = "KRURLErrorFailingURLErrorKey";
	const std::string URLErrorFailingURLStringErrorKey    = "KRURLErrorFailingURLStringErrorKey";
	const std::string URLErrorFailingURLPeerTrustErrorKey = "KRURLErrorFailingURLPeerTrustErrorKey";
}