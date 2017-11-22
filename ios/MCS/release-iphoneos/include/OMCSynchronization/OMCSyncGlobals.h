//
//  OMCSyncGlobals.h
//  OMCSynchronization
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved. 
//

#import <Foundation/Foundation.h>

@class OMCMobileFile;
@class OMCMobileResource;

/**
 * The callback on successfully fetching the resource.
 @param mobileResource This could be OMCMobileObject or a custom mobile object,
 OMCMobileObjectCollection or OMCMobileFile.
 */
typedef void(^OMCMobileResourceSuccess) (id mobileResource);

/**
 * The callback on successfully fetching the object.
 @param mobileObject This could be OMCMobileObject or a custom mobile object.
 */
typedef void(^OMCObjectSuccess) (id mobileObject);

/**
 The callback on successfully fetching the mobile file.
 @param mobileFile The mobile file retrieved.
 */
typedef void(^OMCFileSuccess) (OMCMobileFile * mobileFile);

/**
 The callback used when an error has occurred while fetching data.
 @param error The standard error object.
 */
typedef void(^OMCSyncErrorBlock) (NSError* error);

/**
 The callback used when data has been successfully fetched.
 @param data The data fetched.
 @param response The HTTP response object.
 */
typedef void(^OMCSyncSuccessBlock) (NSData* data, NSHTTPURLResponse* response);


/**
 The callback used when a resource is synchronized or refreshed in the cache.
 @param uri Uri of the changed resource
 @param resource MobileResource that is changed in the cache (the mobileResource can be either OMCMobileObject/OMCMobileObjectCollection/OMCMobileFile or a customClass object )
 */
typedef void(^OMCSyncResourceChanged) (NSString* uri, id mobileResource);

/**
 The callback used when a mobile resources is successfully loaded.
 @param mobileResources NSArray of all loaded mobile resources
 */
typedef void(^OMCSyncMobileResourceArray) (NSArray* mobileResources);


/**
 * An enumeration of the different resource types.
 *
 * Default is file (ResourceKindFile).
 */
typedef NS_ENUM(int, SyncResourceKind) {
    /** Denotes a file resource. */
    ResourceKindFile = 0,

    /** Denotes an object resource. */
    ResourceKindObject = 1,

     /** Denotes a collection resource. */
    ResourceKindCollection = 2,
    
    /** Denotes an unknown type. */
    ResourceKindUnknown = -1,
};

/**
 * An enumeration of the different HTTP request method types.
 *
 * Default is "Get".
 */
typedef NS_ENUM(int, SyncRequestMethod) {
    /** HTTP method GET */
    RequestMethodGet = 0,
    
    /** HTTP method PUT */
    RequestMethodPut = 1,
    
    /** HTTP method POST */
    RequestMethodPost = 2,
    
    /** HTTP method DELETE */
    RequestMethodDelete = 3,
    
    /** HTTP method PATCH */
    RequestMethodPatch = 4,
};

/**
 * An enumeration of the different Sync network states.
 *
 * Default is "SyncOnline".
 */
typedef NS_ENUM(int, SyncNetworkStatus) {
   
    /** Online state */
    SyncOnline = 0,
    
    /** Offline state */
    SyncOffline = 1,
    
    /** Offline state for test */
    SyncOfflineTest = 2,
};


/**
 * This interface defines global constants to be used by the client.
 */
@interface OMCSyncGlobals : NSObject

@end
