//
//  OMCMobileObjectCollection.h
//  OMCSynchronization
//
//  Copyright (c) 2015 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMCMobileResource.h"
#import "OMCSyncGlobals.h"

@class OMCMobileEndpoint;

/**
 * Class that represent the collection of MobileObjects derived from MobileResource
 */
@interface OMCMobileObjectCollection : OMCMobileResource

/**
 * Returns all the mobileObjects of this collection.
 @return mobileObjects array of OMCMobileObject object
 */
- (NSArray *) getMobileObjects;

/**
 * Deletes the file. Caches the delete locally if offline.
 @param errorBlk block that will be called after the request has finished with an error.
 */
- (void) deleteResourceOnError:(OMCSyncErrorBlock)errorBlk;

/**
 * Deletes the file.
 @param deleteIfOffline If true will cache the delete locally and sync back to the service if the device is offline. If false will fail if the device is offline.
 @param errorBlk block that will be called after the request has finished with an error.
 */
- (void) deleteResource:(BOOL) deleteIfOffline
                OnError:(OMCSyncErrorBlock)errorBlk;

@end
