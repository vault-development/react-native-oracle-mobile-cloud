//
//  OMCLocationObjectQueryResult.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>
@class OMCLocationObjectQuery;
@class OMCLocationObject;

NS_ASSUME_NONNULL_BEGIN

/**
 A query result represents the results returned from the Location
 service for a particular query.
 Query results are immutable.
 
 @see -[OMCLocationAssetQuery executeWithCompletionHandler:]
 @see -[OMCLocationDeviceQuery executeWithCompletionHandler:]
 @see -[OMCLocationPlaceQuery executeWithCompletionHandler:]
 */
@interface OMCLocationObjectQueryResult<__covariant QueryType:OMCLocationObjectQuery*, __covariant ItemType:OMCLocationObject*> : NSObject

/**
 The query that generated the result.
 */
@property (readonly) QueryType query;

/**
 The items (assets, devices, or places) that match the original query's search
 arguments.
 */
@property (readonly) NSArray<ItemType>* items;

/**
 The result's raw properties (corresponding to the JSON payload).
 */
@property (readonly) NSDictionary<NSString*, id>* properties;

/**
 The total number of items that match the original query's search arguments,
 but may not all be returned in the result.
 */
@property (readonly) NSNumber* totalResults;

/**
 The offset of the items contained by the result.
 */
@property (readonly) NSNumber* offset;

/**
 The number of items contained by the result.
 */
@property (readonly) NSNumber* count;

/**
 The requested limit of how many items were to be returned by the query.
 */
@property (readonly) NSNumber* limit;

/**
 Flag indicating whether there are more items to be fetched from the server
 that match the original query's search arguments.
 @see nextQuery
 @see nextWithCompletionHandler:
 */
@property (readonly) BOOL hasMore;

/**
 Query that, when executed, will fetch the result's "next" set of items.
 @see hasMore
 @see totalResults
 @see nextWithCompletionHandler:
 */
@property (readonly) QueryType nextQuery;

/**
 Asynchronously fetches the result's "next" set of items,
 invoking the specified completion handler block when finished.
 @param completionHandler The block to be invoked when the query has
 finished executing. The completion block will be invoked on
 the main dispatch queue.
 @see hasMore
 @see totalResults
 @see nextQuery
 */
- (void)nextWithCompletionHandler:(void (^)(OMCLocationObjectQueryResult<QueryType, ItemType>* _Nullable result, NSError* _Nullable error))completionHandler;

@end


#pragma mark - Constants

/**
 The name of the query result total results JSON property (`totalResults`).
 */
extern NSString* const OMCLocationObjectQueryResultTotalResultsPropertyName;

/**
 The name of the query result count JSON property (`offset`).
 */
extern NSString* const OMCLocationObjectQueryResultOffsetPropertyName;

/**
 The name of the query result count JSON property (`count`).
 */
extern NSString* const OMCLocationObjectQueryResultCountPropertyName;

/**
 The name of the query result limit JSON property (`limit`).
 */
extern NSString* const OMCLocationObjectQueryResultLimitPropertyName;

/**
 The name of the query result has-more JSON property (`hasMore`).
 */
extern NSString* const OMCLocationObjectQueryResultHasMorePropertyName;

NS_ASSUME_NONNULL_END
