//
//  OMCLocationPlace.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import "OMCLocationDeviceContainer.h"
#import "OMCLocationDevice.h"
@class OMCLocationPlace;
@class OMCLocationAddress;

NS_ASSUME_NONNULL_BEGIN

/**
 Completion handler used when retrieving a specific place (by ID).
 */
typedef void (^OMCLocationPlaceCompletionBlock)(OMCLocationPlace* _Nullable place, NSError* _Nullable error);


/**
 Completion handler used when retrieving a list of places.
 */
typedef void (^OMCLocationPlacesCompletionBlock)(NSArray<OMCLocationPlace*>* _Nullable places, NSError* _Nullable error);


/**
 A place represents a geographical location that can be associated with one
 or more devices. Optionally, places can also form a hierarchy, where a place
 has a single parent and, possibly, multiple children. Typically this is used
 to aggregate a set of contiguous places into a larger place that represents the
 whole collection of smaller places.
 */
@interface OMCLocationPlace : OMCLocationDeviceContainer

/**
 The place's address (a geo point, circle, or polygon).
 */
@property (readonly, nullable) OMCLocationAddress* address;


#pragma mark - All Devices

/**
 Asynchronously fetches all the place's devices, including the devices of all
 the place's descendants, invoking the specified completion
 handler block when finished.
 Asynchronously invokes the completion handler immediately if the place's devices
 have already been fetched.
 @param completionHandler The block to be invoked when the devices have been
 fetched. The completion block will be invoked on the main dispatch queue.
 @see -[OMCLocationObject refreshWithCompletionHandler:]
 */
- (void)allDevicesWithCompletionHandler:(OMCLocationDevicesCompletionBlock)completionHandler;


#pragma mark - Parent/Children

/**
 Asynchronously fetches the place's parent, invoking the specified completion
 handler block when finished.
 Asynchronously invokes the completion handler immediately if the place's parent
 has already been fetched.
 @param completionHandler The block to be invoked when the devices have been
 fetched. The completion block will be invoked on the main dispatch queue.
 @see hasChildren
 @see childrenWithCompletionHandler:
 @see -[OMCLocationObject refreshWithCompletionHandler:]
 */
- (void)parentWithCompletionHandler:(OMCLocationPlaceCompletionBlock)completionHandler;

/**
 Returns whether the place has children, without querying the server.
 @see parentWithCompletionHandler:
 @see childrenWithCompletionHandler:
 */
@property (readonly) BOOL hasChildren;

/**
 Asynchronously fetches the place's children (i.e. its direct descendants),
 invoking the specified completion handler block when finished.
 Asynchronously invokes the completion handler immediately if the place's children
 have already been fetched.
 @param completionHandler The block to be invoked when the devices have been
 fetched. The completion block will be invoked on the main dispatch queue.
 @warning The children will be fetched in a *single* query with a "long" format.
 The results will not be paginated.
 @see parentWithCompletionHandler:
 @see hasChildren
 @see hierarchyWithCompletionHandler:
 @see descendantsWithCompletionHandler:
 @see -[OMCLocationObject refreshWithCompletionHandler:]
 */
- (void)childrenWithCompletionHandler:(OMCLocationPlacesCompletionBlock)completionHandler;

/**
 Asynchronously fetches the place's hierarchy (i.e. the place itself and all its descendants),
 invoking the specified completion handler block when finished.
 Asynchronously invokes the completion handler immediately if the place's hierarchy
 has already been fetched.
 @param completionHandler The block to be invoked when the devices have been
 fetched. The completion block will be invoked on the main dispatch queue.
 @warning The hierarchy will be fetched in a *single* query with a "long" format.
 The results will not be paginated.
 @see childrenWithCompletionHandler:
 @see descendantsWithCompletionHandler:
 @see -[OMCLocationObject refreshWithCompletionHandler:]
 */
- (void)hierarchyWithCompletionHandler:(OMCLocationPlacesCompletionBlock)completionHandler;

/**
 Asynchronously fetches the place's descendants (i.e. its children, grandchildren, etc.),
 invoking the specified completion handler block when finished.
 Asynchronously invokes the completion handler immediately if the place's descendants
 have already been fetched.
 @param completionHandler The block to be invoked when the devices have been
 fetched. The completion block will be invoked on the main dispatch queue.
 @warning The descendants will be fetched in a *single* query with a "long" format.
 The results will not be paginated.
 @see childrenWithCompletionHandler:
 @see hierarchyWithCompletionHandler:
 @see -[OMCLocationObject refreshWithCompletionHandler:]
 */
- (void)descendantsWithCompletionHandler:(OMCLocationPlacesCompletionBlock)completionHandler;

@end


#pragma mark - Constants

/**
 The relative path for the Location place REST endpoints.
 This is appended to the Location service's relative URL
 (`places`).
 */
extern NSString* const OMCLocationPlaceResourceDir;

/**
 The name of the place address JSON property (`address`).
 */
extern NSString* const OMCLocationPlaceAddressPropertyName;

/**
 The name of the place parent place ID JSON property (`parentPlace`).
 */
extern NSString* const OMCLocationPlaceParentIDPropertyName;

/**
 The name of the place "has children" JSON property (`hasChildren`).
 */
extern NSString* const OMCLocationPlaceHasChildrenPropertyName;

/**
 The name of the place children JSON property (`children`).
 */
extern NSString* const OMCLocationPlaceChildrenPropertyName;

/**
 The value of the `code` of the `NSError` generated when
 an unexpected result was returned by a deep refresh.
 See the values in the `userInfo` dictionary.
 */
extern NSInteger const OMCLocationPlaceDeepRefreshError;

/**
 A key to the `userInfo` dictionary in
 the `NSError` generated when a deep refresh generates an unexpected result.
 The corresponding value is the `OMCLocationPlaceQueryResult` that generated the error.
 */
extern NSString* const OMCLocationPlaceDeepRefreshErrorResult;

NS_ASSUME_NONNULL_END
