//
//  MobClickCpp.m
//  MobClickCpp
//
//  Created by 周厚振 on 16-5-24.
//  Copyright (c) 2016年 zhouhouzhen. All rights reserved.
//

#include "UMCCCommon.h"
#include <platform/CCCommon.h>
#include <jni/JniHelper.h>
#include <jni.h>
//#include <stdio.h>
//#include "cocos2d.h"

#include <map>
#include <string>
#include <utility>
#include <vector>
#include <stddef.h>





USING_NS_CC;
using namespace std;



    
 extern "C"
    {
         static bool getCommonMethod(JniMethodInfo &mi, const char *methodName,const char *signature) {
            return JniHelper::getStaticMethodInfo(mi,
            "com/umeng/common/UMCocosConfuture", methodName, signature);
        }

        static void releaseCommonMethod(JniMethodInfo &mi) {
        mi.env->DeleteLocalRef(mi.classID);
        }
        static void initwrap() {
        
        JniMethodInfo mi;
        bool isHave = getCommonMethod(mi, "initCocos", "(java/lang/String;java/lang/String;)V");
        if (isHave) {
        jstring version = mi.env->NewStringUTF(VERSION);
        jstring type = mi.env->NewStringUTF(WRAP_TYPE);
        mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, version,type);
        mi.env->DeleteLocalRef(version);
        mi.env->DeleteLocalRef(type);

        releaseCommonMethod(mi);
            }
        }

JNIEXPORT void JNICALL Java_com_umeng_common_UMCocosConfuture_InitCC (
        JNIEnv *env, jclass clz) {
    
}
    }
  
    void UMCCCommon::setLogEnabled(bool value){
         JniMethodInfo mi;
        bool isHave = getCommonMethod(mi, "setLog",  "(Z)V");
        if (isHave) {
        mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, value);
        releaseCommonMethod(mi);
        }
       
    }
    void UMCCCommon::init(const char *appkey, const char *channel){
       
    }
   

