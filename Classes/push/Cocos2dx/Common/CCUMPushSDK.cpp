

#include "CCUMPushSDK.h"
#include <platform/CCCommon.h>

#include <stddef.h>


#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#include "UmPushControllerIOS.h"

#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#include "Cocos2dx/Android/CCUMPushController.h"

#endif

USING_NS_CC;
using namespace std;



CCUMPushSDK::CCUMPushSDK() :
		mPlatforms(new vector<int>()),
        _wrapperType("Cocos2d-x"),
        _wrapperVersion("2.0") {


	initSDK();
}

/*
 * 初始化sdk
 */
void CCUMPushSDK::initSDK() {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS



#endif
}
 CCUMPushSDK* CCUMPushSDK::create() {
    
    if (_instance == NULL) {
        _instance = new CCUMPushSDK();
    }
    return _instance;
}
void CCUMPushSDK::addTags(const char *tags,  PushRemainTagsCallBack callback){
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
   
  
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    UmPushControllerIOS::addTags(tags, callback);
    
#endif
}
void CCUMPushSDK::deleteTags(const char *tags,  PushRemainTagsCallBack callback){
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    UmPushControllerIOS::deleteTags(tags, callback);
    
#endif
}
void CCUMPushSDK::getTags(PushGetTagsCallBack callback){
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    UmPushControllerIOS::getTags(callback);
    
#endif
}
void CCUMPushSDK::addAlias(const char *name, const char *type, PushAliasCallBack callback){
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    UmPushControllerIOS::addAlias(name, type,callback);
    
#endif
}
void CCUMPushSDK::setAlias(const char *name, const char *type, PushAliasCallBack callback){
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    UmPushControllerIOS::setAlias(name,type, callback);
    
#endif
}
void CCUMPushSDK::removeAlias(const char *name, const char *type, PushAliasCallBack callback){
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    UmPushControllerIOS::removeAlias(name,type, callback);
    
#endif
}