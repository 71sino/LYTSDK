//
//  LYTSafetySet.h
//  LYTDemo
//
//  Created by Shangen Zhang on 2017/7/26.
//  Copyright © 2017 深圳柒壹思诺科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LYTSafetySet : NSObject
+ (instancetype)safetySet;

+ (instancetype)safetySetWithSet:(NSSet *)set;
+ (instancetype)safetySetWithArray:(NSArray *)array;

- (instancetype)initWithArray:(NSArray *)array;
- (instancetype)initWithSet:(NSSet *)set;

@property (readonly, copy) NSSet *objcSet;
@property (readonly, copy) NSArray *allObjects;
@property(readonly) NSUInteger count;
- (id)anyObject;
- (BOOL)containsObject:(id)anObject;


- (void)addObject:(id)object;
- (void)removeObject:(id)object;
- (void)removeAllObjects;

- (void)addObjectsFromArray:(NSArray *)array;
- (void)intersectSet:(NSSet *)otherSet;
- (void)removeObjectsFromArray:(NSArray *)array;

- (void)enumerateObjectsUsingBlock:(void (^)(id obj, BOOL *stop))block;
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (NS_NOESCAPE ^)(id obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);
@end
