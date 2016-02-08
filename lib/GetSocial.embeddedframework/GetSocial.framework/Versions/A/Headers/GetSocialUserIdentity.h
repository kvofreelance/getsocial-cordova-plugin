//
//  GetSocialUserIdentity.h
//  GetSocialSDK
//
//  Created by Jan-Eric Duden on 12/05/14.
//  Copyright (c) 2014 GetSocial. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GetSocialConstants.h"

/**
 Describes an user.
 */
@interface GetSocialUserIdentity : NSObject

/**
 *  Unique Identifier of the user.
 */
@property(strong, readonly) NSString* guid;

/**
 *  Display name of the user. Can be nil if no display name is available.
 */
@property(strong, readonly) NSString* displayName;

/**
 *  The Avatar Url of the user. Can be nil if no avatar URL is available.
 */
@property(strong, readonly) NSString* avatarUrl;

/**
 * A dictionary with the providers and provider Ids of the user.
 */
@property(strong, readonly) NSDictionary* identities;

/**
 *  Gets the Id of the user for the specified provider
 *
 *  @param provider Id of the provider
 *
 *  @return Id of the user for the specified provider
 */
- (NSString*)idForProvider:(GetSocialProvider) provider;

@end
