//
//  OMCServiceProxy.h
//  OMCCore
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved. 
//

#import <Foundation/Foundation.h>
@class OMCMobileBackend;

NS_ASSUME_NONNULL_BEGIN

/**
 Interface to an Oracle Mobile Cloud service proxy.
 This is an abstract superclass of the various OMC service proxies.
 */
@interface OMCServiceProxy : NSObject

/** The service proxy's mobile backend. */
@property (readonly, nonatomic) OMCMobileBackend* mobileBackend;

@end

NS_ASSUME_NONNULL_END
