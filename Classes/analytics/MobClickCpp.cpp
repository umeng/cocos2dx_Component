//
//  MobClickCpp.m
//  MobClickCpp
//
//  Created by 周厚振 on 16-5-24.
//  Copyright (c) 2016年 zhouhouzhen. All rights reserved.
//

#include "MobClickCpp.h"

#include <jni/JniHelper.h>
#include <jni.h>

using namespace std;

namespace umeng {


    void MobClickCpp::setLogEnabled(bool value){
        JniMethodInfo t;
        if (getMethod(t,"setDebugMode", "(Z)V")){
            t.env->CallStaticVoidMethod(t.classID, t.methodID,value);
        }
    }
    void MobClickCpp::setCheckDevice(bool value){
        JniMethodInfo t;
        if (getMethod(t, "setCheckDevice", "(Z)V")){
            t.env->CallStaticVoidMethod(t.classID, t.methodID,value);
        }
    }
    void MobClickCpp::setSessionIdleLimit(int seconds){
        JniMethodInfo t;
        if (getMethod(t, "setSessionContinueMillis", "(J)V")){
            t.env->CallStaticVoidMethod(t.classID, t.methodID,seconds);
        }
    }
    
    void MobClickCpp::doNotCallItFromYourCode(const char *appKey, const char * channelId){
        //for ios
    }
    void MobClickCpp::setAppVersion(const char *){
        //for ios
    }
    void MobClickCpp::event(const char * eventId, const char * label){
        JniMethodInfo t;
        if (getMethod(t, "event", "(Ljava/lang/String;Ljava/lang/String;)V")){
            jstring eId = t.env->NewStringUTF(eventId);
            jstring la = t.env->NewStringUTF(label);
            t.env->CallStaticVoidMethod(t.classID, t.methodID,eId,la);
            t.env->DeleteLocalRef(eId);
            t.env->DeleteLocalRef(la);
        }
    }
    void MobClickCpp::event(const char * eventId, eventDict * attributes, int counter){
        JniMethodInfo t;
        if (getMethod(t, "event", "(Ljava/lang/String;Ljava/util/Map;I)V")){
            jstring eId = t.env->NewStringUTF(eventId);
            jobject jparamMap = createJavaMapObject(t.env, attributes);
            t.env->CallStaticVoidMethod(t.classID, t.methodID,eId,jparamMap,counter);
            t.env->DeleteLocalRef(eId);
            t.env->DeleteLocalRef(jparamMap);
        }
    }
    void MobClickCpp::event(const char * eventId, eventDict * attributes){
        JniMethodInfo t;
        if (getMethod(t, "event", "(Ljava/lang/String;Ljava/util/Map;)V")){
            jstring eId = t.env->NewStringUTF(eventId);
            jobject jparamMap = createJavaMapObject(t.env, attributes);
            t.env->CallStaticVoidMethod(t.classID, t.methodID,eId,jparamMap);
            t.env->DeleteLocalRef(eId);
            t.env->DeleteLocalRef(jparamMap);
        }
    }
   
    void MobClickCpp::setUserLevel(int level) {
        JniMethodInfo t;
        if (getMethod(t,"setPlayerLevel", "(I)V")){
            t.env->CallStaticVoidMethod(t.classID, t.methodID,level);
        }
    }
   
    
    void MobClickCpp::startLevel(const char *level){
        JniMethodInfo t;
        if (getMethod(t, "startLevel", "(Ljava/lang/String;)V")){
            jstring le = t.env->NewStringUTF(level);
            t.env->CallStaticVoidMethod(t.classID, t.methodID,le);
            t.env->DeleteLocalRef(le);
        }
    }
    
    void MobClickCpp::finishLevel(const char *level){
        JniMethodInfo t;
        if (getMethod(t, "finishLevel", "(Ljava/lang/String;)V")){
            jstring le = t.env->NewStringUTF(level);
            t.env->CallStaticVoidMethod(t.classID, t.methodID,le);
            t.env->DeleteLocalRef(le);
        }
    }
    
    void MobClickCpp::failLevel(const char *level){
        JniMethodInfo t;
        if (getMethod(t, "failLevel", "(Ljava/lang/String;)V")){
            jstring le = t.env->NewStringUTF(level);
            t.env->CallStaticVoidMethod(t.classID, t.methodID,le);
            t.env->DeleteLocalRef(le);
        }
    }
    
    void MobClickCpp::pay(double cash, int source, double coin){
        JniMethodInfo t;
        if (getMethod(t, "pay", "(DDI)V")){
            t.env->CallStaticVoidMethod(t.classID, t.methodID,cash,coin,source);
        }
    }
    
