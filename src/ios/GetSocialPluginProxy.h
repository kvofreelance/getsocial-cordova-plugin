//
//  GetSocialPluginProxy.h
//  GetSocial
//
//  Created by Igor on 2/8/16.
//
//

#import <Cordova/CDV.h>
#import <Foundation/Foundation.h>
#import <GetSocial/GetSocialInvitePlugin.h>

@interface GetSocialPluginProxy : GetSocialInvitePlugin
@property (nonatomic, assign) BOOL availableForDeviceStatus;
@property (nonatomic, weak) id <CDVCommandDelegate> commandDelegate;
@property (nonatomic, strong) NSString *callbackId;

@property (nonatomic, strong) GetSocialInviteSuccessCallback successCallback;
@property (nonatomic, strong) GetSocialCancelCallback cancelCallback;
@property (nonatomic, strong) GetSocialErrorCallback errorCallback;

-(id) initWithCommandDelegate:(id<CDVCommandDelegate>) commandDelegate callbackId:(NSString*) callbackId available:(BOOL) GetSocialInvitePlugin;
-(void) initializeCallbackId;

-(BOOL) onComplete:(NSDictionary*) dict;
-(BOOL) onCancel;
-(BOOL) onError;

@end
