//
//  OMCLocationDevice.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import "OMCLocationObject.h"
#import "OMCLocationObjectQueryResult.h"
@class OMCLocationDeviceContainer;
@class OMCLocationBeacon;

NS_ASSUME_NONNULL_BEGIN

/**
 A device adds context to a vendor-specific beacon and associates it
 with an asset or place.
 
 @see -[OMCLocationDeviceContainer devices]
 */
@interface OMCLocationDevice : OMCLocationObject

/**
 The device's container, either a place or an asset.
 A device can be associated with either a place or an asset, but not both.
 @see OMCLocationAsset
 @see OMCLocationPlace
 */
@property (readonly, nullable) OMCLocationDeviceContainer* container;

/**
 The device's beacon (altBeacon, Eddystone beacon, or iBeacon).
 */
@property (readonly, nullable) OMCLocationBeacon* beacon;

@end


#pragma mark - Typedefs

/**
 Completion block invoked when retrieving a specific device (by ID).
 */
typedef void (^OMCLocationDeviceCompletionBlock)(OMCLocationDevice* _Nullable device, NSError* _Nullable error);


/**
 Completion block invoked when retrieving a list of devices.
 */
typedef void (^OMCLocationDevicesCompletionBlock)(NSArray<OMCLocationDevice*>* _Nullable devices, NSError* _Nullable error);


#pragma mark - Constants

/**
 The relative path for the Location device REST endpoints.
 This is appended to the Location service's relative URL
 (`devices`).
 */
extern NSString* const OMCLocationDeviceResourceDir;

/**
 The name of the device place JSON property (`place`).
 */
extern NSString* const OMCLocationDevicePlacePropertyName;

/**
 The name of the device asset JSON property (`asset`).
 */
extern NSString* const OMCLocationDeviceAssetPropertyName;

/**
 The name of the device beacon JSON property (`beacon`).
 */
extern NSString* const OMCLocationDeviceBeaconPropertyName;

NS_ASSUME_NONNULL_END
