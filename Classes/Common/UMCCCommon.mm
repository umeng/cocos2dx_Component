#include "UMCCCommon.h"
#include <UMCommon/UMConfigure.h>
//#include <UMAnalytics/MobClick.h>
#include <UMAnalytics/MobClick.h>
#include <UMAnalytics/MobClickGameAnalytics.h>

#define UMENG_SDK_WRAPPER_TYPE                      @"Cocos2d-x"
#define UMENG_SDK_WRAPPER_VERSION                   @"4.7.1"


static  NSString* getNSStringFromCString(const char* cstr){
    if (cstr) {
        return [NSString stringWithUTF8String:cstr];
    }
    return nil;
}
    
       void UMCCCommon::setLogEnabled(bool value){
        BOOL valTmp = value?YES:NO;
        [UMConfigure setLogEnabled:valTmp];
        
    }
    void UMCCCommon::init(const char *appkey, const char *channel){
        
         [UMConfigure initWithAppkey:getNSStringFromCString(appkey) channel:getNSStringFromCString(channel)];
    }
    

