//
//  EntranceScene.cpp
//  UmengGame
//
//  Created by wangfei on 16/4/6.
//
//

#include "Entrance.h"
#include "AuthScene.h"
#include "ShareScene.h"
#include "GetScene.h"
#include "HelloWorldScene.h"
USING_NS_CC;

Scene* Entrance::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    Entrance *layer = Entrance::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Entrance::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    Label *pLabel = Label::createWithTTF("Cocos2dx-UMSocial", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    MenuItemFont *authButton = MenuItemFont::create("授权", CC_CALLBACK_1(Entrance::gotoAuth, this));

    authButton->setPosition(Vec2(visibleSize.width/2, 160));
    authButton->setFontSizeObj(14);
    // 底层API分享
    MenuItemFont *shareButton = MenuItemFont::create("分享", CC_CALLBACK_1(Entrance::gotoShare, this));
    shareButton->setPosition(Vec2(visibleSize.width/2, 120));
 shareButton->setFontSizeObj(14);
    // 授权某平台
    MenuItemFont *getInfoButton = MenuItemFont::create("获取用户信息", CC_CALLBACK_1(Entrance::gotoGetPlatform, this));
    getInfoButton->setPosition(Vec2(visibleSize.width/2, 80));
 getInfoButton->setFontSizeObj(14);
    MenuItemFont *pCloseItem = MenuItemFont::create("返回", CC_CALLBACK_1(Entrance::menuCloseCallback, this));
    pCloseItem->setFontSizeObj(14);
    
    pCloseItem->setPosition(Vec2(origin.x + visibleSize.width - pCloseItem->getContentSize().width ,
                                 origin.y + pCloseItem->getContentSize().height));
   
    Menu* pMenu = Menu::create();
    pMenu->addChild(getInfoButton, 1);
    pMenu->addChild(pCloseItem, 1);
    pMenu->addChild(shareButton, 1);
    pMenu->addChild(authButton, 1);
    pMenu->setPosition(Size::ZERO);
    this->addChild(pMenu, 1);
    return true;
}

void Entrance::gotoAuth(Ref* pSender) {
    TransitionScene * reScene = NULL;
    Scene * s = Auth::scene();
    float t = 1.2f;
   
    reScene = TransitionJumpZoom ::create(t , s);
     Director::getInstance()->replaceScene(reScene);
}
void Entrance::gotoShare(Ref* pSender) {
    TransitionScene * reScene = NULL;
    Scene * s = Share::scene();
    float t = 1.2f;
    
    reScene = TransitionJumpZoom ::create(t , s);
     Director::getInstance()->replaceScene(reScene);
}
void Entrance::gotoGetPlatform(Ref* pSender) {
    TransitionScene * reScene = NULL;
    Scene * s = Get::scene();
    float t = 1.2f;
    
    reScene = TransitionJumpZoom ::create(t , s);
     Director::getInstance()->replaceScene(reScene);
}
void Entrance::menuCloseCallback(Ref* pSender)
{
    
    TransitionScene * reScene = NULL;
    Scene * s = HelloWorld::createScene();
    float t = 1.2f;
    
    reScene = TransitionJumpZoom ::create(t , s);
    Director::getInstance()->replaceScene(reScene);
}

