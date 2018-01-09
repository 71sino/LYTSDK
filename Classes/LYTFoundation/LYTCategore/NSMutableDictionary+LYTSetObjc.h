//
//  NSMutableDictionary+LYTSetObjc.h
//  LeYingTong
//
//  Created by admin on 16/12/23.
//  Copyright © 2016年 深圳柒壹思诺科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableDictionary (LYTSetObjc)
/**
 *  筛选出 空字符串、空数组、空字典 
 *
 */
- (void)lyt_setObject:(id)object forKey:(NSString *)key;
@end
