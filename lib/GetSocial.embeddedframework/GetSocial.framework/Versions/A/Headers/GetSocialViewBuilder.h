//
//  GetSocialViewBuilder.h
//  GetSocialSDK
//
//  Created by GetSocial on 16/04/15.
//  Copyright (c) 2015 GetSocial. All rights reserved.
//

#ifndef __GetSocialViewBuilder_h
#define __GetSocialViewBuilder_h

#import <UIKit/UIKit.h>

/**
 *  Abstract class for ViewBuilders
 */
@interface GetSocialViewBuilder : NSObject

/**
 *  Get/Set the title to show on top of the view
 */
@property(nonatomic, strong) NSString *title;

/**
 *  Shows the view
 */
- (void)show;

@end

#endif
