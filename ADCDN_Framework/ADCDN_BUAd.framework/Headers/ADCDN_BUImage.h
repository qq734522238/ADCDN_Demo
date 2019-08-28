//
//  ADCDN_BUImage.h
//  ADCDN_BUAd
//
//  Created by DL on 2019/8/23.
//  Copyright © 2019 DLL. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADCDN_BUImage : NSObject

// image address URL
@property (nonatomic, copy) NSString *imageURL;

// image width
@property (nonatomic, assign) float width;

// image height
@property (nonatomic, assign) float height;

@end

NS_ASSUME_NONNULL_END
