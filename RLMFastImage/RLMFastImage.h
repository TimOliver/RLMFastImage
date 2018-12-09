//
//  RLMFastImage.h
//  RLMFastImageExample
//
//  Created by Tim Oliver on 9/12/18.
//  Copyright © 2018 Tim Oliver. All rights reserved.
//

#import <Realm/Realm.h>

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

/** The image format in which this image was encoded to disk. */
@property (nonatomic, readonly) RLMFastImageFormat imageFormat;

@property (nonatomic, readonly) UIColor *backgroundColor;


@end

NS_ASSUME_NONNULL_END
