//
//  KRDefines.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/25/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef KrakenKit_KRDefines_h
#define KrakenKit_KRDefines_h

#if defined(__cplusplus)
#define KRAKENKIT_EXTERN extern "C"
#else
#define KRAKENKIT_EXTERN extern
#endif

#define KRAKENKIT_EXPORT KRAKENKIT_EXTERN

#define KRAssert(cond) \
do { if (!(cond)) KRAssertInternal(#cond, __FILE__, __LINE__); } while(0)

KRAKENKIT_EXPORT void KRAssertInternal(const char *failingStatement, const char *filename, unsigned int line);

#endif
