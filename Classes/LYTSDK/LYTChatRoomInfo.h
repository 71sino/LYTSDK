//
//  LYTChatRoomInfo.h
//  LYTSoketSDKDemo
//
//  Created by Shangen Zhang on 2017/10/24.
//  Copyright © 2017年 深圳柒壹思诺科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LYTGlobalEnum.h"


@interface LYTChatRoomBaseInfo : NSObject
/** 聊天室名称 */
@property(nonatomic,copy) NSString * roomName;

/** 聊天室标识 */
@property(nonatomic,copy) NSString * roomId;

@end




@class LYTChatPreference;
@interface LYTChatRoomPreferenceInfo : LYTChatRoomBaseInfo

/** 接受消息的类型 */
@property(nonatomic,assign) LYTRecieveMessageNotiLevel receiveType;

/** 聊天室偏好设置模型（用于以后拓展） */
@property(nonatomic,strong) LYTChatPreference *config;

@end





@class LYTUserBaseInfo;
@interface LYTChatRoomExpanInfo : LYTChatRoomPreferenceInfo
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

/** 成员列表 */
@property(nonatomic,strong) NSArray <LYTUserBaseInfo *> * members;

@end




/**
 偏好设置类 用于拓展
 */
@interface LYTChatPreference : NSObject

@end
