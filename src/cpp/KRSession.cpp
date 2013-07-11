//
//  KRSession.cpp
//  KrakenKit
//
//  Created by Robert Widmann on 6/24/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#include "KRSession.h"
#include "KRURLRequest.h"

using namespace KrakenKit::API;

void KrakenKit::API::fetchUserWithName(const char *name, KRHTTPOperationSuccessCallback callback){
    HTTPOperation *op = new HTTPOperation(Session::defaultSession().accessToken());
    URLRequest *request = new URLRequest(Session::defaultSession().baseURL());
    op->getPath(*request, callback);
}