//
//  OMCLocationBeacon.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 The beacon type.
 @see -[OMCLocationBeacon type]
 */
typedef NS_ENUM (NSUInteger, OMCLocationBeaconType) {
    /**
     AltBeacon type. The device's beacon is an AltBeacon.
     */
    OMCLocationBeaconTypeAltBeacon,

    /**
     Eddystone beacon type. The device's beacon is an Eddystone beacon.
     */
    OMCLocationBeaconTypeEddystoneBeacon,

    /**
     iBeacon type. The device's beacon is an iBeacon.
     */
    OMCLocationBeaconTypeIBeacon
};

NS_ASSUME_NONNULL_BEGIN

/**
 A beacon represents the vendor-specific state associated with
 a device. Beacons are immutable.
 
 @see -[OMCLocationDevice beacon]
 */
@interface OMCLocationBeacon : NSObject

/**
 The beacon type (altBeacon, Eddystone beacon, or iBeacon).
 */
@property (readonly) OMCLocationBeaconType type;

/**
 The beacon's raw properties (corresponding to the JSON payload).
 */
@property (readonly) NSDictionary<NSString*, id>* properties;

@end

NS_ASSUME_NONNULL_END
