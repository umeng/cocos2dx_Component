//
//  ShareScene.hpp
//  UmengGame
//
//  Created by wangfei on 16/4/6.
//
//

#ifndef ShareScene_hpp
#define ShareScene_hpp

#include "cocos2d.h"

class Share: public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* scene();
    void qqShare(Ref* pSender);
    void sinaShare(Ref* pSender);
    void wxShare(Ref* pSender);
    void boardShare(Ref* pSender);
    void boardcustomShare(Ref* pSender);
    // a selector callback
    void menuCloseCallback(Ref* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(Share);
};

#endif
