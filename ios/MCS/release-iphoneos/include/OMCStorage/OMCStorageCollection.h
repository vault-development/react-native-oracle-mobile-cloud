//
//  OMCStorageCollection.h
//  OMCStorage
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved. 
//

#import <Foundation/Foundation.h>
#import "OMCStorageObject.h"

/**
 This interface defines the `OMCStorageCollection` object which contains parameters and public methods
 to operate on the OMCStorageObjects in the current collection.
 */
@interface OMCStorageCollection : NSObject

/**
 Identification of the current `OMCStorageCollection` in the service.
 */
@property(readonly, nonatomic) NSString* collectionID;

/**
 Description of the current `OMCStorageCollection` in the service.
 */
@property(readonly, nonatomic) NSString* collectionDescription;

/**
 Tells if the OMCStorageObject with the key exists in the current `OMCStorageCollection`.
 Return YES if it exists, NO otherwise.
 
 @param objectID The ID of the `OMCStorageObject` to find.
 */
-(BOOL) contains: (NSString*) objectID;

/**
 Returns a list of OMCStorageobjects for the StorageCollection starting with the 'offset' index,
 with the count up to but not necessarily including the 'limit' count.
 
 In a shared collection, it always returns the whole objects.
 In a user-isolated collection, if `allObjects` is false, then it only returns the objects owned by the current user.
 In a user-isolated collection, if `allObjects` is true, then it returns all the objects visible to the current user. 
 The user must have READ_ALL or READ_WRITE_ALL permission.
 
 @param offset The 'start' index.
 @param limit The count.
 @param allObjects True when a technician gets all the objects in a userIsolated collection, otherwise false.
 */
-(NSMutableArray*) get: (int) offset
             withLimit: (int) limit
         getAllObjects: (BOOL) allObjects;

/**
 Fetches and returns the `OMCStorageObject` in the current OMCStorageCollection. 
 The `OMCStorageObject` is specified with the key.
 
 @param objectID The ID of the `OMCStorageObject` to be fetched.
 */
-(OMCStorageObject*) get: (NSString*) objectID;

/**
 Creates and uploads an `OMCStorageObject` to the current OMCStorageCollection.
 Note that for a POST request, the server will generate an Object ID and ignore
 the Object ID currently in the current storage object.  To preserve the Object ID,
 use the put: method, even with a new object.
 Returns the OMCStorageObject.
  
 @param storageObject The `OMCStorageObject` to be uploaded.
 */
-(OMCStorageObject*) post: (OMCStorageObject*) storageObject;

/**
 Uploads a new `OMCStorageObject` or updates an existing `OMCStorageObject` in the current OMCStorageCollection.
 Returns the updated `OMCStorageObject.
 
 @param storageObject The `OMCStorageObject` to be uploaded.
 */
-(OMCStorageObject*) put: (OMCStorageObject*) storageObject;

/**
 Deletes the `OMCStorageObject` in the OMCStorageCollection.
 The `OMCStorageObject` is specified with the key.
 Return YES if delete is successful.
 
 @param objectID The ID of the `OMCStorageObject` to be deleted.
 */
-(BOOL) deleteWithKey : (NSString*) objectID;

/**
 Deletes the `OMCStorageObject` in the OMCStorageCollection.
 Return YES if delete is successful.
 
 @param storageObject The `OMCStorageObject` to be deleted.
 */
-(BOOL) delete: (OMCStorageObject*) storageObject;


@end
