//
//  JSONAdapter.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/15/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__JSONAdapter__
#define __KrakenKit__JSONAdapter__

#include <iostream>
#include "Serializable_Object.h"


namespace KrakenKit {
	class JSONAdapter {
	public:
		Serializable_Object model();
		static Serializable_Object modelFromJSONDictionary(std::map<char *, void *> &JSON);
		
	private:
		Serializable_Object mModel;
	};
}

#endif /* defined(__KrakenKit__JSONAdapter__) */
