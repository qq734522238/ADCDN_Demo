//
//  ADCDN_BUNativeAd.h
//  ADCDN_BUAd
//
//  Created by DL on 2019/8/22.
//  Copyright © 2019 DLL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ADCDN_BUMaterialMeta.h"
#import "ADCDN_BUMaterialMeta.h"

NS_ASSUME_NONNULL_BEGIN

@class ADCDN_BUNativeAd;

@protocol ADCDN_BUNativeAdDelegate <NSObject>

@optional
/// 加载成功
- (void)nativeAdDidLoad:(ADCDN_BUNativeAd *)nativeAd;
/// 加载失败
- (void)nativeAd:(ADCDN_BUNativeAd *)nativeAd didFailWithError:(NSError *_Nullable)error;
/// 点击广告时
- (void)nativeAdDidClick:(ADCDN_BUNativeAd *)nativeAd withView:(UIView *_Nullable)view;
/// 曝光回调
- (void)nativeAdDidBecomeVisible:(ADCDN_BUNativeAd *)nativeAd;


@end

@interface ADCDN_BUNativeAd : NSObject

@property (nonatomic, copy  ) NSString * _Nullable slotID;
/// placeID
@property (nonatomic, copy  ) NSString *placementId;

/// 加载广告位视图 （必传）
@property (nonatomic, strong) UIView *customView;
/*
 required.
 Root view controller for handling ad actions.
 */
@property (nonatomic, weak) UIViewController * _Nullable rootViewController;

/**
 Ad slot material.
 */
@property (nonatomic, strong) ADCDN_BUMaterialMeta *data;

@property (nonatomic, weak, nullable) id<ADCDN_BUNativeAdDelegate> delegate;


+ (instancetype)shareManagerWithAppID:(NSString *)appID;


- (void)buildupView;
- (void)loadNativeAd;

@end

NS_ASSUME_NONNULL_END
