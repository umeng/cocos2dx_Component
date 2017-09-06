//
//  GetScene.hpp
//  UmengGame
//
//  Created by wangfei on 16/4/6.
//
//

#ifndef GetScene_hpp
#define GetScene_hpp

#include "cocos2d.h"

class Get: public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* scene();
    void qqGet(Ref* pSender);
    void sinaGet(Ref* pSender);
    void wxGet(Ref* pSender);

    // a selector callback
    void menuCloseCallback(Ref* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(Get);
};

#endif
