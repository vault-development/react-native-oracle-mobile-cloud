//
//  OMCStorageObject.h
//  OMCStorage
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved. 
//

#import <Foundation/Foundation.h>

/**
 This interface manages the contents and metadata of a StorageObject.  Note that
 a StorageObject can be in either a "raw" or "completed" state.  After the user
 initializes the StorageObject from data or an input stream, none of the object
 metadata (such as creation date) is populated, so it is still in the "raw" state.
 It is only when the object reference is retrieved from a PUT, POST, or GET call on
 OMCStorageCollection, that the object is in its completed state.  In other words,
 the object must interact with the server or storage cache (Sync) to be fully initialized.
 */
@interface OMCStorageObject : NSObject

/**
 Identification of the `OMCStorageObject`
 should be unique across the OMCStorageCollection.
 */
@property(readwrite, nonatomic) NSString* ID;


/**
 Display Name of the `OMCStorageObject`.
 */
@property(readwrite, nonatomic) NSString* displayName;

/**
 The MIME Content-Type of the payload in the `OMCStorageObject`, for example "image/jpeg".
 */
@property(readwrite, nonatomic) NSString* contentType;

/**
 The property `createdBy`.
 */
@property(readonly, nonatomic) NSString* createdBy;

/**
 The property `modifiedBy`. Might be NULL if the object is never modified.
 */
@property(readonly, nonatomic) NSString* modifiedBy;

/**
 The property `createdOn` in the date format "yyyy-MM-dd'T'HH:mm:ss'Z'".
 */
@property(readonly, nonatomic) NSDate* createdOn;

/**
 The property `modifiedOn` in the date format "yyyy-MM-dd'T'HH:mm:ss'Z'".
 Might be NULL if the object is never modified.
 */
@property(readonly, nonatomic) NSDate* modifiedOn;

/**
 The property `canonicalLink` is the canonical link for the current StorageObject.
 The link is a relative url.
 */
@property(readonly, nonatomic) NSString* canonicalLink;


/**
 Initializes an `OMCStorageObject` object with NSData format payload.
 @param objectID The ID of the object in the Storage service.
 @param data The payload of the current object in the format of NSData.
 @param contentType The MIME Content-Type of the payload, for example "image/jpeg".
 */
-(instancetype) initPayload: (NSString*) objectID
                   withData: (NSData*) data
             andContentType: (NSString*) contentType;

/**
 Initializes an `OMCStorageObject` object with NSInputStream format payload.
 Note: as reading an NSInputStream involves registering on a Run Loop and
 doing asynchronous processing, invoking this API will block the current thread
 until the asynchronous processing completes.  Thus, it is not recommended that this
 method be called on the UI (main) thread.
 @param objectID The ID of the object in the Storage service.
 @param inputStream The payload of the current object in the format of NSInputStream.
 @param contentType The MIME Content-Type of the payload, for example "image/jpeg".
 */
-(instancetype) initPayload: (NSString*) objectID
                 withStream: (NSInputStream*) inputStream
             andContentType: (NSString*) contentType;


/**
 Returns the payload as NSData.
 */
-(NSData*) getPayloadData;

/**
 Returns the payload as NSInputStream.
 */
-(NSInputStream*) getPayloadStream;

/**
 Sets the payload and content-Type of the `OMCStorageObject`.
 Returns the updated `OMCStorageObject`.

 @param data is the new payload
 @param contentType The MIME Content-Type of the payload, for example "image/jpeg".
 */
-(OMCStorageObject*) setPayloadFromData: (NSData*) data
                        withContentType: (NSString*) contentType;
/**
 Sets the payload and content-Type of the `OMCStorageObject`.
 Returns the updated `OMCStorageObject`.
 Note: as reading an NSInputStream involves registering on a Run Loop and
 doing asynchronous processing, invoking this API will block the current thread
 until the asynchronous processing completes.  Thus, it is not recommended that this
 method be called on the UI (main) thread.
 @param inputStream The new payload.
 @param contentType The MIME Content-Type of the payload, for example "image/jpeg".
 */

-(OMCStorageObject*) setPayloadFromStream: (NSInputStream*) inputStream
                          withContentType: (NSString*) contentType;


@end
