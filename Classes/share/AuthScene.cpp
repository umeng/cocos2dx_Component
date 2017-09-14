//
//  AuthScene.cpp
//  UmengGame
//
//  Created by wangfei on 16/4/6.
//
//

#include "AuthScene.h"
#include "Entrance.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "CCUMSocialSDK.h"
USING_NS_CC;

// 环境变量PATH在windows下和linux下的分割符定义
#ifdef _WIN32
#define PATH_SEPARATOR ';'
#else
#define PATH_SEPARATOR ':'
#endif
int labelTag = 456;
int layerTag = 123;
Scene* Auth::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    Auth *layer = Auth::create();
    layer->setTag(layerTag);
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Auth::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
       Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    auto pLabel = Label::createWithSystemFont("授权界面","Arial", 18);
    
    // position the label on the center of the screen
    pLabel->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(pLabel, 1);
    int width = 50;
    MenuItemFont *qqButton = MenuItemFont::create("qq授权",  CC_CALLBACK_1(Auth::qqAuth, this));
    qqButton->setPosition(Vec2(visibleSize.width/2-width, 240));
    qqButton->setFontSizeObj(12);
    // 底层API分享
    MenuItemFont *sinaButton = MenuItemFont::create("新浪授权", CC_CALLBACK_1(Auth::sinaAuth, this));
    sinaButton->setPosition(Vec2(visibleSize.width/2-width, 210));
      sinaButton->setFontSizeObj(12);
    // 授权某平台
    MenuItemFont *wxButton = MenuItemFont::create("微信授权", CC_CALLBACK_1(Auth::wxAuth, this));
    wxButton->setPosition(Vec2(visibleSize.width/2-width,180));
      wxButton->setFontSizeObj(12);
    MenuItemFont *fbButton = MenuItemFont::create("facebook授权", CC_CALLBACK_1(Auth::facebookAuth, this));
    fbButton->setPosition(Vec2(visibleSize.width/2-width, 150));
      fbButton->setFontSizeObj(12);
    MenuItemFont *twitterButton = MenuItemFont::create("twitter授权", CC_CALLBACK_1(Auth::twitterAuth, this));
    twitterButton->setPosition(Vec2(visibleSize.width/2-width, 125));
      twitterButton->setFontSizeObj(12);
       MenuItemFont *delqqButton = MenuItemFont::create("qq删除授权", CC_CALLBACK_1(Auth::qqAuthDel, this));
    delqqButton->setPosition(Vec2(visibleSize.width/2+width, 240));
    delqqButton->setFontSizeObj(12);
  
    // 底层API分享
    MenuItemFont *delsinaButton = MenuItemFont::create("新浪删除授权", CC_CALLBACK_1(Auth::sinaAuthDel, this));
    delsinaButton->setPosition(Vec2(visibleSize.width/2+width, 210));
      delsinaButton->setFontSizeObj(12);
    // 授权某平台
    MenuItemFont *delwxButton = MenuItemFont::create("微信删除授权", CC_CALLBACK_1(Auth::wxAuthDel, this));
    delwxButton->setPosition(Vec2(visibleSize.width/2+width, 180));
      delwxButton->setFontSizeObj(12);
    MenuItemFont *delfacebookButton = MenuItemFont::create("facebook删除授权", CC_CALLBACK_1(Auth::doubanAuthDel, this));
    delfacebookButton->setPosition(Vec2(visibleSize.width/2+width, 150));
      delfacebookButton->setFontSizeObj(12);
    MenuItemFont *deltwitterButton = MenuItemFont::create("twitter删除授权", CC_CALLBACK_1(Auth::renrenAuthDel, this));
    deltwitterButton->setPosition(Vec2(visibleSize.width/2+width, 125));
      deltwitterButton->setFontSizeObj(12);
   
    MenuItemImage *pCloseItem = MenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          CC_CALLBACK_1(Auth::menuCloseCallback, this));
    
    pCloseItem->setPosition(Vec2(origin.x + visibleSize.width - pCloseItem->getContentSize().width ,
                                origin.y + pCloseItem->getContentSize().height));
    
    Menu* pMenu = Menu::create();
    pMenu->addChild(qqButton, 1);
    pMenu->addChild(pCloseItem, 1);
    pMenu->addChild(sinaButton, 1);
    pMenu->addChild(wxButton, 1);
    pMenu->addChild(delqqButton, 1);
    pMenu->addChild(delsinaButton, 1);
    pMenu->addChild(delwxButton, 1);
    
    pMenu->addChild(fbButton, 1);
    pMenu->addChild(twitterButton, 1);
   
   
    pMenu->addChild(delfacebookButton, 1);
    pMenu->addChild(deltwitterButton, 1);
    pMenu->setPosition(Size::ZERO);

    this->addChild(pMenu, 1);
    auto authlabel = Label::createWithSystemFont("回调结果",
    			"Arial", 18);
    authlabel->setTag(labelTag);
    	// position the label on the center of the screen
    authlabel->setPosition(
    			Vec2(origin.x + visibleSize.width / 2,
    					40));

    	// add the label as a child to this layer
    	this->addChild(authlabel, 1);
    return true;
}
/*
 *授权回调
 * @param platform 要授权的平台
 * @param stCode 返回码, 200代表授权成功, 100代表开始授权, 0代表授权出错, -1代表取消授权
 * @param data 授权时返回的数据
 */
