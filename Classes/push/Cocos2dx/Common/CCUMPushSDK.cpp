

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
