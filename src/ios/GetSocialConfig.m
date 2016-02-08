//
//  GetSocialConfiguration.m
//  GetSocial
//
//  Created by Igor on 2/8/16.
//
//

#import "GetSocialConfig.h"

@implementation GetSocialConfig

-(void) successWithCallbackId:(NSString*) callbackId {
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    [self.commandDelegate sendPluginResult:result callbackId:callbackId];
}

-(void) setConfiguration:(CDVInvokedUrlCommand*)command {
    NSString* callbackId = [command callbackId];
    
    NSString* path = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:[[command arguments] objectAtIndex:0]];
    
    GetSocialConfiguration *config = [GetSocial sharedInstance].configuration;
    [config setConfiguration:path];
    
    [self successWithCallbackId:callbackId];
}

-(void) clear:(CDVInvokedUrlCommand*) command {
    NSString* callbackId = [command callbackId];
    
    [[[GetSocial sharedInstance] configuration] clear];
    
    [self successWithCallbackId:callbackId];
}

-(void) beginTransaction:(CDVInvokedUrlCommand*) command {
    NSString* callbackId = [command callbackId];
    
    [[[GetSocial sharedInstance] configuration] beginTransaction];
    
    [self successWithCallbackId:callbackId];
}

-(void) endTransaction:(CDVInvokedUrlCommand*) command {
    NSString* callbackId = [command callbackId];
    
    [[[GetSocial sharedInstance] configuration] endTransaction];
    
    [self successWithCallbackId:callbackId];
}

-(void) setBasePath:(CDVInvokedUrlCommand*) command {
    NSString* callbackId = [command callbackId];
    NSString* basePath = [[command arguments] objectAtIndex:0];
    
    [[[GetSocial sharedInstance] configuration] setBasePath:basePath];
    
    [self successWithCallbackId:callbackId];
}

-(void) setImagePath:(CDVInvokedUrlCommand*) command {
    NSString* callbackId = [command callbackId];
    NSString* elementId = [[command arguments] objectAtIndex:0];
    NSString* imagePath = [[command arguments] objectAtIndex:1];
    
    [[[GetSocial sharedInstance] configuration] setImagePath:imagePath forElementID:elementId];
    
    [self successWithCallbackId:callbackId];
}

-(void) setBaseDesign:(CDVInvokedUrlCommand*) command {
    NSString* callbackId = [command callbackId];
    
    CGFloat width = [[[command arguments] objectAtIndex:0] floatValue];
    CGFloat height = [[[command arguments] objectAtIndex:1] floatValue];
    CGFloat ppi = [[[command arguments] objectAtIndex:2] floatValue];
    NSString* scaleMode = [[command arguments] objectAtIndex:3];
    
    [[[GetSocial sharedInstance] configuration] setBaseDesign:width height:height ppi:ppi scaleMode:scaleMode];
    
    [self successWithCallbackId:callbackId];
}

-(void) setDimension:(CDVInvokedUrlCommand*) command {
    NSString* callbackId = [command callbackId];
    NSString* elementId = [[command arguments] objectAtIndex:0];
    CGFloat dimension = [[[command arguments] objectAtIndex:1] floatValue];
    
    [[[GetSocial sharedInstance] configuration] setDimension:dimension forElementID:elementId];
    
    [self successWithCallbackId:callbackId];
}

-(void) setAspectRatio:(CDVInvokedUrlCommand*) command {
    NSString* callbackId = [command callbackId];
    NSString* elementId = [[command arguments] objectAtIndex:0];
    CGFloat aspectRatio = [[[command arguments] objectAtIndex:1] floatValue];
    
    [[[GetSocial sharedInstance] configuration] setAspectRatio:aspectRatio forElementID:elementId];
    
    [self successWithCallbackId:callbackId];
}

-(void) setTextStyle:(CDVInvokedUrlCommand*) command {
    NSString* callbackId = [command callbackId];
    NSString* elementId = [[command arguments] objectAtIndex:0];
    NSString* textStyle = [[command arguments] objectAtIndex:1];
    CGFloat fontSize = [[[command arguments] objectAtIndex:2] floatValue];
    UIColor* fontColor =  [[command arguments] objectAtIndex:3];
    UIColor* strokeColor = [[command arguments] objectAtIndex:4];
    CGFloat strokeSize = [[[command arguments] objectAtIndex:5] floatValue];
    CGSize* strokeOffset = (__bridge CGSize *)([[command arguments] objectAtIndex:6]);
    
    [[[GetSocial sharedInstance] configuration] setTextStyle:textStyle fontSize:fontSize fontColor:fontColor strokeColor:strokeColor strokeSize:strokeSize strokeOffset:*strokeOffset forElementID:elementId];
    
    [self successWithCallbackId:callbackId];
}

-(void) setAnimationStyle:(CDVInvokedUrlCommand*) command {
    NSString* callbackId = [command callbackId];
    NSString* elementId = [[command arguments] objectAtIndex:0];
    CGFloat animationStyle = [[[command arguments] objectAtIndex:1] floatValue];
    
    [[[GetSocial sharedInstance] configuration] setAnimationStyle:animationStyle forElementID:elementId];
    
    
    [self successWithCallbackId:callbackId];
}

-(void) setInsets:(CDVInvokedUrlCommand*) command {
    NSString* callbackId = [command callbackId];
    NSString* elementId = [[command arguments] objectAtIndex:0];
    CGFloat top = [[[command arguments] objectAtIndex:1] floatValue];
    CGFloat right = [[[command arguments] objectAtIndex:2] floatValue];
    CGFloat bottom = [[[command arguments] objectAtIndex:3] floatValue];
    CGFloat left = [[[command arguments] objectAtIndex:4] floatValue];
    
    [[[GetSocial sharedInstance] configuration] setInsets:top right:right bottom:bottom left:left forElementID:elementId];
    
    [self successWithCallbackId:callbackId];
}

@end
