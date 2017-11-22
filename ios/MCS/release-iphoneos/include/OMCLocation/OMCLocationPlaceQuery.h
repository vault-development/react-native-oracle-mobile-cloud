//
//  OMCLocationPlaceQuery.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import "OMCLocationDeviceContainerQuery.h"
#import "OMCLocationPlace.h"
#import "OMCLocationObjectQueryResult.h"
@class OMCLocationGeoPoint;
@class OMCLocationGeoCircle;

NS_ASSUME_NONNULL_BEGIN

/**
 A place query can be configured to search for places.
 */
@interface OMCLocationPlaceQuery : OMCLocationDeviceContainerQuery

/**
 The query's results will be filtered to be the direct children of
 the place with the specified ID.
 @see -[OMCLocationPlace parentWithCompletionHandler:]
 */
@property (nonatomic, nullable) NSNumber* parentID;

/**
 The query's results will be filtered to be the direct children of
 the specified place.
 @param parent The parent of the place to be searched for.
 @see -[OMCLocationPlace parentWithCompletionHandler:]
 */
- (void)setParent:(nullable OMCLocationPlace*)parent;


/**
 The query will search for the place closest to this geo point.
 */
@property (nonatomic, nullable) OMCLocationGeoPoint* geoPoint;

/**
 Sets the query to search for the place closest to the specified geo point.
 @param latitude The geo point's latitude.
 @param longitude The geo point's longitude.
 */
- (void)setGeoPointLatitude:(NSNumber*)latitude
                  longitude:(NSNumber*)longitude;


/**
 The query will search for the places in this geo fence.
 */
@property (nonatomic, nullable) OMCLocationGeoCircle* geoFence;

/**
 Sets the query to search for the places in the specified geo fence.
 @param latitude The latitude of the geo fence's center point.
 @param longitude The longitude of the geo fence's center point.
 @param radius The radius of the geo fence's circle, in meters.
 */
- (void)setGeoFenceLatitude:(NSNumber*)latitude
                  longitude:(NSNumber*)longitude
                     radius:(NSNumber*)radius;


/**
 Asynchronously executes the query, invoking the specified completion
 handler block when finished.
 @param completionHandler The block to be invoked when the query has
 finished executing. The completion block will be invoked on
 the main dispatch queue.
 */
- (void)executeWithCompletionHandler:(void (^)(OMCLocationObjectQueryResult<OMCLocationPlaceQuery*, OMCLocationPlace*>* _Nullable result, NSError* _Nullable error))completionHandler;

@end


#pragma mark - Typedefs

/**
 Convenience typedef that can be used when executing a place query.
 */
typedef OMCLocationObjectQueryResult<OMCLocationPlaceQuery*, OMCLocationPlace*> OMCLocationPlaceQueryResult;

/**
 Completion block invoked when executing a place query.
 */
typedef void (^OMCLocationPlaceQueryCompletionBlock)(OMCLocationPlaceQueryResult* _Nullable result, NSError* _Nullable error);


#pragma mark - Constants

/**
 The name of the place query IDs JSON property (`listOfPlaces`).
 */
extern NSString* const OMCLocationPlaceQueryIDsParmName;

/**
 The name of the place query parent JSON property (`descendantOf`).
 */
extern NSString* const OMCLocationPlaceQueryParentIDParmName;

/**
 The name of the place query geo point JSON property (`nearestTo`).
 */
extern NSString* const OMCLocationPlaceQueryGeoPointParmName;

/**
 The name of the place query geo fence JSON property (`inGeoFence`).
 */
extern NSString* const OMCLocationPlaceQueryGeoFenceParmName;

NS_ASSUME_NONNULL_END
