/*
 * FileName : CCUMScoialSDK.h
 * Author   : hehonghui
 * Company  : umeng.com
 *
 */

#ifndef __CCUMPushSDK__
#define __CCUMPushSDK__

#include "cocos2d.h"

#include <vector>

USING_NS_CC;
using namespace std;


typedef void (*PushGetTagsCallBack)(int stCode,list<string>& data);
typedef void (*PushRemainTagsCallBack)(int stCode,int remain);
typedef void (*PushAliasCallBack)(int stCode);

#define push_gettag_selector(_SELECTOR) (PushGetTagsCallBack)(&_SELECTOR)
#define push_remain_selector(_SELECTOR) (PushRemainTagsCallBack)(&_SELECTOR)
#define push_alias_selector(_SELECTOR) (PushAliasCallBack)(&_SELECTOR)

namespace umeng {

class CCUMPushSDK {

public:

	/**
	 * 构建CCUMPushSDK对象
	 * @param appKey 友盟app key
	 */
	static CCUMPushSDK* create();
    static void addTags(const char *tags,  PushRemainTagsCallBack callback);
    static void deleteTags(const char *tags,  PushRemainTagsCallBack callback);
    static void getTags(PushGetTagsCallBack callback);
    static void addAlias(const char *name, const char *type, PushAliasCallBack callback);
    static void setAlias(const char *name, const char *type, PushAliasCallBack callback);
    static void removeAlias(const char *name, const char *type, PushAliasCallBack callback);
	



};

}
#endif
