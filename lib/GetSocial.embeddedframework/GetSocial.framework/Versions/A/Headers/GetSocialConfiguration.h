//
//  GetSocialConfiguration.h
//  GetSocialSDK
//
//  Created by Demian Denker on 05/02/15.
//  Copyright (c) 2015 GetSocial. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "GetSocialConstants.h"

/**
 *  The GetSocialConfiguration Singleton provides the main entry point for all UI customization
 */
@interface GetSocialConfiguration : NSObject

#pragma mark - Singleton
/** @name Singleton */

/**
 *  Gets the shared instance of GetSocialConfiguration
 *
 *  @return GetSocialConfiguration instance
 */
+ (instancetype)sharedInstance;

#pragma mark - General Customization Methods

/**
 * Loads a configuration from a configuration file
 *
 * @param filePath The the path to the configuration file.
 */
- (void)setConfiguration:(NSString*)filePath;

/**
 * Clear SDK Customizations and set them to default
 *
 */
- (void)clear;

/**
 * Starts a new UI configuration transaction
 *
 */
- (void)beginTransaction;

/**
 * Ends the current UI configuration transaction
 *
 */
- (void)endTransaction;

#pragma mark - Base Customization Methods

/**
 *  Sets the main design properties.
 *
 *  @param width     The width of the design.
 *  @param height    The height of the design.
 *  @param ppi       The ppi of the design.
 *  @param scaleMode Could be two types:
 *                   -  kGetSocialScaleModeConstantPhysicalSize - The size of all elements will be constant on different screens
 *                   -  kGetSocialScaleModeScaleWithScreenSize - The size of all elements will be scaled according to the sceen
 */
- (void)setBaseDesign:(CGFloat)width height:(CGFloat)height ppi:(CGFloat)ppi scaleMode:(NSString*)scaleMode;

/**
 * Sets the base path for all the resources.
 *
 * @param path The path to the resources.
 */
- (void)setBasePath:(NSString*)path;

#pragma mark - Images Customization Methods

/**
 * Sets the image path for a specific elementID.
 *
 * @param path          The path to the file.
 * @param elementID     The ID of the element to customise.
 */
- (void)setImagePath:(NSString*)path forElementID:(NSString*)elementID;

/**
 * Sets the image for a specific elementID.
 *
 * @param image         The image to use.
 * @param elementID     The ID of the element to customise.
 */
- (void)setImageResource:(UIImage*)image forElementID:(NSString*)elementID;

#pragma mark - Color Customization Methods

/**
 * Sets the image for a specific elementID.
 *
 * @param color         The color to use.
 * @param elementID     The ID of the element to customise.
 */
- (void)setColor:(UIColor*)color forElementID:(NSString*)elementID;

#pragma mark - Dimension Customization Methods

/**
 * Sets the dimension for a specific elementID.
 *
 * @param dimension     The dimension value.
 * @param elementID     The ID of the element to customise.
 */
- (void)setDimension:(CGFloat)dimension forElementID:(NSString*)elementID;

#pragma mark - Aspect Ratio Customization Methods

/**
 * Sets the aspect ratio for a specific elementID.
 *
 * @param aspectRatio   The aspectRatio value.
 * @param elementID     The ID of the element to customise.
 */
- (void)setAspectRatio:(CGFloat)aspectRatio forElementID:(NSString*)elementID;

#pragma mark - Text Style Customization Methods

/**
 * Sets the text style for a specific elementID.
 *
 * @param fontPath      The path to the font for the element.
 * @param fontSize      The font size for the element.
 * @param fontColor     The color of the font for the element.
 * @param elementID     The ID of the element to customise.
 */
- (void)setTextStyle:(NSString*)fontPath fontSize:(CGFloat)fontSize fontColor:(UIColor*)fontColor forElementID:(NSString*)elementID;

/**
 * Sets the text style for a specific elementID.
 *
 * @param fontPath      The path to the font for the element.
 * @param fontSize      The font size for the element.
 * @param fontColor     The color of the font for the element.
 * @param strokeColor   The color of the stroke of the font for the element.
 * @param strokeSize    The size of the stroke of the font for the element.
 * @param strokeOffset  The offset of the stroke of the font for the element.
 * @param elementID     The ID of the element to customise.
 */
- (void)setTextStyle:(NSString*)fontPath
            fontSize:(CGFloat)fontSize
           fontColor:(UIColor*)fontColor
         strokeColor:(UIColor*)strokeColor
          strokeSize:(CGFloat)strokeSize
        strokeOffset:(CGSize)strokeOffset
        forElementID:(NSString*)elementID;
/**
 * Sets the text style for a specific elementID.
 *
 * @param font      The font for the element.
 * @param fontColor The color of the font for the element.
 * @param elementID The ID of the element to customise.
 */
- (void)setTextStyle:(UIFont*)font fontColor:(UIColor*)fontColor forElementID:(NSString*)elementID;

/**
 * Sets the text style for a specific elementID.
 *
 * @param font          The font for the element.
 * @param fontColor     The color of the font for the element.
 * @param strokeColor   The color of the stroke of the font for the element.
 * @param strokeSize    The size of the stroke of the font for the element.
 * @param strokeOffset  The offset of the stroke of the font for the element.
 * @param elementID     The ID of the element to customise.
 */
- (void)setTextStyle:(UIFont*)font
           fontColor:(UIColor*)fontColor
         strokeColor:(UIColor*)strokeColor
          strokeSize:(CGFloat)strokeSize
        strokeOffset:(CGSize)strokeOffset
        forElementID:(NSString*)elementID;

#pragma mark - Flags Customization Methods

/**
 * Sets flags.
 *
 * @param flagID    The ID of the flag.
 * @param flagValue The value of the flag
 *
 */
- (void)setFlag:(BOOL)flagValue forID:(NSString*)flagID;

#pragma mark - Animation Customization Methods

/**
* Sets the animation style for a specific elementID.
*
* @param style      The style of animation.
* @param elementID  The ID of the element to customise.
*/
- (void)setAnimationStyle:(GetSocialAnimationStyle)style forElementID:(NSString*)elementID;

#pragma mark - Insets Customization Methods

/**
 * Sets the insets for a specific elementID.
 *
 * @param top       Top inset.
 * @param left      Left inset.
 * @param bottom    Bottom inset.
 * @param right     Right inset.
 * @param elementID The ID of the element to customise.
 */
- (void)setInsets:(CGFloat)top right:(CGFloat)right bottom:(CGFloat)bottom left:(CGFloat)left forElementID:(NSString*)elementID;

@end