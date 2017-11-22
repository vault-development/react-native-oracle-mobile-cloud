//
//  OMCLocation.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import "OMCCore/OMCServiceProxy.h"
#import "OMCLocationAsset.h"
@class OMCLocationAssetQuery;
#import "OMCLocationDevice.h"
#import "OMCLocationDeviceQuery.h"
#import "OMCLocationPlace.h"
#import "OMCLocationPlaceQuery.h"
@class OMCLocationGeoPoint;

NS_ASSUME_NONNULL_BEGIN

/**
 Library interface to the Oracle Mobile Cloud Location service.
 
 The Location service provides support for associating places, assets,
 devices and beacons.
 */
@interface OMCLocation : OMCServiceProxy

#pragma mark - Asset

/**
 Asynchronously retrieves the asset with the specified ID from the Location service
 and passes it to the specified completion handler.
 @param id_ The ID of the asset to retrieve from the Location service.
 @param completionHandler The block invoked when the request to the
    Location service is finished. The completion block will be invoked on the
    main dispatch queue.
 */
- (void)assetWithID:(NSNumber*)id_
  completionHandler:(OMCLocationAssetCompletionBlock)completionHandler;

/**
 Builds and returns a new asset query that can be configured to retrieve
 a set of assets from the Location service.
 */
- (OMCLocationAssetQuery*)buildAssetQuery;


#pragma mark - Device

/**
 Asynchronously retrieves the device with the specified ID from the Location service
 and passes it to the specified completion handler.
 @param id_ The ID of the device to retrieve from the Location service.
 @param completionHandler The block invoked when the request to the
    Location service is finished. The completion block will be invoked on the
    main dispatch queue.
 */
- (void)deviceWithID:(NSNumber*)id_
   completionHandler:(OMCLocationDeviceCompletionBlock)completionHandler;

/**
 Asynchronously retrieves the devices with the specified beacon from the Location service
 and passes them to the specified completion handler. Typically there will be
 only a single device associated with the beacon.
 @param beacon The beacon of the devices to retrieve from the Location service.
 @param completionHandler The block invoked when the request to the
 Location service is finished. The completion block will be invoked on the
 main dispatch queue.
 */
- (void)devicesWithBeacon:(OMCLocationBeacon*)beacon
        completionHandler:(OMCLocationDeviceQueryCompletionBlock)completionHandler;

/**
 Builds and returns a new device query that can be configured to retrieve
 a set of devices from the Location service.
 */
- (OMCLocationDeviceQuery*)buildDeviceQuery;


#pragma mark - Place

/**
 Asynchronously retrieves the place with the specified ID from the Location service
 and passes it to the specified completion handler.
 @param id_ The ID of the place to retrieve from the Location service.
 @param completionHandler The block invoked when the request to the
    Location service is finished. The completion block will be invoked on the
    main dispatch queue.
 */
- (void)placeWithID:(NSNumber*)id_
  completionHandler:(OMCLocationPlaceCompletionBlock)completionHandler;

/**
 Asynchronously retrieves the place closest to the specified geo point
 from the Location service and passes it to the specified completion handler.
 @param point The geo point to search out from.
 @param completionHandler The block invoked when the request to the
 Location service is finished. The completion block will be invoked on the
 main dispatch queue.
 */
- (void)placeClosestToPoint:(OMCLocationGeoPoint*)point
          completionHandler:(OMCLocationPlaceQueryCompletionBlock)completionHandler;

/**
 Asynchronously retrieves the places in the specified geo fence
 from the Location service and passes them to the specified completion handler.
 @param geoFence The geo fence to search.
 @param completionHandler The block invoked when the request to the
 Location service is finished. The completion block will be invoked on the
 main dispatch queue.
 */
- (void)placesInGeoFence:(OMCLocationGeoCircle*)geoFence
       completionHandler:(OMCLocationPlaceQueryCompletionBlock)completionHandler;

/**
 Builds and returns a new place query that can be configured to retrieve
 a set of places from the Location service.
 */
- (OMCLocationPlaceQuery*)buildPlaceQuery;

@end


#pragma mark - Constants

/**
 The Location library's current version.
 */
extern NSString* const OMCLocationVersion;

/**
 The relative path for the Location REST endpoints.
 This is appended to the Location service's backend's base URL
 (`location`).
 */
extern NSString* const OMCLocationPath;

/**
 The value of the `code` of the `NSError` generated when
 an unexpected status code was returned by the Location service.
 See the values in the `userInfo` dictionary.
 */
extern NSInteger const OMCLocationHTTPRequestError;

/**
 A key to the `userInfo` dictionary in
 the `NSError` generated when an HTTP call generates an unexpected response.
 The corresponding value is the `NSURLRequest` that generated the error.
 */
extern NSString* const OMCLocationHTTPRequestErrorRequest;

/**
 A key to the `userInfo` dictionary in
 the `NSError` generated when an HTTP call generates an unexpected response.
 The corresponding value is the `NSHTTPURLResponse` returned by the HTTP call.
 */
extern NSString* const OMCLocationHTTPRequestErrorResponse;

/**
 A key to the `userInfo` dictionary in
 the `NSError` generated when an HTTP call generates an unexpected response.
 The corresponding value is the `NSData` returned by the HTTP call.
 */
extern NSString* const OMCLocationHTTPRequestErrorResponseData;

/**
 A key to the `userInfo` dictionary in
 the `NSError` generated when an unexpected error is encountered.
 The corresponding value is the `NSError` encountered.
 */
extern NSString* const OMCLocationHTTPRequestErrorCause;

NS_ASSUME_NONNULL_END
