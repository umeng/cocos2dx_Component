//
//  AuthScene.hpp
//  UmengGame
//
//  Created by wangfei on 16/4/6.
//
//

#ifndef __AUTH_SCENE_H__
#define __AUTH_SCENE_H__

#include "cocos2d.h"
using namespace std;
class Auth: public cocos2d::Layer
{
public:
  
    virtual bool init();

    static cocos2d::Scene* scene();
    void qqAuth(Ref* pSender);
    void sinaAuth(Ref* pSender);
    void wxAuth(Ref* pSender);
    void qqAuthDel(Ref* pSender);
    void sinaAuthDel(Ref* pSender);
    void wxAuthDel(Ref* pSender);
    void doubanAuth(Ref* pSender);
    void renrenAuth(Ref* pSender);
    void facebookAuth(Ref* pSender);
    void doubanAuthDel(Ref* pSender);
    void renrenAuthDel(Ref* pSender);
    void facebookAuthDel(Ref* pSender);
    void twitterAuth(Ref* pSender);
    void twitterAuthDel(Ref* pSender);


   
    // a selector callback
    void menuCloseCallback(Ref* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(Auth);
};

#endif
