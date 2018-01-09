//
//  LYTSDKConversationManagerProtocol.h
//  LeYingTong
//
//  Created by Vieene on 2017/3/20.
//  Copyright © 2017 深圳柒壹思诺科技有限公司. All rights reserved.
//

#ifndef LYTSDKConversationManagerProtocol_h
#define LYTSDKConversationManagerProtocol_h

#define LYTMaxCount NSIntegerMax
#define LYTMaxVernierIndex NSIntegerMax

#import "LYTBaseManagerProtocol.h"

typedef void(^LYTQueryMessageBlock)(NSArray<LYTMessage *>*mesages,LYTError *error);

// 查询方向
typedef NS_ENUM(NSInteger,LYTQueryDirection) {
    LYTQueryDirectionUp     = 0, // 向上查询
    LYTQueryDirectionDown   = 1, // 向下查询
};


/********************************************************************/
@protocol LYTSDKConversationManagerProtocol <LYTBaseManagerProtocol>

/**
 保存自定义消息到本地数据库

 @param messages 消息数组
 @param complete 完成回调
 */
- (void)addMessageToDB:(NSArray <LYTMessage *>*)messages complete:(LYTCompleteBlock)complete;



#pragma mark - delete 删除消息
/**
 删除本地的一条消息
        -- messageId 不为空
 
 @param message 消息
 */
- (void)chatTabledeleteMessage:(LYTMessage *)message complete:(LYTCompleteBlock)complete;

/**
  清空本地的某个会话下的所有消息记录

 @param sessionId 会话Id

 @param complete 完成回调 有error清除失败
 */
- (void)emptyConversasionMessagesWithSessionId:(NSString *)sessionId  complete:(LYTCompleteBlock)complete;

#pragma mark - update
/**
 设置某条消息为已查看
     -- 跟设置未读数无关
     -- 仅仅只是单个消息的已读状态 (例如：语音消息的未读状态)
 
 @param message 消息模型
 @param compelte 完成回调
 */
- (void)checkMessage:(LYTMessage *)message complete:(LYTCompleteBlock)compelte;



/**
 更新消息内容 
    -- 如:已下载某个文件 需要更新本地内容

 @param message 要更新的消息  需要关键字段: messageIndex、sendUserId、targetId、sessionType、messageBody
 @param compelte 完成回调
 */
- (void)updateMessage:(LYTMessage *)message complete:(LYTCompleteBlock)compelte;

#pragma mark - query
/**
 查询本地消息记录
     -- 分页查询

 @param sessionId 会话ID
 @param messageId 消息ID  传nil的时候默认是查最新的  查询的结果不会包含本messageId消息的向上多少条或者向下多少条
 @param count 查询的数量 大于0
 @param direction 查询的方向
 @param complete 完成回调
         -- 有error 查询失败
         -- 返回值messages 默认按照本地时间排序
 */
- (void)dbChatTableGetMessagesFromSession:(NSString *)sessionId
                                messageId:(NSString *)messageId
                                    count:(NSUInteger)count
                           queryDirection:(LYTQueryDirection)direction
                                 complete:(LYTQueryMessageBlock)complete;


#pragma mark - 网络获取消息记录
/**
 查询某个会话下的历史消息  分页查询方式

 @param sessionId sdk 内部使用
 @param chatIndex 查询的起始index，默认为1
 @param count 查询的数量，默认20条
 @complete 完成回调  有error 获取数据失败
 */
- (void)fetchHistoryMsgWithSessionId:(NSString *)sessionId
                           fromIndex:(long)chatIndex
                               count:(NSUInteger)count
                            complete:(LYTQueryMessageBlock)complete;

#pragma mark - 查询未读数
/**
 查询会话列表未读数

 @param sessionIds 会话ID列表  不能为空或空数组
 @param complete 完成回调
     -- unreadCounts 为nil 查询失败， unreadCounts数组每个元素与传进来的会话列表每个元素与之对应
     -- totalUnread 本次查询的会话总未读数
 
 */
- (void)unreadCountWithSessions:(NSArray <NSString *>*)sessionIds
                       complete:(void(^)(NSArray<NSNumber *>* unreadCounts,NSInteger totalUnread))complete;

#pragma mark - 获取最后一条消息
/**
 通过sessionIDs 获取对应的最后一条消息

 @param sessionIds 会话id组
 @param complete  完成回调
        --- data  每个sessionid 对应的最后一条消息对象
 */
- (void)fetchLastMessagesWithSessionIDs:(NSArray <NSString *>*)sessionIds complete:(void(^)(NSDictionary<NSString *,LYTMessage *>* data))complete;


@end

#endif /* LYTSDKConversationManagerProtocol_h */
