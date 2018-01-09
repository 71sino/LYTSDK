//
//  LYTSDKSetting.h
//  LYTSDK
//
//  Created by Shangen Zhang on 2017/9/27.
//  Copyright © 2017年 深圳柒壹思诺科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface LYTSDKSetting : NSObject
/**
 设置是否切换到外网环境
 
 @param isProduct YES:使用外网 ; NO:使用内网（默认值）
 @return 是否允许更改(当前有用户登录时不允许更改) 返回YES时即允许更改并已更改
 */
+ (BOOL)setProductNetWork:(BOOL)isProduct;


/**
 是否打印调试bug信息 （默认设置为NO）
 
 @param isLog 是否开启打印
 -- YES 开启打印SDK   log信息
 -- NO  不打印内部SDK log信息
 */
+ (void)isPrintDebugLog:(BOOL)isLog;
@end
