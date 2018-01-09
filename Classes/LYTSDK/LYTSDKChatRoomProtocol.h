//
//  LYTChatRoomProtocol.h
//  LeYingTong
//
//  Created by admin on 16/12/26.
//  Copyright © 2016年 深圳柒壹思诺科技有限公司. All rights reserved.
//

#ifndef LYTSDKChatRoomProtocol_h
#define LYTSDKChatRoomProtocol_h

#import "LYTBaseManagerProtocol.h"
#import "LYTChatNoti.h"


// 监听 并接受数据 SDK外部实现
@protocol LYTSDKChatRoomDelegate <NSObject>

/**
 接收到讨论组通知
 
 @param chatRoomNoti 通知消息对象
 */
- (void)didReceiveChatRoomNoti:(LYTChatNoti *) chatRoomNoti;

@end



/***************************************************************/
@protocol LYTSDKChatRoomProtocol <LYTBaseManagerProtocol>

// 设置代理
- (void)addDelegate:(id <LYTSDKChatRoomDelegate>)delegate;

@end

#endif /* LYTSDKChatRoomProtocol_h */
