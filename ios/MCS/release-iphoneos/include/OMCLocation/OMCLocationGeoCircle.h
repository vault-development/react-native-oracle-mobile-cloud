//
//  OMCLocationGeoCircle.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import "OMCLocationAddress.h"
@class OMCLocationGeoPoint;

NS_ASSUME_NONNULL_BEGIN

/**
 A geo circle, which consists of a geographical center point and a radius,
 is one of several ways to specify a place's address.
 Geo circles are immutable.
 
 @see -[OMCLocationPlace address]
 */
@interface OMCLocationGeoCircle : OMCLocationAddress

/**
 The circle's center point.
 */
@property (readonly, nullable) OMCLocationGeoPoint* center;

/**
 The circle's radius in meters.
 */
@property (readonly, nullable) NSNumber* radius;

/**
 Constructs a new geo circle with the specified latitude, longitude,
 and radius (in meters).
 @param latitude The latitude of the circle's center point.
 @param longitude The longitude of the circle's center point.
 @param radius The circle's radius in meters.
 */
+ (instancetype)circleWithLatitude:(NSNumber*)latitude
                         longitude:(NSNumber*)longitude
                            radius:(NSNumber*)radius;

/**
 Constructs a new geo circle with the specified center point and radius (in meters).
 @param center The circle's center point.
 @param radius The circle's radius in meters.
 */
+ (instancetype)circleWithCenter:(OMCLocationGeoPoint*)center
                          radius:(NSNumber*)radius;

@end


#pragma mark - Constants

/**
 The name of the geo circle JSON property (`gpsCircle`).
 */
extern NSString* const OMCLocationGeoCirclePropertyName;

/**
 The name of the geo circle latitude JSON property (`latitude`).
 */
extern NSString* const OMCLocationGeoCircleLatitudePropertyName;

/**
 The name of the geo circle longitude JSON property (`longitude`).
 */
extern NSString* const OMCLocationGeoCircleLongitudePropertyName;

/**
 The name of the geo circle radius JSON property (`radius`).
 */
extern NSString* const OMCLocationGeoCircleRadiusPropertyName;

NS_ASSUME_NONNULL_END
