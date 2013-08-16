//
//  KRARepositoryContent.m
//  KrakenKit
//
//  Created by Robert Widmann on 8/11/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#import "KRARepositoryContent.h"

@implementation KRARepositoryContent

+ (NSDictionary *)JSONKeyPathsByPropertyKey {
	return @{
		@"type" : @"type",
		@"encoding" : @"encoding",
		@"size" : @"size",
		@"name" : @"name",
		@"path" : @"path",
		@"content" : @"content",
		@"sha" : @"sha",
		@"url" : @"url",
		@"submoduleURL" : @"submodule_git_url"
	};
}

+ (NSValueTransformer *)urlJSONTransformer {
	return [MTLValueTransformer valueTransformerForName:MTLURLValueTransformerName];
}

+ (NSValueTransformer *)submoduleURLJSONTransformer {
	return [MTLValueTransformer valueTransformerForName:MTLURLValueTransformerName];
}

+ (NSValueTransformer *)typeJSONTransformer {
	NSDictionary *actionTypes = @{
		@"blob" : @(KRARepositoryContentTypeFile),
		@"file" : @(KRARepositoryContentTypeFile),
		@"tree" : @(KRARepositoryContentTypeDirectory),
		@"dir" : @(KRARepositoryContentTypeDirectory),
		@"symlink" : @(KRARepositoryContentTypeSymlink),
		@"submodule" : @(KRARepositoryContentTypeSubmodule),
	};
	
    return [MTLValueTransformer reversibleTransformerWithForwardBlock:^(NSString *str) {
		if (!str) return @(KRARepositoryContentTypeNone);
        return (NSNumber *)actionTypes[str];
    } reverseBlock:^(NSNumber *state) {
        return [actionTypes allKeysForObject:state].lastObject;
    }];
}

- (void)setNilValueForKey:(NSString *)key {
	if ([key isEqualToString:@"type"]) {
		self.type = KRARepositoryContentTypeNone;
		return;
	}
	[super setNilValueForKey:key];
}

@end
