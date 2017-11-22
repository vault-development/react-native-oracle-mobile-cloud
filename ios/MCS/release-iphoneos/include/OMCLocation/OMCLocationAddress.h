//
//  OMCLocationAddress.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 The address type.
 @see -[OMCLocationAddress type]
 */
typedef NS_ENUM (NSUInteger, OMCLocationAddressType) {
    /**
     Geo point address type, which consists of a latitude/longitude pair
     of coordinates.
     */
    OMCLocationAddressTypeGeoPoint,

    /**
     Geo circle address type, which consists of a latitude/longitude pair
     of coordinates and a radius in meters.
     */
    OMCLocationAddressTypeGeoCircle,

    /**
     Geo polygon address type, which consists of a set of geo points that
     specify the polygon's vertices.
     */
    OMCLocationAddressTypeGeoPolygon
};

NS_ASSUME_NONNULL_BEGIN

/**
 An address is used to specify the physical location
 of an `OMCLocationPlace`. Addresses are immutable.
 
 @see -[OMCLocationPlace address]
 */
@interface OMCLocationAddress : NSObject

/**
 The address type (geo point, circle, or polygon).
 */
@property (readonly) OMCLocationAddressType type;

/**
 The address's raw properties (corresponding to the JSON payload).
 */
@property (readonly) NSDictionary<NSString*, id>* properties;

@end

NS_ASSUME_NONNULL_END
