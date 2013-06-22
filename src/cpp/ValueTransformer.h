//
//  ValueTransformer.h
//  KrakenKit
//
//  Created by Robert Widmann on 6/16/13.
//  Copyright (c) 2013 CodaFi. All rights reserved.
//

#ifndef __KrakenKit__ValueTransformer__
#define __KrakenKit__ValueTransformer__

#include <iostream>

extern char *KKNegateBooleanTransformerName;
extern char *KKIsNilTransformerName;
extern char *KKIsNotNilTransformerName;

namespace KrakenKit {
	class ValueTransformer {
		virtual static bool allowsReverseTransformation;
		virtual static setValueTransformerForName(ValueTransformer *transformer, NSString * name);
		+ (Class) transformedValueClass;
		+ (NSValueTransformer *) valueTransformerForName:(NSString *) name;
		+ (NSArray *) valueTransformerNames;
		
		- (id) reverseTransformedValue:(id) value;
		- (id) transformedValue:(id) value;

	public:
		<#member functions#>
	};
}

#endif /* defined(__KrakenKit__ValueTransformer__) */
