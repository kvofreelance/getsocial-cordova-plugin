//
//  GetSocialConstants.h
//  GetSocialSDK
//
//  Created by Demian Denker on 03/10/13.
//  Copyright (c) 2013 GetSocial. All rights reserved.
//

#ifndef GetSocialSDK_GetSocialConstants_h
#define GetSocialSDK_GetSocialConstants_h

/** Constants for the Invite friends listener  */
typedef NS_ENUM(NSInteger, GetSocialInviteFriendsStatus)
{
    /**Invite is sent */
    GetSocialInviteFriendsStatusSent = 1,
    /**Invite is created but there is no information if it is sent  */
    GetSocialInviteFriendsStatusIntent = 2,
};

/** Constants for the Leaderboard score types  */
typedef NS_ENUM(NSInteger, GetSocialLeaderboardScoreType)
{
    /** Contains the scores of all the users */
    GetSocialLeaderboardScoreTypeWorld = 1,
    /** Contains the scores of the users that you follow */
    GetSocialLeaderboardScoreTypeFollowing = 2,
    /** Contains a subset of all users scores*/
    GetSocialLeaderboardScoreTypeOthers = 3
};

/** Constants for the Leaderboard score direction  */
typedef NS_ENUM(NSInteger, GetSocialLeaderboardDirectionType)
{
    /** The type is ASC */
    GetSocialLeaderboardDirectionTypeASC = 1,
    /** The type is DESC */
    GetSocialLeaderboardDirectionTypeDESC = 2
};

/** Constants for the User Generated Content  */
typedef NS_ENUM(NSInteger, GetSocialUserGeneratedContentType)
{
    /** Activity */
    GetSocialUserGeneratedContentTypeActivity = 1,
    /** Activity comment */
    GetSocialUserGeneratedContentTypeComment = 2,
    /** Private Chat message */
    GetSocialUserGeneratedContentTypePrivateChatMessage = 3,
    /** Open room chat message */
    GetSocialUserGeneratedContentTypeGroupChatMessage = 4,
    /** Open room chat message */
    GetSocialUserGeneratedContentTypePublicChatMessage = 5
};

typedef NSString *GetSocialProvider;

/**
 * The typedef defines the signature of a block that is called when an operation completes.
 */
typedef void (^GetSocialCompleteCallback)();

/**
 * The typedef defines the signature of a block that is called when an operation fails.
 * @param error is the error that caused the failure.
 */
typedef void (^GetSocialErrorCallback)(NSError *error);

/** Constants that define the open/close animation */
typedef NS_ENUM(NSInteger, GetSocialAnimationStyle)
{
    /** No Animation */
    GetSocialAnimationStyleNone = 0,
    /** Animation scales the element In and Out */
    GetSocialAnimationStyleScale = 1,
    /** Animation fades the element In and Out */
    GetSocialAnimationStyleFade = 2,
    /** Animation fades and scales the element In and Out */
    GetSocialAnimationStyleFadeAndScale = 3
};

/** Constants that define the source of the event */
typedef NS_ENUM(NSInteger, GetSocialSourceView)
{
    /** Notifications View */
    GetSocialSourceViewNotifications = 1,
    /** Chat List View */
    GetSocialSourceViewChatList = 2,
    /** Chat View */
    GetSocialSourceViewChat = 3,
    /** Chat Room View */
    GetSocialSourceViewChatRoom = 4,
    /** Activities View */
    GetSocialSourceViewActivities = 5,
    /** Comments View */
    GetSocialSourceViewComments = 6,
    /** List of Likes View */
    GetSocialSourceViewLikeList = 7,
    /** Following List of Users View */
    GetSocialSourceViewFollowingList = 8
};

extern NSString *const kGetSocialScaleModeScaleWithScreenSize;
extern NSString *const kGetSocialScaleModeConstantPhysicalSize;

extern NSString *const kGetSocialProviderFacebook;
extern NSString *const kGetSocialProviderGooglePlus;
extern NSString *const kGetSocialProviderGeneric;
extern NSString *const kGetSocialProviderEmail;
extern NSString *const kGetSocialProviderSMS;
extern NSString *const kGetSocialProviderLink;
extern NSString *const kGetSocialProviderTwitter;
extern NSString *const kGetSocialProviderKik;
extern NSString *const kGetSocialProviderKakao;
extern NSString *const kGetSocialProviderWhatsapp;

extern NSString *const kGetSocialImage;
extern NSString *const kGetSocialText;
extern NSString *const kGetSocialSubject;
extern NSString *const kGetSocialReferralData;

#define kGetSocialAuthPermissionsFacebook @[ @"email", @"user_friends" ]

extern NSString *const kGetSocialAppInviteUrlPlaceholder;
extern NSString *const kGetSocialAppNamePlaceholder;
extern NSString *const kGetSocialAppIconUrlPlaceholder;
extern NSString *const kGetSocialAppPackageNamePlaceholder;
extern NSString *const kGetSocialUserDisplayNamePlaceholder;

extern NSString *const GetSocialViewOpenNotification;
extern NSString *const GetSocialViewCloseNotification;

extern NSString *const GetSocialUserIdentityUpdatedNotification;

#endif
