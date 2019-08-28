//
//  ADCDN_BUMaterialMeta.h
//  ADCDN_BUAd
//
//  Created by DL on 2019/8/23.
//  Copyright © 2019 DLL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ADCDN_BUImage.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ADCDN_BUFeedADMode) {
    ADCDN_BUFeedADModeSmallImage = 2,
    ADCDN_BUFeedADModeLargeImage = 3,
    ADCDN_BUFeedADModeGroupImage = 4,
    ADCDN_BUFeedVideoAdModeImage = 5, // video ad || rewarded video ad horizontal screen
    ADCDN_BUFeedVideoAdModePortrait = 15, // rewarded video ad vertical screen
    ADCDN_BUFeedADModeImagePortrait = 16
};

@interface ADCDN_BUMaterialMeta : NSObject

/// material pictures.
@property (nonatomic, strong) NSArray<ADCDN_BUImage *> *imageAry;

/// ad headline.
@property (nonatomic, copy) NSString *AdTitle;

/// ad description.
@property (nonatomic, copy) NSString *AdDescription;

/// display format of the in-feed ad, other ads ignores it.
@property (nonatomic, assign) ADCDN_BUFeedADMode imageMode;

@end

NS_ASSUME_NONNULL_END
