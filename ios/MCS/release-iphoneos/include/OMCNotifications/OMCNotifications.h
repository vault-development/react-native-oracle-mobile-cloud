//
//  OMCNotifications.h
//  OMCNotifications
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <OMCCore/OMCServiceProxy.h>

/**
 The format of the completion block called on success.
 @param response The HTTP response object.
 */
typedef void(^OMC_Notifications_SuccessBlock)(NSHTTPURLResponse *response);

/**
 The format of the completion block called on error.
 @param error The standard error object.
 */
typedef void(^OMC_Notifications_ErrorBlock)(NSError* error);

/**
 * This class is used to both register and deregister the device with MCS for push notifications.
 *
 * Note the methods provided here assume that the app has already registered the desired notification
 * types for the app with iOS, and has received the device token bytes via the callback method for this
 * registration.  See the code in the AppDelegate in the GettingStartediOS or GettingStartedSwift for
 * sample code to make these calls.
 */
@interface OMCNotifications : OMCServiceProxy

/**
 Registers the device token with MCS.  This is an asynchronous call.
 @param deviceToken Device token of iOS device.
 @param successCallback (optional) The block to be called on success.
 The format of the callback is ^(NSHTTPURLResponse*).
 @param errorCallback (optional) The block to be called on error.
 The format of the callback is ^(NSError*).
 */
- (void) registerForNotifications:(NSData*) deviceToken
                        onSuccess:(OMC_Notifications_SuccessBlock) successCallback
                          onError:(OMC_Notifications_ErrorBlock) errorCallback;

/**
 De-registers the device token with MCS.  This is an asynchronous call.
 @param deviceToken Device token of iOS device.
 @param successCallback (optional) The block to be called on success.
 @param errorCallback (optional) The block to be called on error.
 */
- (void) deregisterForNotifications:(NSData*) deviceToken
                          onSuccess:(OMC_Notifications_SuccessBlock) successCallback
                            onError:(OMC_Notifications_ErrorBlock) errorCallback;

@end


/**
 The Notifications library's current version.
 */
extern NSString* const OMCNotificationsVersion;
