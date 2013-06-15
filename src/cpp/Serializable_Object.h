//
//  Serializable_Object.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/15/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__Serializable_Object__
#define __KrakenKit__Serializable_Object__

#include <map>
#include <stdio.h>
#include <stdlib.h>

typedef void(*KKSerializableFunction)();

namespace KrakenKit {
	class Serializable_Object {
    public:
        virtual std::map<char *, KKSerializableFunction> &JSONKeysToFunctions();
        virtual char *description();
		
	private:
		std::map<char *, KKSerializableFunction> mJSONKeyMap;
	};
}

#endif /* defined(__KrakenKit__Serializable_Object__) */
