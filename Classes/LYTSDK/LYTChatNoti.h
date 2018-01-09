//
//  LYTChatNoti.h
//  LeYingTong
//
//  Created by admin on 17/1/3.
//  Copyright © 2017年 深圳柒壹思诺科技有限公司. All rights reserved.
//

#ifndef LYTChatNoti_H
#define LYTChatNoti_H

#import <Foundation/Foundation.h>
#import "LYTGlobalEnum.h"
#import "LYTUserBaseInfo.h"


@class LYTChatNotiContent;
@interface LYTChatNoti : NSObject

/** messageType 通知类型 */
@property(nonatomic,assign) LYTChatNotiType notiType;

/** 会话ID */
@property(nonatomic,copy) NSString * sessionId;

/** 通知游标 */
@property(nonatomic,copy) NSString * chatIndex;

/** 通知内容 */
@property(nonatomic,strong) LYTChatNotiContent *content;

/** 通知时间 */
@property(nonatomic,assign) NSUInteger messageTime;

@end


@class LYTUserBaseInfo;
@interface LYTChatNotiContent : NSObject
/** 通知类型 */
@property(nonatomic,assign) LYTChatNotiType notiType;
/** 操作者ID */
@property(nonatomic,copy) NSString * operateId;
/** 成员 */
@property(nonatomic,strong) NSArray <LYTUserBaseInfo *> * members;
/** 用户ID */
@property (nonatomic,copy)NSString * userId;
/** 用户名 */
@property(nonatomic,copy) NSString * userName;
@end



@interface LYTChatRoomNotiContent : LYTChatNotiContent
/** 头像 */
@property (nonatomic,copy)NSString * roomPicture;

/** 聊天室名称 */
@property(nonatomic,copy) NSString * roomName;

/** 聊天室标识 */
@property(nonatomic,copy) NSString * roomId;

/** 描述 */
@property(nonatomic,copy) NSString * desc;

/** 备注 */
@property(nonatomic,copy) NSString * remark;

/** 扩展信息1 */
@property(nonatomic,copy) NSString * attr1;
/** 扩展信息2 */
@property(nonatomic,copy) NSString * attr2;
/** 扩展信息3 */
@property(nonatomic,copy) NSString * attr3;

/** 是否开启机器人 */
@property(nonatomic,assign) BOOL robotFlag;

/** 机器人类型 */
@property(nonatomic,copy) NSString * robotType;

@end







#endif
