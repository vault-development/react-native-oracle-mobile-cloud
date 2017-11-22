//
//  OMCLocationDeviceContainerQuery.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import "OMCLocationObjectQuery.h"

/**
 Order-by attribute (ascending or descending). Used in conjunction with the
 order-by order, which specifies the attribute by which the query result's
 items will be sorted.
 By default, the order-by attribute is unspecified and the query result's
 items are returned unsorted.
 @see -[OMCLocationDeviceContainerQuery orderByAttribute]
 */
typedef NS_ENUM (NSUInteger, OMCLocationDeviceContainerQueryOrderByAttributeType) {
    /**
     No order-by attribute is specified. The query result's items will
     be returned unsorted.
     */
    OMCLocationDeviceContainerQueryOrderByAttributeTypeNone,
    
    /**
     Name order-by attribute. The query result's items will be sorted by the
     items' names.
     */
    OMCLocationDeviceContainerQueryOrderByAttributeTypeName,
    
    /**
     Label order-by attribute. The query result's items will be sorted by the
     items' labels.
     */
    OMCLocationDeviceContainerQueryOrderByAttributeTypeLabel,
    
    /**
     Created-on order-by attribute. The query result's items will be sorted by the
     items' created-on dates.
     */
    OMCLocationDeviceContainerQueryOrderByAttributeTypeCreatedOn,
    
    /**
     Modified-on order-by attribute. The query result's items will be sorted by the
     items' modified-on dates.
     */
    OMCLocationDeviceContainerQueryOrderByAttributeTypeModifiedOn,
};

NS_ASSUME_NONNULL_BEGIN

/**
 A device container query can be configured to search for
 device containers (assets or places).
 */
@interface OMCLocationDeviceContainerQuery : OMCLocationObjectQuery

/**
 The query's results will be filtered on a
 match of this string with the location object's user-defined label.
 @see -[OMCLocationDeviceContainer label]
 */
@property (nonatomic, nullable) NSString* label;

/**
 The attribute by which the query results will be sorted when returned.
 The sort order (ascending or descending) is determined by the order-by order.
 
 The default value is `OMCLocationDeviceContainerQueryOrderByAttributeTypeNone`.
 @see -[OMCLocationObjectQuery orderByOrder]
 */
@property (nonatomic) OMCLocationDeviceContainerQueryOrderByAttributeType orderByAttribute;

@end


#pragma mark - Constants

/**
 The name of the device container query label JSON property (`label`).
 */
extern NSString* const OMCLocationDeviceContainerQueryLabelParmName;

NS_ASSUME_NONNULL_END
