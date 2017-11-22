//
//  OMCLocationAssetQuery.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import "OMCLocationDeviceContainerQuery.h"
#import "OMCLocationAsset.h"

NS_ASSUME_NONNULL_BEGIN

/**
 An asset query can be configured to search for assets.
 */
@interface OMCLocationAssetQuery : OMCLocationDeviceContainerQuery

/**
 The query will search for the asset associated with this device ID.
 */
@property (nonatomic, nullable) NSNumber* deviceID;

/**
 The query will search for the asset associated with the specified device.
 @param device The device associated with the asset the query will search for.
 @see deviceID
 */
- (void)setDevice:(nullable OMCLocationDevice*)device;

/**
 Asynchronously executes the query, invoking the specified completion
 handler block when finished.
 @param completionHandler The block to be invoked when the query has
 finished executing. The completion block will be invoked on
 the main dispatch queue.
 */
- (void)executeWithCompletionHandler:(void (^)(OMCLocationObjectQueryResult<OMCLocationAssetQuery*, OMCLocationAsset*>* _Nullable result, NSError* _Nullable error))completionHandler;

@end


#pragma mark - Typedefs

/**
 Convenience typedef that can be used when executing an asset query.
 */
typedef OMCLocationObjectQueryResult<OMCLocationAssetQuery*, OMCLocationAsset*> OMCLocationAssetQueryResult;

/**
 Completion block invoked when executing an asset query.
 */
typedef void (^OMCLocationAssetQueryCompletionBlock)(OMCLocationAssetQueryResult* _Nullable result, NSError* _Nullable error);


#pragma mark - Constants

/**
 The name of the asset query IDs JSON property (`listOfAssets`).
 */
extern NSString* const OMCLocationAssetQueryIDsParmName;

/**
 The name of the asset query device ID JSON property (`associatedDeviceId`).
 */
extern NSString* const OMCLocationAssetQueryDeviceIDParmName;

NS_ASSUME_NONNULL_END
