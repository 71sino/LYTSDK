//
//  LYTUploadManagerProtocol.h
//  LYTSoketSDKDemo
//
//  Created by Shangen Zhang on 2017/11/10.
//  Copyright © 2017年 深圳柒壹思诺科技有限公司. All rights reserved.
//

#ifndef LYTUploadManagerProtocol_h
#define LYTUploadManagerProtocol_h

#import "LYTError.h"
#import <UIKit/UIKit.h>


typedef void(^LYTUploadTaskBlock)(NSURLSessionDataTask *uploadtask);
typedef void(^LYTHttpProgressBlock)(CGFloat progress);
typedef void(^LYTHttpCompleteBlock)(id json ,LYTError *error);

@protocol LYTUploadManagerProtocol <NSObject>

/**
 上传文件工具
 
 @param filePath 本地全路径
 @param uploadtask 上传任务 用于暂停 、取消
 @param progress 进度回调
 @param complete 完成回调
 -- 有error 时上传失败
 -- json 成功回调格式:
 {
 "fileId"       : "文件ID",
 "fileName"     : "文件名称",
 "fileType"     : "文件类型",
 "dowmnloadUrl" : "文件下载地址",
 "fileSize"     : "文件大小",
 "fileMD5"      : "文件的MD5值"
 }
 */
- (void)uploadToFtpServcerFilePath:(NSString *)filePath
                        uploadTask:(LYTUploadTaskBlock)uploadtask
                          progress:(LYTHttpProgressBlock)progress
                          complete:(LYTHttpCompleteBlock)complete;




/**
 文件批量上传
 
 @param filePaths 文件路径集合
 @param progress 进度回调
 @param complete 完成回调
 -- 有error 时上传失败
 -- json 成功回调格式:
 [
 {
 "fileId"       : "文件ID",
 "fileName"     : "文件名称",
 "fileType"     : "文件类型",
 "dowmnloadUrl" : "文件下载地址",
 "fileSize"     : "文件大小",
 "fileMD5"      : "文件的MD5值"
 },
 {
 "fileId"       : "文件ID",
 "fileName"     : "文件名称",
 "fileType"     : "文件类型",
 "dowmnloadUrl" : "文件下载地址",
 "fileSize"     : "文件大小",
 "fileMD5"      : "文件的MD5值"
 },
 ]
 
 
 @return 上传任务 用于暂停 、取消
 */
- (NSURLSessionDataTask *)batchUploadToFtpServcerWithFilePaths:(NSArray <NSString *> *)filePaths
                                                      progress:(LYTHttpProgressBlock)progress
                                                      complete:(LYTHttpCompleteBlock)complete;



@end

#endif /* LYTUploadManagerProtocol_h */
