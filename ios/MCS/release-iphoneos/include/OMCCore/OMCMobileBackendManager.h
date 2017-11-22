//
//  OMCMobileBackendManager.h
//  OMCCore
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved. 
//

#import <Foundation/Foundation.h>

@class OMCMobileBackend;
@class OMCServiceProxy;
@class OMCAuthorization;

NS_ASSUME_NONNULL_BEGIN

/**
 The mobile backend manager is the entry point to the Oracle Mobile Cloud Service SDK.
 It is responsible for building and holding the various mobile backends.
 */
@interface OMCMobileBackendManager : NSObject

/**
 The mobile backend manager's default mobile backend. This is the mobile backend
 designated as the the "default" mobile backend in the OMC property list file
 (`OMC.plist`).
 
 The default mobile backend can be designated by adding a boolean flag named
 `default` to the corresponding mobile backend's dictionary in the OMC property
 list file (`OMC.plist`) and setting its value to `YES`. The manager's default
 mobile backend is undefined if more than one mobile backend is designated "default"
 or if no mobile backend is designated "default".
 */
@property (readonly, nonatomic, nullable) OMCMobileBackend* defaultMobileBackend;

/**
 The mobile backend manager's properties, as specified by the OMC property list file
 (`OMC.plist`).
 */
@property (readonly, nonatomic) NSDictionary<NSString*, id>* properties;

/**
 The mobile backend manager's log level. This log level controls the volume of log entries
 produced by the Oracle Mobile Cloud Service SDK. The log level can be set to one of the following
 levels: none, error, warning, info, debug.
 This log level can be either initialized
 from the default property list file (`OMC.plist`) or set directly at
 runtime via this property. If it is not set explicitly, the log level is `error`.
 */
@property (nonatomic) NSString* logLevel;

/**
 Returns the singleton mobile backend manager.
 */
+ (OMCMobileBackendManager*)sharedManager;


#pragma mark - Mobile backends

/**
 Returns the receiver's mobile backend for the specified name, if present.

 Returns `nil` if the receiver does not contain a mobile backend for the specified name.
 @param name The name of the mobile backend.
 @warning Raises an `NSInvalidArgumentException` if `name` is `nil`.
 */
- (nullable OMCMobileBackend*)mobileBackendForName:(NSString*)name;

/**
 Adds to the receiver and returns a new mobile backend for the specified name
 and initialized with the specified properties.
 The properties must be in the same form as the properties in the OMC property
 list file (`OMC.plist`).

 If the receiver already contains a mobile backend with the specified name, replaces
 it with the newly created mobile backend.
 
 If the specified properties indicate the new mobile backend should be the default
 mobile backend, the new mobile backend will replace the current default mobile backend.
 
 If the receiver does not yet have a default mobile backend, the new mobile backend
 will become the default mobile backend, even if the specified properties do not
 indicate the new mobile backend should be the default.
 @param name The name of the new mobile backend.
 @param properties The new mobile backend's initial properties.
 @warning Raises an `NSInvalidArgumentException` if either `name` or `properties` is `nil`.
 */
- (OMCMobileBackend*)addMobileBackendForName:(NSString*)name
                                  properties:(NSDictionary<NSString*, id>*)properties;

/**
 Removes from the receiver the specified mobile backend.

 Does nothing if the receiver does not contain the specified mobile backend.
 @param mobileBackend The mobile backend.
 @warning Raises an `NSInvalidArgumentException` if `mobileBackend` is `nil`.
 */
- (void)removeMobileBackend:(OMCMobileBackend*)mobileBackend;

/**
 Removes from the receiver the mobile backend for the specified name.

 Does nothing if the receiver does not contain a mobile backend for the specified name.
 @param name The name of the mobile backend.
 @warning Raises an `NSInvalidArgumentException` if `name` is `nil`.
 */
- (void)removeMobileBackendForName:(NSString*)name;

@end

#pragma mark - Constants


/**
 The mobile backend manager's `mobileBackends` property name.
 */
extern NSString* const OMCMobileBackendManagerMobileBackendsPropertyName;

/**
 The mobile backend manager's `logLevel` property name.
 */
extern NSString* const OMCMobileBackendManagerLogLevelPropertyName;

/**
 Use this constant to set the mobile backend manager's log level to "none".
 */
extern NSString* const OMCMobileBackendManagerLogLevelNone;

/**
 Use this constant to set the mobile backend manager's log level to "error".
 */
extern NSString* const OMCMobileBackendManagerLogLevelError;

/**
 Use this constant to set the mobile backend manager's log level to "warning".
 */
extern NSString* const OMCMobileBackendManagerLogLevelWarning;

/**
 Use this constant to set the mobile backend manager's log level to "info".
 */
extern NSString* const OMCMobileBackendManagerLogLevelInfo;

/**
 Use this constant to set the mobile backend manager's log level to "debug".
 */
extern NSString* const OMCMobileBackendManagerLogLevelDebug;

/**
 This constant specifies the mobile backend manager's default log level (i.e. "error").
 */
extern NSString* const OMCMobileBackendManagerLogLevelDefault;

NS_ASSUME_NONNULL_END
