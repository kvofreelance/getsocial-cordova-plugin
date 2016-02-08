//
//  SmartInviteViewBuilder.h
//  GetSocialSDK
//
//  Created by GetSocial on 22/04/15.
//  Copyright (c) 2015 GetSocial. All rights reserved.
//

#import "GetSocialViewBuilder.h"

/**
 *  Provides a way to build a view to show Notifications
 *  Should be created only by calling `[[GetSocial sharedInstance] createNotificationsView]`
 */
@interface GetSocialSmartInviteViewBuilder : GetSocialViewBuilder

/**
 *  Get/Set the subject to be use on the Smart Invite
 */
@property(nonatomic, strong) NSString *subject;

/**
 *  Get/Set the text to be use on the Smart Invite
 */
@property(nonatomic, strong) NSString *text;

/**
 *  Get/Set a NSDictionary with custom data that will be retrieved by the recipient after the app is installed
 */
@property(nonatomic, strong) NSDictionary *referralData;

/**
 *  Get/Set the image to be use on the Smart Invite if provider supports it
 */
@property(nonatomic, strong) UIImage *image;

@end
