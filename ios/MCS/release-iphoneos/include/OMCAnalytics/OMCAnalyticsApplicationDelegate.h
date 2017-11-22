//
//  OMCAnalyticsAppDelegate.h
//  OMCAnalytics
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved. 
//

#import <UIKit/UIKit.h>
@class OMCAnalytics;
@class OMCMobileBackend;

/**
 An Analytics client application delegate can subclass this application delegate
 and the application's Analytics sessions will correspond with the
 application's being in the device's foreground
 (i.e. a session will start when the app moves to the foreground and
 end when the app moves to the background).
 
 NB: Read the comments of any method in this class that the client application delegate class
 overrides, as some subclass methods must call the `super` implementation for this class
 to behave correctly.
 
 NB: Subclasses of this class must "synthesize" the `window` property declared by
 `UIApplicationDelegate` in the subclass implementation:
 
 `@synthesize window;`
 */
@interface OMCAnalyticsApplicationDelegate : UIResponder <UIApplicationDelegate>

/**
 The application's Oracle Mobile Cloud Analytics service.
 */
@property (readonly, nonatomic) OMCAnalytics* analytics;


/**
 This implementation sets the value of the `analytics` property with the
 Analytics service for the mobile backend that is returned by the `mobileBackend` method.
 
 Subclasses must call `[super application:application didFinishLaunchingWithOptions:launchOptions]`,
 typically at the beginning of the method.
 @param application The singleton app object.
 @param launchOptions A dictionary indicating the reason the app was launched (if any).
 The contents of this dictionary may be empty in situations where the user launched
 the app directly. For information about the possible keys in this dictionary and
 how to handle them, see Launch Options Keys.
 */
- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions;

/**
 This implementation returns the mobile backend with the name returned by the method
 `mobileBackendName`. If the name returned by `mobileBackendName` is `nil`,
 this method returns the default mobile backend.
 
 Subclasses can override this method to return a mobile
 backend other than the one specified by the method `mobileBackendName`.
 This is particularly useful if the application specifies a mobile backend's
 settings programmatically, rather than via the `OMC.plist` file.
 */
- (OMCMobileBackend*)mobileBackend;

/**
 This implementation returns `nil`.
 
 Subclasses can override this method to return a non-`nil` value if a mobile
 backend other than the default is to be used.
 */
- (NSString*)mobileBackendName;
							
/**
 This implementation does nothing.

 Subclasses are free to override this method.
 @param application The singleton app object.
 */
- (void)applicationWillEnterForeground:(UIApplication*)application;

/**
 This implementation starts a new Analytics session.

 Subclasses must call `[super applicationDidBecomeActive:application]`,
 typically at the beginning of the method.
 @param application The singleton app object.
 */
- (void)applicationDidBecomeActive:(UIApplication*)application;

/**
 This implementation does nothing.

 Subclasses are free to override this method.
 @param application The singleton app object.
 */
- (void)applicationWillResignActive:(UIApplication*)application;

/**
 This implementation ends the current Analytics session.

 Subclasses must call `[super applicationDidEnterBackground:application]`,
 typically at the end of the method.
 @param application The singleton app object.
 */
- (void)applicationDidEnterBackground:(UIApplication*)application;

/**
 This implementation does nothing.

 Subclasses are free to override this method.
 @param application The singleton app object.
 */
- (void)applicationWillTerminate:(UIApplication*)application;

@end
