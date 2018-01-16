//
//  LYTSDK.h
//  LeYingTong
//
//  Created by HHLY on 2016/12/23.
//  Copyright © 2016年 深圳柒壹思诺科技有限公司. All rights reserved.
//


// SDK 模块协议
#import "LYTSDKChatRoomProtocol.h"
#import "LYTSDKChatManagerProtocol.h"
#import "LYTSDKConversationManagerProtocol.h"
// 文件上传工具
#import "LYTUploadManagerProtocol.h"
// 设置类
#import "LYTSDKSetting.h"
#import "LYTPush.h"

@interface LYTSDK : NSObject


/**
 必须 通过 initWithProductId:messageTypeRange 方法 进行初始化
 */
- (instancetype)init __attribute__((unavailable("‘init’ Forbidden use!")));
/**
 实例
 
 @param company 公司代码（注册）
 @param key appKey
 @param secret appSecret
 @return 创建的实例
 
 
 
 说明:
 1.sdk接入方 使用当前方法进行 实例初始化
 2.sdk接入方 可以通过 继承当前类，再实现个sharedSDK(),做一个单例，方便方法的调用。  我们强烈推荐该方法。
 eg:
 
 @ interface LYTSUBCLASSSDK : LYTSDK
 + (instancetype)sharedSDK;
 @end
 
 @implementation LYTSUBCLASSSDK
 
 + (instancetype)sharedSDK {
 static LYTTESTSDK *_instance = nil;
 static dispatch_once_t onceToken;
 dispatch_once(&onceToken, ^{
 _instance = [[self alloc] initWith:@"your_comany_code" appKey:@"your_app_key" appSecret:@"your_app_sectet"];
 });
 return _instance;
 }
 
 */
- (instancetype)initWith:(NSString *)company appKey:(NSString *)key appSecret:(NSString *)secret;

/**
 *  获取SDK版本号
 *  @return 当前SDK的版本号
 */
- (NSString *)sdkVersion;

/**
 获取当前appkey
 
 @return 当前appkey
 */
- (NSString *)getCurrentAppKey;

/**
 获取当前company
 @return 当前company
 */
- (NSString *)getCurrentCompany;

/**
 当前用户
 @return 当前用户userId
 */
- (NSString *)currentUser;


/**
 *  LYTSDKDelegate代理对象
 */
@property(nonatomic,weak) id <LYTSDKDelegate> delegate;


/**
 *  消息接收 发送 管理类 （详阅LYTSDKChatManagerProtocol头文件）
 */
@property (nonatomic,strong,readonly)   id <LYTSDKChatManagerProtocol> chatManager;

/**
 *  会话管理类,负责消息,会话内容的读写和管理 （详阅LYTSDKConversationManagerProtocol头文件）
 */
@property (nonatomic,strong,readonly)   id <LYTSDKConversationManagerProtocol> conversationManager;

/**
 *  聊天室 通知类 （详阅LYTSDKChatRoomProtocol头文件）
 */
@property (nonatomic,strong,readonly)   id <LYTSDKChatRoomProtocol> chatRoomManager;

/** 上传工具 */
@property (nonatomic,strong,readonly) id <LYTUploadManagerProtocol> uploadManager;


/**
 SDK是否登录
 YES --- 已登录
 NO  --- 未登录, 需要调用  loginSDKWithUserId:forceLogin:complete方法进行登录
 */
@property(nonatomic,assign,readonly) BOOL isLogined;



#pragma mark - 初始化配置 方法
/**
 设置SDK是否需要使用 聊天室、讨论组功能 默认都不加载
        -- 登录之前要配置 默认都设置为NO
 
 @param isChatRoom 是否需要聊天室功能
 @param isGroup 是否需要讨论组功能
 */
- (void)setChatRoomEnable:(BOOL)isChatRoom groupEnable:(BOOL)isGroup;

/**
 设置是否接收离线消息

 @param shouldReceive 是否接收离线消息 （默认YES）
 */
- (void)setShouldReceiveOfflineMessage:(BOOL)shouldReceive;


/**
 设置重连发送的超时 （默认15s）
 sendTmieOut 设置在[10s,60s]
 
 @param sendTmieOut 重连超时时间
 */
- (void)setSendTimeOut:(NSTimeInterval)sendTmieOut;

#pragma mark - 设置登录失败是否立即返回
/**
 设置登录接口失败是否立即给回调标志

 @param bImmediateFlag
 YES---登录失败,立即返回，sdk不进行重连操作. 默认值为YES
 NO ---登录失败，多次尝尝试重连后返回接口。   这个参数导致上层拿到的回调时间延后,最糟糕情况下 60s后返回。
 */
- (void)setCallBackImmedWhenLoginFailed:(BOOL)bImmediateFlag;

#pragma mark - 登录接口
/**
 SDK 登录接口

 @param uid 登录者的uid --- 应用方需保证唯一
 @param bFlag 登录失败是否使用本地数据库数据  YES:登录失败,使用本地数据库数据， NO:登录成功时才使用本地数据库数据。--- tips:应用方根据需求使用,建议设置为NO。
 @param complete 登录接口的结果回调。error = nil时:登录成功，  error != nil:登录失败，error中附带登录失败的原因
 -- 退出当前账号时  请务必调用 logoutWithComplete: 方法。
 */
- (void)loginSDKWith:(NSString *)uid useDbWhenLoginFailed:(BOOL)bFlag complete:(void(^)(LYTError *error))complete;

#pragma mark - 退出登录

/**
 SDK退出登录
 */
- (void)logoutSDK;




#pragma mark - 远程推送铃声修改
/**
 更新远程推送的铃声
     -- 默认为 常规铃声
     -- 必须先 注册deviceToken 才能生效 且 要开启推送才有效
 
 @param sound 铃声
 */
- (void)updateRemotePlaySound:(NSString *)sound;

#pragma mark - 自定义主题消息订阅 （一般用于接受透传消息）
/**
 订阅自定义消息主题

 @param customTopics 自定义消息主题数组:实现内部默认为 每个主题 添加了 appkey/ 当前缀
 */
- (void)subscrCustomRealTimeMessageTopids:(NSArray<NSString*> *)customTopics;

/**
 取消订阅自定义消息相关

 @param customTopics 自定义消息主题数组:实现内部默认 每个主题 添加了 appkey/ 当前缀
 */
- (void)cancelSubscrCustomRealTimeMessageTopids:(NSArray<NSString*> *)customTopics;

#pragma mark - 清理本地数据
/**
 清理本地SDK数据库
 */
- (void)clearLocalData;

/**
 设置企业相关信息

 @param company 公司代码（注册）
 @param key appkey
 @param secret appSecret
 */
- (BOOL)setCompany:(NSString *)company appKey:(NSString *)key appSecret:(NSString *)secret;
@end
