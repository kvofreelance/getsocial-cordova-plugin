#import "GetSocialCordova.h"

@implementation GetSocialCordova

static NSMutableArray *registeredPlugins = nil;

+ (NSMutableArray *)registeredPlugins {
    if (registeredPlugins == nil) {
        registeredPlugins = [[NSMutableArray alloc] init];
    }
    return registeredPlugins;
}

- (void)alertCordova:(CDVInvokedUrlCommand*)command
{
    NSString* callbackId = [command callbackId];
    NSString* name = [[command arguments] objectAtIndex:0];
    NSString* msg = [NSString stringWithFormat: @"Hello, %@ in Native iOS", name];

    CDVPluginResult* result = [CDVPluginResult
                               resultWithStatus:CDVCommandStatus_OK
                               messageAsString:msg];
    [self.commandDelegate sendPluginResult:result callbackId:callbackId];
}

-(void) successWithCallbackId:(NSString*) callbackId {
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    [self.commandDelegate sendPluginResult:result callbackId:callbackId];
}

-(void) successWithBoolResult:(BOOL) value andCallbackId:(NSString*) callbackId {
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsBool:value];
    [self.commandDelegate sendPluginResult:result callbackId:callbackId];
}
-(void) successWithNSStringResult:(NSString*) value andCallbackId:(NSString*) callbackId {
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:value];
    [self.commandDelegate sendPluginResult:result callbackId:callbackId];
}
-(void) successWithArrayResult:(NSArray*) value andCallbackId:(NSString*) callbackId {
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsMultipart:value];
    [self.commandDelegate sendPluginResult:result callbackId:callbackId];
}
-(void) successWithDictionaryResult:(NSDictionary*) value andCallbackId:(NSString*) callbackId {
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:value];
    [self.commandDelegate sendPluginResult:result callbackId:callbackId];
}
-(void) errorWithMsg:(NSString*) messsage andCallbackId:(NSString*) callbackId {
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:messsage];
    [self.commandDelegate sendPluginResult:result callbackId:callbackId];
}

- (void)init:(CDVInvokedUrlCommand*)command
{
    NSString* callbackId = [command callbackId];
    NSString* key = [[command arguments] objectAtIndex:0];
    
    [[GetSocial sharedInstance] initWithKey:key success:^{
        [self successWithCallbackId:callbackId];
        NSLog(@"GetSocial initialization successful");
    } failure:^(NSError *error) {
        [self errorWithMsg:@"GetSocial initialization failed" andCallbackId:callbackId];
        NSLog(@"GetSocial initialization failed");
    }];
}

-(void) isInitialized:(CDVInvokedUrlCommand*)command {
     NSString* callbackId = [command callbackId];
    [self successWithBoolResult:[[GetSocial sharedInstance] isInitialized] andCallbackId:callbackId];
}

-(void) getVersion:(CDVInvokedUrlCommand*)command {
    NSString* callbackId = [command callbackId];
    NSString* version = [NSString stringWithFormat:@"%d", (int)[GetSocial version]];
    [self successWithNSStringResult:version andCallbackId:callbackId];
}

-(void) getApiVersion:(CDVInvokedUrlCommand*)command {
    NSString* callbackId = [command callbackId];
    [self successWithNSStringResult:[GetSocial sharedInstance].sdkVersion andCallbackId:callbackId];

}
-(void) getEnvironment:(CDVInvokedUrlCommand*)command {
    NSString* callbackId = [command callbackId];
    [self successWithNSStringResult:@"iOS" andCallbackId:callbackId];
}

// //???
// -(void) getConfiguration:(CDVInvokedUrlCommand*)command {
//     NSString* callbackId = [command callbackId];
//     [self successWithNSStringResult:@"" andCallbackId:callbackId];
// }

-(void) setOnReferralDataReceivedListener:(CDVInvokedUrlCommand*)command {
    NSString* callbackId = [command callbackId];
    [[GetSocial sharedInstance] setOnReferralDataReceivedHandler:^(NSArray *referralData) {
        NSLog(@"Referral data received: %@.", referralData);
        [self successWithArrayResult:referralData andCallbackId:callbackId];
    }];
}

-(void) setOnInviteFriendsListener:(CDVInvokedUrlCommand*) command {
    NSString* callbackId = [command callbackId];
    [[GetSocial sharedInstance] setInviteFriendsBlock:^(GetSocialInviteFriendsStatus status, NSInteger number) {
        NSMutableDictionary *property = [[NSMutableDictionary alloc] init];
        [property setObject:[NSNumber numberWithInt:(status - 1)] forKey:@"Event"];
        if(status == GetSocialInviteFriendsStatusSent) {
            [property setObject:[NSNumber numberWithInteger:number] forKey:@"InvitedFriends"];
        }
        
        [self successWithDictionaryResult:property andCallbackId:callbackId];
    }];
}