    void MobClickCpp::pay(double cash, int source, const char *item, int amount, double price){
        JniMethodInfo t;
        if (getMethod(t, "pay", "(DLjava/lang/String;IDI)V")){
            jstring it = t.env->NewStringUTF(item);
            t.env->CallStaticVoidMethod(t.classID, t.methodID,cash,it,amount,price,source);
            t.env->DeleteLocalRef(it);
        }
    }
    
    void MobClickCpp::buy(const char *item, int amount, double price){
        JniMethodInfo t;
        if (getMethod(t, "buy", "(Ljava/lang/String;ID)V")){
            jstring it = t.env->NewStringUTF(item);
            t.env->CallStaticVoidMethod(t.classID, t.methodID,it,amount,price);
            t.env->DeleteLocalRef(it);
        }
    }
    
    void MobClickCpp::use(const char *item, int amount, double price){
        JniMethodInfo t;
        if (getMethod(t, "use", "(Ljava/lang/String;ID)V")){
            jstring it = t.env->NewStringUTF(item);
            t.env->CallStaticVoidMethod(t.classID, t.methodID,it,amount,price);
            t.env->DeleteLocalRef(it);
        }
    }
    
    void MobClickCpp::bonus(double coin, int source){
        JniMethodInfo t;
        if (getMethod(t, "bonus", "(DI)V")){
            t.env->CallStaticVoidMethod(t.classID, t.methodID,coin,source);
        }
    }
    
    void MobClickCpp::bonus(const char *item, int amount, double price, int source){
        JniMethodInfo t;
        if (getMethod(t, "bonus", "(Ljava/lang/String;IDI)V")){
            jstring it = t.env->NewStringUTF(item);
            t.env->CallStaticVoidMethod(t.classID, t.methodID,it,amount,price,source);
            t.env->DeleteLocalRef(it);
        }
    }
    
    void MobClickCpp::beginLogPageView(const char *pageName){
        JniMethodInfo t;
        if (getMethod(t, "onPageStart", "(Ljava/lang/String;)V")){
            jstring page = t.env->NewStringUTF(pageName);
            t.env->CallStaticVoidMethod(t.classID, t.methodID,page);
            t.env->DeleteLocalRef(page);
        }
    }
    
    void MobClickCpp::endLogPageView(const char *pageName){
        JniMethodInfo t;
        if (getMethod(t, "onPageEnd", "(Ljava/lang/String;)V")){
            jstring page = t.env->NewStringUTF(pageName);
            t.env->CallStaticVoidMethod(t.classID, t.methodID,page);
            t.env->DeleteLocalRef(page);
        }
    }
    
    void MobClickCpp::setEncryptEnabled(bool value) {
       JniMethodInfo t;
        if (getMethod(t, "enableEncrypt", "(Z)V")){
            t.env->CallStaticVoidMethod(t.classID, t.methodID,value);
        }
    }
    
    void MobClickCpp::profileSignIn(const char *puid, const char *provider) {
        JniMethodInfo t;
        if(provider == NULL){
            if (getMethod(t, "onProfileSignIn", "(Ljava/lang/String;)V")){
                jstring uid = t.env->NewStringUTF(puid);
                t.env->CallStaticVoidMethod(t.classID, t.methodID,uid);
                t.env->DeleteLocalRef(uid);
            }
        }else{
            if (getMethod(t, "onProfileSignIn", "(Ljava/lang/String;Ljava/lang/String;)V")){
                jstring uid = t.env->NewStringUTF(puid);
                jstring pro = t.env->NewStringUTF(provider);
                t.env->CallStaticVoidMethod(t.classID, t.methodID,uid,pro);
                t.env->DeleteLocalRef(uid);
                t.env->DeleteLocalRef(pro);
            }
        }
    }
    
    void MobClickCpp::profileSignOff() {
        JniMethodInfo t;
        if (getMethod(t, "onProfileSignOff", "()V")){
            t.env->CallStaticVoidMethod(t.classID, t.methodID);
        }
    }
    void MobClickCpp::exchange(const char *orderId, double currencyAmount, const char *currencyType,double virtualAmount,int channel) {
        JniMethodInfo t;
        if (getMethod(t, "exchange", "(Ljava/lang/String;DLjava/lang/String;DI)V")){
            jstring oId = t.env->NewStringUTF(orderId);
            jstring cTp = t.env->NewStringUTF(currencyType);
            t.env->CallStaticVoidMethod(t.classID, t.methodID,oId,currencyAmount,cTp,virtualAmount,channel);
            t.env->DeleteLocalRef(oId);
            t.env->DeleteLocalRef(cTp);
        }
    }
    void MobClickCpp::setLatency(unsigned int latency) {
        JniMethodInfo t;
        if (getMethod(t,"setLatencyWindow", "(J)V")){
            t.env->CallStaticVoidMethod(t.classID,t.methodID,latency);
        }
    }
}
