//
//  GetSocialConfigurationProperties.h
//  GetSocialSDK
//
//  Created by Chirag Gupta on 12/1/15.
//  Copyright (c) 2015 GetSocial. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GetSocialConfigurationProperties : NSObject

struct GetSocialConfigurationPropertyStruct {

    __unsafe_unretained NSString *const WINDOW_WIDTH;  // dimension
    __unsafe_unretained NSString *const WINDOW_HEIGHT; // dimension
    __unsafe_unretained NSString *const WINDOW_BG_COLOR; // color
    __unsafe_unretained NSString *const WINDOW_BG_IMAGE; // drawable
    __unsafe_unretained NSString *const WINDOW_OVERLAY_IMAGE; // drawable
    __unsafe_unretained NSString *const WINDOW_TINT_COLOR; // color
    __unsafe_unretained NSString *const WINDOW_ANIMATION_STYLE; // animation style
    
    __unsafe_unretained NSString *const HEADER_HEIGHT; // dimension
    __unsafe_unretained NSString *const HEADER_BG_COLOR; // color
    
    __unsafe_unretained NSString *const TITLE_TEXT_STYLE; // text style
    __unsafe_unretained NSString *const TITLE_MARGIN_TOP; // dimension
    
    __unsafe_unretained NSString *const BACK_BUTTON_WIDTH; // dimension
    __unsafe_unretained NSString *const BACK_BUTTON_HEIGHT; // dimension
    __unsafe_unretained NSString *const BACK_BUTTON_MARGIN_LEFT; // dimension
    __unsafe_unretained NSString *const BACK_BUTTON_MARGIN_TOP; // dimension
    __unsafe_unretained NSString *const BACK_BUTTON_BG_IMAGE_NORMAL; // drawable
    __unsafe_unretained NSString *const BACK_BUTTON_BG_IMAGE_PRESSED; // drawable
    
    __unsafe_unretained NSString *const CLOSE_BUTTON_WIDTH; // dimension
    __unsafe_unretained NSString *const CLOSE_BUTTON_HEIGHT; // dimension
    __unsafe_unretained NSString *const CLOSE_BUTTON_MARGIN_RIGHT; // dimension
    __unsafe_unretained NSString *const CLOSE_BUTTON_MARGIN_TOP; // dimension
    __unsafe_unretained NSString *const CLOSE_BUTTON_BG_IMAGE_NORMAL; // drawable
    __unsafe_unretained NSString *const CLOSE_BUTTON_BG_IMAGE_PRESSED; // drawable
    
    __unsafe_unretained NSString *const CONTENT_MARGIN_TOP; // dimension
    __unsafe_unretained NSString *const CONTENT_MARGIN_LEFT; // dimension
    __unsafe_unretained NSString *const CONTENT_MARGIN_RIGHT; // dimension
    __unsafe_unretained NSString *const CONTENT_MARGIN_BOTTOM; // dimension
    __unsafe_unretained NSString *const CONTENT_TEXT_STYLE; // text style

    __unsafe_unretained NSString *const ENTITY_NAME_TEXT_STYLE; // text style
    
    __unsafe_unretained NSString *const TIMESTAMP_TEXT_STYLE; // text style
    
    __unsafe_unretained NSString *const BADGE_TEXT_STYLE; // text style
    __unsafe_unretained NSString *const BADGE_BG_IMAGE; // drawable
    __unsafe_unretained NSString *const BADGE_BG_IMAGE_INSETS; // insets
    __unsafe_unretained NSString *const BADGE_TEXT_INSETS; // insets
    
    __unsafe_unretained NSString *const LINK_TEXT_STYLE; // text style
    
    __unsafe_unretained NSString *const VERIFIED_ACCOUNT_BG_IMAGE; // drawable
    
