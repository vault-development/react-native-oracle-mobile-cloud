//
//  OMCSynchronization.h
//  OMCSynchronization
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMCCore/OMCServiceProxy.h"
#import "OMCSyncPolicy.h"
#import "OMCSyncGlobals.h"
#import "OMCMobileEndpoint.h"

NS_ASSUME_NONNULL_BEGIN

@class OMCSyncSettings;

/**
 The main class for the Synchronization service implementation. Contains methods to make requests and manipulate the local cache.
 */
@interface OMCSynchronization : OMCServiceProxy

#pragma mark - Initialization
/**
 Initializes an `OMCSynchronization` object with the settings from the 'synchronization' node of OMC.plist
 * This method OR initializeWithMobileObjectEntities: should be the first method called on the OMCSynchronization class
 * As per periodicRefreshPolicy in the 'synchronization' node of OMC.plist, this method will check for expired resources in the cache to auto refresh in background.
 * If periodicRefreshPolicy is not or set to none, this method will continue with the expired resources in cache for auto eviction based on eviction policy set for those resources.
 */
- (void) initialize;

/**
 Initializes an `OMCSynchronization` object with the settings from the  'synchronization' node of OMC.plist and creates database entities for your business model or mobile objects using provided custom classes.
 * This method OR the initialize method should be the first method called on the OMCSynchronization class
 * As per periodicRefreshPolicy in the 'synchronization' node of OMC.plist, this method will check for expired resources in the cache to auto refresh in the background.
 * If periodicRefreshPolicy is not set or is set to none, this method will continue with the expired resources in the cache for auto eviction based on the eviction policy set for those resources.
 * When calling this method again, or after initialize with the different custom classes (entities), this will purge the local cache and re-create a blank database with new custom classes/entities as the db schema.
 @param customEntities (optional) Array of custom classes derived from the OMCMobileObject class; use class properties as entity attributes for queries.
    Example array: [NSArray arrayWithObjects:[MyClass1 class], [MyClass2 class], ... , nil]
 */
- (void) initializeWithMobileObjectEntities:(NSArray * _Nullable) customEntities;

#pragma mark -
/**
 Returns an object that provides access to an endpoint in a custom code API.
 @param mobileClass (optional) The custom mobile object (entity) class that the custom code API exposes.
 (the custom mobile object class must have been registered through initializeWithMobileObjectEntities: method. Or pass nil. )
 @param apiName The name of the custom code API.
 @param endpointPath The endpoint in the custom code API.
 @return An MobileEndpoint object for accessing custom code.
 */
- (OMCMobileEndpoint *) openEndpoint:(Class _Nullable) mobileClass
                             apiName:(NSString *) apiName
                        endpointPath:(NSString *) endpointPath;

/**
 * Request for any method; can go to server or cache, depending on policy settings.
 @param uri The URI to send the request to.
 @param method RequestMethod value.
 @param policy (optional) SyncPolicy object which has all policy settings.
 @param headers (optional) NSDictionary for extra headers to support request.
 @param data (optional) NSData for http body data; can set `nil` for GET method.
 @param success (optional) The block will be invoked on success of the request.
 @param error (optional) The block will be invoked on error of the request.
 */
- (void) requestWithUri:(NSString *) uri
                 method:(SyncRequestMethod) method
             syncPolicy:(OMCSyncPolicy * _Nullable) policy
                headers:(NSDictionary * _Nullable) headers
                   data:(NSData * _Nullable) data
              onSuccess:(OMCSyncSuccessBlock _Nullable) success
                onError:(OMCSyncErrorBlock _Nullable) error;


#pragma mark -
/**
 * Synchronize all pinned resources.
 @param background boolean to specify for background mode sync.
 */
- (void) synchronizePinnedResources:(BOOL) background;

/**
 * Returns a list of all MobileResource objects that were updated offline/locally, and not yet successfully synchronized with the server.
 @param success (optional) The block will be invoked on success; contains NSArray of OMCMobileResource(s) objects. (Can also be OMCMobileObject/OMCMobileFile/CustomClass)
 @param error (optional) The block will be invoked on error.
 */
- (void) loadOfflineResourcesOnSuccess:(OMCSyncMobileResourceArray _Nullable) success
                               onError:(OMCSyncErrorBlock _Nullable) error;

/**
 * Discards all offline/local edits only for all the resources that are not yet successfully synchronized with server.
 * Persistent state of the resources will remain in cache as is.
 @param error (optional) The block will be invoked on error.
 */
- (void) discardOfflineUpdatesOnError:(OMCSyncErrorBlock _Nullable) error;


#pragma mark - Eventing callbacks
/**
 * Event that is raised after every offline resource is synchronized with the service.
 @param synchronizedResource The block, invoked for each resource that is finished synchronizing. Pass nil to be removed from callbacks.
 */
- (void) offlineResourceSynchronized:(OMCSyncResourceChanged) synchronizedResource;

/**
 * Event that is raised every time a cached resource is updated, either from new data from the service,
 * from an online or offline write by the application, or on a delete.
 @param changedResource The block invoked for each resource changed in the cache. Pass nil to be removed from callbacks.
 */
- (void) cachedResourceChanged:(OMCSyncResourceChanged) changedResource;

#pragma mark -

/**
 * Evict (delete) the resource from the local cache.
 @param uri The URI of the resource.
 @param error (optional) The block will be invoked on error of the request.
 */
- (void) evictResource:(NSString *) uri
               onError:(OMCSyncErrorBlock _Nullable) error;

/**
* Purge entire store with all files.
*/
- (void) purge;

#pragma mark -
/**
 * Returns the number of cache hits.
 * @return The number of cache hits.
 */
- (int) cacheHitCount;

/**
 * Returns the number of cache misses.
 * @return The number of cache misses.
 */
- (int) cacheMissCount;

/**
 * Sets device to offline mode. Useful for testing
 * Note that calling setOfflineMode:true has no effect when the device isn't connected to the internet.
 @param isOffline boolean to set offline mode
 */
- (void) setOfflineMode:(BOOL) isOffline;

/**
 * Gets device network status that is currently being used by Synchronization.
 @return SyncNetworkStatus enum
 */
- (SyncNetworkStatus) getNetworkStatus;

@end


extern NSString* const OMCSynchronizationVersion;

NS_ASSUME_NONNULL_END
