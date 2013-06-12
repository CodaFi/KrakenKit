//
//  KRAUserSpec.m
//  KrakenKit
//
//  Created by Robert Widmann on 5/12/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

SpecBegin(KRAUser)

__block KRAUser *testUser = nil;

before(^{
	testUser = [[KRAUser alloc] init];
	testUser.userID = @"-1";
	testUser.login = @"CodaFi";
	testUser.name = @"Robert Widmann";
});

describe(@"NSCopying", ^{
	it(@"should conform to NSCopying", ^{
		expect([testUser conformsToProtocol:@protocol(NSCopying)]).to.beTruthy();
	});
	
	it(@"should produce a valid copy of itself", ^{
		KRAUser *userCopy = testUser.copy;
		expect(userCopy.userID).to.equal(testUser.userID);
		expect(userCopy.login).to.equal(testUser.login);
		expect(userCopy.name).to.equal(testUser.name);
		expect(userCopy.hash).to.equal(testUser.hash);
	});
});

SpecEnd