-(void) getSupportedInviteProviders:(CDVInvokedUrlCommand*)command {
    NSString* callbackId = [command callbackId];
    [self successWithArrayResult:[[GetSocial sharedInstance] getSupportedInviteProviders] andCallbackId:callbackId];
}

-(void) registerPlugin:(CDVInvokedUrlCommand*)command {
    NSString* callbackId = [command callbackId];
    
    NSDictionary *dictionary = [[command arguments] objectAtIndex:0];
    BOOL isAvailableForDevice = [dictionary objectForKey:@"isAvailableForDevice"];
    NSString *provider = [dictionary objectForKey:@"provider"];
    
    GetSocialPluginProxy *getSocialPluginProxy = [[GetSocialPluginProxy alloc] initWithCommandDelegate:self.commandDelegate callbackId:callbackId available:isAvailableForDevice];
    
    [GetSocialCordova.registeredPlugins addObject:getSocialPluginProxy];
    
    [[GetSocial sharedInstance] registerPlugin:getSocialPluginProxy provider:provider];
    
    [getSocialPluginProxy initializeCallbackId];
}

-(void) inviteFriendsUsingProvider:(CDVInvokedUrlCommand*)command {
    NSString* callbackId = [command callbackId];
    NSDictionary* option = [[command arguments] objectAtIndex:0];
    if(option == nil)
        [self errorWithMsg:@"Wrong data" andCallbackId:callbackId];
    
    NSMutableDictionary *properties = [[NSMutableDictionary alloc] init];
    
    NSString* provider = [option objectForKey:@"provider"];
    if([self isEmptyOrNull:provider])
        return;
    
    NSString* subject = [option objectForKey:@"subject"];
    if(![self isEmptyOrNull:subject])
        properties[kGetSocialSubject] = subject;
    
    NSString* text = [option objectForKey:@"text"];
    if(![self isEmptyOrNull:text])
        properties[kGetSocialText] = [NSString stringWithFormat:@"%@", text];
    
    
    NSString *imageUrlString = [option objectForKey:@"image"];
    if([self isEmptyOrNull:imageUrlString]) {
        properties[kGetSocialImage] = [self getImageFromGetSocialPluginParam:imageUrlString];
    }
    
    NSDictionary *referralsArray = [option objectForKey:@"referrals"];
    if(referralsArray != nil) {
        properties[kGetSocialReferralData] = referralsArray;
    }
    
    [[GetSocial sharedInstance] inviteFriendsUsingProvider:provider withProperties:properties];
    [self successWithCallbackId:callbackId];
}

-(void) createSmartInviteView:(CDVInvokedUrlCommand*)command {
    NSString* callbackId = [command callbackId];
    NSDictionary* object = [[command arguments] objectAtIndex:0];
    
    GetSocialSmartInviteViewBuilder *smartIvite = [[GetSocial sharedInstance] createSmartInviteView];
    
    NSString *subject = [object objectForKey:@"subject"];
    if([self isEmptyOrNull:subject])
        smartIvite.subject = subject;
    
    NSString *text = [object objectForKey:@"text"];
    if([self isEmptyOrNull:text])
        smartIvite.text = text;
    
    NSString *title = [object objectForKey:@"title"];
    if([self isEmptyOrNull:title])
        smartIvite.text = title;
    
    NSString *imageUrlString = [object objectForKey:@"image"];
    if([self isEmptyOrNull:imageUrlString]) {
        smartIvite.image = [self getImageFromGetSocialPluginParam:imageUrlString];
    }
    
    NSDictionary *referralData = [object objectForKey:@"referralData"];
    if(referralData != nil && referralData.count != 0)
        smartIvite.referralData = referralData;
    
    [smartIvite show];
    
    [self successWithCallbackId:callbackId];
}

-(BOOL) isEmptyOrNull:(NSString*) data {
    return (data == nil || data.length != 0);
}

-(UIImage*) getImageFromGetSocialPluginParam:(NSString*) data {
    NSString* path = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:data];
    if([[NSFileManager defaultManager] fileExistsAtPath:path]) {
        // it's path
        return [UIImage imageWithContentsOfFile:path];
    } else {
        // it's base64
        if([data containsString:@","]) {
            NSUInteger position = [data rangeOfString:@","].location+1;
            data = [data substringFromIndex:position];
        }
        NSData *dataBase64String = [[NSData alloc] initWithBase64EncodedString:data options:0];
        return [UIImage imageWithData:dataBase64String];
    }
    
    return nil;
}






@end