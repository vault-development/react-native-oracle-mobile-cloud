//
//  OMCCustomCodeClient.h
//  OMCCore
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A detailed callback invoked upon receiving a response on a custom API request
 */
typedef void (^OMCCustomRequestCompletionHandler)(NSError* _Nullable error,
                                                  NSHTTPURLResponse* _Nullable response,
                                                  id _Nullable responseData  // Map or Array of JSON
                                                  );

/**
 This class provides convenience methods to invoke custom API endpoints for the
 currently active mobile backend.  These are not intended to exhaustively cover all
 possible endpoints.  For example, it is assumed only JSON payloads will be sent or
 received.
 */
@interface OMCCustomCodeClient : NSObject

/**
 * A property that configures whether or not to use URL caching.  URL Caching
 * will increase performance for large data objects such as images that are
 * frequently retrieved, but will increase the memory footprint.  It may also cause
 * problems if some sort of caching is already being implemented locally by the app.
 * This setting will be applied to every REST invocation, and may be changed at any
 * time in between invocations.
 *
 * It is assumed that for most MCS custom API methods, caching is not desired, so the default is NO.
 */
@property (nonatomic, readwrite) BOOL useURLCaching;

/**
 Invoke a custom API HTTP request on the supplied data with a callback
 handler.  If the completion handler is set, it will be invoked
 in the UI (main) thread upon completion of the method invocation,
 allowing update of UI items.  The call assumes any input or expected
 output will be in JSON format.  Given the completion handler, this is
 an asynchronous function.
 
 The completion block will contain the format-specific data for a JSON object,
 namely an NSDictionary or NSArray.  Use the completion block for any
 returned data or errors, HTTP or system.
 
 All of the required MCS headers, such as Authorization (assuming the user has authenticated)
 and Diagnostics headers will automatically be inserted into the request.
 
 @param function The "function" is the relative part of the URL to invoke
 (everything after "<base URL from the OMC.plist>/mobile/custom/").
 @param method The HTTP method: "PUT", "POST", "GET", etc..
 @param data a JSON object represented as a dictionary or array for the request.
 Note, for a GET call, the data value must be nil, or the iOS HTTP stack will
 incur a network error.
 @param completion the handler called asynchronously on successful or unsuccessful completion.
 */
-(void) invokeCustomRequest: (NSString *) function
                     method: (NSString *) method
                       data: (nullable id) data
                 completion: (nullable OMCCustomRequestCompletionHandler) completion;

@end

NS_ASSUME_NONNULL_END
