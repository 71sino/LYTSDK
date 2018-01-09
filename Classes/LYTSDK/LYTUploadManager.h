//
//  LYTUploadManager.h
//  LYTDemo
//
//  Created by Shangen Zhang on 2017/7/4.
//  Copyright © 2017 深圳柒壹思诺科技有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LYTError;

typedef void(^LYTUploadTaskBlock)(NSURLSessionDataTask *uploadtask);
typedef void(^LYTHttpProgressBlock)(CGFloat progress);
typedef void(^LYTHttpCompleteBlock)(id json ,LYTError *error);


typedef void(^LYTBatchUploadTaksBlock)(NSString *filePath,NSUInteger index,NSURLSessionDataTask *task);
typedef void(^LYTBatchUploadProressBlock)(NSString *filePath,NSUInteger index,CGFloat progress);
typedef BOOL(^LYTBatchShouldContinueBlock)(NSString *filePath,NSUInteger index,LYTError *upoadError);
typedef void(^LYTBatchCompleteBlock)(NSArray <NSDictionary *>* respose,LYTError *error);


@interface LYTUploadManager : NSObject
// 外界禁止创建
- (instancetype)init __attribute__((unavailable("‘init’ Forbidden use!")));
+ (instancetype)new  __attribute__((unavailable("‘init’ Forbidden use!")));

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


#pragma mark - 过期方法

/**
 批量上传

 @param filePaths 文件路径集合
 @param uploadtaskBlock 上传任务回调
 @param progressBlock 上传进度回调
 @param shouldContinue 当有一个任务上传失败时 其他任务是否继续
                    -- 返回YES 该任务返回上传失败、其他任务
 @param completeBlock 完成回调
 */
- (void)batchUploadToFtpServcerWithFilePaths:(NSArray <NSString *> *)filePaths
                                  uploadTask:(LYTBatchUploadTaksBlock)uploadtaskBlock
                                    progress:(LYTBatchUploadProressBlock)progressBlock
                 uploadFailureShouldContinue:(LYTBatchShouldContinueBlock)shouldContinue
                                    complete:(LYTBatchCompleteBlock)completeBlock;




@end

