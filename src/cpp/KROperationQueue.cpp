//
//  KROperationQueue.cpp
//  KrakenKit
//
//  Created by Robert Widmann on 7/11/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#include "KROperationQueue.h"

using namespace KrakenKit;

extern void dequeueAndExecute(std::list<Operation> &mQueue,pthread_mutex_t mLock, pthread_cond_t  mLockCond);

OperationQueue::OperationQueue() {
	pthread_mutex_init(&mLock, NULL);
	pthread_cond_init(&mLockCond, NULL);
}

OperationQueue::~OperationQueue() {
	pthread_mutex_destroy(&mLock);
    pthread_cond_destroy(&mLockCond);
}

void OperationQueue::addOperation(Operation *operation) {
	pthread_mutex_lock(&mLock);
    mQueue.push_back(operation);
	std::thread newTask(&OperationQueue::dequeueAndExecute, *this);
	newTask.join();
    pthread_cond_signal(&mLockCond);
    pthread_mutex_unlock(&mLock);
}

size_t OperationQueue::size() {
	pthread_mutex_lock(&mLock);
	size_t size = mQueue.size();
	pthread_mutex_unlock(&mLock);
	return size;
}

void OperationQueue::dequeueAndExecute() {
	pthread_mutex_lock(&mLock);
    while (mQueue.size() == 0) {
        pthread_cond_wait(&mLockCond, &mLock);
    }
    Operation *item = mQueue.front();
    mQueue.pop_front();
    pthread_mutex_unlock(&mLock);
	item->main();
}
