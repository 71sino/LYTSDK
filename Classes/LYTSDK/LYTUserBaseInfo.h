//
//  LYTUserBaseInfo.h
//  LeYingTong
//
//  Created by admin on 16/12/24.
//  Copyright © 2016年 深圳柒壹思诺科技有限公司. All rights reserved.
//

#ifndef LYTUserBaseInfo_H
#define LYTUserBaseInfo_H

#import <Foundation/Foundation.h>
#import "LYTGlobalEnum.h"



@protocol LYTUserUnitInfoProtocol <NSObject>

/** 用户ID */
- (nonnull NSString *)userId;

/** 用户名称 */
- (nonnull NSString *)userName;

@end

@protocol LYTUserBaseInfoProtocol <LYTUserUnitInfoProtocol>

/** 用户头像 */
- (nonnull NSString *)picture;

/** 用户昵称 */
- (nullable NSString *)nikeName;

/** 用户性别 */
- (nullable NSString *)sex;

/** 用户签名 */
- (nullable NSString *)signature;
@end




@interface LYTUserBaseInfo : NSObject <LYTUserBaseInfoProtocol>

/** 在线状态 */
@property(nonatomic,assign) LYTAuthStatus status;

/** 用户名 */
@property(nonatomic,copy,nonnull) NSString * userName;

/** 用户ID */
@property(nonatomic,copy,nonnull) NSString * userId;

/** 性别	 */
@property(nonatomic,copy,nullable) NSString * sex;

/** 用户头像 */
@property(nonatomic,copy,nonnull) NSString * picture;

/** 个性签名 */
@property(nonatomic,copy,nullable) NSString * signature;

/** 用户昵称 */
@property (nonatomic,copy,nullable)NSString * nikeName;

@end




@interface LYTUserExpanInfo : LYTUserBaseInfo

/** 描述 */
@property(nonatomic,copy,nullable) NSString * desc;

/** 备注 */
@property(nonatomic,copy,nullable) NSString * remark;


/** 扩展信息1 */
@property(nonatomic,copy,nullable) NSString * attr1;
/** 扩展信息2 */
@property(nonatomic,copy,nullable) NSString * attr2;
/** 扩展信息3 */
@property(nonatomic,copy,nullable) NSString * attr3;


/** 创建时间（时间戳） */
@property(nonatomic,copy,nullable) NSString * createTime;
/** 修改时间（时间戳） */
@property(nonatomic,copy,nullable) NSString * updateTime;

- (NSDictionary *_Nonnull)convertToDictionary;
@end




#endif





