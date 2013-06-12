//
//  KRAEventSpec.m
//  KrakenKit
//
//  Created by Robert Widmann on 5/19/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

SpecBegin(KRAEvent)

__block KRAEvent *testEvent = nil;

before(^{
	testEvent = [[KRAEvent alloc] init];
	testEvent.createdAt = NSDate.date;
	testEvent.eventID = @1;
});

describe(@"NSCopying", ^{
	it(@"should conform to NSCopying", ^{
		expect([testEvent conformsToProtocol:@protocol(NSCopying)]).to.beTruthy();
	});
	
	it(@"should produce a valid copy of itself", ^{
		KRAEvent *eventCopy = testEvent.copy;
		expect(eventCopy.createdAt).to.equal(testEvent.createdAt);
		expect(eventCopy.eventID).to.equal(testEvent.eventID);
	});
});

SpecEnd