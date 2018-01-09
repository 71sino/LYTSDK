//
//  LYTGlobalEnum.h
//  LeYingTong
//
//  Created by admin on 16/12/23.
//  Copyright © 2016年 深圳柒壹思诺科技有限公司. All rights reserved.
//

#ifndef SDKGlobalEnum_h
#define SDKGlobalEnum_h
// 消息类型 !< message type
typedef NS_ENUM(NSInteger,LYTMessageType) {
    // 普通消息
    LYTMessageTypeReceipt           = 1000, // 回执消息
    LYTMessageTypeText              = 1001, // 文本
    LYTMessageTypeImage             = 1002, // 图片
    LYTMessageTypeVoice             = 1003, // 音频
    LYTMessageTypeVideo             = 1004, // 视频
    LYTMessageTypeFile              = 1005, // 文件
    LYTMessageTypeLocation          = 1006, // 地理位置
    LYTMessageTypeMixtureText       = 1007, // 图文混合
    LYTMessageTypeTipMsg            = 1008, // @消息
    LYTMessageTypeMultiAudioChat    = 1009, // 多人音视频
    LYTMessageTypeP2PFileRecepit    = 1010, // 点对点文件接收回执
    LYTMessageTypeDistructRecepit   = 1011, // 阅后即焚已读回执消息
    LYTMessageTypeMass              = 1012, // 群发助手消息
    LYTMessageTypeP2PAudioChat      = 1013, // 单人音视频
    LYTMessageTypeRevoke            = 1014, // 撤销一条消息
    LYTMessageTypeCustom            = 3898, // 自定义消息
    LYTMessageTypeRealTime          = 3899, // 透传消息 （自定义主题消息）
};


// 混排结构 类型
typedef NS_ENUM(NSUInteger,LYTContentType) {
    LYTContentTypeLineFeed  = 0000,  // 换行结构
    LYTContentTypeText      = 1001,  // 文本内容结构
    LYTContentTypePicture   = 1002,  // 图片结构
    LYTContentTypeTipsAll   = 1111,  // @全体成员
    LYTContentTypeTipBodys  = 1112,  // @成员
};


// 用户状态
typedef NS_ENUM(NSInteger,LYTAuthStatus) {
    
    LYTAuthStatusOffline     =  2100,  // 用户离线
    LYTAuthStatusOnline      =  2101,  // 用户在线
    LYTAuthStatusLeave       =  2102,  // 用户离开
    LYTAuthStatusBusy        =  2103,  // 用户忙碌
    //LYTAuthStatusExqueted    =  2108,  // 用户被踢出
    LYTAuthStatusDead        =  2109,  // 用户账号被停用
    LYTAuthStatusInfoChange  =  2110,  // 用户信息变更 （头像、名称等）
    LYTAuthStatusPwdChanged  =  2111,  // 用户修改密码，踢出登录
    LYTAuthStatusLogOutForce =  2112,  // 强制退出登录
};


// 聊天室、讨论组 通知类型
typedef NS_ENUM(NSInteger,LYTChatNotiType)  {
    // 聊天室的
    LYTChatRoomNotiTypeCreate       =  2201,  // 创建聊天室
    LYTChatRoomNotiTypeDismiss      =  2202,  // 解散聊天
    LYTChatRoomNotiTypeAddMember    =  2203,  // 聊天室成员变更 (增加成员)
    LYTChatRoomNotiTypeDelMember    =  2204,  // 聊天室成员变更 （删除成员）
    LYTChatRoomNotiTypeQuitChat     =  2205,  // 聊天室成员变更 （成员退出）
    LYTChatRoomNotiTypeInfoChange   =  2206,  // 聊天室成员变更 （备注信息变更）
    LYTChatRoomNotiTypeUpdate       =  2207,  // 聊天室更新 （包括头像、名称等）
    LYTChatRoomNotiTypeReadDestroy  =  2291,  // 聊天室是阅后即焚模式
    LYTChatRoomNotiTypeNormalMsg    =  2292,  // 聊天室是普通消息模式
    
    // 讨论组的
    LYTGroupNotiTypeCreate       =  2501,  // 创建讨论组
    LYTGroupNotiTypeDismiss      =  2502,  // 解散聊天
    LYTGroupNotiTypeAddMember    =  2503,  // 讨论组成员变更 (增加成员)
    LYTGroupNotiTypeDelMember    =  2504,  // 讨论组成员变更 （删除成员）
    LYTGroupNotiTypeQuitChat     =  2505,  // 讨论组成员变更 （成员退出）
    LYTGroupNotiTypeInfoChange   =  2506,  // 讨论组成员变更 （备注信息变更）
    LYTGroupNotiTypeUpdate       =  2507,  // 讨论组更新 （包括头像、名称等）
    LYTGroupNotiTypeOwnerChange  =  2508,  // 讨论组群主转让
    LYTGroupNotiTypeManagerChange=  2509,  // 管理员发送变更
};

