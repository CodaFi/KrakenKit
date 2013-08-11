//
//  KRSession.cpp
//  KrakenKit
//
//  Created by Robert Widmann on 6/24/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#include "KRGithubClient.h"
#include "KRURLRequest.h"
#include "KRError.h"

using namespace KrakenKit::API;

GithubClient::GithubClient(GithubClient const&other) : HTTPClient(other) {
	mUsername = other.mUsername;
	mPassword = other.mPassword;
	mAccessToken = other.mAccessToken;
}


GithubClient &GithubClient::operator=(GithubClient const&other) {
	HTTPClient::operator=(other);
	this->mAccessToken = other.mAccessToken;
	return *this;
}

GithubClient::~GithubClient() {
	
}

void GithubClient::authenticate(std::string &user_name, std::string &password) {
	std::map<std::string, std::string> parameters;
	parameters["client_id"] = KRGithubClientID;
	parameters["client_secret"] = KRGithubClientSecret;
	parameters["scopes"] = "user";



}

void GithubClient::initializeHTTPAuthClient() {
	mHTTPAuthClient = new GithubClient(*this);
}
