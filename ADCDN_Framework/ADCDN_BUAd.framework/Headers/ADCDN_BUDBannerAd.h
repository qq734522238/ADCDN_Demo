//
//  ADCDN_BUDBannerAd.h
//  ADCDN_BUAd
//
//  Created by DL on 2019/8/29.
//  Copyright © 2019 DLL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@class ADCDN_BUDBannerAd;

@protocol ADCDN_BUDBannerAdDelegate <NSObject>

@optional
/// 加载成功
- (void)bannerAdDidLoad:(ADCDN_BUDBannerAd *)nativeAd;
/// 加载失败
- (void)bannerAd:(ADCDN_BUDBannerAd *)nativeAd didFailWithError:(NSError *_Nullable)error;
/// 点击广告时
- (void)bannerAdDidClick:(ADCDN_BUDBannerAd *)nativeAd;
/// 曝光回调
- (void)bannerAdDidBecomeVisible:(ADCDN_BUDBannerAd *)nativeAd;

@end


@interface ADCDN_BUDBannerAd : NSObject
/// 加载banner广告的父视图
@property (nonatomic, strong) UIView *customView;
/// 根控制器 (必传)
@property (nonatomic, weak) UIViewController * rootViewController;
/// 是否轮循 大于 30 为轮循  默认为不轮循
@property (nonatomic, assign) NSInteger interval;

@property (nonatomic, weak, nullable) id<ADCDN_BUDBannerAdDelegate> delegate;

/// 初始化
+ (instancetype)shareManagerWithAppID:(NSString *)appID;
/// 刷新加载
- (void)refreshBanner;

@end

NS_ASSUME_NONNULL_END
