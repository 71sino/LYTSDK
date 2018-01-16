//
//  LYTMessageBody.h
//  Antenna
//
//  Created by HHLY on 2016/12/8.
//  Copyright © 2016年 深圳柒壹思诺科技有限公司. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "LYTUserBaseInfo.h"
/**
 文件下载状态
 */
typedef NS_ENUM(NSUInteger, LYTMediaDownloadState) {
    /** 还没下载 */
    LYTMediaUnDownload,
    /** 正在下载 */
    LYTMediaDownloading,
    /** 下载失败 */
    LYTMediaDownloadFail,
    /** 下载成功 */
    LYTMediaDownloadSuccessed,
};

/**
 文件更新状态
 */
typedef NS_ENUM(NSUInteger, LYTMediaUploadState) {
    /** 默认 */
    LYTMediaUnUpload     = 0,
    /** 正在上传 */
    LYTMediaUploading,
    /** 上传成功 */
    LYTMediaUploadSuccessed,
    /** 上传失败 */
    LYTMediaUploadFail,
};

// 通话状态
typedef NS_ENUM(NSUInteger, LYTNetCallState) {
    /** 默认(未知) */
    LYTNetCallStateUnknow     = -1,
    /** 已经结束 */
    LYTNetCallStateDidEnd     = 0,
    /** 已经开始 */
    LYTNetCallStateDidBegan   = 1,
};


typedef NS_ENUM(NSUInteger, LYTCallEventType) {
    /** 对方拒接电话 */
    LYTCallEventTypeReject        = -1,
    /** 对方无人接听 */
    LYTCallEventTypeNoResponse    = -2,
    /** 开启电话 */
    LYTCallEventTypeStart         =  1,
    /** 未接电话 */
    LYTCallEventTypeMiss          = 101,
    /** 电话回单 */
    LYTCallEventTypeBill          = 102,
    /** 拨打方取消 */
    LYTCallEventTypeCancel        = 103,
};

// 网络聊天类型
typedef NS_ENUM(NSUInteger, LYTCallMessageType) {
    /** 默认(未知) */
    LYTCallMessage_Unknow    = -1,
    /** 音频 */
    LYTCallMessage_Audio     = 1,
    /** 视频 */
    LYTCallMessage_Video     = 2,
};

// 会议状态
typedef NS_ENUM(NSUInteger, LYTMeetingCallState) {
    /** 默认(未知) */
    LYTMeetingCallStateUnknow     = -1,
    /** 已经结束 */
    LYTMeetingCallStateDidEnd     = 0,
    /** 已经开始 */
    LYTMeetingCallStateDidBegan   = 1,
};






#pragma mark -
/// 消息体基类
@interface LYTMessageBody : NSObject <NSCoding>

/**
 @brief 消息体的类型
 */
@property (assign, nonatomic) LYTMessageType bodyType;

/** 列表显示的文字 getter 方法 */
- (NSString *_Nonnull)showText;
@end





#pragma mark -
@interface LYTTextMessageBody : LYTMessageBody

/**
 @brief 文本
 */
@property (copy, nonatomic,nonnull) NSString *text;

/**
 @brief 富文本，本地展示使用
 */
@property (copy, nonatomic,nullable) NSAttributedString *attributeText;


- (instancetype _Nonnull )initWithText:(NSString *_Nonnull)text;

@end






#pragma mark -
@interface LYTFileMessageBody : LYTMessageBody

/**
 @bried 文件显示名
 */
@property (copy, nonatomic,nullable) NSString *displayName;

/**
 文件消息体的本地文件路径  （全路径）
 -- 发送消息传这个路径
 */
@property (nonatomic, strong,nullable) NSString *localPath;

/**
 缓存在SDK中的缓存路径。
 -- 展示消息的用的相对路径
 */
@property (nonatomic,copy,nullable) NSString  * cachePath;

/**
 文件名
 */
@property(nonatomic,copy,nonnull) NSString * fileName;
/**
 文件url
 */
@property(nonatomic,copy,nullable) NSString * fileUrl;
/**
 文件大小(单位为B)
 */
@property(nonatomic,assign) NSUInteger size;

/**
 文件下载状态
 */
@property (assign, nonatomic) LYTMediaDownloadState downloadState;

