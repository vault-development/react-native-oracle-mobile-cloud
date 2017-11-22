//
//  OMCAppConfig.h
//  OMCCore
//
//  Created by Brian Vosburgh on 6/23/15.
//  Copyright (c) 2015 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Application configuration stored in Mobile Cloud Service.
 The configuration's property values can be changed after the client app
 has been published.
 
 @see -[OMCMobileBackend appConfig]
 */
@interface OMCAppConfig : NSObject

/**
 Returns a `BOOL` for the specified property.
 Returns the specified default value if the property is absent.
 @param property The name of the property, as specified on the server by the mobile backend.
 @param defaultValue The value returned if the property is not specified.
 @warning Raises an `NSInternalInconsistencyException` if the specified property is not a boolean.
 */
- (BOOL)booleanForProperty:(NSString*)property
                   default:(BOOL)defaultValue;

/**
 Returns an `NSInteger` for the specified property.
 Returns the specified default value if the property is absent.
 @param property The name of the property, as specified on the server by the mobile backend.
 @param defaultValue The value returned if the property is not specified.
 @warning Raises an `NSInternalInconsistencyException` if the specified property is not an integer.
 */
- (NSInteger)integerForProperty:(NSString*)property
                        default:(NSInteger)defaultValue;

/**
 Returns a `double` for the specified property.
 Returns the specified default value if the property is absent.
 @param property The name of the property, as specified on the server by the mobile backend.
 @param defaultValue The value returned if the property is not specified.
 @warning Raises an `NSInternalInconsistencyException` if the specified property is not a double.
 */
- (double)doubleForProperty:(NSString*)property
                    default:(double)defaultValue;

/**
 Returns an `NSNumber` for the specified property.
 Returns the specified default value if the property is absent.
 @param property The name of the property, as specified on the server by the mobile backend.
 @param defaultValue The value returned if the property is not specified.
 @warning Raises an `NSInternalInconsistencyException` if the specified property is not a number.
 */
- (nullable NSNumber*)numberForProperty:(NSString*)property
                                default:(nullable NSNumber*)defaultValue;

/**
 Returns a string for the specified property.
 Returns the specified default value if the property is absent.
 @param property The name of the property, as specified on the server by the mobile backend.
 @param defaultValue The value returned if the property is not specified.
 @warning Raises an `NSInternalInconsistencyException` if the specified property is not a string.
 */
- (nullable NSString*)stringForProperty:(NSString*)property
                                default:(nullable NSString*)defaultValue;

@end

NS_ASSUME_NONNULL_END
