//
//  OMCLocationGeoPolygon.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import "OMCLocationAddress.h"
@class OMCLocationGeoPoint;

NS_ASSUME_NONNULL_BEGIN

/**
 A geo polygon, which consists of a list of geographical vertices,
 is one of several ways to specify a place's address.
 Geo polygons are immutable.
 
 @see -[OMCLocationPlace address]
 */
@interface OMCLocationGeoPolygon : OMCLocationAddress

/**
 The polygon's list of vertices.
 */
@property (readonly) NSArray<OMCLocationGeoPoint*>* vertices;

/**
 Constructs a geo polygon with the specified list of vertices.
 @param vertices The polygon's vertices.
 */
+ (instancetype)polygonWithVertices:(NSArray<OMCLocationGeoPoint*>*)vertices;

@end


#pragma mark - Constants

/**
 The name of the geo polygon JSON property (`gpsPolygon`).
 */
extern NSString* const OMCLocationGeoPolygonPropertyName;

/**
 The name of the geo polygon vertices JSON property (`vertices`).
 */
extern NSString* const OMCLocationGeoPolygonVerticesPropertyName;

NS_ASSUME_NONNULL_END
