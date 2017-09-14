//
//  GetScene.cpp
//  UmengGame
//
//  Created by wangfei on 16/4/6.
//
//

#include "GetScene.h"
#include "Entrance.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "CCUMSocialSDK.h"
USING_NS_CC;

USING_NS_CC;
int getlabelTag = 333;
int getlayerTag = 444;
Scene* Get::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    Get *layer = Get::create();
    layer->setTag(getlayerTag);
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Get::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
   auto pLabel = Label::createWithSystemFont("获取用户信息界面", "Arial", 18);
    
    // position the label on the center of the screen
    pLabel->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(pLabel, 1);
    
    MenuItemFont *qqButton = MenuItemFont::create("qq", CC_CALLBACK_1(Get::qqGet, this));
    qqButton->setPosition(Vec2(visibleSize.width/2, 160));
    qqButton->setFontSizeObj(14);
    // 底层API分享
    MenuItemFont *sinaButton = MenuItemFont::create("新浪", CC_CALLBACK_1(Get::sinaGet, this));
    sinaButton->setPosition(Vec2(visibleSize.width/2, 120));
    sinaButton->setFontSizeObj(14);
    // 授权某平台
    MenuItemFont *wxButton = MenuItemFont::create("微信", CC_CALLBACK_1(Get::wxGet, this));
    wxButton->setPosition(Vec2(visibleSize.width/2, 80));
    wxButton->setFontSizeObj(14);
    MenuItemImage *pCloseItem = MenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          CC_CALLBACK_1(Get::menuCloseCallback, this));
    
    pCloseItem->setPosition(Vec2(origin.x + visibleSize.width - pCloseItem->getContentSize().width ,
                                origin.y + pCloseItem->getContentSize().height));
    
    Menu* pMenu = Menu::create();
    pMenu->addChild(sinaButton, 1);
    pMenu->addChild(pCloseItem, 1);
    pMenu->addChild(qqButton, 1);
    pMenu->addChild(wxButton, 1);
    pMenu->setPosition(Size::ZERO);
    this->addChild(pMenu, 1);
    Label* getlabel = Label::createWithSystemFont("Umeng Social Cocos2d-x SDK",
       			"Arial", 18);
    getlabel->setTag(getlabelTag);
       	// position the label on the center of the screen
    getlabel->setPosition(
       			Vec2(origin.x + visibleSize.width / 2,
       					origin.y + visibleSize.height
       							- pLabel->getContentSize().height-getlabel->getContentSize().height));

       	// add the label as a child to this layer
       	this->addChild(getlabel, 1);
    return true;
}
void getCallback(int platform, int stCode, map<string, string>& data) {
	Get* hwLayer =(Get*) Director::getInstance()->getRunningScene()->getChildByTag(
		           					getlayerTag);
		           	Label* item = (Label*) hwLayer->getChildByTag(getlabelTag);
		           	string result = "";
     if (stCode == 200) {
    	 result = "获取成功";
        log("#### 获取成功");
    } else if (stCode == 0) {
        log("#### 获取出错");
    } else if (stCode == -1) {
        log("#### 取消获取");
    }
    
    // 输入授权数据, 如果授权失败,则会输出错误信息
    map<string, string>::iterator it = data.begin();
    for (; it != data.end(); ++it) {
        log("#### data  %s -> %s.", it->first.c_str(), it->second.c_str());
//        result.append(it->first.c_str());
//        result.append(it->second.c_str());
    }
    item->setString(result.c_str());
}
void Get::qqGet(Ref* pSender) {
    umeng::CCUMSocialSDK::getPlatformInfo(QQ, auth_selector(getCallback));

}
void Get::sinaGet(Ref* pSender) {
    umeng::CCUMSocialSDK::getPlatformInfo(SINA, auth_selector(getCallback));

}
void Get::wxGet(Ref* pSender) {
   umeng::CCUMSocialSDK::getPlatformInfo(WEIXIN, auth_selector(getCallback));

}

void Get::menuCloseCallback(Ref* pSender)
{
    TransitionScene * reScene = NULL;
    Scene * s = Entrance::scene();
    float t = 1.2f;
    
    reScene = TransitionJumpZoom ::create(t , s);
    Director::getInstance()->replaceScene(reScene);
}
