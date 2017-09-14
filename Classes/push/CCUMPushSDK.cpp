

#include "CCUMPushSDK.h"
#include <platform/CCCommon.h>
#include <CCUMPushSDK.h>
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




PushGetTagsCallBack tagsCallback = NULL;

PushRemainTagsCallBack remainCallback = NULL;
PushAliasCallBack aliasCallback = NULL;
 extern "C"
    {
       static bool getPushMethod(JniMethodInfo &mi, const char *methodName,
        const char *signature) {
    return JniHelper::getStaticMethodInfo(mi,
            "com/umeng/push/CCUMPushController", methodName, signature);
        }

        static void releasePushMethod(JniMethodInfo &mi) {
        mi.env->DeleteLocalRef(mi.classID);
        }
        JNIEXPORT void JNICALL Java_com_umeng_push_CCUMPushController_TagsCallBack(
        JNIEnv *env, jclass clz, jint stCode, jobjectArray data) {
    
if (tagsCallback != NULL) {
        list<string> tags;

    if (data == NULL)
    {
         tags.push_back("null");
        tagsCallback(stCode, tags);
        return;
    }
    for(int i=0;i<env->GetArrayLength(data);i++){
        jsize temp = i;
        jstring value = (jstring) env->GetObjectArrayElement(data,temp);
        if(value == NULL){
            continue;
        }

        const char* pvalue = env->GetStringUTFChars(value, NULL);
         tags.push_back(pvalue);
    }
        tagsCallback(stCode, tags);
    }
}

JNIEXPORT void JNICALL Java_com_umeng_push_CCUMPushController_AliasCallback(
        JNIEnv *env, jclass clz, jint stCode) {
    if (aliasCallback != NULL) {
        
        aliasCallback( stCode);
    }

}
JNIEXPORT void JNICALL Java_com_umeng_push_CCUMPushController_RemainCallback(
        JNIEnv *env, jclass clz, jint stCode, jint remain) {
    if (remainCallback != NULL) {
        
        remainCallback( stCode,remain);
    }

}
}
namespace umeng{
void CCUMPushSDK::addTags(const char *tags,  PushRemainTagsCallBack callback){
    remainCallback = callback;
    CCLog("addTags");
    if (remainCallback != NULL) {
        CCLog("#### addTags回调不为NULL");

    }
    JniMethodInfo mi;
    bool isHave = getPushMethod(mi, "addTag", "(Ljava/lang/String;)V");
    if (isHave) {
        jstring umtags = mi.env->NewStringUTF(tags);
        mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, umtags);
        mi.env->DeleteLocalRef(umtags);

        releasePushMethod(mi);
    }
}
 void CCUMPushSDK::deleteTags(const char *tags,  PushRemainTagsCallBack callback){
    remainCallback = callback;
    if (remainCallback != NULL) {
        CCLog("#### deleteTags回调不为NULL");

    }
    JniMethodInfo mi;
    bool isHave = getPushMethod(mi, "deleteTag", "(Ljava/lang/String;)V");
    if (isHave) {
        jstring umtags = mi.env->NewStringUTF(tags);
        mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, umtags);
        mi.env->DeleteLocalRef(umtags);

        releasePushMethod(mi);
    }
 }
 void CCUMPushSDK::getTags(PushGetTagsCallBack callback){
    tagsCallback = callback;
    if (remainCallback != NULL) {
        CCLog("#### getTags回调不为NULL");

    }
    JniMethodInfo mi;
    bool isHave = getPushMethod(mi, "listTag", "()V");
    if (isHave) {

            mi.env->CallStaticVoidMethod(mi.classID, mi.methodID);
            releasePushMethod(mi);
        }

 }
  void CCUMPushSDK::addAlias(const char *name, const char *type, PushAliasCallBack callback){
    aliasCallback = callback;

    if (aliasCallback != NULL) {
        CCLog("#### addAlias回调不为NULL");

    }
    JniMethodInfo mi;
    bool isHave = getPushMethod(mi, "addAlias", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (isHave) {
        jstring umname = mi.env->NewStringUTF(name);
        jstring umtype = mi.env->NewStringUTF(type);
        mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, umname,umtype);
        mi.env->DeleteLocalRef(umname);
        mi.env->DeleteLocalRef(umtype);
        releasePushMethod(mi);

    }
  }
  void CCUMPushSDK::setAlias(const char *name, const char *type, PushAliasCallBack callback){
        aliasCallback = callback;

    if (aliasCallback != NULL) {
        CCLog("#### addAlias回调不为NULL");

    }
    JniMethodInfo mi;
    bool isHave = getPushMethod(mi, "setAlias", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (isHave) {
        jstring umname = mi.env->NewStringUTF(name);
        jstring umtype = mi.env->NewStringUTF(type);
        mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, umname,umtype);
        mi.env->DeleteLocalRef(umname);
        mi.env->DeleteLocalRef(umtype);
        releasePushMethod(mi);

    }
  }
  void CCUMPushSDK::removeAlias(const char *name, const char *type, PushAliasCallBack callback){
            aliasCallback = callback;

    if (aliasCallback != NULL) {
        CCLog("#### addAlias回调不为NULL");

    }
    JniMethodInfo mi;
    bool isHave = getPushMethod(mi, "deleteAlias", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (isHave) {
        jstring umname = mi.env->NewStringUTF(name);
        jstring umtype = mi.env->NewStringUTF(type);
        mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, umname,umtype);
        mi.env->DeleteLocalRef(umname);
        mi.env->DeleteLocalRef(umtype);
        releasePushMethod(mi);

    }
  }

}
