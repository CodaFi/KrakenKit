//
//  KRSession.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/24/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__KRSession__
#define __KrakenKit__KRSession__

#include "KRHTTPOperation.h"
#include "KRTypes.h"
#include <string>

namespace KrakenKit {
    namespace API {
        
        void fetchUserWithName(const char *name, KRHTTPOperationSuccessCallback callback);
//        void fetchUserWithName(const char *name, KRHTTPOperationSuccessCallback success, KRHTTPOperationFailureCallback failure);
//#if __has_feature(blocks)
//        void fetchUserWithName(const char *name, KRHTTPOperationSuccessBlock success);
//        void fetchUserWithName(const char *name, KRHTTPOperationSuccessBlock success, KRHTTPOperationFailureBlock failure);
//#endif
        
        class Session {
            
        public:
            static Session& defaultSession() {
                static Session instance;
                return instance;
            }
            
            std::string &accessToken() { return mAccessToken; }
            void setAccessToken(std::string &token) { mAccessToken = token; }
            
            std::string &baseURL() { return mBaseURL; }
            void setBaseURL(std::string &url) { mBaseURL = url; }
            
        private:
            Session() {}
            Session(Session const&);
            void operator=(Session const&);
            std::string mAccessToken;
            std::string mBaseURL;
        };
    }
}

#endif /* defined(__KrakenKit__KRSession__) */
