//
//  KRAClientSpec.m
//  KrakenKit
//
//  Created by Robert Widmann on 5/16/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

SpecBegin(KRAClient)

it(@"should have a base URL that points to api.github.com", ^{
	expect(KRAClient.sharedClient.baseURL.absoluteString).to.equal(@"https://api.github.com/");
});

it(@"should use JSON as a parameter encoding", ^{
	expect(KRAClient.sharedClient.parameterEncoding).to.equal(AFJSONParameterEncoding);
});

describe(@"NSCopying", ^{
	it(@"should conform to NSCopying", ^{
		expect([KRAClient.sharedClient conformsToProtocol:@protocol(NSCopying)]).to.beTruthy();
	});
	
	it(@"should copy its access token", ^{
		KRAClient *copyClient = KRAClient.sharedClient.copy;
		expect(copyClient).notTo.beNil();
		expect(KRAClient.sharedClient.accessToken).to.equal(copyClient.accessToken);
	});
});

SpecEnd
