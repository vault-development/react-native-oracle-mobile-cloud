//
//  OMCLocationEddystoneBeacon.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import "OMCLocationBeacon.h"
@class OMCLocationEddystoneBeaconUID;

NS_ASSUME_NONNULL_BEGIN

/**
 An Eddystone beacon is used to specify the vendor-specific state for a device's beacon.
 Eddystone beacons are immutable.
 
 @see -[OMCLocationDevice beacon]
 */
@interface OMCLocationEddystoneBeacon : OMCLocationBeacon

/**
 The beacon's UID.
 */
@property (readonly, nullable) OMCLocationEddystoneBeaconUID* uid;

/**
 The beacon's URL.
 */
@property (readonly, nullable) NSURL* url;

/**
 Constructs a new Eddystone beacon with the specified namespace, instance,
 and URL.
 @param namespace The new beacon's namespace.
 @param instance The new beacon's instance.
 @param url The new beacon's URL.
 */
+ (instancetype)eddystoneBeaconWithNamespace:(nullable NSString*)namespace
                                    instance:(nullable NSString*)instance
                                         url:(nullable NSURL*)url;

/**
 Constructs a new Eddystone beacon with the specified UID and URL.
 @param uid The new beacon's UID.
 @param url The new beacon's URL.
 */
+ (instancetype)eddystoneBeaconWithUID:(nullable OMCLocationEddystoneBeaconUID*)uid
                                   url:(nullable NSURL*)url;

@end


/**
 An Eddystone beacon UID is used to specify an Eddystone beacon's UID.
 
 @see -[OMCLocationEddystoneBeacon uid]
 */
@interface OMCLocationEddystoneBeaconUID : NSObject

/**
 The UID's raw properties (corresponding to the JSON payload).
 */
@property (readonly) NSDictionary<NSString*, id>* properties;

/**
 The UID's namespace.
 */
@property (readonly, nullable) NSString* namespace;

/**
 The UID's instance.
 */
@property (readonly, nullable) NSString* instance;

/**
 Constructs a new Eddystone beacon UID with the specified namespace and instance.
 @param namespace The new beacon's namespace.
 @param instance The new beacon's instance.
 */
+ (instancetype)uidWithNamespace:(nullable NSString*)namespace
                        instance:(nullable NSString*)instance;

@end


#pragma mark - Constants

/**
 The name of the Eddystone beacon JSON property (`eddystone`).
 */
extern NSString* const OMCLocationEddystoneBeaconPropertyName;

/**
 The name of the Eddystone beacon UID JSON property (`eddystoneUid`).
 */
extern NSString* const OMCLocationEddystoneBeaconUIDPropertyName;

/**
 The name of the Eddystone beacon UID namespace JSON property (`namespace`).
 */
extern NSString* const OMCLocationEddystoneBeaconUIDNamespacePropertyName;

/**
 The name of the Eddystone beacon UID instance JSON property (`instance`).
 */
extern NSString* const OMCLocationEddystoneBeaconUIDInstancePropertyName;

/**
 The name of the Eddystone beacon URL JSON property (`eddystoneUrl`).
 */
extern NSString* const OMCLocationEddystoneBeaconURLPropertyName;

/**
 The name of the Eddystone beacon URL URL JSON property (`url`).
 */
extern NSString* const OMCLocationEddystoneBeaconURLURLPropertyName;


/**
 The name of the Eddystone beacon device query namespace JSON property (`eddystone_namespace`).
 */
extern NSString* const OMCLocationEddystoneBeaconDeviceQueryNamespacePropertyName;

/**
 The name of the Eddystone beacon device query instance JSON property (`eddystone_instance`).
 */
extern NSString* const OMCLocationEddystoneBeaconDeviceQueryInstancePropertyName;

/**
 The name of the Eddystone beacon device query URL JSON property (`eddystone_url`).
 */
extern NSString* const OMCLocationEddystoneBeaconDeviceQueryURLPropertyName;

NS_ASSUME_NONNULL_END
