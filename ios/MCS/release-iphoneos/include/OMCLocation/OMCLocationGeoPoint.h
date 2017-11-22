//
//  OMCLocationGeoPoint.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import "OMCLocationAddress.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A geo point, which is specified as a latitude/longitude pair,
 is one of several ways to specify a place's address.
 Geo points are immutable.
 
 @see -[OMCLocationPlace address]
 */
@interface OMCLocationGeoPoint : OMCLocationAddress

/**
 The point's latitude.
 */
@property (readonly, nullable) NSNumber* latitude;

/**
 The point's longitude.
 */
@property (readonly, nullable) NSNumber* longitude;

/**
 Constructs a new geo point with the specified latitude and longitude.
 @param latitude The point's latitude.
 @param longitude The point's longitude.
 */
+ (instancetype)pointWithLatitude:(NSNumber*)latitude
                        longitude:(NSNumber*)longitude;

@end


#pragma mark - Constants

/**
 The name of the geo point JSON property (`gpsPoint`).
 */
extern NSString* const OMCLocationGeoPointPropertyName;

/**
 The name of the geo point latitude JSON property (`latitude`).
 */
extern NSString* const OMCLocationGeoPointLatitudePropertyName;

/**
 The name of the geo point longitude JSON property (`longitude`).
 */
extern NSString* const OMCLocationGeoPointLongitudePropertyName;

NS_ASSUME_NONNULL_END
