

#include "CCUMPushSDK.h"
#import <UIKit/UIKit.h>
#import <UMPush/UMessage.h>
#import "CCUMPushSDK.h"



static UIViewController* getViewController(){
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
static  NSString* getNSStringFromCString(const char* cstr){
    if (cstr) {
        return [NSString stringWithUTF8String:cstr];
    }
    return nil;
}
static string asserstring(NSString* str){
    if (str == nil || str.length == 0) {
        return "nil";
    }else{
        return  string([str UTF8String]);
    }
}

namespace umeng {
    
void CCUMPushSDK::addTags(const char *tags, PushRemainTagsCallBack callback){
    [UMessage addTags:getNSStringFromCString(tags) response:^(id  _Nonnull responseObject, NSInteger remain, NSError * _Nonnull error) {
        int code = -1;
        int remainnum = 0;
        if (error) {
            code = error.code;
        }else{
            if ([responseObject isKindOfClass:[NSDictionary class]]) {
                NSDictionary *respobj = responseObject;
                // 授权信息
                if ([[respobj allKeys] containsObject:@"success"]) {
                    if ([[respobj objectForKey:@"success"] isEqualToString:@"ok"]) {
                        code = 200 ;
                    }
                }
                if ([[respobj allKeys] containsObject:@"remain"]) {
                    remainnum = [[respobj objectForKey:@"remain"] intValue];
                }
            }
        }
        callback(code, remainnum);

    }];
}

void CCUMPushSDK::deleteTags(const char *tags, PushRemainTagsCallBack callback){
    [UMessage deleteTags:getNSStringFromCString(tags) response:^(id  _Nonnull responseObject, NSInteger remain, NSError * _Nonnull error) {
        int code = -1;
        int remainnum = 0;
        if (error) {
            code = error.code;
        }else{
            if ([responseObject isKindOfClass:[NSDictionary class]]) {
                NSDictionary *respobj = responseObject;
                // 授权信息
                if ([[respobj allKeys] containsObject:@"success"]) {
                    if ([[respobj objectForKey:@"success"] isEqualToString:@"ok"]) {
                        code = 200 ;
                    }
                }
                if ([[respobj allKeys] containsObject:@"remain"]) {
                    remainnum = [[respobj objectForKey:@"remain"] intValue];
                }
            }
        }
        callback(code, remainnum);
    }];
}

void CCUMPushSDK::getTags(PushGetTagsCallBack callback){
    [UMessage getTags:^(NSSet * _Nonnull responseTags, NSInteger remain, NSError * _Nonnull error) {
        int code = -1;
        list<string> tags;
        int remainnum = 0;
        if (error) {
            code = error.code;
        }else{
            if ([responseTags isKindOfClass:[NSSet class]]) {
                NSArray * tagsarray = [responseTags allObjects];
                for (int i = 0; i < tagsarray.count; i++) {
                    NSString *str = tagsarray[i];
                    tags.push_back(asserstring(str));
                }
            }
        }
        if (remain) {
            remainnum = remain ;
        }
        callback(code,tags);
    }];
}

void CCUMPushSDK::addAlias(const char *name, const char *type, PushAliasCallBack callback){
    [UMessage addAlias:getNSStringFromCString(name) type:getNSStringFromCString(type) response:^(id  _Nonnull responseObject, NSError * _Nonnull error) {
        int code = -1;
        int remainnum = 0;
        if (error) {
            code = error.code;
        }else{
            if ([responseObject isKindOfClass:[NSDictionary class]]) {
                NSDictionary *respobj = responseObject;
                // 授权信息
                if ([[respobj allKeys] containsObject:@"success"]) {
                    if ([[respobj objectForKey:@"success"] isEqualToString:@"ok"]) {
                        code = 200 ;
                    }
                }
            }
        }
        callback(code);
    }];

}

void CCUMPushSDK::setAlias(const char *name, const char *type, PushAliasCallBack callback){
    [UMessage setAlias:getNSStringFromCString(name) type:getNSStringFromCString(type) response:^(id  _Nonnull responseObject, NSError * _Nonnull error) {
        int code = -1;
        if (error) {
            code = error.code;
        }else{
            if ([responseObject isKindOfClass:[NSDictionary class]]) {
                NSDictionary *respobj = responseObject;
                // 授权信息
                if ([[respobj allKeys] containsObject:@"success"]) {
                    if ([[respobj objectForKey:@"success"] isEqualToString:@"ok"]) {
                        code = 200 ;
                    }
                }
            }
        }
        callback(code);
    }];
}

void CCUMPushSDK::removeAlias(const char *name, const char *type, PushAliasCallBack callback){
    [UMessage removeAlias:getNSStringFromCString(name) type:getNSStringFromCString(type) response:^(id  _Nonnull responseObject, NSError * _Nonnull error) {
        int code = -1;
        if (error) {
            code = error.code;
        }else{
            if ([responseObject isKindOfClass:[NSDictionary class]]) {
                NSDictionary *respobj = responseObject;
                // 授权信息
                if ([[respobj allKeys] containsObject:@"success"]) {
                    if ([[respobj objectForKey:@"success"] isEqualToString:@"ok"]) {
                        code = 200 ;
                    }
                }
            }
        }
        callback(code);
    }];
}

}

