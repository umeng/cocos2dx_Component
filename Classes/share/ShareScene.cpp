//
//  ShareScene.cpp
//  UmengGame
//
//  Created by wangfei on 16/4/6.
//
//

#include "ShareScene.h"
#include "Entrance.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Cocos2dx/Common/CCUMSocialSDK.h"
USING_NS_CC;

USING_NS_UM_SOCIAL;
int sharelabelTag = 222;
int sharelayerTag = 111;
Scene* Share::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    Share *layer = Share::create();
    layer->setTag(sharelayerTag);
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Share::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    auto pLabel = Label::createWithSystemFont("分享界面", "Arial", 18);
    
    // position the label on the center of the screen
    pLabel->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(pLabel, 1);
    
    MenuItemFont *qqButton = MenuItemFont::create("qq", CC_CALLBACK_1(Share::qqShare, this));
    qqButton->setPosition(Vec2(visibleSize.width/2, 200));
    qqButton->setFontSizeObj(14);
    // 底层API分享
    MenuItemFont *sinaButton = MenuItemFont::create("新浪", CC_CALLBACK_1(Share::sinaShare, this));
    sinaButton->setPosition(Vec2(visibleSize.width/2, 160));
    sinaButton->setFontSizeObj(14);

    // 授权某平台
    MenuItemFont *wxButton = MenuItemFont::create("微信", CC_CALLBACK_1(Share::wxShare, this));
    wxButton->setPosition(Vec2(visibleSize.width/2, 120));
    wxButton->setFontSizeObj(14);
    MenuItemFont *boardButton = MenuItemFont::create("打开分享面板", CC_CALLBACK_1(Share::boardShare, this));
    boardButton->setPosition(Vec2(visibleSize.width/2, 80));
    boardButton->setFontSizeObj(14);
    MenuItemFont *boardcustomButton = MenuItemFont::create("打开分享不同内容分享面板", CC_CALLBACK_1(Share::boardcustomShare, this));
    boardcustomButton->setPosition(Vec2(visibleSize.width/2, 40));
    boardcustomButton->setFontSizeObj(14);
    MenuItemImage *pCloseItem = MenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          CC_CALLBACK_1(Share::menuCloseCallback, this));
    
    pCloseItem->setPosition(Vec2(origin.x + visibleSize.width - pCloseItem->getContentSize().width ,
                                origin.y + pCloseItem->getContentSize().height));
    
Menu* pMenu = Menu::create();
    pMenu->addChild(qqButton, 1);
    pMenu->addChild(sinaButton, 1);
    pMenu->addChild(wxButton, 1);
    pMenu->addChild(pCloseItem, 1);
    pMenu->addChild(boardButton, 1);
        pMenu->addChild(boardcustomButton, 1);
    pMenu->setPosition(Size::ZERO);
    this->addChild(pMenu, 1);
     auto sharelabel = Label::createWithSystemFont("分享回调",
      			"Arial", 18);
    sharelabel->setTag(sharelabelTag);
      	// position the label on the center of the screen
    sharelabel->setPosition(
      			Vec2(origin.x + visibleSize.width / 2,
      					origin.y + visibleSize.height
      							- pLabel->getContentSize().height-sharelabel->getContentSize().height));

      	// add the label as a child to this layer
      	this->addChild(sharelabel, 1);
    return true;
}
/*
 * 分享回调
 * @param platform 要分享到的目标平台
 * @param stCode 返回码, 200代表分享成功, 100代表开始分享
 * @param errorMsg 分享失败时的错误信息,android平台没有错误信息
 */
