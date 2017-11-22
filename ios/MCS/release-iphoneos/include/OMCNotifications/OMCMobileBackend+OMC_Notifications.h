//
//  OMCMobileBackend+OMC_Notifications.h
//  OMCNotifications
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved. 
//

#import "OMCCore/OMCMobileBackend.h"
@class OMCNotifications;

/**
 Extends `OMCMobileBackend` with Notifications-specific methods.
 */
@interface OMCMobileBackend (OMC_Notifications)

/**
 Returns the receiver's notifications service.
 */
- (OMCNotifications*)notifications;

/**
 Removes the receiver's notifications service.
 */
- (void)removeNotifications;

@end
