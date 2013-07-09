//
//  KRAEntity.cpp
//  KrakenKit
//
//  Created by Robert Widmann on 6/25/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#include "KREntity.h"
#include <jsonz/jsonz.h>

using namespace KrakenKit;

Entity::Entity() {
	AuthenticatedObject();
}

AuthenticatedObject *Entity::deserialize(jsonz_object_t *object) {
	Entity *entity = new Entity();
	
	std::string avatarURL = (char *)jsonz_dict_get(object, "avatar_url");
	unsigned long publicRepos = *(unsigned long *)jsonz_dict_get(object, "public_repos");
	unsigned long privateRepos = *(unsigned long *)jsonz_dict_get(object, "owned_private_repos");
	unsigned long diskUsage = *(unsigned long *)jsonz_dict_get(object, "disk_usage");
	
	entity->setAvatarURL(avatarURL);
	entity->setDiskUsage(diskUsage);
	entity->setPublicRepoCount(publicRepos);
	entity->setPrivateRepoCount(privateRepos);
	
	return entity;
}
