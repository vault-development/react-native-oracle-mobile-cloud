//
//  OMCStorage.h
//  OMCStorage
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved. 
//

#import <Foundation/Foundation.h>
#import "OMCCore/OMCServiceProxy.h"
#import "OMCStorageCollection.h"

/**
 This is the main class for Storage API operations.  As the Storage functionality
 relies heavily on the Sync module, it is necessary to include the OMCSynchronization
 library and SyncStore.mom with your app.
 */
@interface OMCStorage : OMCServiceProxy

/**
 Fetch an `OMCStorageCollection` from the Storage Service for the current user.
 The `OMCStorageCollection` is specified with the collectionID.
 
 @param collectionID The ID of the `OMCStorageCollection` to be fetched.
 @return The target `OMCStorageCollection` object, or nil if a collection is not found
 for the given collectionID.
 */
-(OMCStorageCollection*) getCollection: (NSString*) collectionID;



/**
 In comparison to the getCollection function, which returns OMCStorageCollections for
 the current user, this function is designed to return OMCStorageCollections for
 a different specified user.  This is useful when, from a MCS perspective, the collection
 is marked as 'isolated' rather than 'shared' and the current user needs access to
 another user's isolated collection objects.  In order to access objects in another
 user's isolated collected, the current user must have READ_ALL or READ_WRITE_ALL
 privileges on the other user's collection.
 
 @param collectionID The ID of the `OMCStorageCollection`.
 @param userId The ID of the user who owns the collection.
 @return The target `OMCStorageCollection` object, or nil if a collection is not found
 for the given collectionID.
 */
-(OMCStorageCollection*) getCollection:(NSString*) collectionID
                             forUserId:(NSString*) userId;

@end

/**
 The Storage library's current version.
 */
extern NSString* const OMCStorageVersion;
