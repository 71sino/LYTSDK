//
//  LYSqlite.h
//  LYTDataBase
//
//  Created by Shangen Zhang on 2018/1/4.
//  Copyright © 2018年 Shangen Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LYResultSet.h"

@interface LYSqlite : NSObject
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

+ (instancetype)slqiteWithPath:(NSString *)sqlitePath;
- (instancetype)initWithSqlitePath:(NSString *)sqlitePath;

/** sqlitePath */
@property (nonatomic,copy,readonly)NSString * sqlitePath;



- (BOOL)openSqlite;
- (BOOL)closeSqlite;


- (BOOL)executeUpdate:(NSString*)sql, ...;

- (LYResultSet *)executeQuery:(NSString*)sql, ...;

@end



#pragma mark - 事务处理
@interface LYSqlite (Transaction)

- (BOOL)beginTransaction;

- (BOOL)beginDeferredTransaction;

- (BOOL)commit;

- (BOOL)rollback;

@property (nonatomic, readonly) BOOL isInTransaction;

@end
