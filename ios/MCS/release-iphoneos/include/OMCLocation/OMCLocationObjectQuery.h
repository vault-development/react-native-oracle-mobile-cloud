//
//  OMCLocationObjectQuery.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMCLocationObject.h"
@class OMCLocation;
@class OMCLocationObjectQuery;

/**
 Query format (long or short). Query results in long format will include all
 the items' attributes. Query results in short format will include only
 a subset of the items' attributes, depending on the objects' type.
 The default query format is long.
 @see -[OMCLocationObjectQuery format]
 */
typedef NS_ENUM (NSUInteger, OMCLocationObjectQueryFormatType) {
    /**
     Long format: the query results will include all the items' attributes.
     */
    OMCLocationObjectQueryFormatTypeLong,

    /**
     Short format: the query results will include only a subset of the items'
     attributes, depending on the items' type.
     */
    OMCLocationObjectQueryFormatTypeShort
};


/**
 Order-by order (ascending or descending). Used in conjunction with the
 order-by attribute, which specifies the attribute by which the query result's
 items will be sorted.
 The default order is ascending.
 @see -[OMCLocationObjectQuery orderByOrder]
 */
typedef NS_ENUM (NSUInteger, OMCLocationObjectQueryOrderByOrderType) {
    /**
     Ascending order-by. The query result's items will be sorted by the
     order-by attribute in ascending order.
     */
    OMCLocationObjectQueryOrderByOrderTypeAscending,

    /**
     Descending order-by. The query result's items will be sorted by the
     order-by attribute in descending order.
     */
    OMCLocationObjectQueryOrderByOrderTypeDescending
};

NS_ASSUME_NONNULL_BEGIN

/**
 A location object query can be configured to search for the
 various location objects (assets, devices, or places).
 */
@interface OMCLocationObjectQuery : NSObject

/**
 The location service against which the query will execute.
 */
@property (readonly) OMCLocation* location;

/**
 The query's raw properties (corresponding to the JSON payload).
 */
@property (readonly) NSDictionary<NSString*, id>* properties;

/**
 The query's results will be filtered on a case-insensitive partial
 match of this string with the location object's user-defined name.
 @see -[OMCLocationObject name]
 */
@property (nonatomic, nullable) NSString* name;

/**
 The query's results will be filtered on a case-insensitive partial
 match of this string with the location object's user-defined description.
 @see -[OMCLocationObject description_]
 */
@property (nonatomic, nullable) NSString* description_;

/**
 The query's results will be filtered on a case-insensitive partial
 match of this string with the location object's user-defined name
 or description.
 @see -[OMCLocationObject name]
 @see -[OMCLocationObject description_]
 */
@property (nonatomic, nullable) NSString* search;


#pragma mark - Attributes

/**
 The query's results will be filtered on a match of these attribute
 values with the location object's user-defined attribute values.
 @see -[OMCLocationObject attributes]
 */
@property (readonly) NSDictionary<NSString*, NSString*>* attributes;

/**
 Set the specified attribute's value.
 @param value The attribute's user-defined value.
 @param key The attribute's user-defined key.
 @see attributes
 */
- (void)setAttribute:(NSString*)value forKey:(NSString*)key;

/**
 Remove the specified attribute's value.
 @param key The attribute's user-defined key.
 @see attributes
 */
- (void)removeAttributeForKey:(NSString*)key;

/**
 Set all the query's attributes to the specified attributes.
 @param attributes The query's new set of attributes.
 @see attributes
 */
- (void)setAttributes:(NSDictionary<NSString*, NSString*>*)attributes;

/**
 Add to the query's attributes the specified set of attributes.
 @param attributes The set of attributes to be added to the query's
 current set of attributes.
 @see attributes
 */
- (void)addAttributes:(NSDictionary<NSString*, NSString*>*)attributes;

/**
 Remove all the attribute values.
 @see attributes
 */
- (void)clearAttributes;


#pragma mark - IDs

/**
 The query's results will be filtered to match this list of
 location object IDs.
 @see -[OMCLocationObject id_]
 */
