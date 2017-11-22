//
//  OMCMobileBackend+OMC_Storage.h
//  OMCStorage
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved. 
//

#import "OMCCore/OMCMobileBackend.h"
@class OMCStorage;
@class OMCMobileBackend;

/**
 Extends `OMCMobileBackend` with Storage-specific methods.
 */

@interface OMCMobileBackend (OMCStorage)

/**
 Returns the receiver's storage service.
 */
-(OMCStorage*) storage;

/**
 Removes the receiver's storage service.
 */
-(void) removeStorage;

@end
