//
//  OMCCore.h
//  OMCCore
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved. 
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Defines the version constant for the Core library.
 */
@interface OMCCore : NSObject

@end

/**
 The Core library's current version.
 */
extern NSString* const OMCCoreVersion;

/**
 Completion handler used when reporting an optional error.
 */
typedef void (^OMCErrorCompletionBlock)(NSError* _Nullable error);

NS_ASSUME_NONNULL_END
