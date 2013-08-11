//
//  KRSession.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/24/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__KRSession__
#define __KrakenKit__KRSession__

#include "KRHTTPClient.h"
#include "KRHTTPOperation.h"
#include "KRTypes.h"
#include <string>

namespace KrakenKit {
    namespace API {
        class GithubClient : public HTTPClient {
            
        public:
			GithubClient();
			~GithubClient();
			
			std::string &username() { return mUsername; }
            void setUsername(std::string &token) { mUsername = token; }
			
			std::string &password() { return mPassword; }
            void setPassword(std::string &token) { mPassword = token; }
			
            std::string &accessToken() { return mAccessToken; }
            void setAccessToken(std::string &token) { mAccessToken = token; }
            
		public:
			void authenticate(std::string &user_name, std::string &password);
#if __has_feature(blocks)
			void authenticate(std::string &user_name, std::string &password, void(^completionHander)(bool success, Error &error));
#endif
			
			void fetchUserWithName(const char *user_name, KRHTTPOperationSuccessCallback callback);
			//        void fetchUserWithName(const char *name, KRHTTPOperationSuccessCallback success, KRHTTPOperationFailureCallback failure);
			//#if __has_feature(blocks)
			//        void fetchUserWithName(const char *name, KRHTTPOperationSuccessBlock success);
			//        void fetchUserWithName(const char *name, KRHTTPOperationSuccessBlock success, KRHTTPOperationFailureBlock failure);
			//#endif
			
		public:
            GithubClient(GithubClient const&);
            GithubClient &operator=(GithubClient const&other);
			
		private:
			std::string mUsername;
            std::string mPassword;
			
            std::string mAccessToken;
			
			GithubClient *mHTTPAuthClient;
			
		private:
			void initializeHTTPAuthClient();
        };
    }
}

#endif /* defined(__KrakenKit__KRSession__) */
