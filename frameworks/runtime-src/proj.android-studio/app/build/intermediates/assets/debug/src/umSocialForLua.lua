cc.exports.umSocialForLua = {}


cc.exports.umSharePlatform = {
    QQ = 0,
    SINA = 1,
    WEIXIN = 2,
    WEIXIN_CIRCLE = 3,
    QZONE = 4,
    EMAIL = 5,
    SMS = 6,
    FACEBOOK = 7,
    TWITTER = 8,
    WEIXIN_FAVORITE = 9,
    GOOGLEPLUS = 10,
    RENREN = 11,
    TENCENT = 12,
    DOUBAN = 13,
    FACEBOOK_MESSAGER = 14,
    YIXIN = 15,
    YIXIN_CIRCLE = 16,
    INSTAGRAM = 17,
    PINTEREST = 18,
    EVERNOTE = 19,
    POCKET = 20,
    LINKEDIN = 21,
    FOURSQUARE = 22,
    YNOTE = 23,
    WHATSAPP = 24,
    LINE = 25,
    FLICKR = 26,
    TUMBLR = 27,
    ALIPAY = 28,
    KAKAO = 29,
    DROPBOX = 30,
    VKONTAKTE = 31,
    DINGTALK = 32,
    MORE = 33
};
--[[ 授权
     @platform 平台
     @callback 回调接口
     @return .
 ]]
function umSocialForLua.authorize(platform,callback_str)
    umeng_authorize(platform,callback_str)
end
--[[ qq取消授权
     @platform 平台
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.del_authorize(platform,callback_str)
    umeng_del_authorize(platform,callback_str)
end

--[[ 分享
     @platform 平台
     @text 文本
     @title 标题
     @targeturl 目标url
     @imgName   图片名称
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.share(platform,text,title,targeturl,imgName,callback_str)
    umeng_directShare(platform,text,title,targeturl,imgName,callback_str)
end

--[[ 打开分享界面
     @platforms 要分享的平台数组
     @text 文本
     @title 标题
     @targeturl 目标url
     @imgName   图片名称
     @boardDismissCallback 平台消失时的回调
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.open_share(platforms,text,title,targeturl,imgName,boardDismissCallback,callback_str)
    umeng_openShare(platforms,text,title,targeturl,imgName,boardDismissCallback,callback_str)
end

--[[ 自定义分享
     @platforms 要分享的平台数组
     @boardDismissCallback 平台消失时的回调
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.custom_share(platforms,boardDismissCallback,callback_str)
    umeng_customShare(platforms,boardDismissCallback,callback_str)
end


--[[ 获取用户qq信息
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.getInfo(platform,callback_str)
    umeng_getInfo(platform,callback_str)
end

return cc.exports.umSocialForLua
