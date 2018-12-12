//
//  RLMFastImage.h
//  RLMFastImageExample
//
//  Created by Tim Oliver on 9/12/18.
//  Copyright © 2018 Tim Oliver. All rights reserved.
//

#import <Realm/Realm.h>
#import <CoreGraphics/CoreGraphics.h>

@class UIColor;
@class UIImage;

/** The types of pixel formats in which image data can be saved */
typedef NS_ENUM(NSInteger, RLMFastImageFormat) {
    RLMFastImageFormat32BitBGRA, // 32-bit color, with alpha component
    RLMFastImageFormat32BitBGR,  // 32-bit color, but with alpha ignored
    RLMFastImageFormat16BitBGR,  // 16-bit color, no alpha
    RLMFastImageFormat8BitGrayscale // 8-bit grayscale, no alpha
};

NS_ASSUME_NONNULL_BEGIN

@interface RLMFastImage : RLMObject

/** The main image, loaded back from disk. */
@property (nonatomic, readonly) UIImage *image;

/** A far smaller image, used as a placeholder while the main image loads. */
@property (nonatomic, readonly) UIImage *placeholderImage;

/** The image format in which this image was encoded to disk. */
@property (nonatomic, readonly) RLMFastImageFormat imageFormat;

/** The average color of all of the pixels in the image. This can
    be applied to any view as an extremely fast placeholder. */
@property (nonatomic, readonly) UIColor *backgroundColor;

/**
 Save an uncompressed image to Realm.

 @param image The image to save to Realm.
 @param imageFormat The color format in which the image will be saved (Lower means less file space)
 @param size The size in which the image will be shrunk down to fit.
 @param placeholderScale From 0.0 to 1.0, the size of the placeholder image compared to the main one.
 */
- (void)saveImage:(UIImage *)image
      imageFormat:(RLMFastImageFormat)imageFormat
     fittedToSize:(CGSize)size
 placeholderScale:(CGFloat)placeholderScale;

/**
 Save an uncompressed image to Realm, with a customized image format, and custom size.
 - The placeholder size is the image width divided by three.

 @param image The image to save to Realm.
 @param format The color format in which the image will be saved (Lower means less file space)
 @param size The size in which the image will be shrunk down to fit.
 */
- (void)saveImage:(UIImage *)image imageFormat:(RLMFastImageFormat)format fittedToSize:(CGSize)size;

/**
 Save an uncompressed image to Realm, with a customized image format, but all other default settings.
 - The size is the size of the image itself.
 - The placeholder size is the image width divided by three.

 @param image The image to save to Realm.
 @param format The color format in which the image will be saved (Lower means less file space)
 */
- (void)saveImage:(UIImage *)image imageFormat:(RLMFastImageFormat)format;

/**
 Saves an uncompressed image with all default settings to the Realm.
 - The image format is determined from the image's own color space.
 - The size is the size of the image itself.
 - The placeholder size is the image width divided by 3.

 @param image The image to save to Realm.
 */
- (void)saveImage:(UIImage *)image;

@end

NS_ASSUME_NONNULL_END
