# 工程配置
## Android
## iOS
# 统计
## Android
## iOS
## 接口说明
# 推送
## Android

## iOS
## 接口说明
# 分享
## AndroidStudio
### 导出Android工程
![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTlfNTFfMDRfNjg0X3M3NC5wbmciXV0/s74.png)

按照[SDK文档](http://dev.umeng.com/social/android/quick-integration) 进行对应的工程配置，这个不在赘述。
### cocos2dx工程中添加文件
在cocos2dx工程中添加文件夹`classes/share`中这两个文件夹中的代码
![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMjNfMDlfOTJfczY0LnBuZyJdXQ/s64.png)

添加后如图所示:
![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMjNfMDlfMTcyX3M2NS5wbmciXV0/s65.png)
### 配置application
在android工程中建立一个Application文件配置appkey

![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMDZfMzFfMjcxX3M2MC5wbmciXV0/s60.png)

并且在AndroidManifest文件中加入这个application

![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMDZfMzFfMzQwX3M2MS5wbmciXV0/s61.png)

### 配置activity
在你的主Activity也就是继承Cocos2dxActivity的activity中进行如下配置

![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMDZfMzFfNDA1X3M2Mi5wbmciXV0/s62.png)

这里一定要注意如下代码是必须要加的，这是对cocos2dx的一个初始化

	UMShareAPI.get(this);
		CCUMSocialController.initSocialSDK(mActivity, "com.umeng.social");
		Config.shareType = "cocos2dx";
		
		
然后在onActivityResult中添加如下代码

![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMTNfMzBfNTA5X3M2My5wbmciXV0/s63.png)

### 引入对应文件到Android工程

首先需要拷贝CCUMSocialController.java到 com.umeng.social路径，这里注意一定要是这个路径不能变

![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMjdfMjlfMzI0X3M2Ni5wbmciXV0/s66.png)



### 编辑jni中mk脚本
如果使用新浪微博完整版，会需要引入.so文件，可以将所有.so放到一个prebuild文件夹中，然后通过Android.mk脚本引入，参照我们的demo即可：

![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMzZfMDBfMjQ1X3M2OC5wbmciXV0/s68.png)
![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMzZfMDBfMzA1X3M2OS5wbmciXV0/s69.png)

如果是用精简版则不需要导入.so文件

只需要引入我们classes中的文件即可

![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfNDFfMzVfMjU2X3M3MC5wbmciXV0/s70.png)



### 自定义分享面板
在android工程的CCUMSocialController.java文件中，找到openShare的方法，以及openCustomShare的方法。增加设置方法，如下所示

	ShareBoardConfig config = new ShareBoardConfig();
	                config.setShareboardPostion(ShareBoardConfig.SHAREBOARD_POSITION_CENTER);
	                config.setMenuItemBackgroundShape(ShareBoardConfig.BG_SHAPE_CIRCULAR); // 圆角背景
	                config.setTitleVisibility(false); // 隐藏title
	                config.setCancelButtonVisibility(false); // 隐藏取消按钮
				// 打开分享面板
				new ShareAction(mActivity).setDisplayList(disfinal).withText(text).setCallback(umShareListener)
				.withTitle(title).withTargetUrl(targeturl).withMedia(getUmImage(image)).open(config);

更多修改方式可以参照[自定义分享面板文档](http://dev.umeng.com/social/android/%E8%BF%9B%E9%98%B6%E6%96%87%E6%A1%A3#3_2)

## eclipse

### 下载包的用法
![](http://upload-images.jianshu.io/upload_images/1483670-3998832e17494138.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
如上图所示，箭头指示文件：
在cocos2dx工程中添加文件classes中这两个文件夹中的代码
![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMjNfMDlfOTJfczY0LnBuZyJdXQ/s64.png)

添加后如图所示

![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMjNfMDlfMTcyX3M2NS5wbmciXV0/s65.png)

还有一个androidSrc文件夹请将其中的文件放置于android工程的`com.umeng.social`路径下，切记不可换路径。
### 配置application
在android工程中建立一个Application文件配置appkey

![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMDZfMzFfMjcxX3M2MC5wbmciXV0/s60.png)

并且在AndroidManifest文件中加入这个application

![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMDZfMzFfMzQwX3M2MS5wbmciXV0/s61.png)

### 配置activity
在你的主Activity也就是继承Cocos2dxActivity的activity中进行如下配置

![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMDZfMzFfNDA1X3M2Mi5wbmciXV0/s62.png)

这里一定要注意如下代码是必须要加的，这是对cocos2dx的一个初始化

	UMShareAPI.get(this);
		CCUMSocialController.initSocialSDK(mActivity, "com.umeng.social");
		Config.shareType = "cocos2dx";
		
		
然后在onActivityResult中添加如下代码

![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMTNfMzBfNTA5X3M2My5wbmciXV0/s63.png)

### 引入对应文件到Android工程

首先需要拷贝CCUMSocialController.java到 com.umeng.social路径，这里注意一定要是这个路径不能变

![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMjdfMjlfMzI0X3M2Ni5wbmciXV0/s66.png)

### 引入Classes到Android工程
如图所示
![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMzZfMDBfMTczX3M2Ny5wbmciXV0/s67.png)

### 编辑jni中mk脚本
如果使用新浪微博完整版，会需要引入.so文件，可以将所有.so放到一个prebuild文件夹中，然后通过Android.mk脚本引入，参照我们的demo即可：

![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMzZfMDBfMjQ1X3M2OC5wbmciXV0/s68.png)
![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfMzZfMDBfMzA1X3M2OS5wbmciXV0/s69.png)

如果是用精简版则不需要导入.so文件

只需要引入我们classes中的文件即可

![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTFfNDFfMzVfMjU2X3M3MC5wbmciXV0/s70.png)

### 自定义分享面板
在android工程的CCUMSocialController.java文件中，找到openShare的方法，以及openCustomShare的方法。增加设置方法，如下所示

	ShareBoardConfig config = new ShareBoardConfig();
	                config.setShareboardPostion(ShareBoardConfig.SHAREBOARD_POSITION_CENTER);
	                config.setMenuItemBackgroundShape(ShareBoardConfig.BG_SHAPE_CIRCULAR); // 圆角背景
	                config.setTitleVisibility(false); // 隐藏title
	                config.setCancelButtonVisibility(false); // 隐藏取消按钮
				// 打开分享面板
				new ShareAction(mActivity).setDisplayList(disfinal).withText(text).setCallback(umShareListener)
				.withTitle(title).withTargetUrl(targeturl).withMedia(getUmImage(image)).open(config);

更多修改方式可以参照[自定义分享面板文档](http://dev.umeng.com/social/android/%E8%BF%9B%E9%98%B6%E6%96%87%E6%A1%A3#3_2)



## iOS
***玉强添加***
## 接口说明
### 拷贝对应的文件到工程中
Common是cocos2dx的桥接文件用来沟通android和ios，所以您只需要调用common中的方法即可实现对应分享授权功能
如下图所示：

![](http://dev.umeng.com/system/images/W1siZiIsIjIwMTYvMTEvMDgvMTVfMjFfNTFfNjg4X3M3My5wbmciXV0/s73.png)

### 实现分享功能
#### 单平台直接分享
```
	sdk->directShareAndroid(QQ,
                            "Umeng Social Cocos2d-x SDK -->  qqshare   testing","title" ,"","res/closenormal",
                            share_selector(shareCallback))；
```                        
第一个参数是平台第二个参数是内容，第三个参数是title，第四个参数是targeturl，第五个参数是图片，第六个参数是回调
#### 分享面板
需要提前设置在分享面板中要展示的平台：
```
	vector<int>* platforms = new vector<int>();
    platforms->push_back(SINA);
    platforms->push_back(RENREN);
    platforms->push_back(DOUBAN);
    platforms->push_back(QZONE);
    platforms->push_back(QQ);

    platforms->push_back(WEIXIN);
    platforms->push_back(WEIXIN_CIRCLE);
     sdk->setPlatforms(platforms);
 ```    
然后调用：
```	
	sdk->openShare(platforms, "来自分享面板", "title", "", "",share_selector(shareCallback));
```
打开分享面板。
其中第一个参数是所有平台，第二个参数是分享内容，第三个参数第三个参数是title，第四个参数是targeturl，第五个参数是图片，第六个参数是回调

#### 不同平台分享不同内容
跟上面一样，需要先设置展示平台

然后调用
```
	sdk->openCustomShare(platforms, board_selector(boardCallback));
```
其中boardCallback是点击对应平台的回调，可以在这里面设置不同的分享内容，如：
```
	void boardCallback(int platform) {
    
       CCLog("platform num is : %d", platform);
    if (platform == QQ) {
        CCUMSocialSDK *sdk = CCUMSocialSDK::create();

        sdk->directShare(QQ,
                         "Umeng Social Cocos2d-x SDK -->  qqshare   DIFFERENT CONTENT","title" ,"","",
                         share_selector(shareCallback));


    }
    else{
    	   CCUMSocialSDK *sdk = CCUMSocialSDK::create();
        	        sdk->directShare(platform,
    	                         "Umeng Social Cocos2d-x SDK -->  qqshare   DIFFERENT CONTENT","title" ,"","",
    	                         share_selector(shareCallback));
    	
    }
    
	}
```
#### android与ios分享不同内容

可以使用如下代码：
```
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    
    sdk->directShareAndroid(QQ,
                            "Umeng Social Cocos2d-x SDK -->  qqshare   testing","title" ,"","res/closenormal",
                            share_selector(shareCallback));
    
	#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    
    sdk->directShareIos(QQ,
                        "Umeng Social Cocos2d-x SDK -->  qqshare   testing","title" ,"","CloseNormal",
                        share_selector(shareCallback));
    
    
	#endif
```

#### 实现授权功能
授权只能获取对应平台的uid和accesstoken，如果需要获取用户名和资料请调用获取用户资料的接口
调用如下代码实现授权功能
```
	CCUMSocialSDK *sdk = CCUMSocialSDK::create( );
    
    sdk->authorize(QQ, auth_selector(authCallback));
```    
授权的回调信息可以通过data来获取：
```
	void authCallback(int platform, int stCode, map<string, string>& data) {
	CCLog("#### 授权回调");
	 Auth* hwLayer =(Auth*) CCDirector::sharedDirector()->getRunningScene()->getChildByTag(
	           					layerTag);
	           	CCLabelTTF* item = (CCLabelTTF*) hwLayer->getChildByTag(labelTag);
	           	string result = "";
	if (stCode == 200) {
        CCLog("#### 授权完成");
        result = "授权完成";

        map<string, string>::iterator it = data.begin();

        	for (; it != data.end(); ++it) {
        		CCLog("#### data  %s -> %s.", it->first.c_str(), it->second.c_str());

        	}

    } else if (stCode == 0) {


    	 result = "授权出错";
        CCLog("#### 授权出错");
    } else if (stCode == -1) {
	
    	 result = "取消授权";
        CCLog("#### 取消授权");
    }else {
    	   CCLog("#### 未知类型");
    }

	item->setString(result.c_str());

	}
```	
#### 实现获取用户资料的功能

可以通过如下代码获取用户资料：
```
	CCUMSocialSDK *sdk = CCUMSocialSDK::create();
    
    sdk->getPlatformInfo(SINA, auth_selector(getCallback));
 ```
其中的回调为：
```
	void getCallback(int platform, int stCode, map<string, string>& data) {
	Get* hwLayer =(Get*) CCDirector::sharedDirector()->getRunningScene()->getChildByTag(
		           					getlayerTag);
		           	CCLabelTTF* item = (CCLabelTTF*) hwLayer->getChildByTag(getlabelTag);
		           	string result = "";
     if (stCode == 200) {
    	 result = "获取成功";
        CCLog("#### 获取成功");
    } else if (stCode == 0) {
        CCLog("#### 获取出错");
    } else if (stCode == -1) {
        CCLog("#### 取消获取");
    }
    
    // 输入授权数据, 如果授权失败,则会输出错误信息
    map<string, string>::iterator it = data.begin();
    for (; it != data.end(); ++it) {
        CCLog("#### data  %s -> %s.", it->first.c_str(), it->second.c_str());

    }
    item->setString(result.c_str());
	}
```
#### 分享面板的关闭回调
利用分享面板的关闭回调，可以监控面板的消失状态，在面板消失之后进行特定操作。
首先需要构造一个回调监听器：

```
void boardDismissCallback() {
    
    log("dismiss");
    
}
```

然后在打开分享面板之前调用

```
sdk->setBoardDismissCallback(boarddismiss_selector(boardDismissCallback));

```
