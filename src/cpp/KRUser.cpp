//
//  KRUser.cpp
//  KrakenKit
//
//  Created by Robert Widmann on 6/25/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#include "KRUser.h"

using namespace KrakenKit;

User::User(std::string &name, std::string &email) {
	Entity::setName(name);
	Entity::setEmail(email);
}

User::User(std::string &login, Server &server) {
	AuthenticatedObject::setServer(server);
	Entity::setLogin(login);
}