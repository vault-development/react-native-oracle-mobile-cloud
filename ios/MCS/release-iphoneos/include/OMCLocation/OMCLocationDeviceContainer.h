//
//  OMCLocationDeviceContainer.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import "OMCLocationObject.h"
#import "OMCLocationDevice.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A device container is an object that can be associated with one or more
 devices (either an asset or place).
 @see -[OMCLocationDevice container]
 */
@interface OMCLocationDeviceContainer : OMCLocationObject

/**
 The device container's user-defined label.
 */
@property (readonly, nullable) NSString* label;

/**
 Asynchronously fetches the container's devices, invoking the specified completion
 handler block when finished.
 Asynchronously invokes the completion handler immediately if the container's devices
 have already been fetched.
 @param completionHandler The block to be invoked when the devices have been
 fetched. The completion block will be invoked on the main dispatch queue.
 @see -[OMCLocationObject refreshWithCompletionHandler:]
 */
- (void)devicesWithCompletionHandler:(OMCLocationDevicesCompletionBlock)completionHandler;

@end


#pragma mark - Constants

/**
 The name of the device container label JSON property (`label`).
 */
extern NSString* const OMCLocationDeviceContainerLabelPropertyName;

/**
 The name of the device container devices JSON property (`devices`).
 */
extern NSString* const OMCLocationDeviceContainerDevicesPropertyName;

NS_ASSUME_NONNULL_END
