//
//  GetSocialPluginEvents.m
//  GetSocial
//
//  Created by Igor on 2/8/16.
//
//

#import "GetSocialPluginEvents.h"

@implementation GetSocialPluginEvents

-(void) successWithCallbackId:(NSString*) callbackId {
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    [self.commandDelegate sendPluginResult:result callbackId:callbackId];
}

-(void) errorWithMsg:(NSString*) messsage andCallbackId:(NSString*) callbackId {
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:messsage];
    [self.commandDelegate sendPluginResult:result callbackId:callbackId];
}

-(GetSocialPluginProxy*) getSocialPluginProxy:(NSString*) callbackId {
    if([GetSocialCordova registeredPlugins] == nil)
        return nil;
    
    for(int i=0; i < [[GetSocialCordova registeredPlugins] count]; i++) {
        if([[[[GetSocialCordova registeredPlugins] objectAtIndex:i] callbackId] isEqualToString:callbackId]) {
            return [[GetSocialCordova registeredPlugins] objectAtIndex:i];
        }
    }
    
    return nil;
}

- (void)completeCallback:(CDVInvokedUrlCommand*)command {
    NSString* callbackId = [command callbackId];
    NSString* pluginCallbackId = [[command arguments] objectAtIndex:0];
    
    GetSocialPluginProxy *plugin = [self getSocialPluginProxy:pluginCallbackId];
    if(plugin != nil) {
        [plugin onComplete:nil];
        [self successWithCallbackId:callbackId];
        return;
    }
    
    [self errorWithMsg:@"Not found plugin" andCallbackId:callbackId];
}

- (void)cancelCallback:(CDVInvokedUrlCommand*)command {
    NSString* callbackId = [command callbackId];
    NSString* pluginCallbackId = [[command arguments] objectAtIndex:0];
    
    GetSocialPluginProxy *plugin = [self getSocialPluginProxy:pluginCallbackId];
    if(plugin != nil) {
        [plugin onCancel];
        [self successWithCallbackId:callbackId];
        return;
    }
    
    [self errorWithMsg:@"Not found plugin" andCallbackId:callbackId];
}

- (void)errorCallback:(CDVInvokedUrlCommand*)command {
    NSString* callbackId = [command callbackId];
    NSString* pluginCallbackId = [[command arguments] objectAtIndex:0];
    
    GetSocialPluginProxy *plugin = [self getSocialPluginProxy:pluginCallbackId];
    if(plugin != nil) {
        [plugin onError];
        [self successWithCallbackId:callbackId];
        return;
    }
    
    [self errorWithMsg:@"Not found plugin" andCallbackId:callbackId];
}

- (void)clickedCallback:(CDVInvokedUrlCommand*)command {
    NSString* callbackId = [command callbackId];
    [self successWithCallbackId:callbackId];
}
@end