@property (readonly) NSArray<NSNumber*>* ids;

/**
 Add the specified ID to the list of IDs the query will search for.
 @param id_ The ID to add to the query's list of IDs.
 @see ids
 */
- (void)addID:(NSNumber*)id_;

/**
 Insert the specified ID at the specified index of the list of
 IDs the query will search for.
 @param id_ The ID to add to the query's list of IDs.
 @param index The index at which to insert the new ID.
 @see ids
 */
- (void)insertID:(NSNumber*)id_ atIndex:(NSUInteger)index;

/**
 Remove the specified ID from the list of IDs the query will search for.
 @param id_ The ID to remove from the query's list of IDs.
 @see ids
 */
- (void)removeID:(NSNumber*)id_;

/**
 Remove the ID at the specified index from the list of IDs
 the query will search for.
 @param index The index of the ID to remove from the query's list of IDs.
 @see ids
 */
- (void)removeIDAtIndex:(NSUInteger)index;

/**
 Set all the query's IDs to the specified IDs.
 @param ids The query's new list of IDs.
 @see ids
 */
- (void)setIDs:(NSArray<NSNumber*>*)ids;

/**
 Add to the query's IDs the specified list of IDs.
 @param ids The set of IDs to be added to the query's
 current list of IDs.
 @see ids
 */
- (void)addIDs:(NSArray<NSNumber*>*)ids;

/**
 Remove all the IDs.
 @see ids
 */
- (void)clearIDs;


#pragma mark - Query Meta Data

/**
 The format of the results returned by the query, which can be `"long"` or `"short"`.
 When the requested format is `"short"`, only a subset of the properties of
 each object will be populated. The `'id'`, `'name'`, and `'description'`
 will be populated, along with any subclass-specific properties.
 
 The default value is `OMCLocationObjectQueryFormatTypeLong`.
 */
@property (nonatomic) OMCLocationObjectQueryFormatType format;

/**
 The order (ascending or descending) in which the query result's items will be
 sorted. This property determines only the *order* of the
 query result's items. The specific property by which the result's items
 will be sorted is determined by the value of `orderByAttribute`, which is
 defined by `OMCLocationDeviceContainerQuery` or `OMCLocationDeviceQuery`.
 
 The default value is `OMCLocationObjectQueryOrderByOrderTypeAscending`.
 @see -[OMCLocationDeviceContainerQuery orderByAttribute]
 @see -[OMCLocationDeviceQuery orderByAttribute]
 */
@property (nonatomic) OMCLocationObjectQueryOrderByOrderType orderByOrder;

/**
 Zero-based index of the first item to return in the results.
 
 The default value is `0`.
 */
@property (nonatomic, nullable) NSNumber* offset;

/**
 The maximum number of items to return (in the range `0` to `100`).
 If the requested limit is greater than `100`, then `100` is substituted.
 
 The default value is determined by server.
 */
@property (nonatomic, nullable) NSNumber* limit;

@end


#pragma mark - Constants

/**
 The name of the object query name JSON property (`name`).
 */
extern NSString* const OMCLocationObjectQueryNameParmName;

/**
 The name of the object query description JSON property (`description`).
 */
extern NSString* const OMCLocationObjectQueryDescriptionParmName;

/**
 The name of the object query search JSON property (`search`).
 */
extern NSString* const OMCLocationObjectQuerySearchParmName;

/**
 The name of the object query attributes JSON property (`attributes`).
 */
extern NSString* const OMCLocationObjectQueryAttributesParmName;

/**
 The name of the object query format JSON property (`format`).
 */
extern NSString* const OMCLocationObjectQueryFormatParmName;

/**
 The name of the object query order-by JSON property (`orderBy`).
 */
extern NSString* const OMCLocationObjectQueryOrderByParmName;

/**
 The name of the object query offset JSON property (`offset`).
 */
extern NSString* const OMCLocationObjectQueryOffsetParmName;

/**
 The name of the object query limit JSON property (`limit`).
 */
extern NSString* const OMCLocationObjectQueryLimitParmName;

NS_ASSUME_NONNULL_END
