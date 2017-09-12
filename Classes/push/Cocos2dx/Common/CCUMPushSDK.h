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



class CCUMPushSDK {
private:
	CCUMPushSDK();
	void initSDK();
public:

	/**
	 * 构建CCUMPushSDK对象
	 * @param appKey 友盟app key
	 */
	static CCUMPushSDK* create();

	

private:
	static CCUMPushSDK *_instance;
	vector<int>* mPlatforms;
    const char* _wrapperType;
	const char* _wrapperVersion;

};
typedef void (*PushGetTagsCallBack)(int stCode,int remain,const list<string>& data);
typedef void (*PushRemainTagsCallBack)(int stCode,int remain);
typedef void (*PushAliasCallBack)(int stCode);
#define push_selector(_SELECTOR) (PushCallBack)(&_SELECTOR)

#endif
