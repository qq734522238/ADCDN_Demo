//
//  ADCDN_SplashAdManager.h
//  ADCDN_BaseSDK
//
//  Created by DL on 2019/8/15.
//  Copyright © 2019 DLL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ADCDN_SplashAdManager;

@protocol ADCDN_SplashAdManagerDelegate <NSObject>

@optional
/**
 *  开屏广告成功展示
 */
- (void)ADCDN_SplashAdSuccessPresentScreen:(ADCDN_SplashAdManager *_Nullable)splashAd;
/**
 *  开屏广告展示失败
 */
- (void)ADCDN_SplashAdFailToPresent:(ADCDN_SplashAdManager *_Nullable)splashAd withError:(NSError *_Nullable)error;
/**
 *  开屏广告曝光回调
 */
- (void)ADCDN_SplashAdExposured:(ADCDN_SplashAdManager *_Nullable)splashAd;
/**
 *  开屏广告点击回调
 */
- (void)ADCDN_SplashAdClicked:(ADCDN_SplashAdManager *_Nullable)splashAd;
/**
 *  开屏广告将要关闭回调
 */
- (void)ADCDN_SplashAdWillClosed:(ADCDN_SplashAdManager *_Nullable)splashAd;
/**
 *  开屏广告关闭回调
 */
- (void)ADCDN_SplashAdClosed:(ADCDN_SplashAdManager *_Nullable)splashAd;

@end

@interface ADCDN_SplashAdManager : NSObject

@property (nonatomic, strong)UIWindow * _Nullable window;
@property (nonatomic, assign)CGRect wFrame;


@property (nonatomic, weak) id <ADCDN_SplashAdManagerDelegate> _Nullable delegate;

/// 初始化创建单例
+ (instancetype _Nullable )shareManager;

/// 加载开屏广告
- (void)loadSplashAd;

@end

