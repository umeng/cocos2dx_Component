//
//  UmSocialControllerIOS.h
//  UmengGame
//
//  Created by 张梓琦 on 14-3-16.
//
//

#ifndef __UmengGame__UmSocialControllerIOS__
#define __UmengGame__UmSocialControllerIOS__

#include "CCUMTypeDef.h"
#include <string>
#include <vector>

#define CC_ShareToWeibo    1
#define CC_ShareToWechat       1
#define CC_ShareToQQOrQzone    1
#define CC_ShareToLaiWang      1
#define CC_ShareToYiXin        1
#define CC_ShareToFacebook     1
#define CC_ShareToTwitter      1
#define CC_ShareToInstagram    1

using namespace std;
using namespace umeng::social;

class UmSocialControllerIOS {
public:
    
   
    
    //初始化sdk
    static void initCocos2dxSDK(const char *sdkType, const char *version);

   
    
    //授权某社交平台
    static void authorize(int platform, AuthEventHandler callback);
    //获取用户信息
    static void getinfo(int platform, AuthEventHandler callback);
    //解除某平台授权
    static void deleteAuthorization(int platform,AuthEventHandler callback);
    
    //是否已经授权某平台
    static bool isAuthorized(int platform);
    
    //打开分享面板
    static void openShareWithImagePath(vector<int>* platform, const char* text, const char* title,const char* imagePath,const char* targeturl,ShareEventHandler callback);
    //打开自定义分享面板
    static void openCustomShareBoard(vector<int>* platform, BoardEventHandler callback);

    static void setDismissCallback(BoardDismissEventHandler callback);

    //直接分享到各个社交平台
    static void directShare(const char* text, const char* title, const char* targeturl,const char* imagePath, int platform, ShareEventHandler callback);
    
    //打开SDK的log输出
    static void openLog(bool flag);
    
  
    
    
      
      
private:
    static string m_appKey;
};

#endif /* defined(__UmengGame__UmSocialControllerIOS__) */
