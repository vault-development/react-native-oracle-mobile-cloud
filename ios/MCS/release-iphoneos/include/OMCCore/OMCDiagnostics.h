//
//  OMCDiagnostics.h
//  OMCCore
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved. 
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class OMCMobileBackend;

/**
 The Diagnostics interface is responsible for adding the appropriate HTTP headers
 to any MCS URL request.  Note this class is typically used indirectly through
 the OMCMobileBackend setHTTPHeadersOnRequest: method, so this class would not need
 to be used directly.
 */
@interface OMCDiagnostics : NSObject

/** The mobile backend that is being tracked. */
@property (readonly, nonatomic, weak) OMCMobileBackend* mobileBackend;

/**
 The device ID HTTP header value.
 Uses the value returned by `-[UIDevice identifierForVendor]`.
 */
@property (readonly, nonatomic) NSString* deviceID;

/**
 The session ID HTTP header value.
 Uses the value returned by `getpid()`.
 */
@property (readonly, nonatomic) NSString* sessionID;

/**
 The request timestamp HTTP header value.
 Uses the value returned by `+[NSDate date]`.
 */
@property (readonly, nonatomic) NSString* requestTimestamp;


#pragma mark - HTTP headers

/**
 Sets all the required MCS Diagnostics headers on the specified URL request.
 
 @param request The URL request.
 @warning Raises an `NSInvalidArgumentException` if `request` is `nil`.
 @see -[OMCMobileBackend setHTTPHeadersOnRequest:]
 */
- (void)setHTTPHeadersOnRequest:(NSMutableURLRequest*)request;

/**
 Sets the MCS Diagnostics timestamp on the specified URL request.
 
 @param request The URL request.
 @see -[OMCMobileBackend setHTTPHeadersOnRequest:]
 @warning Raises an `NSInvalidArgumentException` if `request` is `nil`.
 */
- (void)setTimestampOnRequest:(NSMutableURLRequest*)request;

@end


#pragma mark - Constants

///---------------------------
/// @name External definitions
///---------------------------

/**
 The Device ID header field name.
 */
extern NSString* const OMCDiagnosticsDeviceIDHTTPHeaderFieldName;

/**
 The Session ID header field name.
 */
extern NSString* const OMCDiagnosticsSessionIDHTTPHeaderFieldName;

/**
 The Client Request Timestamp header field name.
 */
extern NSString* const OMCDiagnosticsClientRequestTimeHTTPHeaderFieldName;

NS_ASSUME_NONNULL_END
