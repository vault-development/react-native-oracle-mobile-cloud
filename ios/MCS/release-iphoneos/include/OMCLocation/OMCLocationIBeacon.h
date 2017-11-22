//
//  OMCLocationIBeacon.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMCLocationBeacon.h"

NS_ASSUME_NONNULL_BEGIN

/**
 An iBeacon is used to specify the vendor-specific state for a device's beacon.
 iBeacons are immutable.
 
 @see -[OMCLocationDevice beacon]
 */
@interface OMCLocationIBeacon : OMCLocationBeacon

/**
 The iBeacon's UUID.
 */
@property (readonly, nullable) NSUUID* uuid;

/**
 The iBeacon's major value.
 */
@property (readonly, nullable) NSNumber* major;

/**
 The iBeacon's minor value.
 */
@property (readonly, nullable) NSNumber* minor;

/**
 Constructs an iBeacon with the specified UUID, major value, and minor value.
 @param uuid The new iBeacon's UUID.
 @param major The new iBeacon's major value.
 @param minor The new iBeacon's minor value.
 */
+ (instancetype)iBeaconWithUUID:(nullable NSUUID*)uuid
                          major:(nullable NSNumber*)major
                          minor:(nullable NSNumber*)minor;

@end


#pragma mark - Constants

/**
 The name of the iBeacon JSON property (`iBeacon`).
 */
extern NSString* const OMCLocationIBeaconPropertyName;

/**
 The name of the iBeacon UUID JSON property (`uuid`).
 */
extern NSString* const OMCLocationIBeaconUUIDPropertyName;

/**
 The name of the iBeacon major JSON property (`major`).
 */
extern NSString* const OMCLocationIBeaconMajorPropertyName;

/**
 The name of the iBeacon minor JSON property (`minor`).
 */
extern NSString* const OMCLocationIBeaconMinorPropertyName;

/**
 The name of the iBeacon device query UUID JSON property (`iBeacon_uid`).
 */
extern NSString* const OMCLocationIBeaconDeviceQueryUUIDPropertyName;

/**
 The name of the iBeacon device query major JSON property (`iBeacon_major`).
 */
extern NSString* const OMCLocationIBeaconDeviceQueryMajorPropertyName;

/**
 The name of the iBeacon device query minor JSON property (`iBeacon_minor`).
 */
extern NSString* const OMCLocationIBeaconDeviceQueryMinorPropertyName;

NS_ASSUME_NONNULL_END