    __unsafe_unretained NSString *const INVITE_FRIENDS_BUTTON_TEXT_STYLE; // text style
    __unsafe_unretained NSString *const INVITE_FRIENDS_BUTTON_TEXT_Y_OFFSET_NORMAL; // dimension
    __unsafe_unretained NSString *const INVITE_FRIENDS_BUTTON_TEXT_Y_OFFSET_PRESSED; // dimension
    __unsafe_unretained NSString *const INVITE_FRIENDS_BUTTON_BAR_COLOR; // color
    __unsafe_unretained NSString *const INVITE_FRIENDS_BUTTON_BG_IMAGE_NORMAL; // drawable
    __unsafe_unretained NSString *const INVITE_FRIENDS_BUTTON_BG_IMAGE_PRESSED; // drawable
    __unsafe_unretained NSString *const INVITE_FRIENDS_BUTTON_BG_IMAGE_NORMAL_INSETS; // insets
    __unsafe_unretained NSString *const INVITE_FRIENDS_BUTTON_BG_IMAGE_PRESSED_INSETS; // insets
    
    __unsafe_unretained NSString *const ACTIVITY_ACTION_BUTTON_TEXT_STYLE; // text style
    __unsafe_unretained NSString *const ACTIVITY_ACTION_BUTTON_TEXT_Y_OFFSET_NORMAL; // dimension
    __unsafe_unretained NSString *const ACTIVITY_ACTION_BUTTON_TEXT_Y_OFFSET_PRESSED; // dimension
    __unsafe_unretained NSString *const ACTIVITY_ACTION_BUTTON_BG_IMAGE_NORMAL; // drawable
    __unsafe_unretained NSString *const ACTIVITY_ACTION_BUTTON_BG_IMAGE_PRESSED; // drawable
    __unsafe_unretained NSString *const ACTIVITY_ACTION_BUTTON_BG_IMAGE_NORMAL_INSETS; // insets
    __unsafe_unretained NSString *const ACTIVITY_ACTION_BUTTON_BG_IMAGE_PRESSED_INSETS; // insets
    
    __unsafe_unretained NSString *const OVERSCROLL_TEXT_STYLE; // text style
    
    __unsafe_unretained NSString *const PLACEHOLDER_TITLE_TEXT_STYLE; // text style
    __unsafe_unretained NSString *const PLACEHOLDER_CONTENT_TEXT_STYLE; // text style
    
    __unsafe_unretained NSString *const INPUT_FIELD_TEXT_STYLE; // text style
    __unsafe_unretained NSString *const INPUT_FIELD_BG_COLOR; // color
    __unsafe_unretained NSString *const INPUT_FIELD_HINT_COLOR; // color
    __unsafe_unretained NSString *const INPUT_FIELD_BORDER_SIZE; // dimension
    __unsafe_unretained NSString *const INPUT_FIELD_BORDER_COLOR;// color
    __unsafe_unretained NSString *const INPUT_FIELD_RADIUS; // dimension
    
    __unsafe_unretained NSString *const ACTIVITY_INPUT_BAR_BG_COLOR; // color
    __unsafe_unretained NSString *const COMMENT_INPUT_BAR_BG_COLOR; // color
    
    __unsafe_unretained NSString *const AVATAR_BORDER_SIZE; // dimension
    __unsafe_unretained NSString *const AVATAR_BORDER_COLOR; // color
    __unsafe_unretained NSString *const AVATAR_RADIUS; // dimension
    __unsafe_unretained NSString *const AVATAR_DEFAULT_IMAGE; // drawable
    
    __unsafe_unretained NSString *const LIKE_BUTTON_BG_IMAGE_NORMAL; // drawable
    __unsafe_unretained NSString *const LIKE_BUTTON_BG_IMAGE_SELECTED; // drawable
    
    __unsafe_unretained NSString *const DIVIDER_BG_COLOR; // color
    __unsafe_unretained NSString *const DIVIDER_HEIGHT; // dimension
    
    
    __unsafe_unretained NSString *const LOAD_MORE_BUTTON_TEXT_STYLE; // text style
    __unsafe_unretained NSString *const LOAD_MORE_BUTTON_TEXT_Y_OFFSET_NORMAL; // dimension
    __unsafe_unretained NSString *const LOAD_MORE_BUTTON_TEXT_Y_OFFSET_PRESSED; // dimension
    __unsafe_unretained NSString *const LOAD_MORE_BUTTON_BG_IMAGE_NORMAL; // drawable
    __unsafe_unretained NSString *const LOAD_MORE_BUTTON_BG_IMAGE_PRESSED; // drawable
    __unsafe_unretained NSString *const LOAD_MORE_BUTTON_BG_IMAGE_NORMAL_INSETS; // insets
    __unsafe_unretained NSString *const LOAD_MORE_BUTTON_BG_IMAGE_PRESSED_INSETS; // insets

