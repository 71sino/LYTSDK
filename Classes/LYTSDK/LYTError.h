//
//  LYTError.h
//  LeYingTong
//
//  Created by admin on 16/12/30.
//  Copyright © 2016年 深圳柒壹思诺科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger,LYTErrorCode) {
    LYTErrorCodeGeneral       =  1,      // 一般错误
    LYTErrorCodeNetWorkUnable = 2,           // 网络不可用
    LYTErrorCodeFileUnable = 3,              // 文件不可用
    LYTErrorCodeConnectTimeOut = 4,          // 重连超时
    LYTErrorCodeUnloginSDK = 5,              // 未登录sdk
    LYTErrorCodeDidLoginOnOtherWays = 6,     // 在其他地方登录
    LYTErrorCodeDidLogin = 7,                // 已登录或者正在登录
    LYTErrorCodeFormatError = 8,             // 服务器返回的数据格式错误
    LYTErrorCodeLocalParamaError = 9,        // 客户端参数出错误
    LYTErrorCodeLocalDBOpError = 10,         // 本地数据库操作错误
    
    LYTErrorCodeMessageMissValue = 100 ,       // 缺少必要的参数值
    LYTErrorCodeMessageFormatError = 101,      // 消息格式错误
    LYTErrorCodeMessageUploadFailure = 102,    // 上传失败
    LYTErrorCodeMessageSendFail = 103,         // 发送失败
    LYTErrorCodeMessageNotFoundInDB = 104,     // 数据中找不到改消息
    LYTErrorCodeMessageTimeDifference = 105,   // 操作时间超过限定时间
    LYTErrorCodeMessageSendTimeOut = 106,      // 发送超时
    LYTErrorCodeMessageHighFrequent = 107,      // 消息过于频繁
    
    LYTErrorCodeUnAcceptableProtocolVersion = 201,  //!< 服务端不支持客户端请求的协议级别
    LYTErrorCodeIdentiferRejected,                  //!< 客户端标识符在服务端不允许使用
    LYTErrorCodeServerUnavailable,                  //!< 网络连接已建立，但SOCKET服务不可用
    LYTErrorCodeAccountAuthenFailue,                //!< 用户认证失败
    LYTErrorCodeNotAuthorized,                      //!< 客户端未被授权连接到此服务器
    
    LYTErrorCodeChatRoomDisabled = 301,       // 聊天室不可用
    LYTErrorCodeGroupDisabled = 302,          // 讨论组不可用
    LYTErrorCodeMemberDuplication = 303,      // 成员重复
    
    LYTErrorCodeNotFound = 404,          // 网络获取失败
    
    /*
     *注意: 客户端自定义的 错误码段  【1,500】-------- 下面是服务器端的错误码 添加时注意使用的错误码范围
     */
    
    LYTErrorCodeParamaError = 1002,     // 参数有误
    LYTErrorCodeTokenUnable = 1004,     // 无效token
    
    LYTErrorCodeDataOperateFail = 1008, // 数据库操作失败
    
    LYTErrorCodeGrouIsNotExist      = 2004, // 讨论组ID 不存在
    LYTErrorCodeUserNotInGroup      = 2011, // 该用户已经不再讨论组
    LYTErrorCodeUserIsNotManager    = 2014, // 用户不是管理员
    LYTErrorCodeNotiIsNotExist      = 2015, // 讨论组公告id不存在
    LYTErrorCodeNonsupportEmoji     = 2016, // 包含表情符异常 不支持表情符
    
    LYTErrorCodeNotFindMember   = 5001,             // 找不到成员信息
    LYTErrorCodeNotFindRoom     = 5002,             // 找不到聊天室详情
    LYTErrorCodeNoMember        = 5003,             // 当前没有操作的成员
    LYTErrorCodeMemberOutOfRang = 5004,             // 当前操作的人员数过多
    LYTErrorCodeCreatRoomFailure  = 5005,           // 创建聊天室失败
    LYTErrorCodeDeleteRoomFailure = 5006,           // 删除聊天室失败
    LYTErrorCodeAddMenberFailure  = 5007,           // 添加聊天室成员失败
    LYTErrorCodeDelMenberFailure  = 5008,           // 删除聊天室成员失败
    LYTErrorCodeChangeMenberInfoFailure  = 5009,    // 修改聊天室成员信息失败
    LYTErrorCodeChangeRoomInfoFailure  = 5010,      // 修改聊天室信息失败
    LYTErrorCodeExitRoomFailure  = 5011,            // 删除聊天室成员失败
    LYTErrorCodeRepeatAdd        = 5012,            // 重复添加
    LYTErrorCodeRepeatInvite     = 5013,            // 重复邀请
    
    
    LYTErrorCodeCompanyFailue  = 5101,   // 注册公司失败
    LYTErrorCodeCompanyNotFind = 5102,   // 公司不存在
    LYTErrorCodeAppKeyFailue   = 5103,   // 注册app失败
    LYTErrorCodeAppNotExist    = 5104    // app不存在
    
};


@interface LYTError : NSObject

/**
  错误码
 */
@property(nonatomic,assign) LYTErrorCode code;


/**
  错误描述
 */
@property(nonatomic,copy) NSString *domain;



/** 错误信息 */
@property(nonatomic,strong) id errorInfo;


/**
  错误信息类工厂方法

 @param code  错误码
 @param domain 错误信息描述
 @return 错误信息对象
 */
+ (instancetype)errorWithErrorCode:(LYTErrorCode)code domain:(NSString *)domain errorInfo:(id)info;


/**
 错误信息构造方法

 @param code 错误码
 @param domain 错误信息描述
 @return 错误信息对象
 */
- (instancetype)initWithErrorCode:(LYTErrorCode)code domain:(NSString *)domain errorInfo:(id)info;

@end