void shareCallback(int platform, int stCode, string& errorMsg) {
    
       log("#### callback!!!!!!");
       Share* hwLayer =(Share*) Director::getInstance()->getRunningScene()->getChildByTag(
                       					sharelayerTag);
                       	Label* item = (Label*) hwLayer->getChildByTag(sharelabelTag);
    string result = "";
   if (stCode == 200) {
        result = "分享成功";
        log("#### HelloWorld 分享成功 --> Cocos2d-x SDK ");

                 	item->setString("share success");
    } else if (stCode == -1) {
    	 result = "分享取消";
    	   log("#### HelloWorld 分享取消 --> Cocos2d-x SDK ");

    	                 	item->setString("share cancel");
    }
    	else {
        result = "分享失败";
        log("#### HelloWorld 分享出错 --> Cocos2d-x SDK ");
        item->setString("share fail");
        cout << errorMsg << endl;
    }
    
    istringstream is;
    is >> platform;
    result.append(is.str());
    log("#### callback!!!!!! %s\n",result.c_str());
  
    log("platform num is : %d, %d", platform, stCode);
    
}
void boardCallback(int platform) {
    

        CCLog("platform num is : %d", platform);
     if (platform == QQ) {

         CCUMSocialSDK *sdk = CCUMSocialSDK::create();

         sdk->directShare(QQ,
                          "Umeng Social Cocos2d-x SDK -->  qqshare   DIFFERENT CONTENT","title" ,"","res/closenormal",
                          share_selector(shareCallback));


     }
     else{

     	   CCUMSocialSDK *sdk = CCUMSocialSDK::create();
         	        sdk->directShare(platform,
     	                         "Umeng Social Cocos2d-x SDK -->  qqshare   DIFFERENT CONTENT","title" ,"","CloseSelected.png",
     	                         share_selector(shareCallback));

     }
    
}
void boardDismissCallback() {
    
    log("dismiss");
    
}
void Share::qqShare(Ref* pSender) {
    	CCUMSocialSDK *sdk = CCUMSocialSDK::create();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    
    sdk->directShareAndroid(QQ,
                     "Umeng Social Cocos2d-x SDK -->  qqshare   testing","title" ,"","res/closenormal",
                     share_selector(shareCallback));
    
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    
    sdk->directShareIos(QQ,
                     "Umeng Social Cocos2d-x SDK -->  qqshare   testing","title" ,"","CloseNormal",
                     share_selector(shareCallback));

    
#endif
    
    
 
 }
void Share::sinaShare(Ref* pSender) {
    CCUMSocialSDK *sdk = CCUMSocialSDK::create();
      sdk->directShare(SINA,
                     "Umeng Social Cocos2d-x SDK -->  qqshare   testing","title" ,"https://wsq.umeng.com/","https://dev.umeng.com/images/tab2_1.png",
                     share_selector(shareCallback));
}
void Share::wxShare(Ref* pSender) {
    CCUMSocialSDK *sdk = CCUMSocialSDK::create( );
    

    sdk->directShare(WEIXIN,
                     "Umeng Social Cocos2d-x SDK -->  qqshare   testing", "title" ,"https://wsq.umeng.com/","https://dev.umeng.com/images/tab2_1.png",
                     share_selector(shareCallback));

}
void Share::boardShare(Ref* pSender) {
    CCUMSocialSDK *sdk = CCUMSocialSDK::create( );
    vector<int>* platforms = new vector<int>();
    platforms->push_back(SINA);
    platforms->push_back(QZONE);
    platforms->push_back(QQ);
    platforms->push_back(WEIXIN);
    platforms->push_back(WEIXIN_CIRCLE);
    platforms->push_back(TWITTER);
    platforms->push_back(FACEBOOK);
    sdk->setBoardDismissCallback(boarddismiss_selector(boardDismissCallback));
    sdk->openShare(platforms, "来自分享面板", "title" ,"https://dev.umeng.com/images/tab2_1.png","https://wsq.umeng.com/",share_selector(shareCallback));

}
void Share::boardcustomShare(Ref* pSender) {
    CCUMSocialSDK *sdk = CCUMSocialSDK::create( );
    vector<int>* platforms = new vector<int>();
    platforms->push_back(SINA);
      platforms->push_back(WEIXIN);
      platforms->push_back(WEIXIN_CIRCLE);
      platforms->push_back(QZONE);
      platforms->push_back(QQ);

      platforms->push_back(FACEBOOK);
      platforms->push_back(TWITTER);
    sdk->setBoardDismissCallback(boarddismiss_selector(boardDismissCallback));
    sdk->openCustomShare(platforms, board_selector(boardCallback));
    
}
void Share::menuCloseCallback(Ref* pSender)
{
    TransitionScene * reScene = NULL;
    Scene * s = Entrance::scene();
    float t = 1.2f;
    
    reScene = TransitionJumpZoom ::create(t , s);
    Director::getInstance()->replaceScene(reScene);
}
