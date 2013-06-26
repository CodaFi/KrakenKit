//
//  KRServer.cpp
//  KrakenKit
//
//  Created by Robert Widmann on 6/25/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#include "KRServer.h"

using namespace KrakenKit;

static Server *dotcomServer = NULL;

Server *Server::DotComServer() {
	if (dotcomServer == NULL) {
		dotcomServer = new Server();
	}
	return dotcomServer;
}

Server::Server() { }

Server::Server(std::string &baseURL) : mBaseURL(baseURL) { }

const std::string &Server::baseWebURL() {
	if (mBaseURL.length() == 0) {
		return DotComBaseWebURL;
	}
	return mBaseURL;
}

const std::string &Server::endPoint() {
	if (mBaseURL.length() == 0) {
		return DotComAPIEndpoint;
	}
	return mBaseURL;
}

namespace KrakenKit {
	const std::string DotComAPIEndpoint = "https://api.github.com";
	const std::string DotComBaseWebURL = "https://github.com";
}