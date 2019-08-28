# ADCDN_Demo

1.概述
尊敬的开发者朋友，欢迎您使用ADCDN广告sdk平台。通过本文档，您可以轻松的在几分钟之内完成广告的集成过程。

2.SDK接入流程
2.1 添加sdk到工程
接入环境：Xcode 可以复制Demo中ADCDN_Framework文件目录下的Framework到项目中。

2.2 添加依赖库
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

2.3 在Target->Build Settings -> Other Linker Flags中添加-ObjC, 字母o和c大写。

3. 权限申请
3.1 SDK 不会主动获取应用位置权限，当应用本身有获取位置权限逻辑时，需要在应用的 info.plist 添加相应配置信息，避免 App Store 审核被拒：
   //应用根据实际情况配置
   Privacy - Location When In Use Usage Description
   Privacy - Location Always and When In Use Usage Description
   Privacy - Location Always Usage Description
   Privacy - Location Usage Description

3.2 苹果公司在iOS9中升级了应用网络通信安全策略，默认推荐开发者使用HTTPS协议来进行网络通信，并限制HTTP协议的请求。为了避免出现无法拉取到广告的情况，我们推荐开发者在info.plist文件中增加如下配置来实现广告的网络访问：（信任HTTP请求）  
<key>NSAppTransportSecurity</key>
    <dict>
         <key>NSAllowsArbitraryLoads</key>
         <true/>
    </dict>
