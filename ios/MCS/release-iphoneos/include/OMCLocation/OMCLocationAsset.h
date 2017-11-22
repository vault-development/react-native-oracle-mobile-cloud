//
//  OMCLocationAsset.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import "OMCLocationDeviceContainer.h"
#import "OMCLocationObjectQueryResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 An asset describes a portable item that can be associated with one
 or more devices.
 */
@interface OMCLocationAsset : OMCLocationDeviceContainer

@end


#pragma mark - Typedefs

/**
 Completion block invoked when retrieving a specific asset (by ID).
 */
typedef void (^OMCLocationAssetCompletionBlock)(OMCLocationAsset* _Nullable asset, NSError* _Nullable error);


#pragma mark - Constants

/**
 The relative path for the Location asset REST endpoints.
 This is appended to the Location service's relative URL
 (`assets`).
 */
extern NSString* const OMCLocationAssetResourceDir;

/**
 The name of the asset last known place JSON property (`lastKnownPlace`).
 */
extern NSString* const OMCLocationAssetLastKnownPlacePropertyName;

/**
 The name of the asset object last known place ID JSON property (`placeId`).
 */
extern NSString* const OMCLocationAssetLastKnownPlacePlaceIDPropertyName;

NS_ASSUME_NONNULL_END
