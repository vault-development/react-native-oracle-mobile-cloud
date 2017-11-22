//
//  OMCMobileBackend+OMC_Location.h
//  OMCLocation
//
//  Copyright © 2016 Oracle. All rights reserved.
//

#import "OMCCore/OMCMobilebackend.h"
@class OMCLocation;

NS_ASSUME_NONNULL_BEGIN

/**
 Extends `OMCMobileBackend` with Location-specific methods.
 */
@interface OMCMobileBackend (OMC_Location)

/**
 Returns the receiver's location service.
 */
- (OMCLocation*)location;

/**
 Removes the receiver's location service.
 */
- (void)removeLocation;

@end

NS_ASSUME_NONNULL_END
