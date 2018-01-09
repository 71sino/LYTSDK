//
//  LYTSDKChatManagerProtocol.h
//  LeYingTong
//
//  Created by admin on 16/12/26.
//  Copyright © 2016年 深圳柒壹思诺科技有限公司. All rights reserved.
//

#ifndef LYTSDKChatManagerProtocol_h
#define LYTSDKChatManagerProtocol_h

#import "LYTBaseManagerProtocol.h"
#import "LYTMessage.h"


// block回调
typedef void(^LYTSendCompleteBlock)(LYTError *error,LYTMessageSendState statues);
typedef void(^LYTSendReceiptBlock)(LYTMessage *receiptMessage, LYTError *error);
typedef void(^LYTSendProgressBlock)(CGFloat progress);



#pragma mark - LYTSDKChatManagerDelegate 接受消息

/** 监听 并接受数据 SDK外部实现 */
@protocol LYTSDKChatManagerDelegate <NSObject>

/**
 收到一条消息
 描述：收到即时消息(在线消息)
 @param message 消息模型
 */
- (void)didReceiveOnlineMessage:(LYTMessage *)message;

/**
 接收到离线消息
 描述：在手机进入后台以后，假如有未收到的消息，就会通过离线消息传输过来。在刚刚登录或者刚刚进入到前台的时后会收到
 @param messages 离线消息数组
 */
- (void)didReceiveOfflineMessages:(NSArray<LYTMessage *> *)messages;



/**
 接收到透传消息 （自定义主题消息）
 描述：改消息将不保存到数据库，只有在线消息没有离线消息
 @param message 透传消息模型
 */
- (void)didReceiveRealTimeMessage:(LYTMessage *)message;

@optional
/**
 接收到回执消息
 -- 其他功能： 代表该消息发送成功到服务器 可以用于第二次进入聊天界面时候 没有block回调刷新消息发送成功通知 的界面即时刷新
 @param message 回执消息
 没有message body
 -- 匹配规则:  同一个会话下 messageId 相同

 */
- (void)didReceiveReceiveReceiptMessage:(LYTMessage *)message;


/**
 对话界面需要刷新
 描述：用来处理接收消息错位
 场景: 使用服务器index 排序的 需要重新刷新界面
 
 @param sessionId 需要重新获取会话内容并刷新界面的会话sessionId
 相关联的接口:didReceiveOnlineMessage: 和 didReceiveOfflineMessagesdidReceiveOfflineMessages：
 */
- (void)chatViewNeedRefreshDataWithSessionId:(NSString *)sessionId;


/**
 第三方根据自己业务需求来确定消息是否保存
 @param message 需要判断的消息
 @return YES-保存入库，NO-丢弃掉
 */
- (BOOL)shouldSaveMessageIntoDB:(LYTMessage *)message;

@end



/***************************************************************/
#pragma mark - LYTSDKChatManagerProtocol 发送消息
@protocol LYTSDKChatManagerProtocol <LYTBaseManagerProtocol>
// 添加代理
- (void)addDelegate:(id<LYTSDKChatManagerDelegate>)delegate;
/**
 根据会话 加载离线消息
    该方法必须确保当前处于连接状态

 @param sessionIds 会话ID
 @param complete 完成回调
 */
- (void)requestOfflineMessageWithSessions:(NSArray <NSString *>*)sessionIds complete:(LYTCompleteBlock)complete;

#pragma mark - Send functionC
/**
 * 发送新消息 / 重发消息   监听服务器回执
        --（判断消息重发的依据是messageIndex != 0）
 
 @param message 消息模型
        -- 模型必须包含targetId、sessionType、messageBody三个字段
 @param shouldSave 是否需要保存到数据库产生聊天记录 
                    一般传YES 传NO时不会产生列表
 
 @param progress  媒体文件上传进度 用于监听上传进度 其他不用上传文件的消息不会回调
        --  媒体类型的消息如图片、文件、语音等消息如果没有远程地址 需要先根据本地路径上传完成后再发送
 @param complete 发送状态回调
        -- 第一次LYTMessageStateSending 回调
 */
- (void)sendMessageWithModel:(LYTMessage *)message shouldSaveMessageInDB:(BOOL)shouldSave progress:(LYTSendProgressBlock)progress complete:(LYTSendCompleteBlock)complete;

#pragma mark - setting function
/**
 设置是否需要接受自己发送的消息 默认为NO -- 聊天室、讨论组、评论等发送的消息自己会收到

 @param bflag NO-不接收  YES-接收
 */
- (void)receiveSelfSendMessage:(BOOL)bflag;


/**
 进入 聊天界面时候调用 -- 功能: 当进入了聊天室时候 多终端 未读数实时同步
 @param sessionId 会话ID
 
 */
- (BOOL)enterChatSession:(NSString *)sessionId;

/**
 退出聊天界面调用

 @return 是否成功
 */
- (BOOL)exitChatSession;

/**
 设置消息映射关系 例如文本消息：1001 但是 在 法义sdk中 则是3901
 
 @param maping 消息映射表例如@{@"3901" : @"1001",@"3902" : @"1002",@"3903" : @"1003",@"3904" : @"1005"}
 */
- (void)setMessageTypeMapping:(NSDictionary <NSString *,NSString *>*)maping;

@end

#endif /* LYTSDKChatManagerProtocol_h */
