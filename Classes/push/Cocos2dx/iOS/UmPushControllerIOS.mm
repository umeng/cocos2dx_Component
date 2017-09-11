

#include "UmPushControllerIOS.h"
#import <UIKit/UIKit.h>
#import "UmPushControllerIOS.h"



UIViewController* getViewController(){
    UIViewController* ctrol = nil;
    if ( [[UIDevice currentDevice].systemVersion floatValue] < 6.0)
    {
        // warning: addSubView doesn't work on iOS6
        NSArray* array=[[UIApplication sharedApplication]windows];
        UIWindow* win=[array objectAtIndex:0];
        
        UIView* ui=[[win subviews] objectAtIndex:0];
        ctrol=(UIViewController*)[ui nextResponder];
    }
    else
    {
        // use this method on ios6
        ctrol=[UIApplication sharedApplication].keyWindow.rootViewController;
    }
    return ctrol;
}
NSString* getNSStringFromCString(const char* cstr){
    if (cstr) {
        return [NSString stringWithUTF8String:cstr];
    }
    return nil;
}
string asserstring(NSString* str){
    if (str == nil || str.length == 0) {
        return "nil";
    }else{
        return  string([str UTF8String]);
    }
}

void UmPushControllerIOS::initCocos2dxSDK(const char *sdkType, const char *version){
 
    
}
void UmPushControllerIOS::setAlias(const char *name, const char *type, PushCallBack callback){
    
    map<string,string> data;
    data.insert(pair<string, string>("uid",asserstring(@"123")));
    callback(0,data);
}


