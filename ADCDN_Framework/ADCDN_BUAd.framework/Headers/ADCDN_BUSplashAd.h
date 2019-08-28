//
//  ADCDN_BUSplashAd.h
//  ADCDN_BUAd
//
//  Created by DL on 2019/8/16.
//  Copyright © 2019 DLL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ADCDN_BUSplashAd;

@protocol ADCDN_BUSplashAdDelegate <NSObject>

@optional
/**
 此方法在成功加载splash广告材料时调用。
 */
- (void)splashAdDidLoad:(ADCDN_BUSplashAd *_Nullable)splashAd;

/**
 开屏广告展示失败
 @param error : the reason of error
 */
- (void)splashAd:(ADCDN_BUSplashAd *_Nullable)splashAd didFailWithError:(NSError * _Nullable)error;

/**
 将显示启动广告位时调用此方法。
 */
- (void)splashAdWillVisible:(ADCDN_BUSplashAd *_Nullable)splashAd;

/**
 单击splash广告时调用此方法。
 */
- (void)splashAdDidClick:(ADCDN_BUSplashAd *_Nullable)splashAd;

/**
 当splash广告关闭时调用此方法。
 */
- (void)splashAdDidClose:(ADCDN_BUSplashAd *_Nullable)splashAd;

/**
 当splash广告即将关闭时调用此方法。
 */
- (void)splashAdWillClose:(ADCDN_BUSplashAd *_Nullable)splashAd;

/**
 当关闭另一个控制器时调用此方法。
 @param interactionType : 在app中打开appstore或打开网页或查看视频广告详情页面。
 */
//- (void)splashAdDidCloseOtherController:(ADCDN_BUSplashAd *_Nullable)splashAd interactionType:(BUInteractionType)interactionType;

@end

@interface ADCDN_BUSplashAd : NSObject

/**
The unique identifier of splash ad.
*/
@property (nonatomic, copy  ) NSString * _Nullable slotID;

/**
 Maximum allowable load timeout, default 3s, unit s.
 */
@property (nonatomic, assign) NSTimeInterval tolerateTimeout;

/**
 开屏广告大小
 */
@property (nonatomic, assign)CGRect splashFrame;

/**
 Whether hide skip button, default NO.
 If you hide the skip button, you need to customize the countdown.
 */
@property (nonatomic, assign) BOOL hideSkipButton;

/**
 The delegate for receiving state change messages.
 */
@property (nonatomic, weak, nullable) id<ADCDN_BUSplashAdDelegate> delegate;

/*
 required.
 Root view controller for handling ad actions.
 */
@property (nonatomic, weak) UIViewController * _Nullable rootViewController;

/**
 Whether the splash ad data has been loaded.
 */
@property (nonatomic, getter=isAdValid, readonly) BOOL adValid;


+ (instancetype _Nullable )shareManagerWithAppID:(NSString *_Nullable)appID;

/**
 Load splash ad datas.
 Start the countdown(@tolerateTimeout) as soon as you request datas.
 */
- (void)loadAdData;

@end



