//
//  LYTPush.h
//  LYTSDK
//
//  Created by hhly on 2017/11/1.
//  Copyright © 2017年 深圳柒壹思诺科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

#define LYT_PUSH_VERSION @"2.5.0"

typedef void(^LYTPushSuccessBlock)(void);
typedef void(^LYTPushErrorBlock)(void);

// 推送环境
typedef NS_ENUM(NSInteger,LYTPushEnvironment) {
    LYTPushEnvironmentUnkown  = 0,   // 未知 不能推送
    LYTPushEnvironmentRelease = 1,   // 发布 APP  发布的时候使用
    LYTPushEnvironmentDebug   = 2,   // 调试的时候 使用
};


/*
 *  应用统一设置 配置
 */
@interface LYTPush : NSObject

/**
 查询推送是否打开(以弹窗为准)
 
 @param result 查询回调.若推送打开,回调参数为 YES, 否则为 NO
 */
+ (void)lyt_isPushOn:(nullable void(^)(BOOL isOn)) result;


/**
 初始化LYTPush   在app delegate 的 ‘didFinishLaunchingWithOptions’ 中调用
 
 @param appId 通过信鸽申请的应用ID
 @param appKey 通过信鸽申请的appKey
 @param appSecret 通过信鸽申请的密钥
 @param environment 推送环境
 */
+ (void)lyt_startApp:(uint32_t)appId
              appKey:(nonnull NSString *)appKey
           appSecret:(nonnull NSString *)appSecret
         environment:(LYTPushEnvironment)environment;

/**
 注册设备
 
 @param deviceToken 通过app delegate的‘didRegisterForRemoteNotificationsWithDeviceToken’回调的获取
 @param successCallback 成功回调
 @param errorCallback 失败回调
 @return  获取的 deviceToken 字符串
 */
+ (nullable NSString *)lyt_registerDevice:(nonnull NSData *)deviceToken
                          successCallback:(nullable LYTPushSuccessBlock)successCallback
                            errorCallback:(nullable LYTPushErrorBlock) errorCallback;


/**
 注销设备，设备不再进行推送
 
 @param successCallback 成功回调
 @param errorCallback 失败回调
 */
+ (void)lyt_unRegisterDevice:(nullable LYTPushSuccessBlock)successCallback
               errorCallback:(nullable LYTPushErrorBlock) errorCallback;

/**
 判断当前是否是已注销状态
 
 @return 是否已经注销推送
 */
+ (BOOL)lyt_isUnRegisterStatus;


/**
 *  开启LOG 关闭LOG
 *
 *  SETTER AND GETTER
 */
+ (void)lyt_enableDebug:(BOOL)enbaleDebug;
+ (BOOL)lyt_isEnableDebug;
@end
