//
//  NSString+Hash.h
//  数据加密
//
//  Created by 二爷 on 13-09-26.
//  Copyright (c) 2013年 ErYe. All rights reserved.
//
/**
 * 命令行测试命令
 *
 * MD5
 * $ echo -n abc | openssl md5
 * SHA1
 * $ echo -n abc | openssl sha1
 * SHA256
 * $ echo -n abc | openssl sha -sha256
 * SHA512
 * $ echo -n abc | openssl sha -sha512
 *
 * 说明：abc是要加密的字符串
 */

#import <Foundation/Foundation.h>

@interface NSString (LYTHash)

//  MD5
- (NSString *)md5String;

// data 二进制 MD5
+ (NSString*)lyt_hashStringForData:(NSData*)data;

//获取文件的md5
+ (NSString *)lyt_getFileMD5WithPath:(NSString *)filePath;




//给文件命名
+ (NSString *)lyt_renamePhotoFileWithType:(NSString *)type;

/**
 给音频命名
 */
+ (NSString *)lyt_renameVoiceFile;

@end
