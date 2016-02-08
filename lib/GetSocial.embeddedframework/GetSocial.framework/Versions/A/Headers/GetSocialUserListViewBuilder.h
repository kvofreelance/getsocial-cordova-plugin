//
//  UserListViewBuilder.h
//  GetSocialSDK
//
//  Created by GetSocial on 20/08/15.
//  Copyright (c) 2015 GetSocial B.V. All rights reserved.
//

#import "GetSocialViewBuilder.h"

/**
 *  Provides a way to build a view to show User List
 *  Should be created only by calling [[GetSocial sharedInstance] createUserListViewWithDismissHandler:]
 */
@interface GetSocialUserListViewBuilder : GetSocialViewBuilder

/**
 *  Get/Set if the invite friends button is visible
 */
@property(nonatomic, assign) BOOL showInviteButton;

@end
