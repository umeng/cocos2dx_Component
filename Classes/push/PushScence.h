//
//  EntranceScene.hpp
//  UmengGame
//
//  Created by wangfei on 16/4/6.
//
//

#ifndef PushScence_hpp
#define PushScence_hpp


#include "cocos2d.h"

class PushScence: public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* scene();
    
    // a selector callback
    void menuCloseCallback(Ref* pSender);
    void addTags(Ref* pSender);
     void delTags(Ref* pSender);
     void listTags(Ref* pSender);
    void addAlias(Ref* pSender);
    void aliasType(Ref* pSender);
    void addExAlias(Ref* pSender);
    void delAlias(Ref* pSender);
    void Serialent(Ref* pSender);
    void appInfo(Ref* pSender);
    // implement the "static node()" method manually
    CREATE_FUNC(PushScence);
};

#endif
