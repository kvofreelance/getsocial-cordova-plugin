//
//  GetSocialPlugin.h
//  GetSocialSDK
//
//  Created by Jan-Eric Duden on 26/05/14.
//  Copyright (c) 2014 GetSocial. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GetSocialConstants.h"
/**
 * This protocol provides the base protocol for all plugins of by the GetSocial SDK.
 */

@interface GetSocialPlugin : NSObject

/** The name of the plugin.*/
@property (nonatomic, strong) id title;

/** The description of the plugin.*/
@property (nonatomic, strong) id details;

/** The image of the plugin.*/
@property (nonatomic, strong) NSString* imageUrl;

/** If the plugin is enabled.*/
@property (nonatomic) BOOL enabled;

/** The sort order of the plugin.*/
@property (nonatomic) NSInteger displayOrder;

/** If the plugin is available for the current device.*/
- (BOOL) isAvailableForDevice;

@end
