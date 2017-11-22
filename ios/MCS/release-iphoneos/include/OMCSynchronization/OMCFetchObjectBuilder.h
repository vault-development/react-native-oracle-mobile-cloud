//
//  OMCFetchObjectBuilder.h
//  OMCSynchronization
//
//  Copyright (c) 2015 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMCSyncGlobals.h"
#import "OMCSyncStoreState.h"
#import "OMCSyncPolicy.h"

@class OMCMobileObject;
@class OMCMobileEndpoint;

/**
 * Fetch object builder to get OMCMobileObject
 */
@interface OMCFetchObjectBuilder : NSObject

/**
 * Gets currently set SyncPolicy
 @return OMCSyncPolicy object. If not set, will return default SyncPolicy.
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
- (void) executeFetchOnSuccess:(OMCObjectSuccess) successBlk
                       OnError:(OMCSyncErrorBlock) errorBlk;

@end
