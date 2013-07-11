//
//  KROperationQueue.h
//  KrakenKit
//
//  Created by Robert Widmann on 7/11/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__KROperationQueue__
#define __KrakenKit__KROperationQueue__

#include "KROperation.h"
#include <pthread.h>
#include <list>
#include <thread>

namespace KrakenKit {
	class OperationQueue {
		
	public:
		OperationQueue();
		~OperationQueue();
		
		void addOperation(Operation &operation);
		void cancelAllOperations();
		
		size_t size();

	private:
		void dequeueAndExecute();
		
	private:
		std::list<Operation> mQueue;
		pthread_mutex_t mLock;
		pthread_cond_t  mLockCond;
	};
	

}

#endif /* defined(__KrakenKit__KROperationQueue__) */
