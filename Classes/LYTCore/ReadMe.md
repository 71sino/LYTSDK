# 版本更新说明
***
### 2.0.09版本
1. 优化
    1.  完善ReadMe.md说明

***
### 2.0.08版本
1. bug处理
    1. 发送已读回执时sendUid为空时导致的crash

2. 优化
    1. subscrCustomRealTimeMessageTopids: 及 cancelSubscrCustomRealTimeMessageTopids: 接口添加参数检验

***
### 2.0.07版本
1. bug处理
    1.  处理被踢下线mqtt出现crash的问题


### 2.0.06版本
1. bug处理
    1. 未设置推送信息导致的登录接口不回调的bug

2. 优化
    1. 登录接口增加对推送参数的校验
    2. 删除不使用的注释及不使用代码
    3. mqtt断开连接优化


***

### 2.0.05版本
1. 接口新增
    1. 新增 setCallBackImmedWhenLoginFailed 主动调用接口
    2. 新增 didReceiveTaReadedMessageStatus:  回调接口
    3. 新增 initWith:appKey:appSecret:  主动调用接口
    4. 新增 setCompany:appKey:appSecret: 主动调用接口

2. 接口删除
    1. 删除 isConnected 接口
    2. 删除 setRemotePushEnable 接口
    3. 删除 configSDKCompany:appKey:appSecret: 接口
    4. 删除 initWithProductId:messageTypeRange: 接口

3. 接口重命名
    1. isLogined 替换 isLogin
    2. sdk登录接口为:loginSDKWith:useDbWhenLoginFailed:complete:
    3. logoutSDK 替换 logoutWithComplete:接口
    4. exitChatSession 替换 exitChatSession:方法

4. 优化
    1. 减小SDK静态库的大小
    2. sdk登录接口使用V4优化
    3. sdk登录逻辑添加了失败重连机制
    4. APNs推送信息上传逻辑优化
    5. ReadMe.md文件随SDK导出给第三方用户

5. 新加功能
    1. 对方消息已读状态
    2. 内部日志系统完善
    3. 新增接收透传消息（自定义主题消息）代理接口

6. 已知bug修复
    1. 首次登录网络请求可能失败的bug
    2. 处理设置铃声不成功的bug

7. 消息类型统一
    1. 文本、图片、语音等常规消息都为统一的类型,其他拓展的消息均为自定义消息类型自己管理content
    2. 新增透传消息类型,不保存,允许丢失
    3. 兼容消息映射关系方法



***
#### 1.0.04 版本

1. 添加 shouldSaveMessageIntoDB:方法。第三方根据自己的业务进行消息过滤操作


#### 1.0.03 版本

1. 修复 修改APNs推送铃声失败的bug
2. 初始化网络状态变量值
3. 修复第一次登录失败，第二次登录时发送没有结果回调bug

***

#### 1.0.02 版本

1.  优化内部日志打印的控制
2.  修复发送图片显示为空的问题
3.  固定了自定义消息类型为 3898  原来的3899为透传消息（本地不保存、不确保送达的消息）
4.  去掉了消息类型映射接口

***

#### 1.0.01 版本

1.  修复 离线消息 请求不到的BUG

***

#### 1.0.0 版本

1. 添加ReadMe.md文件,对每个版本的更新内容做说明
2. 统一使用http接口请求
3. 添加 fetchLastMessagesWithSessionIDs:complete;用来获取sessionid对应的最新的消息对象
4. addHistoryMessageToLocalDB方法重命名为：addMessageToDB
5. didReceiveAMessage：方法重命名为 didReceiveOnlineMessage：

