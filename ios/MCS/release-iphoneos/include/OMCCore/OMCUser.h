//
//  OMCUser.h
//  OMCCore
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved. 
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An MCS user has a name and a set of properties.  A user is retrieved
 from the MCS server and is not stored locally.  Note a user cannot be
 constructed directly - it is retrieved via the method
 `[OMCAuthorization getCurrentUser:]`.  Also note the standard properties -
 currently firstName, lastName and email - as well as the other properties
 may not be modified.
*/
@interface OMCUser : NSObject

/**
 The user's name. The name cannot be modified.
 */
@property (readonly, nonatomic) NSString* username;

/**
 First name of user.  Cannot be modified.
 */
@property (readonly, nonatomic, nullable) NSString* firstName;

/**
 Last name of user.  Cannot be modified.
 */
@property (readonly, nonatomic, nullable) NSString* lastName;

/**
 User's email, must conform to RFC 822 standard.  Cannot be modified.
 */
@property (readonly, nonatomic, nullable) NSString* email;


/**
 The user's other properties.  The standard properties (currently
 email, first and last name) should not be added to the properties
 dictionary, and will be overwritten by the standalone properties
 for those.
 */
@property (readonly, nonatomic) NSMutableDictionary* properties;

@end

NS_ASSUME_NONNULL_END
