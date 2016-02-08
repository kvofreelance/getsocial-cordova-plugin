//
//  GetSocialPluginProxy.m
//  GetSocial
//
//  Created by Igor on 2/8/16.
//
//

#import "GetSocialPluginProxy.h"

@implementation GetSocialPluginProxy

-(id) initWithCommandDelegate:(id<CDVCommandDelegate>) commandDelegate callbackId:(NSString*) callbackId available:(BOOL) availableForDeviceStatus {
    self = [super init];
    if (self) {
        [self setAvailableForDeviceStatus:availableForDeviceStatus];
        [self setCallbackId:callbackId];
        [self setCommandDelegate:commandDelegate];
    }
    return self;
}

-(BOOL) onComplete:(NSDictionary*) dict {
    if([self successCallback] == nil)
        return false;
    
    self.successCallback(dict);
    return true;
}

-(BOOL) onCancel {
    if([self cancelCallback] == nil)
        return false;
    
    self.cancelCallback();
    return true;
}

-(BOOL) onError {
    if([self errorCallback] == nil)
        return false;
    
    self.errorCallback([[NSError alloc] init]);
    return true;
}

-(void) inviteFriendsWithSubject:(NSString *)subject text:(NSString *)text referralDataUrl:(NSString *)referralDataUrl image:(UIImage *)image onViewController:(UIViewController *)onViewController success:(GetSocialInviteSuccessCallback)successCallback cancel:(GetSocialCancelCallback)cancelCallback error:(GetSocialErrorCallback)errorCallback {
    
    [self setSuccessCallback:successCallback];
    [self setCancelCallback:cancelCallback];
    [self setErrorCallback:errorCallback];
    
    NSMutableDictionary *property = [[NSMutableDictionary alloc] init];
    
    property[@"action"] = @"inviteFriends";
    property[@"subject"] = subject;
    property[@"text"] = text;
    property[@"referralDataUrl"] = referralDataUrl;
    property[@"image"] = [self convertUIImageToBase64:image];
    
    CDVPluginResult *result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:property];
    [result setKeepCallbackAsBool:YES];
    [self sentResult:result];
}

-(void) sentResult:(CDVPluginResult*) pluginResult  {
    if (self.commandDelegate != nil) {
        [self.commandDelegate sendPluginResult:pluginResult callbackId:[self callbackId]];
    }
}

-(NSString*) convertUIImageToBase64:(UIImage*) image {
    return @"";
}

-(void) initializeCallbackId {
    NSDictionary *property = @{@"action":@"initCallbackId", @"callbackId":[self callbackId]};
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:property];
    [result setKeepCallbackAsBool:YES];
    [self sentResult:result];
}

-(BOOL) isAvailableForDevice {
    return self.availableForDeviceStatus;
}

@end
