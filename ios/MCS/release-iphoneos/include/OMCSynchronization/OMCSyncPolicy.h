//
//  OMCSyncPolicy.h
//  OMCSynchronization
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved. 
//

#import <Foundation/Foundation.h>


//***** Periodic Refresh Policy to be set from OMC.PLIST'S mobileBackends's mbe > "synchronization"

// Periodic refresh policy key.
extern const NSString* periodicRefreshPolicy;

// Periodic refresh interval key (value in seconds).
extern const NSString* periodicRefreshInterval;

// Do not refresh periodically.
extern const NSString* PERIODIC_REFRESH_POLICY_REFRESH_NONE;

// Refresh expired items on start up.
extern const NSString* PERIODIC_REFRESH_POLICY_REFRESH_EXPIRED_ITEM_ON_START_UP;

// Possible value for {@link #PERIODIC_REFRESH_POLICY_HEADER }
// Refresh expired item periodically, based on value specified in PeriodicRefreshInterval.
extern const NSString* PERIODIC_REFRESH_POLICY_PERIODICALLY_REFRESH_EXPIRED_ITEMS;

//***** Sync Policies to be set from OMC.PLIST'S mobileBackends's mbe > "synchronization" > "policies" Or "defaultPolicy"

extern const NSString* fetchPolicy; // Key
extern const NSString* FETCH_FROM_CACHE;
extern const NSString* FETCH_FROM_SERVICE;
extern const NSString* FETCH_FROM_SERVICE_IF_ONLINE;
extern const NSString* FETCH_FROM_SERVICE_ON_CACHE_MISS_OR_EXPIRY;
extern const NSString* FETCH_FROM_SERVICE_ON_CACHE_MISS;
extern const NSString* FETCH_FROM_CACHE_SCHEDULE_REFRESH;
extern const NSString* FETCH_WITH_REFRESH;

extern const NSString* expirationPolicy;    // Key
extern const NSString* EXPIRE_ON_RESTART;
extern const NSString* EXPIRE_AFTER;
extern const NSString* NEVER_EXPIRE;
extern const NSString* expireAfter;         // Key ( value in seconds )


extern const NSString* evictionPolicy;  // Key
extern const NSString* EVICT_ON_EXPIRY_AT_STARTUP;
extern const NSString* MANUAL_EVICTION;

extern const NSString* updatePolicy;    // Key
extern const NSString* UPDATE_IF_ONLINE;
extern const NSString* QUEUE_IF_OFFLINE;

extern const NSString* conflictResolutionPolicy;    // Key
extern const NSString* CLIENT_WINS;
extern const NSString* SERVER_WINS;
extern const NSString* PRESERVE_CONFLICT;

extern const NSString* noCache;     // Key ( Value is boolean )


//***** Max Store Size to be set from OMC.PLIST'S mobileBackends's mbe > "synchronization"

extern const NSString* maxStoreSize; // Key ( value in MB )


//***** END of configurations file's key/value names   *****//


//***** PROGRAMMATICALLY DEFINING POLICIES ON REQUEST ( SAME AS ABOVE BY MEANING )
/**
 * Always returns from the cache. Can return null on cache miss or expired items.
 */
extern const int FETCH_POLICY_FETCH_FROM_CACHE;

/**
 * Always fetches from the service, will return an error if offline.
 */
extern const int FETCH_POLICY_FETCH_FROM_SERVICE;

/**
 * Fetches from the service if online, otherwise returns the cached item. Can return expired cached items if offline.
 */
extern const int FETCH_POLICY_FETCH_FROM_SERVICE_IF_ONLINE;

/**
 * Fetches from the service if there is a cache miss or the cached item has expired.
 * Will return an error if offline and fetching from the service.
 */
extern const int FETCH_POLICY_FETCH_FROM_SERVICE_ON_CACHE_MISS_OR_EXPIRY;

/**
 * Fetches from the service if there is a cache miss, otherwise returns from the cache. Can return expired items.
 */
extern const int FETCH_POLICY_FETCH_FROM_SERVICE_ON_CACHE_MISS;

/**
 * Always returns the resource from the cache and schedules a background refresh of the resource.
 * Returns status code 200 and a null on cache miss.
 */
extern const int FETCH_POLICY_FETCH_FROM_CACHE_SCHEDULE_REFRESH;

