//
//  Serializable_Object.cpp
//  KrakenKit
//
//  Created by Robert Widmann on 6/15/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#include "Serializable_Object.h"

using namespace KrakenKit;

std::map<char *, KKSerializableFunction> &Serializable_Object::JSONKeysToFunctions() {
	return mJSONKeyMap;
}

char *Serializable_Object::description() {
	char *buf = (char *)malloc(sizeof(char) * 35);
	sprintf(buf, "<Serializable_Object %p>", this);
	return buf;
}