// 讨论组公告 通知
typedef NS_ENUM(NSUInteger,LYTNotificationType) {
    LYTNotificationTypeUnread  =  2580,  // 用户未读的公告 （用于更新公告未读数）
    LYTNotificationTypeCreate  =  2581,  // 新增讨论组公告
    LYTNotificationTypeDelete  =  2582,  // 删除讨论组公告
    LYTNotificationTypeRead    =  2583,  // 讨论组公告已读（多终端同步）
};

// 群聊中 阅后即焚模式通知
typedef NS_ENUM(NSInteger,LYTGroupDestructMode) {
    LYTGroupDestructModeDestroy  = 2591,  // 讨论组是阅后即焚模式
    LYTGroupDestructModeNormal   = 2593,  // 讨论组是普通消息模式
    LYTGroupDestructModeClear    = 2592,  // 清除阅后即焚消息
};

// 邀请加入会话通知
typedef NS_ENUM(NSInteger,LYTSessionInvitionNoti) {
    LYTSessionInvitionNotiInvite       =  2401,  // 邀请加入会话
    LYTSessionInvitionNotiDeal         =  2402,  // 处理邀请会话(同意或拒绝邀请)
};

// 处理加入会话通知
typedef NS_ENUM(NSInteger,LYTSessionDealInvition) {
    LYTSessionInvitionAccept       =  1,  // 接受加入
    LYTSessionInvitionReject       =  2,  // 拒绝加入
};

// 终端来源
typedef NS_ENUM(NSInteger,LYTOSType) {
    LYTOSTypePC       = 1,  // PC端
    LYTOSTypeWEB      = 2,  // WEB端
    LYTOSTypeANDROID  = 3,  // ANDROID
    LYTOSTypeiOS      = 4,  // iOS
    LYTOSTypeServer   = 5   // 服务器
};


// 会话类型
typedef NS_ENUM(NSUInteger, LYTSessionType) {
    /** 未知 */
    LYTSessionTypeUnknown    = 0,
    /** 点对点 */
    LYTSessionTypeP2P        = 1,
    /** 聊天室 */
    LYTSessionTypeChatRoom   = 2,
    /** 评论 */
    LYTSessionTypeComment    = 3,
    /** 群组 */
    LYTSessionTypeGroup      = 4
};


// 发送状态
typedef NS_ENUM(NSUInteger, LYTMessageSendState) {
    
    /** 初始状态 */
    LYTMessageStateBegin = 1,
    
    /** 正在发送 */
    LYTMessageStateSending = 2,
    
    /** 发送成功 */
    LYTMessageStateSuccess = 3,
    
    /** 发送失败 */
    LYTMessageStateFail = 4 ,
    
    /** 消息已发布 但未确认回执 */
    LYTMessageStatePublished = 5
    
};

// 消息状态
typedef NS_ENUM(NSUInteger, LYTMessageState) {
    /** 未读 */
    LYTMessageStateUnread = 0,
    
    /** 已读 与未读数相关 */
    LYTMessageStateRead   = 1,
    
    /** 已查看 与消息阅读状态有关 例如：语音未读数已清，但还未查看 */
    LYTMessageStateCheck  = 2
    
};


// 屏蔽消息级别
typedef NS_ENUM(NSUInteger, LYTRecieveMessageNotiLevel) {
    /** 普通提示 */
    LYTRecieveMessageNotiNormal = 1,
    
    /** 免提示打扰 （产生聊天记录但不提示用户）*/
    LYTRecieveMessageNotiUndisturb = 2,
    
    /** 免消息接受 （完全屏蔽:不产生接受消息流量） */
    LYTRecieveMessageNotiUnreceived = 3
};


#endif /* SDKGlobalEnum_h */
