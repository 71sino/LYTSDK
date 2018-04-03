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
 是否打印调试bug信息 （默认设置为NO）
 
 @param isLog 是否开启打印
 -- YES 开启打印SDK   log信息
 -- NO  不打印内部SDK log信息
 */
+ (void)isPrintDebugLog:(BOOL)isLog;


#pragma mark - 停用的方法
/**
 设置是否切换到外网环境 --- 该接口内部默认转换成生产环境
 
 @param isProduct YES:使用生成环境 ; NO:预发布环境（默认值）
 @return 是否允许更改(当前有用户登录时不允许更改) 返回YES时即允许更改并已更改
 */
+ (BOOL)setProductNetWork:(BOOL)isProduct __attribute__((deprecated("‘+setProductNetWork:’ Forbidden use!")));

@end
