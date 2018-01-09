//
//  NSObject+LYTSelector.h
//  LeYingTong
//
//  Created by admin on 16/12/26.
//  Copyright © 2016年 深圳柒壹思诺科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (LYTSelector)


/**
 * 给一个对象发送消息 不需要校验方法是否实现 debug模式下回抛出异常 但在release环境下会做容错处理返回nil

 @param selector 方法
 @param object 参数 没有参数传nil
 @return sel的返回值 void为nil
 */
- (id)lyt_performSelector:(SEL)selector withObject:(id)object;


/**
 *  给对象发送一个传递多个值 不需要校验方法是否实现 debug模式下回抛出异常 但在release环境下会做容错处理返回nil

 @param selector 方法 SEL
 @param objects 参数数组  参数按照顺序排 传nil值时要使用NSNull对象
 @return 方法的返回值 void 返回为nil
 */
- (id)lyt_performSelector:(SEL)selector withObjects:(NSArray *)objects;



/**
 动态调用类方法 不需要校验方法是否实现 debug模式下回抛出异常 但在release环境下会做容错处理返回nil

 @param selector 类方法SEL
 @return 方法的返回值 void 返回为nil
 */
+ (id)lyt_performClassSelector:(SEL)selector;

/**
  动态调用类方法 不需要校验方法是否实现 debug模式下回抛出异常 但在release环境下会做容错处理返回nil

 @param selector 方法SEL
 @param object 参数 没有传nil
 @return 方法的返回值 void 返回为nil
 */
+ (id)lyt_performClassSelector:(SEL)selector withObject:(id)object;


/**
 动态调用类方法 不需要校验方法是否实现 debug模式下回抛出异常 但在release环境下会做容错处理返回nil

 @param selector 方法SEL
 @param objc1 参数 没有传nil
 @param objc2 参数 没有传nil
 @return 方法的返回值 void 返回为nil
 */
+ (id)lyt_performClassSelector:(SEL)selector withObject1:(id)objc1 object2:(id)objc2;
- (id)lyt_performInstanceSelector:(SEL)selector withObject1:(id)objc1 object2:(id)objc2;
@end
