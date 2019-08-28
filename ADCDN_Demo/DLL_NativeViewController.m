//
//  DLL_NativeViewController.m
//  ADCDN_Demo
//
//  Created by DL on 2019/8/28.
//  Copyright © 2019 DLL. All rights reserved.
//

#import "DLL_NativeViewController.h"
#import <ADCDN_BaseSDK/ADCDN_NativeAdManager.h>

@interface DLL_NativeViewController ()<ADCDN_NativeAdManagerDelegate>

@property (nonatomic, strong) UIView *customview;

@property (nonatomic, strong) UIButton *button;

@end

@implementation DLL_NativeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    [self buildupView];
    ADCDN_NativeAdManager *nativeAd = [ADCDN_NativeAdManager shareManager];
    nativeAd.rootViewController = self;
    nativeAd.delegate = self;
    nativeAd.customView = self.customview;
    [nativeAd loadNativeAd];
}
- (void)buildupView {
    CGFloat cusViewWidth = [UIScreen mainScreen].bounds.size.width;
    // Custom view test
    _customview = [[UIView alloc] initWithFrame:CGRectMake(5, 5, cusViewWidth, cusViewWidth)];
    _customview.backgroundColor = [UIColor clearColor];
    [self.view addSubview:_customview];
    _customview.frame = CGRectMake(5, 5, cusViewWidth, cusViewWidth);
    
    self.button = [[UIButton alloc] init];
    self.button.frame = CGRectMake([UIScreen mainScreen].bounds.size.width-100, CGRectGetMaxY(_customview.frame)+5, 100, 50);
    [self.button setTitle:@"刷新广告" forState:UIControlStateNormal];
    [self.button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [self.button addTarget:self action:@selector(buttonTapped:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.button];
}
- (void)buttonTapped:(UIButton *)sender {
    [[ADCDN_NativeAdManager shareManager] loadNativeAd];
}
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

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
