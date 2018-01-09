//
//  NSMutableArray+LYTAddObject.h
//  LYTDemo
//
//  Created by Shangen Zhang on 2017/4/18.
//  Copyright © 2017 深圳柒壹思诺科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableArray (LYTAddObject)

/**
 发布环境下安全地新增

 @param object 要添加的元素
 */
- (void)lyt_addObject:(_Nonnull id)object;


/**
 快速创建一个固定长度的可变数组,初始化元素均为null对象

 @param count 数组长度
 @return 数组实例化对象
 */
+ (nonnull instancetype)lyt_arrayWithCount:(NSUInteger)count;

@end