/**
 文件上传状态
 */
@property (assign, nonatomic) LYTMediaUploadState uploadState;

/**
 @brief 以文件路径构造文件对象
 @param filePath 磁盘文件全路径
 @param displayName 显示文件名
 */
- (instancetype _Nonnull)initWithFilePath:(NSString *_Nonnull)filePath displayName:(NSString *_Nonnull)displayName;

@end



@interface LYTFileDownloadBody : LYTMessageBody
/** 已下载的文件名 */
@property (nonatomic,copy,nonnull)NSString * fileName;

- (instancetype _Nonnull)initWithFileName:(NSString *_Nonnull)fileName;
@end




#pragma mark -
@interface LYTImageMessageBody : LYTFileMessageBody

/**
 @brief 图片大小
 */
@property (assign, nonatomic) CGSize imageSize;

/** 图片地址 原始 */
@property(nonatomic,copy,nonnull) NSString * picUrl;

/** 图地址 缩略  缩略图服务器路径*/
@property(nonatomic,copy,nullable) NSString * picUrl_thumb;
/** 图地址 中等质量 */
@property(nonatomic,copy,nullable) NSString * picUrl_middle;


/**
 @brief 缩略图本地路径
 */
@property (copy, nonatomic,nullable) NSString *thumbnailLocalPath;


@end


#pragma mark -
/// 语音消息体
@interface LYTVoiceMessageBody : LYTFileMessageBody


/** 语音路径 */
@property(nonatomic,copy,nonnull) NSString * audioUrl;

/**
 @brief 录音时长
 */
@property (assign, nonatomic) NSInteger duration;

/**
 @brief 是否阅读了
 */
@property (assign, nonatomic) BOOL hasRead;

/**
 @brief 是否正在播放
 */
@property (assign, nonatomic) BOOL playing;

@end



#pragma mark -
@interface LYTVideoMessageBody : LYTFileMessageBody

@end



#pragma mark -
@interface LYTLocationMessageBody : LYTMessageBody

/** 地理位置 */
@property(nonatomic,copy,nonnull) NSString * title;
/** 经度 */
@property(nonatomic,assign,nonnull) NSString * lng;
/** 经度 */
@property(nonatomic,assign,nonnull) NSString * lat;

@end




#pragma mark -
@interface LYTMixtureMessageBody : LYTMessageBody

/**
 图文混排 内容
 
 数组的元素为字典 字典包含两个key: "type" 文字内容格式（LYTMessageType）; "content"文字内容 文本内容即为文本信息 图片类型即为图片的url string  type为换行（0000）时即为nil
 */
@property(nonatomic,strong) NSArray <NSDictionary *> * _Nonnull mixture;
/*
 [
 {
 "type":"1001",                        //文本(包含表情)
 "content":"xxxxx"                     //消息内容
 },
 {
 "type":"1002",                                        //图片
 "content":"{\"picUrl\":\"http://www.baidu.com\"}"     //jsonString(图片消息是对象)
 },
 {
 "type":"0000"                          //换行符
 },
 {
 "type":"1002",                          //图片
 "content":"{\"picUrl\":\"http://www.baidu.com\"}"     //jsonString(图片消息是对象)
 },
 {
 "type":"0000"                          //换行符
 },
 {
 "type":"1001",                          //文本(包含表情)
 "content":"xxxxx"                    //消息内容
 }
 ]
 */
@end



FOUNDATION_EXTERN const NSString * _Nonnull const LYTMessagePicUrl;
FOUNDATION_EXTERN const NSString * _Nonnull const LYTMessageLocalPath;
#pragma mark -
@protocol LYTTipContentProtocol;
@interface LYTTipMessageBody : LYTTextMessageBody

/**
 @brief @消息体内容
 */
@property (copy, nonatomic,nonnull) NSArray <id <LYTTipContentProtocol>> * tipContent;


/** 消息体显示的内容 */
@property(nonatomic,copy,nullable) NSString *contentDescription;


/**
 @brief 是否有@我的消息
 */
@property (assign, nonatomic, getter=hasTipMe) BOOL tipMe;

/**
 @我的des range
 */
@property (nonatomic,strong,nullable) NSArray <NSValue *> * atMeRanges;

