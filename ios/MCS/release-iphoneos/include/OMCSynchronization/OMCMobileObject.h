//
//  OMCMobileObject.h
//  OMCSynchronization
//
//  Copyright (c) 2015 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMCMobileResource.h"
#import "OMCSyncGlobals.h"

@class OMCMobileEndpoint;

/**
 Class that represents an object returned by a custom code API. Enables access to strongly typed object properties.
 */
@interface OMCMobileObject : OMCMobileResource

/**
 The underlying JSON representation of the object, typically an NSDictionary or NSArray.
 @return The JSON object (returns local/offline edited copy if found; otherwise returns persistent state/server copy)
 */
- (id) jsonObject;

/**
 Returns the server version (persistent state) of the object. This method is useful when the conflict resolution
 policy is PRESERVE_CONFLICT and a conflict occurs. You can use this method to get the current server version of the
 object, use the jsonObject() method to get the device's local cache version of the object, and then resolve the
 conflict programmatically. For example you can merge the two objects, or you can let user choose which version to persist.
 @return JSON object that represents the persistent state (server copy) of the object.
 */
- (id) jsonObjectPersistentState;

/**
 Adds or updates the property in the JSON object. To persist the added/updated property to the OMCMobileObject object,
 you must invoke the saveResource method.
 @param propertyName key cannot be nil
 @param value value of the property
 */
-(void) addOrUpdateJsonProperty:(NSString *) propertyName
                  propertyValue:(NSString *) value;

/**
 If the device is online, sends all the changes made to the object to the server. If the device is offline,
 the behavior depends on the resource's (or for an add, the configuration file's or default) update policy.
 
 If the device is online, then the changes are sent to the server, regardless of the policy setting. After
 the HTTP request that is sent to the server (PUT/POST/DELETE) completes successfully, the successBlk is
 called. If the HTTP response is not 2XX, 409 or 412, or if the SDK detects an error, such as timeout, then
 the errorBlk is called.
 
 If the device is offline and the update policy is QUEUE_IF_OFFLINE, then the successBlk is called after
 the changes are written to the local cache. The changes are then queued to be sent to the server when the
 device goes online.The errorBlk is called only if there is an error when writing to the local cache, such
 as exceeding the maxStoreSize.
 
 If the device is offline and the update policy is UPDATE_IF_ONLINE, then the errorBlk is called.
 
 Note that you can override the resource's update policy setting by calling saveResource with the saveIfOffline parameter.
 @param successBlk block that will be called after the request has successfully finished with the mobile resource.
 @param errorBlk block that will be called after the request has finished with an error.
 */
- (void) saveResourceOnSuccess:(OMCObjectSuccess) successBlk
                       OnError:(OMCSyncErrorBlock) errorBlk;;

/**
 If the device is online, sends all the changes made to the object to the server. If the device is offline,
 the behavior depends on saveIfOffline parameter value.
 
 If the device is online, then the changes are sent to the server, regardless of the policy setting.
 After the HTTP request that is sent to the server (PUT/POST/DELETE) completes successfully, the successBlk is
 called. If the HTTP response is not 2XX, 409 or 412, or if the SDK detects an error, such as timeout, then the
 errorBlk is called.
 
 If the device is offline and saveIfOffline is true, then the successBlk is called after the changes are written
 to the local cache. The changes are then queued to be sent to the server when the device goes online.The errorBlk
 is called only if there is an error when writing to the local cache, such as exceeding the maxStoreSize.
 
 If the device is offline and saveIfOffline is false, then the errorBlk is called.
 @param saveIfOffline  If the device is online, this parameter has no effect because all saves are sent
 to the server. If the device is offline and this option is true, then the method caches the updates locally,
 and, when the device goes online, it sends the changes to the server. If the device is offline and this option
 is false, then the save fails.
 
 Note: The use of this function overrides any update policy set elsewhere, such as the resource's update
 policy for an update or delete, or the configuration file or default policy for an add. This parameter
 is useful is when you must ensure that a new or updated object is sent to the server immediately, and
 you need to know the results (error or success) instaneneously so that you can act on the result.
 @param successBlk Block that is called after the request completes successfully.
 @param errorBlk Block that is called after the request completes with an error.
 */
- (void) saveResource:(BOOL) saveIfOffline
            OnSuccess:(OMCObjectSuccess) successBlk
              OnError:(OMCSyncErrorBlock) errorBlk;

/**
  Deletes the object. Caches the deletion locally if offline.  Unlike deleteResource: with it's
  deleteIfOffline parameter, this method is always influenced by the Update Policy setting
 @param errorBlk Block that is called after the request completes with error.
 */
- (void) deleteResourceOnError:(OMCSyncErrorBlock) errorBlk;

/**
 Deletes the object.
 @param deleteIfOffline If true and the device is offline, caches the deletion locally and sends the DELETE
 request to the server when the device goes online. If false, then calls the errorBlk. This parameter
 overrides the resource's update policy.
 @param errorBlk Block that is called after the request completes with error.
 */
- (void) deleteResource:(BOOL) deleteIfOffline
                OnError:(OMCSyncErrorBlock)errorBlk;

@end
