cc.exports.socscene = {}
local umShare = require "umSocialForLua"


function cc.exports.boardDismissCallback()
    
    print("share dismiss");
    -- body
end


function cc.exports.shareCallback(platform, stCode, errorMsg)
    local result = ""
   if (stCode == 200) then
        result = "分享成功"
        print("#### HelloWorld 分享成功 --> Cocos2d-x SDK ");
    elseif (stCode == -1) then
         result = "分享取消"
        print("#### HelloWorld 分享取消 --> Cocos2d-x SDK ");
    
    else 
        result = "分享失败";
        print("#### HelloWorld 分享出错 --> Cocos2d-x SDK ");
    end
    if errorMsg ~= nil then
        result = result..errorMsg
    end
    print("#### callback!!!!!! "..result)
  
    print("platform num is : "..platform..","..stCode)
    -- body
end


function cc.exports.custom_callback( platform )

     if (platform == umSharePlatform["QQ"]) then

        umShare.qq_share("Umeng Social Cocos2d-x SDK -->  qqshare   DIFFERENT CONTENT","title" ,"","res/closenormal",
                          "shareCallback");

     elseif(platform == umSharePlatform["WEIXIN"]) then

         umShare.wx_share("Umeng Social Cocos2d-x SDK -->  wxshare   DIFFERENT CONTENT","title" ,"","CloseSelected.png",
                                 "shareCallback");
    else
        umShare.sina_share("Umeng Social Cocos2d-x SDK -->  sinashare   DIFFERENT CONTENT","title" ,"","res/closenormal",
                          "shareCallback");
     end
    
    -- body
end

local lab_tag = 456
local function back(sender)
    -- body
    cc.Director:getInstance():popScene()
end
local function qq_share(sender)
    -- body
    umShare.share(umSharePlatform["QQ"],"Umeng Social Cocos2d-x SDK -->  qqshare   testing","title" ,"","res/closenormal","shareCallback")
end
local function sina_share(sender)
    -- body
    umShare.share(umSharePlatform["SINA"],"Umeng Social Cocos2d-x SDK -->sinashare testing","title" ,"https://wsq.umeng.com/","https://dev.umeng.com/images/tab2_1.png","shareCallback")
end

local function wx_share(sender)
    -- body
    umShare.share(umSharePlatform["WEIXIN"],"Umeng Social Cocos2d-x SDK -->  wxshare   testing","title" ,"https://wsq.umeng.com/","https://dev.umeng.com/images/tab2_1.png","shareCallback")
end

local function open_share(sender)
    -- body
    local platforms = {0,4,3,1,2,12,11}
     umShare.open_share(platforms, "来自分享面板", "title" ,"https://dev.umeng.com/images/tab2_1.png","https://wsq.umeng.com/","boardDismissCallback","shareCallback")

end

local function custom_share(sender)
    -- body
    local platforms = {0,4,3,1,2,12,11}
    umShare.custom_share(platforms,"boardDismissCallback","custom_callback")
end

function socscene.create()
	local scene = cc.Scene:create()
    local size = cc.Director:getInstance():getWinSize()
	local  item1 = cc.MenuItemFont:create("qq"):setPosition(cc.p(300,490))
    item1:registerScriptTapHandler(qq_share)
    local  item2 = cc.MenuItemFont:create("新浪"):setPosition(cc.p(300,420))
    item2:registerScriptTapHandler(sina_share)
    local  item3 = cc.MenuItemFont:create("微信"):setPosition(cc.p(300,350))
    item3:registerScriptTapHandler(wx_share)
    local  item4 = cc.MenuItemFont:create("打开分享面板"):setPosition(cc.p(300,280))
    item4:registerScriptTapHandler(open_share)
    local  item5 = cc.MenuItemFont:create("打开分享不同内容分享面板"):setPosition(cc.p(300,210))
    item5:registerScriptTapHandler(custom_share)
    local label = cc.Label:createWithSystemFont("分享回调结果","Arial", 50)
    label:setPosition(cc.p(size.width/2,50))
    local  item6 = cc.MenuItemFont:create("返回"):setPosition(cc.p(cc.Director:getInstance():getWinSize().width-100,100))
	item6:registerScriptTapHandler(back)
    local  menu = cc.Menu:create()
	menu:addChild(item1)
    menu:addChild(item2)
    menu:addChild(item3)
    menu:addChild(item4)
    menu:addChild(item5)
    menu:addChild(item6)
    menu:setPosition(cc.p(0,0))
    local layer = cc.Layer:create()
    layer:addChild(menu)
    layer:addChild(label,lab_tag)
    scene:addChild(layer)
	return scene
end


return cc.exports.socscene
