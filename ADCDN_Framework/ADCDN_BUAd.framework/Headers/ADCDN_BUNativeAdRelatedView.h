//
//  ADCDN_BUNativeAdRelatedView.h
//  ADCDN_BUAd
//
//  Created by DL on 2019/8/23.
//  Copyright © 2019 DLL. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "BUVideoAdView.h"
#import "ADCDN_BUNativeAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface ADCDN_BUNativeAdRelatedView : NSObject

/**
 Need to actively add to the view in order to deal with the feedback and improve the accuracy of ad.
 */
@property (nonatomic, strong, readonly, nullable) UIButton *dislikeButton;

/**
 Promotion label.Need to actively add to the view.
 */
@property (nonatomic, strong, readonly, nullable) UILabel *adLabel;

/**
 Ad logo.Need to actively add to the view.
 */
@property (nonatomic, strong, readonly, nullable) UIImageView *logoImageView;
/**
 Ad logo + Promotion label.Need to actively add to the view.
 */
@property (nonatomic, strong, readonly, nullable) UIImageView *logoADImageView;

/**
 Video ad view. Need to actively add to the view.
 */
//@property (nonatomic, strong, readonly, nullable) BUVideoAdView *videoAdView;

/**
 Refresh the data every time you get new datas in order to show ad perfectly.
 */
- (void)refreshData:(ADCDN_BUNativeAd *)nativeAd;

@end

NS_ASSUME_NONNULL_END
