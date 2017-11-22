//
//  OMCMobileBackend+OMC_Synchronization.h
//  OMCSynchronization
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved. 
//

#import "OMCCore/OMCMobileBackend.h"
@class OMCSynchronization;
@class OMCMobileBackend;

/**
 Extends `OMCMobileBackend` with Synchronization-specific methods.
 */
@interface OMCMobileBackend (OMC_Synchronization)

/**
 Returns the receiver's synchronization service.
 */
- (OMCSynchronization*)synchronization;

/**
 Removes the receiver's synchronization service.
 */
- (void)removeSynchronization;

@end
