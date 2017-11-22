//
//  OMCFetchObjectCollectionBuilder.h
//  OMCSynchronization
//
//  Copyright (c) 2015 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMCSyncGlobals.h"
#import "OMCSyncPolicy.h"
#import "OMCSyncStoreState.h"

@class OMCMobileEndpoint;
@class OMCMobileObjectCollection;

/**
 * The callback on object fetch success.  
 @param mobileObjectCollection The object collection fetched.
 */
typedef void(^OMCFetchCollectionSuccess) (OMCMobileObjectCollection * mobileObjectCollection);

/**
 * Fetch objectCollection builder to get OMCMobileObjectCollection
 */
@interface OMCFetchObjectCollectionBuilder : NSObject

/**
 * Gets currently set SyncPolicy
 @return OMCSyncPolicy object, if not set will return default SyncPolicy.
 */
- (OMCSyncPolicy *) getSyncPolicy;

/**
 * Sets SyncPolicy
 @param syncPolicy will set the passed policy as current SyncPolicy
 */
- (void) setSyncPolicy:(OMCSyncPolicy *) syncPolicy;

/**
 * Sets Fetch policy in SyncPolicy as FETCH_POLICY_FETCH_FROM_SERVICE_IF_ONLINE. Other policies in SyncPolicy will remain same.
 */
- (void) setSyncPolicyFetchFromServer;


/**
 * Specifies query parameters. (Will override existing parameters with the same name)
 * @param name name of the query param
 * @param value value of the query param
 */
- (void) withParamName:(NSString *) name
            paramValue:(NSString *) value;

/**
 * Sets the query to use when fetching data from the local cache.
 * Must initialize synchronization with the custom class with properties for which to query on.
 * And use that custom class in openEndpoint.
 @param propertyName name of the property to query on
 @param compareOperation compare operator
 @param propertyValue value to compare
 */
- (void) queryForProperty:(NSString *) propertyName
              comparision:(SyncCompareOperator) compareOperation
              compareWith:(id) propertyValue;


/**
 *  Specifies an ascending sort for the results. Multiple sorts can be specified.
 @param propertyName Name of the property to sort on. The sort will be ascending.
 */
- (void) sortByAscending:(NSString *) propertyName;

/**
 *  Specifies a descending sort for the results. Multiple sorts can be specified.
 @param propertyName Name of the property to sort on. The sort will be descending.
 */
- (void) sortByDescending:(NSString *) propertyName;

/**
 * Sets extra request headers.
 * No need to specify headers for authorization and content-type, as they will be added by default.
 * @param headers Extra request headers
 */
- (void) setRequestHeaders:(NSDictionary *) headers;

/**
 * Execute the Get request. Based on the set policy, it will go to the server, to the local cache, or to both.
 @param successBlk block that will be called after the request has successfully finished with the mobile resource.
 @param errorBlk block that will be called after the request has finished with an error.
 */
- (void) executeFetchOnSuccess:(OMCFetchCollectionSuccess) successBlk
                       OnError:(OMCSyncErrorBlock) errorBlk;
@end
