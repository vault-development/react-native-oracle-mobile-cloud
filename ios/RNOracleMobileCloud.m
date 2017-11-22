
#import "RNOracleMobileCloud.h"
#import <React/RCTLog.h>
#import "OMCCore/OMCAuthorization.h"
#import "OMCCore/OMCMobileBackend.h"
#import "OMCCore/OMCMobileBackendManager.h"
#import "OMCCore/OMCCustomCodeClient.h"
#import "OMCUser.h"

@implementation RNOracleMobileCloud

RCT_EXPORT_MODULE();

OMCAuthorization *auth = nil;

- (NSDictionary *)constantsToExport
{
    return @{ @"HTTP_METHOD_GET": @"GET",
              @"HTTP_METHOD_POST": @"POST",
              @"HTTP_METHOD_DELETE": @"DELETE",
              @"HTTP_METHOD_PUT": @"PUT"};
}

RCT_EXPORT_METHOD(loginUser:(NSString *)user password:(NSString *)password callback:(RCTResponseSenderBlock)callback)
{
    @try {
        
        OMCUserRegistrationCompletionBlockWithUser userBlock = ^(NSError *error, OMCUser *user){
            if (error == nil ) {
                NSDictionary *userDetails = @{ @"user" : user.username,
                                               @"email" : user.email,
                                               @"lastName" : user.lastName,
                                               @"firstName" : user.firstName };
                
                callback(@[@true, userDetails]);
            } else {
                callback(@[@false, error.localizedDescription]);
            }
        };
        
        OMCAuthorizationAuthCompletionBlock authBlock = ^(NSError *error) {
            if (error == nil ) {
                [auth getCurrentUser: userBlock];
            } else {
                callback(@[@false, error.localizedDescription]);
            }
        };
        
        // Get the backend
        OMCMobileBackend* mbe = [[OMCMobileBackendManager sharedManager] defaultMobileBackend];
        
        // Get authorization object
        auth = [mbe authorization];
        
        //Authenticate
        [auth authenticate:user password:password completionBlock:authBlock];
    }
    @catch (NSException *exception) {
        callback(@[@false, exception.reason]);
    }
    
}

RCT_EXPORT_METHOD(loginAnonymous:(RCTResponseSenderBlock)callback)
{
    @try {
        
        OMCAuthorizationAuthCompletionBlock authBlock = ^(NSError *error) {
            if (error == nil ) {
                callback(@[@true, @"Successfully authenticated anonymous"]);
            } else {
                callback(@[@false, error.localizedDescription]);
            }
        };
        
        // Get the backend
        OMCMobileBackend* mbe = [[OMCMobileBackendManager sharedManager] defaultMobileBackend];
        
        // Get authorization object
        OMCAuthorization *auth = [mbe authorization];
        
        //Authenticate
        [auth authenticateAnonymous:authBlock];
    }
    @catch (NSException *exception) {
        callback(@[@false, exception.reason]);
    }
    
}

RCT_EXPORT_METHOD(invokeEndPoint:(NSString *)apiEndPoint body:(NSString *)body  httpMethod:(NSString *)httpMethod callback:(RCTResponseSenderBlock)callback)
{
    @try {
        
        // Get the backend
        OMCMobileBackend* mbe = [[OMCMobileBackendManager sharedManager] defaultMobileBackend];
        
        // Get authorization object
        OMCAuthorization *auth = [mbe authorization];
        
        if(!auth.authorized) {
            callback(@[@false, @"You need to login"]);
        }
        else {
            
            OMCCustomRequestCompletionHandler requestBlock = ^(NSError* error, NSHTTPURLResponse *response, id responseData) {
                if (error == nil) {
                    callback(@[@true, responseData]);
                } else {
                    callback(@[@false, error.localizedDescription]);
                }
            };
            
            OMCCustomCodeClient* ccClient = mbe.customCodeClient;
            
            //NSDictionary *jsonPayload = @{@"myKey", @"myValue"};
            [ccClient invokeCustomRequest: apiEndPoint
                                   method: httpMethod
                                     data: body
                               completion: requestBlock];
        }
    }
    @catch (NSException *exception) {
        callback(@[@false, exception.reason]);
    }
    
}

RCT_EXPORT_METHOD(logout:(RCTResponseSenderBlock)callback) {
    @try {
        
        OMCAuthorizationLogoutCompletionBlock authBlock = ^(NSError *error) {
            if (error == nil ) {
                callback(@[@true, @"Successfully user logout"]);
            } else {
                callback(@[@false, error.localizedDescription]);
            }
        };
        
        // Get the backend
        OMCMobileBackend* mbe = [[OMCMobileBackendManager sharedManager] defaultMobileBackend];
        
        // Get authorization object
        OMCAuthorization *auth = [mbe authorization];
        
        [auth logout:authBlock];
    }
    @catch (NSException *exception) {
        callback(@[@false, exception.reason]);
    }
}

@end
