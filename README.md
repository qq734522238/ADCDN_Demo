# ADCDN_Demo

## 1.概述
尊敬的开发者朋友，欢迎您使用ADCDN广告sdk平台。通过本文档，您可以轻松的在几分钟之内完成广告的集成过程。

## 2.SDK接入流程
### 2.1 添加sdk到工程
接入环境：Xcode 
可以复制Demo中ADCDN_Framework文件目录下的Framework到项目中。

### 2.2 添加依赖库
```
StoreKit.framework
MobileCoreServices.framework
WebKit.framework
MediaPlayer.framework
CoreMedia.framework
AVFoundation.framework
CoreTelephony.framework
SystemConfiguration.framework
AdSupport.framework
CoreMotion.framework
CoreLocation.framework
QuartzCore.framework
Security.framework
libxml2.tbd
libresolv.9.tbd
libc++.tbd
libz.tbd
```

### 2.3 在Target->Build Settings -> Other Linker Flags中添加-ObjC, 字母o和c大写。

## 3. 权限申请
### 3.1 SDK 不会主动获取应用位置权限，当应用本身有获取位置权限逻辑时，需要在应用的 info.plist 添加相应配置信息，避免 App Store 审核被拒：
```
   //应用根据实际情况配置
   Privacy - Location When In Use Usage Description
   Privacy - Location Always and When In Use Usage Description
   Privacy - Location Always Usage Description
   Privacy - Location Usage Description
```

### 3.2 苹果公司在iOS9中升级了应用网络通信安全策略，默认推荐开发者使用HTTPS协议来进行网络通信，并限制HTTP协议的请求。为了避免出现无法拉取到广告的情况，我们推荐开发者在info.plist文件中增加如下配置来实现广告的网络访问：（信任HTTP请求）
```
<key>NSAppTransportSecurity</key>
    <dict>
         <key>NSAllowsArbitraryLoads</key>
         <true/>
    </dict>
```
## 4. 接入代码
### 4.1 sdk初始化
提示：appid请联系商务获取，并在AppDelegate的didFinishLaunchingWithOptions方法中进行SDK初始化
```
[ADCDN_ConfigManager shareManagerWithAppID:@"APPID"];
```
### 4.2 开屏广告示例
```
CGRect frame = [UIScreen mainScreen].bounds;
ADCDN_SplashAdManager *manage = [ADCDN_SplashAdManager shareManager];
manage.window = self.window;
manage.wFrame = frame;
manage.delegate = self;
[manage loadSplashAd];
```
### 4.2.1 接入代理 ADCDN_SplashAdManagerDelegate
```
/**
*  开屏广告成功展示
*/
- (void)ADCDN_SplashAdSuccessPresentScreen:(ADCDN_SplashAdManager *_Nullable)splashAd {
NSLog(@"%s---%@",__FUNCTION__,@"开屏广告成功展示");
}
/**
*  开屏广告展示失败
*/
- (void)ADCDN_SplashAdFailToPresent:(ADCDN_SplashAdManager *_Nullable)splashAd withError:(NSError *_Nullable)error {
NSLog(@"%s---%@ error:%@",__FUNCTION__,@"开屏广告展示失败",error);
}
/**
*  开屏广告曝光回调
*/
- (void)ADCDN_SplashAdExposured:(ADCDN_SplashAdManager *_Nullable)splashAd {
NSLog(@"%s---%@",__FUNCTION__,@"开屏广告曝光回调");
}
/**
*  开屏广告点击回调
*/
- (void)ADCDN_SplashAdClicked:(ADCDN_SplashAdManager *_Nullable)splashAd {
NSLog(@"%s---%@",__FUNCTION__,@"开屏广告点击回调");
}
/**
*  开屏广告将要关闭回调
*/
- (void)ADCDN_SplashAdWillClosed:(ADCDN_SplashAdManager *_Nullable)splashAd {
NSLog(@"%s---%@",__FUNCTION__,@"开屏广告将要关闭回调");
}
/**
*  开屏广告关闭回调
*/
- (void)ADCDN_SplashAdClosed:(ADCDN_SplashAdManager *_Nullable)splashAd {
NSLog(@"%s---%@",__FUNCTION__,@"开屏广告关闭回调");
}
```
### 4.3 原生广告示例
```
ADCDN_NativeAdManager *nativeAd = [ADCDN_NativeAdManager shareManager];
nativeAd.rootViewController = self;
nativeAd.delegate = self;
nativeAd.customView = self.customview;
[nativeAd loadNativeAd];
```
### 4.3.1 接入代理 ADCDN_NativeAdManagerDelegate
```
/// 加载成功
- (void)ADCDN_NativeAdDidLoad:(ADCDN_NativeAdManager *)nativeAd {
NSLog(@"%s----%@",__FUNCTION__,@"加载成功");
}
/// 加载失败
- (void)ADCDN_NativeAd:(ADCDN_NativeAdManager *)nativeAd didFailWithError:(NSError *_Nullable)error {
NSLog(@"%s----%@",__FUNCTION__,@"加载失败");
}
/// 点击广告时
- (void)ADCDN_NativeAdDidClick:(ADCDN_NativeAdManager *)nativeAd {
NSLog(@"%s----%@",__FUNCTION__,@"点击广告时");
}
/// 曝光回调
- (void)ADCDN_NativeAdDidBecomeVisible:(ADCDN_NativeAdManager *)nativeAd {
NSLog(@"%s----%@",__FUNCTION__,@"曝光回调");
}
```