void authCallback(int platform, int stCode, map<string, string>& data) {
	log("#### 授权回调");
	 Auth* hwLayer =(Auth*) Director::getInstance()->getRunningScene()->getChildByTag(
	           					layerTag);
	           	Label* item = (Label*) hwLayer->getChildByTag(labelTag);
	           	string result = "";
	if (stCode == 200) {
        log("#### 授权完成");
        result = "授权完成";

        map<string, string>::iterator it = data.begin();

        	for (; it != data.end(); ++it) {
        		log("#### data  %s -> %s.", it->first.c_str(), it->second.c_str());

        	}

//           	item->setString("auth or delete success");
    } else if (stCode == 0) {
//    	item->setString("auth or delete fail");
    	 result = "授权出错";
        log("#### 授权出错");
    } else if (stCode == -1) {
//    	item->setString("auth or delete cancel");
    	 result = "取消授权";
        log("#### 取消授权");
    }else {
    	   log("#### 未知类型");
    }

	item->setString(result.c_str());
//    map<string, string>::iterator it = data.begin();
//    for (; it != data.end(); ++it) {
//        log("#### data  %s -> %s.", it->first.c_str(), it->second.c_str());
//    }
}
//void authCallBack(int platform, int stCode, const char* usid,
//                  const char *token) {
//    printf("%d %d %s %s", platform, stCode, usid, token);
//}






void Auth::qqAuth(Ref* pSender) {
   umeng::CCUMSocialSDK::authorize(QQ, auth_selector(authCallback));
}
void Auth::sinaAuth(Ref* pSender) {
    umeng::CCUMSocialSDK::authorize(SINA, auth_selector(authCallback));
}
void Auth::wxAuth(Ref* pSender) {
    umeng::CCUMSocialSDK::authorize(WEIXIN, auth_selector(authCallback));
}
void Auth::qqAuthDel(Ref* pSender) {
   umeng::CCUMSocialSDK::deleteAuthorization(QQ, auth_selector(authCallback));
}
void Auth::sinaAuthDel(Ref* pSender) {
  umeng::CCUMSocialSDK::deleteAuthorization(SINA, auth_selector(authCallback));
}
void Auth::wxAuthDel(Ref* pSender) {
    umeng::CCUMSocialSDK::deleteAuthorization(WEIXIN, auth_selector(authCallback));
}
void Auth::doubanAuth(Ref* pSender) {
    umeng::CCUMSocialSDK::authorize(DOUBAN, auth_selector(authCallback));
}
void Auth::renrenAuth(Ref* pSender) {
    umeng::CCUMSocialSDK::authorize(RENREN, auth_selector(authCallback));
}
void Auth::facebookAuth(Ref* pSender) {
    umeng::CCUMSocialSDK::authorize(FACEBOOK, auth_selector(authCallback));
}
void Auth::doubanAuthDel(Ref* pSender) {
   umeng::CCUMSocialSDK::deleteAuthorization(DOUBAN, auth_selector(authCallback));
}
void Auth::renrenAuthDel(Ref* pSender) {
   umeng::CCUMSocialSDK::deleteAuthorization(RENREN, auth_selector(authCallback));
}
void Auth::facebookAuthDel(Ref* pSender) {
   umeng::CCUMSocialSDK::deleteAuthorization(FACEBOOK, auth_selector(authCallback));
}

void Auth::twitterAuth(Ref* pSender) {
   umeng::CCUMSocialSDK::authorize(TWITTER, auth_selector(authCallback));
}
void Auth::twitterAuthDel(Ref* pSender) {
   umeng::CCUMSocialSDK::deleteAuthorization(TWITTER, auth_selector(authCallback));
}

void Auth::menuCloseCallback(Ref* pSender)
{
    TransitionScene * reScene = NULL;
    Scene * s = Entrance::scene();
    float t = 1.2f;
    
    reScene = TransitionJumpZoom ::create(t , s);
    Director::getInstance()->replaceScene(reScene);
}

