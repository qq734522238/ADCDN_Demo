//
//  ADCDN_BannerAdManager.h
//  ADCDN_BaseSDK
//
//  Created by DL on 2019/8/29.
//  Copyright © 2019 DLL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ADCDN_BannerAdManager;

@protocol ADCDN_BannerAdManagerDelegate <NSObject>
/// 加载成功
- (void)ADCDN_BannerAdDidLoad:(ADCDN_BannerAdManager *)nativeAd;

@optional
/// 加载失败
- (void)ADCDN_BannerAd:(ADCDN_BannerAdManager *)nativeAd didFailWithError:(NSError *_Nullable)error;
/// 点击广告时
- (void)ADCDN_BannerAdDidClick:(ADCDN_BannerAdManager *)nativeAd;
/// 曝光回调
- (void)ADCDN_BannerAdDidBecomeVisible:(ADCDN_BannerAdManager *)nativeAd;

@end

@interface ADCDN_BannerAdManager : NSObject

/// 加载广告位视图 （必传）
@property (nonatomic, strong) UIView *customView;

@property (nonatomic, strong)UIViewController *rootViewController;
/// 是否轮循 大于 30 为轮循  默认为不轮循
@property (nonatomic, assign) NSInteger interval;

@property (nonatomic, weak, nullable) id<ADCDN_BannerAdManagerDelegate> delegate;

+ (instancetype)shareManager;

- (void)loadNativeAd;

@end

NS_ASSUME_NONNULL_END
