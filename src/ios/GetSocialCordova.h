#import <Cordova/CDV.h>
#import <Foundation/Foundation.h>
#import <GetSocial/GetSocial.h>
#import "GetSocialPluginProxy.h"

@interface GetSocialCordova : CDVPlugin
+ (NSMutableArray*)registeredPlugins;

-(void) successWithCallbackId:(NSString*) callbackId;
-(void) errorWithMsg:(NSString*) messsage andCallbackId:(NSString*) callbackId;
@end