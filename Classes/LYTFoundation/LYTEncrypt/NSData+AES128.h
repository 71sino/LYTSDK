//
//  NSData+AES128.h
//  LYTSoketSDKDemo
//
//  Created by Shangen Zhang on 2017/9/4.
//  Copyright © 2017年 深圳柒壹思诺科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

#define Option_CBC_MODE 0x0001
#define Option_ECB_MODE 0x0002

#define OptionMode uint32_t

@interface NSData (AES128)

/**
 AES 16位 加密  （AES128)

 @param key 密钥
 @param Iv 向量
 @param mode 加密方式
 @return 加密后的data
 */
- (NSData *)AES128EncryptWithKey:(NSString *)key iv:(NSString *)Iv option:(OptionMode)mode;

/**
 AES 16位 解密  （AES128)
 
 @param key 密钥
 @param Iv 向量
 @param mode 加密方式
 @return 解密后的data
 */
- (NSData *)AES128DecryptWithKey:(NSString *)key iv:(NSString *)Iv option:(OptionMode)mode;
@end




@interface NSString (AES128)
/**
 AES 16位 加密  （AES128)
 
 @param key 密钥
 @param Iv 向量
 @param mode 加密方式
 @return 加密后的string
 */
- (NSString *)AES128EncryptWithKey:(NSString *)key iv:(NSString *)Iv option:(OptionMode)mode;

/**
 AES 16位 解密  （AES128)
 
 @param key 密钥
 @param Iv 向量
 @param mode 加密方式
 @return 解密后的string
 */
- (NSString *)AES128DecryptWithKey:(NSString *)key iv:(NSString *)Iv option:(OptionMode)mode;

@end