/**
 *  Fetches from the service if there is a cache miss or the cached item has expired.
 *  On hit cache, schedules a refresh in the background. Returns an error if offline and fetching from the service.
 *  On cache miss, this policy behaves just like FETCH_POLICY_FETCH_FROM_SERVICE_ON_CACHE_MISS_OR_EXPIRY.
 *  On cache hit, the app will get the result from cache and schedule a background refresh.
 */
extern const int FETCH_POLICY_FETCH_WITH_REFRESH;

/**
 * The object expires when the application restarts. This is useful when callers wish to refresh cached objects on application startup.
 */
extern const int EXPIRATION_POLICY_EXPIRE_ON_RESTART;

/**
 * The object never expires. Callers must manually refresh the item using {@link #FETCH_POLICY_FETCH_FROM_SERVICE} or other appropriate values.
 */
extern const int EXPIRATION_POLICY_NEVER_EXPIRE;

/**
 * The item expires after a duration in seconds specified by invoking {@link #setExpireAfter}.
 */
extern const int EXPIRATION_POLICY_EXPIRE_AFTER;

/**
 * If the object has expired, it will be evicted the next time the application starts.
 */
extern const int EVICTION_POLICY_EVICT_ON_EXPIRY_AT_STARTUP;

/**
 * The object is never evicted. Callers can manually evict by invoking the evict methods on {@link Synchronizer}.
 */
extern const int EVICTION_POLICY_MANUAL_EVICTION;

/**
 * Updates the service if online and returns an error if offline.
 */
extern const int UPDATE_POLICY_UPDATE_IF_ONLINE;

/**
 * Updates the service if online and queues the operation if offline.
 */
extern const int UPDATE_POLICY_QUEUE_IF_OFFLINE;

/**
 * Conflict resolution policy for client wins
 */
extern const int CONFLICT_RESOLUTION_POLICY_CLIENT_WINS;

/**
 * Conflict resolution policy for preserve conflict
 */
extern const int CONFLICT_RESOLUTION_POLICY_PRESERVE_CONFLICT;

/**
 * Conflict resolution policy for server wins
 */
extern const int CONFLICT_RESOLUTION_POLICY_SERVER_WINS;

/**
 An OMCSyncPolicy object is used to specify the synchronization policies for an
 OMCMobileObject, OMCMobileObjectCollection or OMCMobileFile object. The policy
 is persisted along with the cached objects and is in effect even after
 application restarts.
 */
@interface OMCSyncPolicy : NSObject

/**
 The fetch policy in use.
 */
@property(nonatomic, readwrite) int fetch_Policy;

/**
 The expiration policy in use.
 */
@property(nonatomic, readwrite) int expiration_Policy;

/**
 The eviction policy in use.
 */
@property(nonatomic, readwrite) int eviction_Policy;

/**
 The update policy in use.
 */
@property(nonatomic, readwrite) int update_Policy;

/**
 The conflict resolution policy in use.
 */
@property(nonatomic, readwrite) int conflictResolution_Policy;

/**
 The time after which the resource expires.
 */
@property(nonatomic, readwrite) int32_t expire_After;

/**
 Specifies whether to cache the resource.
 */
@property(nonatomic, readwrite) BOOL no_cache;


/**
 * Creates a new OMCSyncPolicy object with specified policies.
 * See properties defined in the OMCSyncPolicy header file for more information about each policy.
 * Default Conflict Resolution policy will be set to PRESERVE_CONFLICT.
 * Default no_cache settings will be set to NO.
 @param fetchPolicy The fetch policy value.
 @param expirationPolicy The expiration policy value.
 @param expireAfter The duration in seconds after which an object should expire.
 @param evictionPolicy The eviction policy value.
 @param updatePolicy The update policy value.
 */
-(id) initWithFetchPolicy:(int) fetchPolicy
         expirationPolicy:(int) expirationPolicy
              expireAfter:(int) expireAfter
           evictionPolicy:(int) evictionPolicy
             updatePolicy:(int) updatePolicy;

/**
 * Returns a default OMCSyncPolicy object, with policies:
 * fetchPolicy = FETCH_POLICY_FETCH_FROM_SERVICE_IF_ONLINE,
 * expirationPolicy = EXPIRATION_POLICY_EXPIRE_ON_RESTART,
 * evictionPolicy = EVICTION_POLICY_MANUAL_EVICTION,
 * updatePolicy = UPDATE_POLICY_QUEUE_IF_OFFLINE,
 * expireAfter = NSIntegerMax,
 * conflictResolutionPolicy = CONFLICT_RESOLUTION_POLICY_PRESERVE_CONFLICT,
 * no_cache = NO.
 */
-(id) defaultSyncPolicy;

@end
