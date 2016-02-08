//
//  GetSocialIdentityInfo.h
//  GetSocialSDK
//
//  Created by Demian Denker on 08/09/15.
//  Copyright (c) 2015 GetSocial B.V. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GetSocialConstants.h"

@interface GetSocialIdentityInfo : NSObject

@property(nonatomic, strong, readonly) GetSocialProvider provider;
@property(nonatomic, strong, readonly) NSString* displayName;
@property(nonatomic, strong, readonly) NSString* avatarUrl;
@property(nonatomic, strong, readonly) NSString* token;
@property(nonatomic, strong, readonly) NSString* userId;

+ (instancetype)identityInfoWithProvider:(GetSocialProvider)provider token:(NSString*)token userId:(NSString*)userId;

+ (instancetype)identityInfoWithProvider:(GetSocialProvider)provider
                                  userId:(NSString*)userId
                             displayName:(NSString*)displayName
                               avatarUrl:(NSString*)avatarUrl;

- (void)setValue:(NSString*)value forKey:(NSString*)key;

- (NSString*)valueForKey:(NSString*)key;

@end
