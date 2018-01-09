//
//  LYTBaseManagerProtocol.h
//  LeYingTong
//
//  Created by admin on 17/1/3.
//  Copyright © 2017年 深圳柒壹思诺科技有限公司. All rights reserved.
//

#ifndef LYTBaseManagerProtocol_h
#define LYTBaseManagerProtocol_h

#import <UIKit/UIKit.h>

#import "LYTError.h"
#import "LYTGlobalEnum.h"


typedef void(^LYTCompleteBlock)(LYTError *error);
@class  LYTSDK;



/** SDK 基础功能协议 */
@protocol LYTSDKDelegate <NSObject>

/**
 SDK 被强制退出登录
 
 @param sdk sdk 实例
 @param error sdk退出的原因
 */
- (void)sdk:(LYTSDK *)sdk didForceLogoutWithError:(LYTError *)error;


@optional

// 内部已实现自动连接功能
/**
 *  socket的连接成功
 *  socket的失去连接
 *  socket的连接失败
 */
- (void)socketDidConnectedWithSDK:(LYTSDK *)sdk;
- (void)socketDidDisconnectWithSDK:(LYTSDK *)sdk;
- (void)sdk:(LYTSDK *)sdk socketDidConnectedFail:(LYTError *)error;

@end






/************************************************************/
/** SDK manager 基协议 */
@protocol LYTBaseManagerProtocol <NSObject>

/**
 添加代理监听 多个对象可以同时成为他的代理 只要调用这个方法就可以啦
 
 @param delegate 代理
 */
- (void)addDelegate:(id)delegate;

/**
 移除一个代理
 
 @param delegate 代理对象
 */
- (void)deleteDelegate:(id)delegate;

@end

#endif /* LYTBaseManagerProtocol_h */
