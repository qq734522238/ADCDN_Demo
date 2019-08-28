//
//  ADCDN_NativeAdManager.h
//  ADCDN_BaseSDK
//
//  Created by DL on 2019/8/22.
//  Copyright © 2019 DLL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ADCDN_MaterialMeta.h"

NS_ASSUME_NONNULL_BEGIN

@class ADCDN_NativeAdManager;

@protocol ADCDN_NativeAdManagerDelegate <NSObject>
/// 加载成功
- (void)ADCDN_NativeAdDidLoad:(ADCDN_NativeAdManager *)nativeAd;

@optional
/// 加载失败
- (void)ADCDN_NativeAd:(ADCDN_NativeAdManager *)nativeAd didFailWithError:(NSError *_Nullable)error;
/// 点击广告时
- (void)ADCDN_NativeAdDidClick:(ADCDN_NativeAdManager *)nativeAd;
/// 曝光回调
- (void)ADCDN_NativeAdDidBecomeVisible:(ADCDN_NativeAdManager *)nativeAd;

@end

@interface ADCDN_NativeAdManager : NSObject

/// 加载广告位视图 （必传）
@property (nonatomic, strong) UIView *customView;

@property (nonatomic, strong)UIViewController *rootViewController;

/**
 Ad slot material.
 */
@property (nonatomic, strong) ADCDN_MaterialMeta *data;

@property (nonatomic, weak, nullable) id<ADCDN_NativeAdManagerDelegate> delegate;

+ (instancetype)shareManager;

- (void)loadNativeAd;

@end

NS_ASSUME_NONNULL_END
