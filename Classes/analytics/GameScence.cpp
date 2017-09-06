//
//  EntranceScene.cpp
//  UmengGame
//
//  Created by wangfei on 16/4/6.
//
//

#include "GameScence.h"
#include "AnalyticsHome.h"
USING_NS_CC;

Scene* GameScence::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    GameScence *layer = GameScence::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScence::init()
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
    Label *pLabel = Label::createWithTTF("UM-Cocos2dx-Social", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    MenuItemFont *appButton = MenuItemFont::create("App", CC_CALLBACK_1(GameScence::gotoApp, this));

    appButton->setPosition(Vec2(visibleSize.width/2, 160));
    appButton->setFontSizeObj(14);
    // 底层API分享
    MenuItemFont *gameButton = MenuItemFont::create("游戏", CC_CALLBACK_1(GameScence::gotoGame, this));
    gameButton->setPosition(Vec2(visibleSize.width/2, 120));
 gameButton->setFontSizeObj(14);
    // 授权某平台

    MenuItemImage *pCloseItem = MenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                           CC_CALLBACK_1(GameScence::menuCloseCallback, this));
    
    pCloseItem->setPosition(Vec2(origin.x + visibleSize.width - pCloseItem->getContentSize().width ,
                                origin.y + pCloseItem->getContentSize().height));
   
    Menu* pMenu = Menu::create();
    pMenu->addChild(appButton, 1);
    pMenu->addChild(pCloseItem, 1);
    pMenu->addChild(gameButton, 1);
   
    pMenu->setPosition(Size::ZERO);
    this->addChild(pMenu, 1);
    return true;
}

void GameScence::gotoApp(Ref* pSender) {
   
}
void GameScence::gotoGame(Ref* pSender) {
  
}

void GameScence::menuCloseCallback(Ref* pSender)
{
    TransitionScene * reScene = NULL;
    Scene * s = AnalyticsHome ::scene();
    float t = 1.2f;
    
    reScene = TransitionJumpZoom ::create(t , s);
    Director::getInstance()->replaceScene(reScene);

   }

