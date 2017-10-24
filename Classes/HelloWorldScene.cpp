#include "HelloWorldScene.h"
#include "Entrance.h"
#include "AnalyticsHome.h"
#include "PushScence.h"
#include "GameScence.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    this->setColor(Color3B(255, 255, 255));
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    MenuItemFont *analyticsButton = MenuItemFont::create("统计", CC_CALLBACK_1(::HelloWorld::gotoAnalytics, this));
    
    analyticsButton->setPosition(Vec2(visibleSize.width/2, 160));
    analyticsButton->setFontSizeObj(14);
    // 底层API分享
    MenuItemFont *pushButton = MenuItemFont::create("推送", CC_CALLBACK_1(HelloWorld::gotoPush, this));
    pushButton->setPosition(Vec2(visibleSize.width/2, 120));
    pushButton->setFontSizeObj(14);
    // 授权某平台
    MenuItemFont *shareButton = MenuItemFont::create("分享", CC_CALLBACK_1(HelloWorld::gotoShare, this));
    shareButton->setPosition(Vec2(visibleSize.width/2, 80));
    shareButton->setFontSizeObj(14);

    // create menu, it's an autorelease object
    auto menu = Menu::create();
    menu->setPosition(Vec2::ZERO);
    menu->addChild(analyticsButton,1);
    menu->addChild(pushButton,1);
    menu->addChild(shareButton,1);
    menu->addChild(closeItem,1);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    Label *pLabel = Label::createWithTTF("UM-Component", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(Vec2(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - pLabel->getContentSize().height));
    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
   
    
    return true;
}
void HelloWorld::gotoAnalytics(Ref* pSender) {
    TransitionScene * reScene = NULL;
    Scene * s = GameScence::scene();
    float t = 1.2f;
    
    reScene = TransitionJumpZoom ::create(t , s);
    Director::getInstance()->replaceScene(reScene);
}
void HelloWorld::gotoShare(Ref* pSender) {
    TransitionScene * reScene = NULL;
    Scene * s = Entrance::scene();
    float t = 1.2f;
    
    reScene = TransitionJumpZoom ::create(t , s);
    Director::getInstance()->replaceScene(reScene);
}
void HelloWorld::gotoPush(Ref* pSender) {
    TransitionScene * reScene = NULL;
    Scene * s = PushScence::scene();
    float t = 1.2f;
    
    reScene = TransitionJumpZoom ::create(t , s);
    Director::getInstance()->replaceScene(reScene);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
