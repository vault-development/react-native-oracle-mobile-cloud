//
//  OMCMobileFile.h
//  OMCSynchronization
//
//  Copyright (c) 2015 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMCMobileResource.h"
#import "OMCSyncGlobals.h"

@class OMCMobileEndpoint;

/**
 * Class that represents a file or BLOB returned by a custom code API.
 */
@interface OMCMobileFile : OMCMobileResource

/**
 * Returns the raw file data.
 */
- (NSData *) getData;

/**
 * Returns the raw file data (server copy).
 */
- (NSData *) getDataPersistentState;

/**
 * Returns the input stream of the data.
 */
- (NSInputStream *) getDataStream;

/**
 * Returns the file path of the raw file data.
 */
- (NSString *) getFilepath;

/**
 * Returns the file path of the raw file data (server copy).
 */
- (NSString *) getFilepathPersistentState;

/**
 * Saves any changes to the file back to the service. Caches the changes locally if offline.
 * Unlike saveResource: with it's saveIfOffline parameter, this method is always influenced by the Update Policy setting
 * When online for both saveResource()
 *       - The Update Policy and the similar saveIfOffline parameter on this method has no effect in this case, regardless of their settings.
 *       - successBlk is called once the change has been written directly to MCS and the related PUT/POST/DELETE operation is successful.
 *       - errorBlk is called if, during the save operation, the server returned an error code (status code <> 2XX or <> 409/412) or the SDK detects a separate error (e.g. timeout).
 * When offline and the UpdatePolicy is UPDATE_IF_ONLINE
 *       - An error is raised with the errorBlk, the successBlk is never called as the policy deliberately says only update if online, and no request is sent to MCS.
 * When offline and UpdatePolicy == QUEUE_IF_OFFLINE
 *       - The successBlk is called once the change has been written to the local cache and queued to be later written to MCS.
 *       - The errorBlk is only called if there is an error writing to the local cache (such as exceeding the maxStoreSize)
 @param data raw data for file
 @param contentType type of content in data for file
 @param successBlk block that will be called after request successfully finished with the mobile resource.
 @param errorBlk block that will be called after request finished with error.
 */
- (void) saveResource:(NSData *) data
          contentType:(NSString *) contentType
            OnSuccess:(OMCFileSuccess) successBlk
              OnError:(OMCSyncErrorBlock) errorBlk;
;

/**
 * Saves any changes to the file back to the service. Caches the changes locally if offline.
 * Unlike saveResource: with it's saveIfOffline parameter, this method is always influenced by the Update Policy setting
 * When online for both saveResource()
 *       - The Update Policy and the similar saveIfOffline parameter on this method has no effect in this case, regardless of their settings.
 *       - The successBlk is called once the change has been written directly to MCS and the related PUT/POST/DELETE operation is successful.
 *       - The errorBlk is called if, during the save operation, the server returned an error code (status code <> 2XX or <> 409/412) or the SDK detects a separate error (e.g. timeout).
 * When offline and UpdatePolicy is UPDATE_IF_ONLINE
 *       - An error is raised with the errorBlk, the successBlk is never called as the policy deliberately says only update if online, and no request is sent to MCS.
 * When offline and UpdatePolicy == QUEUE_IF_OFFLINE
 *       - successBlk is called once the change has been written to the local cache and queued to be later written to MCS.
 *       - The errorBlk is only called if there is an error writing to the local cache (such as exceeding the maxStoreSize)
 @param data raw data for file
 @param contentType type of content for file
 @param saveIfOffline If the device is online, this parameter has no effect since any save will be written back to the server. If the device is offline and this option is true, the method will cache updates locally and, when the device returns online, sync them back to the remote service. If the device is offline and this option is false, the save will fail. Note the use of this function overrides any UpdatePolicy setting set elsewhere. This parameter is useful in cases such as a one-off save, where you can set the option to false to ensure the new/updated record is saved to MCS or an error is reported instantaneously, so you can immediately act on the result.
 @param successBlk block that will be called after the request has successfully finished with the mobile resource.
 @param errorBlk block that will be called after the request has finished with an error.
 */
- (void) saveResource:(NSData *) data
          contentType:(NSString *) contentType
        saveIfOffline:(BOOL) saveIfOffline
            OnSuccess:(OMCFileSuccess) successBlk
              OnError:(OMCSyncErrorBlock) errorBlk;
;

/**
 * Deletes the file. Caches the delete locally if offline.
 * Unlike deleteResource: with it's deleteIfOffline parameter, this method is always influenced by the Update Policy setting
 @param errorBlk block that will be called after the request has finished with an error.
 */
- (void) deleteResourceOnError:(OMCSyncErrorBlock) errorBlk;

/**
 * Deletes the file.
 @param deleteIfOffline If true will cache the delete locally and sync back to the service if the device is offline. If false will fail if the device is offline. (This param will override the UpdatePolicy setting set elsewhere.)
 @param errorBlk block that will be called after the request has finished with an error.
 */
- (void) deleteResource:(BOOL) deleteIfOffline
                OnError:(OMCSyncErrorBlock) errorBlk;

@end
