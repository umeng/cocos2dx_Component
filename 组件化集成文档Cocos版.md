# 工程配置
首先需要说明，Cocos2dx下载的只是桥接文件，不含最新版本的jar，对应组件的jar请去[下载中心](http://mobile.umeng.com/custom_sdk)下载。
如果对于文档仍有疑问的，请参照我们在github上的[demo](https://github.com/umeng/cocos2dx_Component)
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
## iOS
## 接口说明
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



