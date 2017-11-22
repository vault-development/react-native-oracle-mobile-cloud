//
//  OMCLocationDeviceQuery.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import "OMCLocationObjectQuery.h"
#import "OMCLocationDevice.h"
@class OMCLocationAsset;

/**
 The device beacon protocol type.
 @see -[OMCLocationDeviceQuery protocol]
 */
typedef NS_ENUM (NSUInteger, OMCLocationDeviceQueryProtocolType) {
    /**
     The device does not yet specify a beacon type.
     */
    OMCLocationDeviceQueryProtocolTypeNone,

    /**
     The AltBeacon type.
     */
    OMCLocationDeviceQueryProtocolTypeAltBeacon,
    
    /**
     The Eddystone Beacon type.
     */
    OMCLocationDeviceQueryProtocolTypeEddystoneBeacon,
    
    /**
     The iBeacon type.
     */
    OMCLocationDeviceQueryProtocolTypeIBeacon
};


/**
 Order-by attribute (ascending or descending). Used in conjunction with the
 order-by order, which specifies the attribute by which the query result's
 items will be sorted.
 By default, the order-by attribute is unspecified and the query result's
 items are returned unsorted.
 @see -[OMCLocationDeviceQuery orderByAttribute]
 */
typedef NS_ENUM (NSUInteger, OMCLocationDeviceQueryOrderByAttributeType) {
    /**
     No order-by attribute is specified. The query result's items will
     be returned unsorted.
     */
    OMCLocationDeviceQueryOrderByAttributeTypeNone,

    /**
     Name order-by attribute. The query result's items will be sorted by the
     items' names.
     */
    OMCLocationDeviceQueryOrderByAttributeTypeName,
    
    /**
     Protocol order-by attribute. The query result's items will be sorted by the
     items' protocols.
     */
    OMCLocationDeviceQueryOrderByAttributeTypeProtocol,
    
    /**
     Created-on order-by attribute. The query result's items will be sorted by the
     items' created-on dates.
     */
    OMCLocationDeviceQueryOrderByAttributeTypeCreatedOn,
    
    /**
     Modified-on order-by attribute. The query result's items will be sorted by the
     items' modified-on dates.
     */
    OMCLocationDeviceQueryOrderByAttributeTypeModifiedOn,
};

NS_ASSUME_NONNULL_BEGIN

/**
 A device query can be configured to search for devices.
 */
@interface OMCLocationDeviceQuery : OMCLocationObjectQuery

/**
 The query's results will be filtered on a
 match of this value with the device's beacon protocol.

 The default value is `OMCLocationDeviceQueryProtocolTypeNone`.
 @see -[OMCLocationDevice beacon]
 */
@property (nonatomic) OMCLocationDeviceQueryProtocolType protocol;


/**
 The query will search for the device associated with this asset ID.
 */
@property (nonatomic, nullable) NSNumber* assetID;

/**
 The query will search for the device associated with the specified asset.
 @param asset The asset associated with the device the query will search for.
 @see assetID
 */
- (void)setAsset:(nullable OMCLocationAsset*)asset;


/**
 The query will search for the device for this beacon.
 */
@property (nonatomic, nullable) OMCLocationBeacon* beacon;

/**
 The attribute by which the query results will be sorted when returned.
 The sort order (ascending or descending) is determined by the order-by order.
 
 The default value is `OMCLocationDeviceQueryOrderByAttributeTypeNone`.
 @see -[OMCLocationObjectQuery orderByOrder]
 */
@property (nonatomic) OMCLocationDeviceQueryOrderByAttributeType orderByAttribute;

/**
 Asynchronously executes the query, invoking the specified completion
 handler block when finished.
 @param completionHandler The block to be invoked when the query has
 finished executing. The completion block will be invoked on
 the main dispatch queue.
 */
- (void)executeWithCompletionHandler:(void (^)(OMCLocationObjectQueryResult<OMCLocationDeviceQuery*, OMCLocationDevice*>* _Nullable result, NSError* _Nullable error))completionHandler;

@end


#pragma mark - Typedefs

/**
 Convenience typedef that can be used when executing a device query.
 */
typedef OMCLocationObjectQueryResult<OMCLocationDeviceQuery*, OMCLocationDevice*> OMCLocationDeviceQueryResult;

/**
 Completion block invoked when executing a device query.
 */
typedef void (^OMCLocationDeviceQueryCompletionBlock)(OMCLocationDeviceQueryResult* _Nullable result, NSError* _Nullable error);


#pragma mark - Constants

/**
 The name of the device query IDs JSON property (`listOfDevices`).
 */
extern NSString* const OMCLocationDeviceQueryIDsParmName;

/**
 The name of the device query protocol JSON property (`protocol`).
 */
extern NSString* const OMCLocationDeviceQueryProtocolParmName;

/**
 The name of the device query asset ID JSON property (`associatedAssetId`).
 */
extern NSString* const OMCLocationDeviceQueryAssetIDParmName;

NS_ASSUME_NONNULL_END
