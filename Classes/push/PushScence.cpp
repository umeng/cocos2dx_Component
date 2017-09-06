//
//  EntranceScene.cpp
//  UmengGame
//
//  Created by wangfei on 16/4/6.
//
//

#include "PushScence..h"
#include "HelloWorldScene.h"
USING_NS_CC;

Scene* PushScence::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    PushScence *layer = PushScence::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PushScence::init()
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

    MenuItemFont *add_tags = MenuItemFont::create("add tags", CC_CALLBACK_1(PushScence::addTags, this));

    add_tags->setPosition(Vec2(visibleSize.width/4, 160));
    add_tags->setFontSizeObj(10);
    
    
    MenuItemFont *del_tags = MenuItemFont::create("del tags", CC_CALLBACK_1(PushScence::delTags, this));
    
    add_tags->setPosition(Vec2(visibleSize.width*2/4, 160));
    add_tags->setFontSizeObj(10);

    
    
    MenuItemFont *list_tags = MenuItemFont::create("list tags", CC_CALLBACK_1(PushScence::listTags, this));
    
    add_tags->setPosition(Vec2(visibleSize.width*3/4, 160));
    add_tags->setFontSizeObj(10);

    
    
    MenuItemFont *add_alias = MenuItemFont::create("add alias", CC_CALLBACK_1(PushScence::addAlias, this));
    
    add_tags->setPosition(Vec2(visibleSize.width/4, 120));
    add_tags->setFontSizeObj(10);

    
    
    MenuItemFont *alias_type = MenuItemFont::create("alias type", CC_CALLBACK_1(PushScence::aliasType, this));
    
    add_tags->setPosition(Vec2(visibleSize.width*2/4, 120));
    add_tags->setFontSizeObj(10);

    
    
    MenuItemFont *add_ex_alias = MenuItemFont::create("add exclisive alias", CC_CALLBACK_1(PushScence::addExAlias, this));
    
    add_tags->setPosition(Vec2(visibleSize.width*3/4, 120));
    add_tags->setFontSizeObj(10);

    
    
    MenuItemFont *del_alias = MenuItemFont::create("del alias", CC_CALLBACK_1(PushScence::delAlias, this));
    
    add_tags->setPosition(Vec2(visibleSize.width/4, 80));
    add_tags->setFontSizeObj(10);

    
    
    MenuItemFont *serialnet = MenuItemFont::create("serialnet", CC_CALLBACK_1(PushScence::Serialent, this));
    
    add_tags->setPosition(Vec2(visibleSize.width*2/4, 80));
    add_tags->setFontSizeObj(10);

    
    
    MenuItemFont *app_info = MenuItemFont::create("appinfo", CC_CALLBACK_1(PushScence::appInfo, this));
    
    add_tags->setPosition(Vec2(visibleSize.width*3/4, 80));
    add_tags->setFontSizeObj(10);

    // 底层API分享
   
    MenuItemImage *pCloseItem = MenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                           CC_CALLBACK_1(PushScence::menuCloseCallback, this));
    
    pCloseItem->setPosition(Vec2(origin.x + visibleSize.width - pCloseItem->getContentSize().width ,
                                origin.y + pCloseItem->getContentSize().height));
   
    Menu* pMenu = Menu::create();
        pMenu->addChild(pCloseItem, 1);
    pMenu->addChild(add_tags, 1);
    pMenu->addChild(del_tags, 1);
    pMenu->addChild(list_tags, 1);
    pMenu->addChild(add_alias, 1);

    pMenu->addChild(alias_type, 1);
    pMenu->addChild(add_ex_alias, 1);

    pMenu->addChild(del_alias, 1);
    pMenu->addChild(serialnet, 1);

    pMenu->addChild(app_info, 1);
   

    pMenu->setPosition(Size::ZERO);
    this->addChild(pMenu, 1);
    return true;
}

void PushScence::addTags(Ref* pSender) {
   
}
void PushScence::delTags(Ref* pSender) {
    
}
void PushScence::listTags(Ref* pSender) {
    
}
void PushScence::addAlias(Ref* pSender) {
    
}
void PushScence::aliasType(Ref* pSender) {
    
}
void PushScence::addExAlias(Ref* pSender) {
    
}
void PushScence::delAlias(Ref* pSender) {
    
}
void PushScence::Serialent(Ref* pSender) {
    
}
void PushScence::appInfo(Ref* pSender) {
    
}
void PushScence::menuCloseCallback(Ref* pSender)
{
    TransitionScene * reScene = NULL;
    Scene * s = HelloWorld::createScene();
    float t = 1.2f;
    
    reScene = TransitionJumpZoom ::create(t , s);
    Director::getInstance()->replaceScene(reScene);
}

