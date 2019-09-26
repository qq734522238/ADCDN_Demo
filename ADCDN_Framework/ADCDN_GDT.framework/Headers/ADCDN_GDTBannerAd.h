//
//  ADCDN_GDTBannerAd.h
//  ADCDN_GDT
//
//  Created by DL on 2019/8/29.
//  Copyright © 2019 DLL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ADCDN_GDTBannerAd;

@protocol ADCDN_GDTBannerAdDelegate <NSObject>

@optional
/// 加载成功
- (void)GDTBannerAdDidLoad:(ADCDN_GDTBannerAd *)nativeAd;
/// 加载失败
- (void)GDTBannerAd:(ADCDN_GDTBannerAd *)nativeAd didFailWithError:(NSError *_Nullable)error;
/// 点击广告时
- (void)GDTBannerAdDidClick:(ADCDN_GDTBannerAd *)nativeAd;
/// 曝光回调
- (void)GDTBannerAdDidBecomeVisible:(ADCDN_GDTBannerAd *)nativeAd;

@end

@interface ADCDN_GDTBannerAd : NSObject
/// 应用id
@property (nonatomic, copy  ) NSString *AppId;
/// placeID
@property (nonatomic, copy  ) NSString *placementId;

/// 加载banner广告的父视图
@property (nonatomic, strong) UIView *customView;
/// 根控制器 (必传)
@property (nonatomic, weak) UIViewController * rootViewController;
/// 是否轮循 大于 30 为轮循  默认为不轮循
@property (nonatomic, assign) int interval;

@property (nonatomic, weak, nullable) id<ADCDN_GDTBannerAdDelegate> delegate;

/// 初始化
+ (instancetype)shareManager;
/// 刷新加载
- (void)refreshBanner;

@end

NS_ASSUME_NONNULL_END