    __unsafe_unretained NSString *const POST_BUTTON_BG_IMAGE_NORMAL; // drawable
    __unsafe_unretained NSString *const POST_BUTTON_BG_IMAGE_PRESSED; // drawable
    
    __unsafe_unretained NSString *const SEGMENT_BAR_TEXT_STYLE_NORMAL; // text style
    __unsafe_unretained NSString *const SEGMENT_BAR_TEXT_STYLE_SELECTED; // text style
    __unsafe_unretained NSString *const SEGMENT_BAR_BORDER_COLOR; // color
    __unsafe_unretained NSString *const SEGMENT_BAR_BORDER_SIZE; // dimension
    __unsafe_unretained NSString *const SEGMENT_BAR_BORDER_RADIUS; // dimension
    __unsafe_unretained NSString *const SEGMENT_BAR_BG_COLOR_NORMAL; // color
    __unsafe_unretained NSString *const SEGMENT_BAR_BG_COLOR_SELECTED; // color
    __unsafe_unretained NSString *const SEGMENT_BAR_BG_IMAGE_NORMAL; // drawable
    __unsafe_unretained NSString *const SEGMENT_BAR_BG_IMAGE_PRESSED; // drawable
    __unsafe_unretained NSString *const SEGMENT_BAR_BG_IMAGE_NORMAL_INSETS; // insets
    __unsafe_unretained NSString *const SEGMENT_BAR_BG_IMAGE_PRESSED_INSETS; // insets
    
    __unsafe_unretained NSString *const LOADING_INDICATOR_BG_IMAGE; // drawable
    
    __unsafe_unretained NSString *const NOTIFICATION_ICON_COMMENT_BG_IMAGE; // drawable
    __unsafe_unretained NSString *const NOTIFICATION_ICON_LIKE_BG_IMAGE; // drawable
    
    __unsafe_unretained NSString *const NO_NETWORK_PLACEHOLDER_BG_IMAGE; // drawable
    __unsafe_unretained NSString *const NO_ACTIVITY_PLACEHOLDER_BG_IMAGE; // drawable
    __unsafe_unretained NSString *const INVITE_PROVIDER_PLACEHOLDER_BG_IMAGE; // drawable
    
    __unsafe_unretained NSString *const NO_FRIENDS_PLACEHOLDER_BG_IMAGE; // drawable

    __unsafe_unretained NSString *const LIST_ITEM_BG_COLOR_ODD; // color
    __unsafe_unretained NSString *const LIST_ITEM_BG_COLOR_EVEN; // color
    
    __unsafe_unretained NSString *const NOTIFICATION_LIST_ITEM_BG_COLOR_READ; // color
    __unsafe_unretained NSString *const NOTIFICATION_LIST_ITEM_BG_COLOR_UNREAD; // color
    
    __unsafe_unretained NSString *const ACTIVITY_IMAGE_ASPECT_RATIO; // aspect ratio
    __unsafe_unretained NSString *const ACTIVITY_IMAGE_RADIUS; // dimension
    __unsafe_unretained NSString *const ACTIVITY_IMAGE_DEFAULT_IMAGE; //drawable
    
    __unsafe_unretained NSString *const CALL_TO_ACTION; //drawable
    __unsafe_unretained NSString *const CALL_TO_ACTION_TEXT_STYLE; // text style
    __unsafe_unretained NSString *const CALL_TO_ACTION_TEXT_Y_OFFSET_NORMAL; // dimension
    __unsafe_unretained NSString *const CALL_TO_ACTION_TEXT_Y_OFFSET_PRESSED; // dimension
    __unsafe_unretained NSString *const CALL_TO_ACTION_BAR_COLOR; // color
    __unsafe_unretained NSString *const CALL_TO_ACTION_BG_IMAGE_NORMAL; // drawable
    __unsafe_unretained NSString *const CALL_TO_ACTION_BG_IMAGE_PRESSED; // drawable
    
};

extern const struct GetSocialConfigurationPropertyStruct GetSocialProperty;


@end
