//
//  KRUser.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/25/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__KRUser__
#define __KrakenKit__KRUser__

#include "KREntity.h"
#include <string>

namespace KrakenKit {
	class User : public Entity {
		
	public:
		User(std::string &name, std::string &email);
	};
}

#endif /* defined(__KrakenKit__KRUser__) */
