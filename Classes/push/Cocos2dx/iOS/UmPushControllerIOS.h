

#ifndef __UmengGame__UmPushControllerIOS__
#define __UmengGame__UmPushControllerIOS__

#include "CCUMTypeDef.h"
#include <string>
#include <vector>
#import "CCUMPushSDK.h"


using namespace std;
using namespace umeng::social;

class UmPushControllerIOS {
public:
    
   
    
    //初始化sdk @石乐
    
    static void addTags(const char *tags,  PushRemainTagsCallBack callback);
    static void deleteTags(const char *tags,  PushRemainTagsCallBack callback);
    static void getTags(PushGetTagsCallBack callback);
    static void addAlias(const char *name, const char *type, PushAliasCallBack callback);
    static void setAlias(const char *name, const char *type, PushAliasCallBack callback);
    static void removeAlias(const char *name, const char *type, PushAliasCallBack callback);
      
private:
    static string m_appKey;
};

#endif /* defined(__UmengGame__UmPushControllerIOS__) */
