//
//  KROperation.h
//  KrakenKit
//
//  Created by Robert Widmann on 7/11/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__KROperation__
#define __KrakenKit__KROperation__


namespace KrakenKit {
	class Operation {
	public:
		Operation();
		~Operation();
		
		bool isCancelled() { return mIsCancelled; }
		bool isExecuting() { return mIsExecuting; }
		bool isFinished() { return mIsFinished; }

		virtual void main() {  }
		virtual void start() { mIsExecuting = true; }
		virtual void cancel() { mIsCancelled = true; }
		
	private:
		bool mIsCancelled;
		bool mIsExecuting;
		bool mIsFinished;
	};
}

#endif /* defined(__KrakenKit__KROperation__) */
