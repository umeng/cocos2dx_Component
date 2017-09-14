/*
 * FileName : CCUMScoialSDK.h
 * Author   : hehonghui
 * Company  : umeng.com
 *
 */

#ifndef __CCUMSOCIALSDK__
#define __CCUMSOCIALSDK__

#include "cocos2d.h"

#include <vector>


using namespace std;

enum Platform {
	/// 新浪微博
	SINA = 0,
	/// 微信
	WEIXIN = 1,
	/// 微信朋友圈
	WEIXIN_CIRCLE = 2,
	/// QQ
	QQ = 3,
	 /// QQ空间
	QZONE = 4,
	/// 人人网
	RENREN = 5,
	/// 豆瓣
	DOUBAN = 6,
	/// 来往
	LAIWANG = 7,
	/// 来往动态
	LAIWANG_CIRCLE = 8,
	/// 易信
	YIXIN = 9,
	/// 易信朋友圈
	YIXIN_CIRCLE = 10,
	/// facebook
	FACEBOOK = 11,
	/// twitter
	TWITTER = 12,
	/// instagram
	INSTAGRAM = 13,
	/// 短信
	SMS = 14,
	/// 邮件
	EMAIL = 15,
	/// 腾讯微博
	TENCENT_WEIBO = 16
};


typedef void (*AuthEventHandler)(int platform, int stCode,
		const map<string, string>& data);

    typedef void (*ShareEventHandler)(int platform, int stCode,
    const string& errorMsg);

typedef void (*BoardEventHandler)(int platform);
typedef void (*BoardDismissEventHandler)();
#define auth_selector(_SELECTOR) (AuthEventHandler)(&_SELECTOR)
#define share_selector(_SELECTOR) (ShareEventHandler)(&_SELECTOR)
#define board_selector(_SELECTOR) (BoardEventHandler)(&_SELECTOR)
#define boarddismiss_selector(_SELECTOR) (BoardDismissEventHandler)(&_SELECTOR)

namespace umeng {
    class CCUMSocialSDK {

    public:
        static void authorize(int platform, AuthEventHandler callback);
        static void deleteAuthorization(int platform, AuthEventHandler callback);
        static void openShare(vector<int>* platforms,const char* text, const char* title,const char* imgName,const char* targeturl,ShareEventHandler callback);
        static void openCustomShare(vector<int>* platforms,BoardEventHandler callback);
        static void setBoardDismissCallback(BoardDismissEventHandler callback);
        static void getPlatformInfo(int platforms,AuthEventHandler callback);
	
        static void directShare(int platform, const char* text,const char* title,const char* targeturl,
			const char* imgName, ShareEventHandler callback);

	

    };
}
#endif
