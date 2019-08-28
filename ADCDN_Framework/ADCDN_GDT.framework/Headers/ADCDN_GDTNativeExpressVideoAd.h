//
//  ADCDN_GDTNativeExpressVideoAd.h
//  ADCDN_GDT
//
//  Created by DL on 2019/8/26.
//  Copyright © 2019 DLL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ADCDN_GDTNativeExpressVideoAd;

@protocol ADCDN_GDTNativeExpressVideoAdDelegate <NSObject>

@optional
/// 加载成功
- (void)GDTNativeAdDidLoad:(ADCDN_GDTNativeExpressVideoAd *)nativeAd;
/// 加载失败
- (void)GDTNativeAd:(ADCDN_GDTNativeExpressVideoAd *)nativeAd didFailWithError:(NSError *_Nullable)error;
/// 点击广告时
- (void)GDTNativeAdDidClick:(ADCDN_GDTNativeExpressVideoAd *)nativeAd;
/// 曝光回调
- (void)GDTNativeAdDidBecomeVisible:(ADCDN_GDTNativeExpressVideoAd *)nativeAd;

@end


@interface ADCDN_GDTNativeExpressVideoAd : NSObject
/// 应用id
@property (nonatomic, copy  ) NSString *AppId;
/// placeID
@property (nonatomic, copy  ) NSString *placementId;

/// 加载广告位视图 （必传）
@property (nonatomic, strong) UIView *customView;
/*
 控制器 （必传）
 */
@property (nonatomic, weak) UIViewController * _Nullable rootViewController;

@property (nonatomic, weak, nullable) id<ADCDN_GDTNativeExpressVideoAdDelegate> delegate;

+ (instancetype)shareManager;
/// 加载
- (void)loadNativeAd;

@end

NS_ASSUME_NONNULL_END
