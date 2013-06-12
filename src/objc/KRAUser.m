//
//  KRAUser.m
//  KrakenKit
//
//  Created by Robert Widmann on 4/30/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRAUser.h"

@implementation KRAUser

+ (NSDictionary *)JSONKeyPathsByPropertyKey {
	return @{
 		@"login": @"login",
		@"userID": @"id",
		@"avatarURL": @"avatar_url",
		@"gravatarID": @"gravatar_id",
		@"userURL": @"url",
		@"name": @"name",
		@"company": @"company",
		@"blogURL": @"blog",
		@"location": @"location",
		@"email": @"email",
		@"hirable": @"hirable",
		@"bio": @"bio",
		@"publicReposCount": @"public_repos",
		@"publicGistsCount": @"public_gists",
		@"followersCount": @"followers",
		@"followingCount": @"following",
		@"createdAt": @"created_at",
		@"type" : @"type",
	};
}

+ (NSValueTransformer *)avatarURLJSONTransformer {
    return [NSValueTransformer valueTransformerForName:MTLURLValueTransformerName];
}

+ (NSValueTransformer *)userURLJSONTransformer {
    return [NSValueTransformer valueTransformerForName:MTLURLValueTransformerName];
}

+ (NSValueTransformer *)blogURLJSONTransformer {
    return [NSValueTransformer valueTransformerForName:MTLURLValueTransformerName];
}

+ (NSDateFormatter *)dateFormatter {
    static NSDateFormatter *dateFormatter = nil;
	if (dateFormatter == nil) {
		dateFormatter = [[NSDateFormatter alloc] init];
		dateFormatter.locale = [[NSLocale alloc] initWithLocaleIdentifier:@"en_US_POSIX"];
		dateFormatter.dateFormat = @"yyyy-MM-dd'T'HH:mm:ss'Z'";
	}
    return dateFormatter;
}

+ (NSValueTransformer *)createdAtJSONTransformer {
    return [MTLValueTransformer reversibleTransformerWithForwardBlock:^(NSString *str) {
        return [self.dateFormatter dateFromString:str];
    } reverseBlock:^(NSDate *date) {
        return [self.dateFormatter stringFromDate:date];
    }];
}

+ (NSValueTransformer *)typeJSONTransformer {
    NSDictionary *types = @{
		@"User": @(KRAUserTypeUser),
		@"Org": @(KRAUserTypeOrganization)
	};
	
    return [MTLValueTransformer reversibleTransformerWithForwardBlock:^(NSString *str) {
        return types[str];
    } reverseBlock:^(NSNumber *state) {
        return [types allKeysForObject:state].lastObject;
    }];
}

- (void)setNilValueForKey:(NSString *)key {
	if ([key isEqualToString:@"type"]) {
		return;
	}
	[super setNilValueForKey:key];
}

@end
