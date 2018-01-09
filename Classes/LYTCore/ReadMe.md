#版本更新说明

***
#### 1.0.05 版本
1. 修复主线程重连问题
2. 减少 SDK 的 size

#### 1.0.04 版本

1. 添加 shouldSaveMessageIntoDB:方法。第三方根据自己的业务进行消息过滤操作


#### 1.0.03 版本

1. 修复 修改APNs推送铃声失败的bug
2. 初始化网络状态变量值
3. 修复第一次登录失败，第二次登录时发送没有结果回调bug

#### 1.0.02 版本

1.  优化内部日志打印的控制
2.  修复发送copy问题


#### 1.0.01 版本

1.  修复 离线消息 请求不到的BUG


#### 1.0.0 版本

1. 添加ReadMe.md文件,对每个版本的更新内容做说明
2. 统一使用http接口请求
3. 添加 fetchLastMessagesWithSessionIDs:complete;用来获取sessionid对应的最新的消息对象
4. addHistoryMessageToLocalDB方法重命名为：addMessageToDB
5. didReceiveAMessage：方法重命名为 didReceiveOnlineMessage：

