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

/**
 * 柒讯  产品标识
 */
FOUNDATION_EXTERN NSString * const LYTQiXunProductIdentifyString;
/**
 * 智八哥 产品标识
 */
FOUNDATION_EXTERN NSString * const LYTZhiBaGeProductIdentifyString;
/**
 * 评论 产品标识
 */
FOUNDATION_EXTERN NSString * const LYTCommentProductIdentifyString;



@interface LYTSDK : NSObject
/**
 必须 通过 initWithProductId:messageTypeRange 方法 进行初始化
 */
- (instancetype)init __attribute__((unavailable("‘init’ Forbidden use!")));

/**
 实例

 @param productId productId 产品ID
 @param range 对应产品使用到的 消息类型 区间段
 @return 初始化对象


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
         _instance = [[self alloc] initWithProductId:@"LYTTESTProductSDK" messageTypeRange:NSMakeRange(2000, 1500)];
     });
     return _instance;
 }
@end
 */
- (instancetype)initWithProductId:(NSString *)productId messageTypeRange:(NSRange)range;


#pragma mark - getter
/**
 *  LYTSDKDelegate代理对象
 */
@property(nonatomic,weak) id <LYTSDKDelegate> delegate;


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


#pragma mark - 初始化配置 方法
/**
 设置SDK是否需要使用 聊天室、讨论组功能 默认都不加载
        -- 登录之前要配置 默认都设置为NO
 
 @param isChatRoom 是否需要聊天室功能
 @param isGroup 是否需要讨论组功能
 */
- (void)setChatRoomEnable:(BOOL)isChatRoom groupEnable:(BOOL)isGroup;


/**
 初始化SDK 
        -- 正常登录SDK之前必须调用该方法

 @param company 公司代码（注册）
 @param appKey APPKey
 @param appSecret app密钥
 */
- (void)configSDKCompany:(NSString *)company appKey:(NSString *)appKey appSecret:(NSString *)appSecret;


/**
 设置是否接收离线消息

 @param shouldReceive 是否接收离线消息 （默认yes）
 */
- (void)setShouldReceiveOfflineMessage:(BOOL)shouldReceive;

/**
 设置重连发送的超时 （默认15s）
sendTmieOut 设置在[10s,60s]

 @param sendTmieOut 重连超时时间
 */
- (void)setSendTimeOut:(NSTimeInterval)sendTmieOut;

#pragma mark - 用户功能模块相关属性
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

#pragma mark - 登录相关
/**
 登录SDK --- 同时用来替换 autoLoginSDK 方法

 @param userId 登录的用户
 @param forceLogin 强制登录
        -- 设置为 YES 时 即使登录失败（只要不调用退出登录‘loginOut’ 或者 被挤下线）也可以访问数据库
           而且登录失败后自动 重新发起登录
        -- 设置为 NO 代表 登录失败 即为退出登录
 
 @param complete 完成回调 有error 登录失败 没有error登录成功
        -- 注意: 当 error的code为 ‘LYTErrorCodeDidLogin’ 时 表示SDK 已登录 
                在 error info中会返回userId表示已登录的账号
 
        -- 如果需要切换账号需要 先调用 ‘logotWithComplete:’ 再调用登录接口

 */
- (void)loginSDKWithUserId:(NSString *)userId forceLogin:(BOOL)forceLogin complete:(void(^)(LYTError *error))complete;


/**
 退出登录
     -- 成功退出登录后 改对象（LYTSDK实例所有的推送）将不会接收到信息推送
 */
- (void)logoutWithComplete:(void(^)(LYTError *error))complete;


/** 
 是否登录
 */
@property(nonatomic,assign,readonly) BOOL isLogin;

#pragma mark - 通讯相关（SDKSocket连接相关）
/**
  通讯功能是否处于连接状态
 
 @return YES 为已连接 NO 为未连接
 */
- (BOOL)isConnected;

#pragma mark - 远程推送相关

/**
 该实例是否开启远程推送 默认为NO

 @param remoteEnable 是否开启远程推送
 */
- (void)setRemotePushEnable:(BOOL)remoteEnable;

/**
 更新远程推送的铃声
     -- 默认为 常规铃声
     -- 必须先 注册deviceToken 才能生效 且 要开启推送才有效
 
 @param sound 铃声
 */
- (void)updateRemotePlaySound:(NSString *)sound;

#pragma mark - 自定义主题消息订阅 （一般用于接受透传消息）
/**
 订阅自定义相关消息

 @param customTopics 自定义主题数组
 */
- (void)subscrCustomRealTimeMessageTopids:(NSArray<NSString*> *)customTopics;

/**
 取消订阅自定义相关消息

 @param customTopics 自定义主题数组
 */
- (void)cancelSubscrCustomRealTimeMessageTopids:(NSArray<NSString*> *)customTopics;

#pragma mark - 清理本地数据
/**
 清理本地SDK数据库
 */
- (void)clearLocalData;



@end