/**
 @brief 初始化@消息体
 
 @param tipContent 存放整个消息块
 */
- (instancetype _Nonnull)initWithTipContent:(NSArray <id<LYTTipContentProtocol>> *_Nonnull)tipContent;
@end




#pragma mark -
/**
 点对点 音视频消息
 */
@interface LYTCallMessageBody : LYTTextMessageBody

/**
 @brief call 类型
 */
@property (assign, nonatomic) LYTCallMessageType callType;


/**
 @brief 通话事件
 */
@property (assign, nonatomic) LYTCallEventType eventType;

/** 通话时长 */
@property (nonatomic,copy,nonnull)NSString * duration;

@end


#pragma mark -
@interface LYTMeetingMessageBody : LYTTextMessageBody

/**
 @brief 会议消息详情 例：{roomName:value, roomId:value, callType:value, creatorId:value}
 */
@property (copy, nonatomic,nonnull) NSDictionary *meetingInfo;

/**
 @brief 会议名称
 */
@property (copy, nonatomic,nonnull) NSString *roomName;

/**
 @brief 会议ID
 */
@property (copy, nonatomic,nonnull) NSString *roomId;

/**
 @brief 会议创建者ID
 */
@property (copy, nonatomic,nonnull) NSString *creatorId;

/**
 @brief 会议类型
 */
@property (assign, nonatomic) LYTCallMessageType callType;

/**
 @brief 会议状态
 */
@property (assign, nonatomic) LYTMeetingCallState roomStatus;

/**
 时长  "1:24:10"
 */
@property (nonatomic,copy,nullable)NSString * duration;

/**
 @brief 会议消息描述
 - 例如:@"视频会议正在进行中，点击加入"
 */
@property (copy, nonatomic,nullable) NSString *meetingPrompt;

/**
 @brief 以会议简介构造会议对象
 @param meetingInfo 会议信息 例：{roomName:value, roomId:value, callType:value, creatorId:value}
 */
- (instancetype _Nonnull)initWithMeetingInfo:(NSDictionary *_Nonnull)meetingInfo;

@end



#pragma mark -
@interface LYTCustomMessageBody : LYTMessageBody
/** 自定义字段 */
@property (nonatomic,copy,nonnull)NSString * jsonString;

/** 自定义消息对象
 -- 该属性给用户自己设定
 -- SDK内部将不会转发、持久保存
 */
@property (nonatomic,strong,nullable) id coustomObjc;

@end









#pragma mark - LYTTipContentProtocol
@protocol LYTTipContentProtocol <NSObject>

@required
/**
 @的消息类型 可能是换行、@全体成员、@人、文本、图片等
 */
- (LYTContentType)type;

/**
 当type == LYTContentTypeTipBodys（1112） 调用
 被@的人 isTipAll == NO 时候不会调用
 -- 非换行符内容返回不为空
 -- 数组内元素为被@的人(可以同时@多人或一人)
 
 */
- (NSArray <id<LYTUserUnitInfoProtocol>> *_Nullable)userInfos;

/**
 被@的内容 文本消息、下载媒体的URL地址
 -- 文本消息（type == 1001） 返回 @"要发送的消息"
 -- 图片消息（type == 1002） 返回
 @{@"picUrl" : @"图片地址"} 或者 @{@"localPath" : @"本地路径"}
 -- 其他格式暂不支持，敬请期待
 @return @的内容
 */
- (id <NSCopying> _Nullable)content;



@optional
/*
 注意: *******  type 是否返回 LYTContentTypeTipsAll 代替 ******
 
 是否@所有人  (暂时未开通）用于以后拓展
 -- 返回YES的时候表示@所有人
 -- 返回NO的时候要返回被@的人
 */
- (BOOL)isTipAll;

@end


@class LYTUserBaseInfo;
@interface LYTTipContent : NSObject <LYTTipContentProtocol>
/** @TYPE */
@property(nonatomic,assign) LYTContentType type;

/** @的人 */
@property (nonatomic,strong,nullable) NSArray <LYTUserBaseInfo *> * userInfos;

/** @content */
@property (nonatomic,strong,nullable) id <NSCopying> content;


- (instancetype _Nonnull)initWithContent:(id<LYTTipContentProtocol>_Nonnull)content;

@end
