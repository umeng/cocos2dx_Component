//
//  MobClickCpp.m
//  MobClickCpp
//
//  Created by zhangziqi on 14-2-24.
//  Copyright (c) 2014年 Umeng Inc. All rights reserved.
//

#ifndef __MobClickGameAnalytics__MobClickCpp__
#define __MobClickGameAnalytics__MobClickCpp__
#include "cocos2d.h"

#include <vector>

using namespace std;
USING_NS_CC;
#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#define UMENG_DEPRECATED __attribute__((deprecated))
#elif _MSC_VER >= 1400 //vs 2005 or higher
#define UMENG_DEPRECATED __declspec(deprecated)
#else
#define UMENG_DEPRECATED
#endif

#define VERSION "1.0"
#define WRAP_TYPE "cocos2dx"

    
    class UMCCCommon{
        
    public:
    
        
        static void setLogEnabled(bool value);
    
        
        static void init(const char *appkey, const char *channel);
        
        
        
    };



/** 开启友盟统计,默认以BATCH方式发送log.
 
 @param appKey 友盟appKey.
 @param channelId 渠道名称,为NULL或""时,ios默认会被被当作@"App Store"渠道，android默认为“Unknown”。
 @return void
 */
#define MOBCLICKCPP_START_WITH_APPKEY_AND_CHANNEL(appkey, channel)  \
umeng::MobClickCpp::doNotCallItFromYourCode((appkey), (channel));

#define MOBCLICKCPP_START_WITH_APPKEY(appkey)   MOBCLICKCPP_START_WITH_APPKEY_AND_CHANNEL(appkey, NULL)


#endif
