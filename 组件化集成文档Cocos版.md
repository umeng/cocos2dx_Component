# 工程配置
首先需要说明，Cocos2dx下载的只是桥接文件，不含最新版本的jar，对应组件的jar请去[下载中心](http://mobile.umeng.com/custom_sdk)下载。
如果对于文档仍有疑问的，请参照我们在github上的[demo](https://github.com/umeng/cocos2dx_Component)
请留意：demo使用xcode9编译会报错，请使用xcode8及以下版本运行demo。
## Android
将所有需要的组件的jar放到Android工程中，如图所示：

![](http://upload-images.jianshu.io/upload_images/1483670-60da48678caa3508.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

然后将所有xxx_cc中的文件放到Cocos2dx工程中，修改`Android.mk`文件，引用所有我们的桥接cpp文件：

```
LOCAL_SRC_FILES := hellocpp/main.cpp \
                    ../../../Classes/share/CCUMSocialSDK.cpp \
                   ../../../Classes/push/CCUMPushSDK.cpp \
                   ../../../Classes/analytics/MobClickCpp.cpp \
                   ../../../Classes/analytics/DplusMobClickCpp.cpp \
                   ../../../Classes/Common/UMCCCommon.cpp \
                   ../../../Classes/HelloWorldScene.cpp
```
接着，将所有xxx_java文件中的java文件，放到Android工程中注意路径一定要是`com.umeng.common(analytics/push/social)`

>这里注意push_java中有一个pushmodule，使用方法请参照下面的push文档

然后找到Android工程的Application文件（如果没有，请新建一个，并在AndroidManifest中引用），在`onCreate`中添加如下代码:

```
 UMConfigure.setLogEnabled(true);//开启调试log，根据需要进行关闭或开启
        UMCocosConfigure.init(this, "59892f08310c9307b60023d0", "Umeng", UMConfigure.DEVICE_TYPE_PHONE,
            "669c30a9584623e70e8cd01b0381dcb4");
```
其中`init`方法第一个参数为Context，第二个参数为友盟Appkey，第三个参数为渠道，第四个参数为硬件类型，第五个参数为push Secret
## iOS
将所有需要的组件的库文件放到iOS工程中，然后将所有xxx_cc中的.h文件和.mm文件引入到iOS工程中：

![](http://upload-images.jianshu.io/upload_images/1483670-71df6dea695206b7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

找到ios文件夹下的`AppController`文件，添加初始化代码：

```
#import "UMCCCommon.h"
UMCCCommon::setLogEnabled(true);
UMCCCommon::init(UMENG_APPKEY, "app store");

```
其中`init`第一个参数为友盟Appkey，第二个参数为渠道
# 统计
## Android
1.1android-studio集成方式：
因为游戏统计组件是依赖于common组件的，所以需要将umeng-analytics-7.3.2.jar
umeng-common-1.3.2.jar以及cocos的统计jar包导入到libs中，
在Cocos2dx的主Activity中添加初始化代码：
```
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        UMGameAnalytics.init(this);
        UMCocosConfigure.init(this, "59892f08310c9307b60023d0", "Umeng", UMConfigure.DEVICE_TYPE_PHONE,
            "669c30a9584623e70e8cd01b0381dcb4");
    }

```
UMGameAnalytics.init需要放到UMCocosConfigure.init之前，因为要先设置游戏统计场景，不然游戏统计不生效。
1.2修改Android.mk文件
```
LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../../Classes/analytics/MobClickCpp.cpp \
                   ../../../Classes/analytics/DplusMobClickCpp.cpp \
                   ../../../Classes/Common/UMCCCommon.cpp \
                   ../../../Classes/HelloWorldScene.cpp
```
## iOS
所需文件：DplusMobClickCpp.h、DplusMobClickCpp.mm、MobClickCpp.h、MobClickCpp.mm、UMAnalytics.framework、UMCCCommon.h、UMCCCommon.mm、UMCommon.framework
请在你的工程目录结构中，右键选择`Add->Existing Files…`，选择这几个文件。或者将文件拖入XCode工程目录结构中，在弹出的界面中勾选`Copy items into destination group's folder(if needed)`, 并确保`Add To Targets`勾选相应的target。

找到ios文件夹下的`AppController`文件，添加初始化代码：

```
#import "UMCCCommon.h"
#import "MobClickCpp.h"
UMCCCommon::setLogEnabled(true);
umeng::MobClickCpp::init();
UMCCCommon::init(UMENG_APPKEY, "app store");
```
umeng::MobClickCpp::init()需要再UMCCCommon::init(UMENG_APPKEY, "app store")之前调用，以便设置游戏场景，来进行游戏统计。
## 接口说明
使用自定义事件

使用自定义事件功能请先在网站应用管理后台(设置->编辑自定义事件)中添加相应的自定义事件后，服务器才会对相应的自定义事件请求进行处理。这里我们将提供几个简单而通用的接口：
事件数量统计  
在您希望跟踪的代码部分，调用如下方法：       
```
umeng::MobClickCpp::event(const char * eventId, const char * label = NULL);
```

`eventId`为当前统计的事件ID。      
  
`label`为当前事件的属性和取值（键值对）。
    
示例：统计微博应用中"转发"事件发生的次数，那么在转发的函数里调用
```
umeng::MobClickCpp::event("Forward");
```
    
示例： 统计游戏中“死亡”事件发生的关卡数，那么可以在死亡的函数里调用
```
umeng::MobClickCpp::event("player_dead", "level");
```
      
考虑事件在一个属性上的取值，可以调用如下方法：
 
```
umeng::MobClickCpp::event(const char *eventId, eventDict *attributes)
```

`attributes`为当前事件的属性和取值（键值对）。


示例：统计电商应用中“购买”事件发生的次数，以及购买的商品类型及数量，那么在购买的函数里调用：     
```
umeng::eventDict dict;
dict["type"] = "book";
dict["quantity"] = "3";
umeng::MobClickCpp::event("purchase", &dict);
```
计算事件
使用计算事件需要在后台添加事件时选择“计算事件”。

统计一个数值类型的连续变量，用户每次触发的数值的分布情况，如事件持续时间、每次付款金额等，可以调用如下方法：

```
umeng::MobClickCpp::event(const char *eventId, eventDict *attributes, int counter);
```
注意事项
id， ts， du是保留字段，不能作为eventId及key的名称。
每个应用至多添加500个自定义事件，每个event 的 key不能超过10个，每个key的取值不能超过1000个（不允许通过key-value结构来统计类似搜索关键词，网页链接等随机生成的字符串信息）

使用页面访问统计

您可以统计每个View停留时长及路径。

需要配对使用,如
```
  umeng::MobClickCpp::beginLogPageView("PageOne");
```

```
  umeng::MobClickCpp::endLogPageView("PageOne");
```

  注意： 
  * 我们针对页面访问进行的是抽样统计，所以只有数据量达到一定规模之后才可以看到。

  * 由于这组方法的调用，需要保证线性不交叉，每个 start 都有一个 end 配对，如下：
    onPageStart ->onPageEnd-> onPageStart -> onPageEnd -> onPageStart ->onPageEnd
    这样才能保证每个页面统计的正确。

游戏方法详解
```
// 设置玩家等级.
void umeng::MobClickCpp::setUserLevel(int level);
umeng::MobClickCpp::setUserLevel(9);
```
```
// 充值.
void umeng::MobClickCpp::pay(double cash, int source, double coin);
umeng::MobClickCpp::pay(10, 2, 1000);
// 充值并购买道具.
void umeng::MobClickCpp::pay(double cash, int source, const char * item, int amount, double price);
umeng::MobClickCpp::pay(10, 2, "magic_bottle", 2, 500);
```
```
// 购买道具.
void umeng::MobClickCpp::buy(const char *item, int amount, double price);
umeng::MobClickCpp::buy("helmet", 1, 1000);
```
```
// 消耗道具.
void umeng::MobClickCpp::use(const char *item, int amount, double price);
umeng::MobClickCpp::use("magic_bottle", 2, 50);
```
```
// 奖励金币.
void umeng::MobClickCpp::bonus(double coin, int source);
umeng::MobClickCpp::bonus(10.0,3);
// 奖励道具.
void umeng::MobClickCpp::bonus(const char *item, int amount, double price, int source);
umeng::MobClickCpp::bonus("daoju",5,10.0,3);
```
```
// 进入关卡.
void umeng::MobClickCpp::startLevel(const char *level);
// 通过关卡.
void umeng::MobClickCpp::finishLevel(const char *level);
// 未通过关卡.
void umeng::MobClickCpp::failLevel(const char *level);
```
```
// 订单充值.
void exchange(const char *orderId, double currencyAmount, const char *currencyType,double virtualAmount,int channel)
umeng::MobClickCpp::exchange("test_order",648.0,"CNY",6480,1);
```
```
track事件
自定义track事件
void track(const char * eventName, eventDict* property = NULL)
```
```
超级属性
对Dplus的事件，可以设置持久化的超级属性，如果用户具有某些典型特征（例如账号信息），或者需要按照某些特征（例如广告来源）分析用户的行为，那么可通过以下方法为用户标记超级属性：

// 设置超级属性集, 标记超级属性后,该用户后续触发的所有行为事件都将自动包含这些属性；且这些属性存入系统文件，APP重启后仍然存在。
umeng::eventDict beginPayMap;
beginPayMap.insert(std::make_pair("userid", std::string("userid-xuezhi")));
beginPayMap.insert(std::make_pair("ordeid", std::string("xxxxxx")));
beginPayMap.insert(std::make_pair("item", std::string("test-xuezhi")));
beginPayMap.insert(std::make_pair("amout", "100"));
umeng::DplusMobClickCpp::registerSuperProperty(&beginPayMap);
/*针对同一超级属性，设定的新值会改写旧值。*/

// 获取某一个超级属性值
std::string pName = umeng::DplusMobClickCpp::getSuperProperty("item");

// 获取所有超级属性值
std::string testMap = umeng::DplusMobClickCpp::getSuperProperties();

// 删除某一个超级属性
umeng::DplusMobClickCpp::unregisterSuperProperty("userid");

// 删除所有超级属性
umeng::DplusMobClickCpp::clearSuperProperties();
```
```
//设置关注首次触发track事件.
umeng::DplusMobClickCpp::setFirstLaunchEvent(std::vector<std::string>* eventIdList)
//比如用户首次付费,因为不同原因可以如下集成:
std::vector<std::string> fisLaunchList;
fisLaunchList.push_back("pay_p");
fisLaunchList.push_back("pay_because_dabai");
fisLaunchList.push_back("pay_because_deng");
 ...  ...
umeng::DplusMobClickCpp::setFirstLaunchEvent(&fisLaunchList);
```
# 推送
## Android
首先，Android push需要让Android app依赖我们提供的push module，再根据文档进行相应的初始化。
找到Cocos2dx使用的Activity，添加初始化代码：

```
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        CCUMPushController.initPushSDK(mActivity);
       PushAgent.getInstance(this).onAppStart();
          }

```
Push SDK 的平台配置与单独 Native 项目集成相同，请参考 [接入Push SDK](http://dev.umeng.com/sdk_integate/android_sdk/android_push_doc#1) 以及 [初始化设置部分](http://dev.umeng.com/sdk_integate/android_sdk/android_push_doc#2_1)
## iOS
Push SDK 的平台配置与单独 Native 项目集成相同，请参考 [接入Push SDK](http://dev.umeng.com/sdk_integate/ios-integrate-guide/push#1) 以及 [初始化设置部分](http://dev.umeng.com/sdk_integate/ios-integrate-guide/push#1)
## 接口说明
### 增加tag

```
 umeng::CCUMPushSDK::addTags("tag", push_remain_selector(remainCallback));
```
第一个参数为tag
第二个参数为回调，回调如下:

```
void remainCallback(int stCode,int remain){
   }
```
stCode为200标识成功，remain为剩余值
### 删除tag
```
 umeng::CCUMPushSDK::deleteTags("tag", push_remain_selector(remainCallback));
```
第一个参数为tag
第二个参数为回调
### 展示tags
```
  umeng::CCUMPushSDK::getTags(push_gettag_selector(tagsCallback));
```
其中回调为：

```
void tagsCallback(int stCode, list<string>& data){
     list<string>::iterator itor = data.begin();
    string string_temp ="tags=";
    while(itor!=data.end())
    {
      string_temp = string_temp+ *itor;
        itor++;
    }
    PushScence* hwLayer =(PushScence*) Director::getInstance()->getRunningScene()->getChildByTag(
                                                                                                 pushlayer);
    Label* item = (Label*) hwLayer->getChildByTag(pushlabel);
   
    item->setString(string_temp);
}
```
### 增加alias

```
umeng::CCUMPushSDK::addAlias("alias", "type", push_alias_selector(aliasCallback));
```
其中第一个参数为alias
第二个参数为type，
第三个参数为回调，回调示例如下：

```
void aliasCallback(int stCode){
 
}
```
stCode为200标识成功
### 增加额外的alias

```
umeng::CCUMPushSDK::setAlias("alias", "type", push_alias_selector(aliasCallback));
```
其中第一个参数为alias
第二个参数为type，
第三个参数为回调，回调示例如下：

```
void aliasCallback(int stCode){
 
}
```
stCode为200标识成功
### 删除alias

```
umeng::CCUMPushSDK::removeAlias("alias", "type", push_alias_selector(aliasCallback));
```
其中第一个参数为alias
第二个参数为type，
第三个参数为回调，回调示例如下：

```
void aliasCallback(int stCode){
 
}
```
stCode为200标识成功
# 分享
## Android
### 导出Android工程
在Application中设置使用的三方平台的appkey：

```
 {

        PlatformConfig.setWeixin("wxdc1e388c3822c80b", "3baf1193c85774b3fd9d18447d76cab0");
        //豆瓣RENREN平台目前只能在服务器端配置
        PlatformConfig.setSinaWeibo("3921700954", "04b48b094faeb16683c32669824ebdad", "http://sns.whalecloud.com");
        PlatformConfig.setYixin("yxc0614e80c9304c11b0391514d09f13bf");
        PlatformConfig.setQQZone("100424468", "c7394704798a158208a74ab60104f0ba");

    }
```

找到Cocos2dx使用的Activity，添加初始化代码：

```
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
      CCUMSocialController.initSocialSDK(mActivity);
          }

```

并添加回调所需代码：

```
 @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {


        // 授权回调
        CCUMSocialController.onActivityResult(requestCode, resultCode, data);

        super.onActivityResult(requestCode, resultCode, data);
    }
```

分享其它工程配置请参照[分享工程配置](http://dev.umeng.com/sdk_integate/android_sdk/android_share_doc#1_3_2)



## iOS
UShare SDK 的平台配置与单独 Native 项目集成相同，请参考 [接入U-Share SDK](http://dev.umeng.com/social/ios/quick-integration#1_1) 以及 [初始化设置部分](http://dev.umeng.com/social/ios/quick-integration#2)
## 接口说明
### 直接分享

```
 umeng::CCUMSocialSDK::directShare(QQ,
                     "Umeng Social Cocos2d-x SDK -->  qqshare   testing","title" ,"","res/closenormal",
                     share_selector(shareCallback));
```

* 第一个参数是平台，是一个int值，传入我们提前写好的枚举变量（CCUMSocialSDK.h中）即可:

```
enum Platform {
	/// 新浪微博
	SINA = 0,
	/// 微信
	WEIXIN = 1,
	/// 微信朋友圈
	WEIXIN_CIRCLE = 2,
	/// QQ
	QQ = 3,
	 /// QQ空间
	QZONE = 4,
	/// 人人网
	RENREN = 5,
	/// 豆瓣
	DOUBAN = 6,
	/// 来往
	LAIWANG = 7,
	/// 来往动态
	LAIWANG_CIRCLE = 8,
	/// 易信
	YIXIN = 9,
	/// 易信朋友圈
	YIXIN_CIRCLE = 10,
	/// facebook
	FACEBOOK = 11,
	/// twitter
	TWITTER = 12,
	/// instagram
	INSTAGRAM = 13,
	/// 短信
	SMS = 14,
	/// 邮件
	EMAIL = 15,
	/// 腾讯微博
	TENCENT_WEIBO = 16
};
```     
* 第二个参数是文本内容
* 第三个参数是标题
* 第四个参数是网络链接
* 第五个参数是图片地址
* 第六个参数是回调，回调示例如下：

```
void shareCallback(int platform, int stCode, string& errorMsg) {
    }
```               
### 分享面板分享

```
vector<int>* platforms = new vector<int>();
    platforms->push_back(SINA);
    platforms->push_back(QZONE);
    platforms->push_back(QQ);
    platforms->push_back(WEIXIN);
    platforms->push_back(WEIXIN_CIRCLE);
    platforms->push_back(TWITTER);
    platforms->push_back(FACEBOOK);
     umeng::CCUMSocialSDK::setBoardDismissCallback(boarddismiss_selector(boardDismissCallback));
     umeng::CCUMSocialSDK::openShare(platforms, "来自分享面板", "title" ,"https://dev.umeng.com/images/tab2_1.png","https://wsq.umeng.com/",share_selector(shareCallback));
```
#### setBoardDismissCallback
分享面板消失回调，示例如下：

```
void boardDismissCallback() {
    
    log("dismiss");
    
}
```
#### openShare
* 第一个参数为分享平台数据
* 第二个参数为文本
* 第三个参数为标题
* 第四个参数为图片地址
* 第五个参数为网络连接
* 第六个参数为分享回调,回调方式与直接分享相同

### 不同分享平台分享不同内容
```
 vector<int>* platforms = new vector<int>();
    platforms->push_back(SINA);
      platforms->push_back(WEIXIN);
      platforms->push_back(WEIXIN_CIRCLE);
      platforms->push_back(QZONE);
      platforms->push_back(QQ);

      platforms->push_back(FACEBOOK);
      platforms->push_back(TWITTER);
     umeng::CCUMSocialSDK::setBoardDismissCallback(boarddismiss_selector(boardDismissCallback));
     umeng::CCUMSocialSDK::openCustomShare(platforms, board_selector(boardCallback));
```
`openCustomShare`中个参数的含义如下：

* 第一个参数为平台 
* 第二个参数为分享面板回调监听器： 

```
void boardCallback(int platform) {
    

        CCLog("platform num is : %d", platform);
     if (platform == QQ) {

        umeng::CCUMSocialSDK::directShare(QQ,
                          "Umeng Social Cocos2d-x SDK -->  qqshare   DIFFERENT CONTENT","title" ,"","res/closenormal",
                          share_selector(shareCallback));


     }
     else{

     	 umeng::CCUMSocialSDK::directShare(platform,
     	                         "Umeng Social Cocos2d-x SDK -->  qqshare   DIFFERENT CONTENT","title" ,"","CloseSelected.png",
     	                         share_selector(shareCallback));

     }
    
}
```
### 授权
授权接口只能拿到uid和token信息，不推荐使用：

```
 umeng::CCUMSocialSDK::authorize(QQ, auth_selector(authCallback));
```
* 第一个参数为平台，各平台定义请参照直接分享
* 第二个参数为授权回调:

```
void authCallback(int platform, int stCode, map<string, string>& data) {

}
```
其中map为用户信息

### 获取用户资料
开发者可以直接调用获取用户资料进行授权，能拿到用户名头像等更多信息:

```
 umeng::CCUMSocialSDK::getPlatformInfo(QQ, auth_selector(getCallback));
```
* 第一个参数为平台，各平台定义请参照直接分享
* 第二个参数为授权回调:

```
void getCallback(int platform, int stCode, map<string, string>& data) {

}
```
其中map为用户信息



