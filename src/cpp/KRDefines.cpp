//
//  KRDefines.cpp
//  KrakenKit
//
//  Created by Robert Widmann on 6/25/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#include "KRDefines.h"
#include <stdio.h>
#include <stdlib.h>

void KRAssertInternal(const char *failingStatement, const char *filename, unsigned int line) {
	fprintf(stderr, "%s:%i: assert %s\n", filename, line, failingStatement);
    abort();
}
