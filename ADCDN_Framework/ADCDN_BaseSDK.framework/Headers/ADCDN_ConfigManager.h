//
//  ADCDN_ConfigManager.h
//  ADCDN_BaseSDK
//
//  Created by DL on 2019/8/16.
//  Copyright © 2019 DLL. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface ADCDN_ConfigManager : NSObject

+ (instancetype)shareManagerWithAppID:(NSString *)appId;

+ (NSString *)getAppId;

@end

