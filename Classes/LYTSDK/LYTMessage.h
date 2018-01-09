//
//  LYTMessage.h
//  JMChatDemo
//
//  Created by HHLY on 2016/12/21.
//  Copyright © 2016年 JM. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "LYTMessageBody.h"

@interface LYTMessage : NSObject <NSCoding>

/** 消息体对象内容 */
@property (strong, nonatomic) LYTMessageBody * messageBody;

/**
 @brief 消息体的类型
 */
@property (assign, nonatomic) LYTMessageType messageType;


/** 自定义消息字段	(可以是jsonString) */
@property(nonatomic,copy) NSString * attr;

/** 
 消息发送者ID 
 */
@property(nonatomic,copy) NSString * sendUserId;

/** 消息接收者ID */
@property(nonatomic,copy) NSString * targetId;

/** 
 消息发送者的操作系统  4 为iOS
 */
@property(nonatomic,assign) LYTOSType os;

/** 阅后即焚标识 0普通消息 1是阅后即焚 */
@property(nonatomic,assign) NSInteger flag;

/** 会话类型 */
@property (assign, nonatomic) LYTSessionType sessionType;

/** 时间戳 服务器生接受到消息的时间戳 */
@property (assign, nonatomic) int64_t messageTime;

/** 会话Id  由SDK内部生成 */
@property(nonatomic,copy) NSString *sessionId;

/** 
 消息唯一标识 ID 由SDK内部生成 
 */
@property (copy, nonatomic) NSString * messageId;

/** 
 消息本地Index 由SDK内部生成 
 */
@property(nonatomic,assign) NSUInteger messageIndex;


/** 
 会话内消息的index 服务器存储的ID唯一的标识 
 */
@property(nonatomic,assign) NSUInteger chatIndex;

/** 
 发送消息状态 
    --  保存本地消息时 需要赋值
 */
@property (assign, nonatomic) LYTMessageSendState sendStatus;

/** 
 每一条消息阅读状态  已读、未读
    -- SDK外部 调用 conversationManager 模块设置已读
    例如: 语音消息展示已读还是未读
 
 */
@property (assign, nonatomic) LYTMessageState status;



/**
 阅后即焚延迟删除的时间 (单位:s)
 */
@property (assign,nonatomic) NSInteger delayDeleteTime;

/**
 消息发送者头像
 */
@property(nonatomic,copy) NSString * sendUserHeadUrl;

/**
 消息发送者用户名
 */
@property(nonatomic,copy) NSString * sendUserName;

/** app的唯一标识 */
@property(nonatomic,copy) NSString * appKey;

/**
 消息体文本内容
    -- 消息传输层json文本本质上是消息体对象 (即messageBody)
 */
@property (nonatomic,copy) NSString * content;

/** 发送的主题 默认不用赋值 特殊情况下用的 */
@property (nonatomic,copy)NSString * topic;

#pragma mark - init method
/**
 构造方法

 @param body messageBody
 @return 实例化对象
 */
- (instancetype)initWithMessageBody:(LYTMessageBody *)body;


/**
 构造方法 （传递的参数均不为空或0时 构造的对象可满足发送基本参数）

 @param body messageBody
 @param sessionType 聊天类型
 @param targetId 目标ID
 @return 实例化对象
 */
- (instancetype)initWithMessageBody:(LYTMessageBody *)body sessionType:(LYTSessionType)sessionType targetId:(NSString *)targetId;


/**
 是否是自己发送的  由UI自己控制赋值
 */
@property (assign, nonatomic) BOOL isSender;


@end
