//
//  MobClickCpp.m
//  MobClickCpp
//
//  Created by zhangziqi on 14-2-24.
//  Copyright (c) 2014年 Umeng Inc. All rights reserved.
//

#ifndef __UMCCCommon_H__
#define __UMCCCommon_H__
#define VERSION "1.0"
#define WRAP_TYPE "cocos2dx"
class UMCCCommon{
        
public:
    static void setLogEnabled(bool value);
    
        
    static void init(const char *appkey, const char *channel);
};
#endif
