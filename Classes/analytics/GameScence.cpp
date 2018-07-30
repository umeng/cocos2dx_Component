//
//  EntranceScene.cpp
//  UmengGame
//
//  Created by wangfei on 16/4/6.
//
//

#include "GameScence.h"
#include "AnalyticsHome.h"
#include "HelloWorldScene.h"
#include "MobClickCpp.h"
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
    Label *pLabel = Label::createWithTTF("UM-Cocos2dx-Game", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(Vec2(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - pLabel->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(pLabel, 1);
    
    // 关卡开始
    MenuItemFont *startButton = MenuItemFont::create("关卡开始", CC_CALLBACK_1(GameScence::startLevel, this));
    startButton->setPosition(Vec2(visibleSize.width/4, visibleSize.height/7*6));
    startButton->setFontSizeObj(14);
    // 关卡失败
    MenuItemFont *failButton = MenuItemFont::create("关卡失败", CC_CALLBACK_1(GameScence::failLevel, this));
    failButton->setPosition(Vec2(visibleSize.width/4, visibleSize.height/7*5));
    failButton->setFontSizeObj(14);
    // 关卡结束
    MenuItemFont *endButton = MenuItemFont::create("关卡结束", CC_CALLBACK_1(GameScence::endLevel, this));
    endButton->setPosition(Vec2(visibleSize.width/4, visibleSize.height/7*4));
    endButton->setFontSizeObj(14);
    // 使用物品
    MenuItemFont *useButton = MenuItemFont::create("使用物品", CC_CALLBACK_1(GameScence::use, this));
    useButton->setPosition(Vec2(visibleSize.width/4, visibleSize.height/7*3));
    useButton->setFontSizeObj(14);
    // 游戏奖励
    MenuItemFont *awardButton = MenuItemFont::create("游戏奖励", CC_CALLBACK_1(GameScence::bonus, this));
    awardButton->setPosition(Vec2(visibleSize.width/4, visibleSize.height/7*2));
    awardButton->setFontSizeObj(14);
    // 用户登入
    MenuItemFont *enterButton = MenuItemFont::create("用户登入", CC_CALLBACK_1(GameScence::enter, this));
    enterButton->setPosition(Vec2(visibleSize.width/4, visibleSize.height/7));
    enterButton->setFontSizeObj(14);
    // 用户登出
    MenuItemFont *outButton = MenuItemFont::create("用户登出", CC_CALLBACK_1(GameScence::out, this));
    outButton->setPosition(Vec2(visibleSize.width/4*3, visibleSize.height/7*2));
    outButton->setFontSizeObj(14);
    // 充值付费
    MenuItemFont *RechargeButton = MenuItemFont::create("充值付费", CC_CALLBACK_1(GameScence::Recharge, this));
    RechargeButton->setPosition(Vec2(visibleSize.width/4*3, visibleSize.height/7*3));
    RechargeButton->setFontSizeObj(14);
    // 购买物品（真实消费）
    MenuItemFont *buyButton = MenuItemFont::create("购买物品（真实消费）", CC_CALLBACK_1(GameScence::buy, this));
    buyButton->setPosition(Vec2(visibleSize.width/4*3, visibleSize.height/7*4));
    buyButton->setFontSizeObj(14);
    // 购买物品（虚拟消费）
    MenuItemFont *buyvirButton = MenuItemFont::create("购买物品（虚拟消费）", CC_CALLBACK_1(GameScence::buyvir, this));
    buyvirButton->setPosition(Vec2(visibleSize.width/4*3, visibleSize.height/7*5));
    buyvirButton->setFontSizeObj(14);
    // 有订单的充值付费
    MenuItemFont *indentButton = MenuItemFont::create("订单充值", CC_CALLBACK_1(GameScence::indent, this));
    indentButton->setPosition(Vec2(visibleSize.width/4*3, visibleSize.height/7*6));
    indentButton->setFontSizeObj(14);
    // 自定义事件
    MenuItemFont *defineButton = MenuItemFont::create("自定义事件", CC_CALLBACK_1(GameScence::define, this));
    defineButton->setPosition(Vec2(visibleSize.width/4*3, visibleSize.height/7));
    defineButton->setFontSizeObj(14);
    MenuItemFont *pCloseItem = MenuItemFont::create("返回", CC_CALLBACK_1(GameScence::menuCloseCallback, this));
    pCloseItem->setFontSizeObj(14);
    
    pCloseItem->setPosition(Vec2(origin.x + visibleSize.width - pCloseItem->getContentSize().width ,
                                 origin.y + pCloseItem->getContentSize().height));
    
    Menu* pMenu = Menu::create();
    pMenu->addChild(pCloseItem, 1);
    pMenu->addChild(startButton, 1);
    pMenu->addChild(failButton, 1);
    pMenu->addChild(endButton, 1);
    pMenu->addChild(useButton, 1);
    pMenu->addChild(awardButton, 1);
    pMenu->addChild(enterButton, 1);
    pMenu->addChild(outButton, 1);
    pMenu->addChild(RechargeButton, 1);
    pMenu->addChild(buyButton, 1);
    pMenu->addChild(buyvirButton, 1);
    pMenu->addChild(indentButton, 1);
    pMenu->addChild(defineButton, 1);
    pMenu->setPosition(Size::ZERO);
    this->addChild(pMenu, 1);
    return true;
}
void GameScence::startLevel(Ref* pSender)
{
    umeng::MobClickCpp::startLevel("start");
    
}
void GameScence::failLevel(Ref* pSender)
{
    umeng::MobClickCpp::failLevel("start");
}
void GameScence::endLevel(Ref* pSender)
{
    umeng::MobClickCpp::finishLevel("start");
}
void GameScence::use(Ref* pSender)
{
    umeng::MobClickCpp::use("use",2,4);
    umeng::MobClickCpp::setUserLevel(9);
}
void GameScence::bonus(Ref* pSender)
{
    umeng::MobClickCpp::bonus("bonus",2.1,4,3.3);
}
void GameScence::enter(Ref* pSender)
{
    umeng::MobClickCpp::profileSignIn("test_aaa");
}
void GameScence::out(Ref* pSender)
{
    umeng::MobClickCpp::profileSignOff();
}
void GameScence::Recharge(Ref* pSender)
{
    umeng::MobClickCpp::pay(1.11,2,2.3);
}
void GameScence::buy(Ref* pSender)
{
    umeng::MobClickCpp::buy("buy",2,4);
}
void GameScence::buyvir(Ref* pSender)
{
    umeng::MobClickCpp::pay(2.22,3,"pay",10,4);
}
void GameScence::indent(Ref* pSender)
{
    umeng::MobClickCpp::exchange("test_order",648.0,"CNY",6480,1);
}
void GameScence::define(Ref* pSender)
{
    umeng::MobClickCpp::event("event_1");
    umeng::MobClickCpp::event("event_2","test");
    umeng::eventDict PayMap;
    PayMap.insert(std::make_pair("userid", std::string("userid-xuezhi")));
    PayMap.insert(std::make_pair("ordeid", std::string("xxxxxx")));
    PayMap.insert(std::make_pair("item", std::string("test-xuezhi")));
    PayMap.insert(std::make_pair("amout", "100"));
    umeng::MobClickCpp::event("__submit_payment", &PayMap);
    
    umeng::eventDict successPayMap;
    successPayMap.insert(std::make_pair("userid", std::string("xuezhi")));
    successPayMap.insert(std::make_pair("orderid", std::string("xxxxxx")));
    successPayMap.insert(std::make_pair("item", std::string("test-xuezhi")));
    successPayMap.insert(std::make_pair("amount", "200"));
    umeng::MobClickCpp::event("__finish_payment", &successPayMap,10);
    
    
    umeng::eventDict beginPayMap;
    beginPayMap.insert(std::make_pair("userid", std::string("userid-xuezhi")));
    beginPayMap.insert(std::make_pair("ordeid", std::string("xxxxxx")));
    beginPayMap.insert(std::make_pair("item", std::string("test-xuezhi")));
    beginPayMap.insert(std::make_pair("amout", "100"));
    
    umeng::MobClickCpp::registerSuperProperty(&beginPayMap);
    
    umeng::MobClickCpp::unregisterSuperProperty("userid");
    
    std::string testMap = umeng::MobClickCpp::getSuperProperties();
    
    
    std::vector<std::string> vec;
    vec.push_back("userid");
    vec.push_back("ordeid");
    vec.push_back("item");
    vec.push_back("amout");
    vec.push_back("test");
    vec.push_back("test1");
    //
    umeng::MobClickCpp::setFirstLaunchEvent(&vec);
    umeng::MobClickCpp::clearSuperProperties();
    
}
void GameScence::menuCloseCallback(Ref* pSender)
{
    auto * s = HelloWorld::createScene();
    float t = 1.2f;
    
    auto reScene = TransitionJumpZoom ::create(t , s);
    Director::getInstance()->replaceScene(reScene);
    
}

