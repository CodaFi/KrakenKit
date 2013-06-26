//
//  KRAuthenticatedObject.cpp
//  KrakenKit
//
//  Created by Robert Widmann on 6/25/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#include "KRAuthenticatedObject.h"

using namespace KrakenKit;

AuthenticatedObject::AuthenticatedObject() {
	mServer = *Server::DotComServer();
}

AuthenticatedObject *AuthenticatedObject::deserialize(jsonz_object_t *object) {
	KRAssert(object != NULL);
	return new AuthenticatedObject();
}
