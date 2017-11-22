//
//  OMCLocationAltBeacon.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import "OMCLocationBeacon.h"

NS_ASSUME_NONNULL_BEGIN

/**
 An altBeacon is used to specify the vendor-specific state for a device's beacon.
 altBeacons are immutable.
 
 @see -[OMCLocationDevice beacon]
 */
@interface OMCLocationAltBeacon : OMCLocationBeacon

/**
 The altBeacon's ID1.
 */
@property (readonly, nullable) NSUUID* id1;

/**
 The altBeacon's ID2.
 */
@property (readonly, nullable) NSNumber* id2;

/**
 The altBeacon's ID3.
 */
@property (readonly, nullable) NSNumber* id3;

/**
 Constructs an altBeacon with the specified IDs.
 @param id1 The altBeacon's ID1.
 @param id2 The altBeacon's ID2.
 @param id3 The altBeacon's ID3.
 */
+ (instancetype)altBeaconWithID1:(nullable NSUUID*)id1
                             id2:(nullable NSNumber*)id2
                             id3:(nullable NSNumber*)id3;

@end


#pragma mark - Constants

extern NSString* const OMCLocationAltBeaconPropertyName;

/**
 The name of the altBeacon ID1 JSON property (`id1`).
 */
extern NSString* const OMCLocationAltBeaconID1PropertyName;

/**
 The name of the altBeacon ID2 JSON property (`id2`).
 */
extern NSString* const OMCLocationAltBeaconID2PropertyName;

/**
 The name of the altBeacon ID3 JSON property (`id3`).
 */
extern NSString* const OMCLocationAltBeaconID3PropertyName;


/**
 The name of the altBeacon device query ID1 JSON property (`altBeacon_id1`).
 */
extern NSString* const OMCLocationAltBeaconDeviceQueryID1PropertyName;

/**
 The name of the altBeacon device query ID2 JSON property (`altBeacon_id2`).
 */
extern NSString* const OMCLocationAltBeaconDeviceQueryID2PropertyName;

/**
 The name of the altBeacon device query ID3 JSON property (`altBeacon_id3`).
 */
extern NSString* const OMCLocationAltBeaconDeviceQueryID3PropertyName;

NS_ASSUME_NONNULL_END
