//
//  OMCMobileResource.h
//  OMCSynchronization
//
//  Copyright (c) 2015 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMCSyncStoreState.h"
#import "OMCSyncGlobals.h"

@class OMCSyncPolicy;

/**
 * OMCMobileResource - Base class for all of the mobile resources
 */
@interface OMCMobileResource : NSObject

/**
 * Uri of the resource
 */
@property( nonatomic, readonly ) NSString* uri;

/**
 * lastSyncTime of the resource
 */
@property( nonatomic, readonly ) double lastSyncTime;

/**
 * Resource's pinned status
 */
@property( nonatomic, readonly ) BOOL pinned;

/**
 * Resource's conflict status
 */
@property( nonatomic, readonly ) BOOL hasConflicts;

/**
 * Resource's offline/local updates status
 */
@property( nonatomic, readonly ) BOOL hasOfflineUpdates;

/**
 * Resource's error status after committing offline updates
 */
@property( nonatomic, readonly ) BOOL hasOfflineCommitError;

/**
 * Pin the resource
 * @param pinPriority specifies the priority 
 * @return NSError* if resource not found, otherwise nil.
 */
-(NSError *) pinResource:(SyncPinPriority) pinPriority;

/**
 * Unpin the resource
 @return NSError* if resource not found, otherwise nil.
 */
-(NSError *) unpinResource;

/**
 * Resource's current offline/local updated state, with specific information of which offline operation is pending, if any.
 @return SyncOfflineState offline state
 */
- (SyncOfflineState) currentOfflineState;

/**
 * Sets extra request headers. Afterwards, you need to call reloadResource from the service or SaveResource to use these extra request headers.
 * No need to specify headers for authorization and content-type, since they will be added by default.
 * @param headers Extra request headers
 */
- (void) setRequestHeaders:(NSDictionary *) headers;

/**
 * Returns response headers which have been retrieved from the server
 * @return NSDictionary* response headers
 */
- (NSDictionary *) getResponseHeaders;

/**
 * Sets Sync Policy. Afterwards you need to call reloadResource or SaveResource to use this Sync Policy.
 * @param policy OMCSyncPolicy object
 */
- (void) setSyncPolicy:(OMCSyncPolicy *) policy;

/**
 * Returns currently associated Sync Policy for this resource.
 * @return policy OMCSyncPolicy object
 */
- (OMCSyncPolicy *) getCurrentSyncPolicy;


/**
 * Reloads the data that was last downloaded from the service. Any offline updates are not discarded.
 * @param successBlk callback block for success
 */
-(void) reloadResource:(OMCMobileResourceSuccess) successBlk;


/**
 * Reloads the data that was last downloaded from the service. Can provide the ability to discard any offline updates for the resource or can go to the service if online to get the latest.
 * @param discardOfflineUpdates If true will delete all offline updates from the cache.
 * @param reloadFromService If true will reload from the service if online or from the cache if offline.
 * @param successBlk callback block for success, will return the reloaded resource.
 */
-(void) reloadResource:(BOOL) discardOfflineUpdates
     reloadFromService:(BOOL) reloadFromService
             onSuccess:(OMCMobileResourceSuccess) successBlk;

@end
