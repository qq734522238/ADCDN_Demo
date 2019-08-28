//
//  ADCDN_GDTSplashAd.h
//  ADCDN_GDT_Framework
//
//  Created by DL on 2019/8/14.
//  Copyright © 2019 DLL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ADCDN_GDTSplashAd;

@protocol ADCDN_GDTSplashAdDelegate <NSObject>

@optional
/**
 *  开屏广告成功展示
 */
- (void)ADCDN_GDTSplashAdSuccessPresentScreen:(ADCDN_GDTSplashAd *)splashAd;
/**
 *  开屏广告展示失败
 */
- (void)ADCDN_GDTSplashAdFailToPresent:(ADCDN_GDTSplashAd *)splashAd withError:(NSError *)error;
/**
 *  开屏广告曝光回调
 */
- (void)ADCDN_GDTSplashAdExposured:(ADCDN_GDTSplashAd *)splashAd;
/**
 *  开屏广告点击回调
 */
- (void)ADCDN_GDTSplashAdClicked:(ADCDN_GDTSplashAd *)splashAd;
/**
 *  开屏广告将要关闭回调
 */
- (void)ADCDN_GDTSplashAdWillClosed:(ADCDN_GDTSplashAd *)splashAd;
/**
 *  开屏广告关闭回调
 */
- (void)ADCDN_GDTSplashAdClosed:(ADCDN_GDTSplashAd *)splashAd;


@end

@interface ADCDN_GDTSplashAd : NSObject

@property (nonatomic, weak) id <ADCDN_GDTSplashAdDelegate> delegate;


@property (nonatomic, copy  ) NSString *GDTMobSDKAppId;
@property (nonatomic, copy  ) NSString *placementId;
@property (nonatomic, strong) UIWindow *window;

/**
 初始化开屏广告
 */
+ (instancetype)shareManager;
//- (instancetype)initGDTSplashAdWithAppId:(NSString *)GDTMobSDKAppId PlacementId:(NSString *)placementId ShowInWindow:(UIWindow *)window;

- (void)loadGDTSplashAd;

@end

