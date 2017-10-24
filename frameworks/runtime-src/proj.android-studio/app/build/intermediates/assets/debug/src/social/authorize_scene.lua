cc.exports.authorizescene = {}


local umShare = require "umSocialForLua"
local lab_tag = 456

function cc.exports.authCallback(platform, stCode, data)
    local result = "";
    print("platform is "..platform)
    print("stCode is "..stCode)
    for k,v in pairs(data) do
        print("#### data "..k.."->"..v..".")
    end

    if (stCode == 200) then
        print("#### 授权完成")
        result = "授权完成"
        for k,v in pairs(data) do
            print("#### data "..k.."->"..v..".")
        end

    elseif (stCode == 0) then
        result = "授权出错";
        print("#### 授权出错");
    elseif (stCode == -1) then
        result = "取消授权";
        print("#### 取消授权");
    else 
           print("#### 未知类型");
    end
    --item->setString(result.c_str());
end

local function back(sender)
    -- body
    cc.Director:getInstance():popScene()
end
local function qq_authorize(sender)
    -- body
    umShare.authorize(umSharePlatform["QQ"],"authCallback")
end
local function qq_del_authorize(sender)
    -- body
    umShare.del_authorize(umSharePlatform["QQ"],"authCallback")
end
local function sina_authorize(sender)
    -- body
    umShare.authorize(umSharePlatform["SINA"],"authCallback")
end
local function sina_del_authorize(sender)
    -- body
    umShare.del_authorize(umSharePlatform["SINA"],"authCallback")
end
local function wx_authorize(sender)
    -- body
    umShare.authorize(umSharePlatform["WEIXIN"],"authCallback")
end
local function wx_del_authorize(sender)
    -- body
    umShare.del_authorize(umSharePlatform["WEIXIN"],"authCallback")
end
local function facebook_authorize(sender)
    -- body
    umShare.authorize(umSharePlatform["FACEBOOK"],"authCallback")
end
local function facebook_del_authorize(sender)
    -- body
    umShare.del_authorize(umSharePlatform["FACEBOOK"],"authCallback")
end
local function twitter_authorize(sender)
    -- body
    umShare.authorize(umSharePlatform["TWITTER"],"authCallback")
end
local function twitter_del_authorize(sender)
    -- body
    umShare.del_authorize(umSharePlatform["TWITTER"],"authCallback")
end

function authorizescene.create()
	local scene = cc.Scene:create()
    local size = cc.Director:getInstance():getWinSize()
	local  item1 = cc.MenuItemFont:create("qq授权"):setPosition(cc.p(300,490))
    item1:registerScriptTapHandler(qq_authorize)
    local  item2 = cc.MenuItemFont:create("新浪授权"):setPosition(cc.p(300,420))
    item2:registerScriptTapHandler(sina_authorize)
    local  item3 = cc.MenuItemFont:create("微信授权"):setPosition(cc.p(300,350))
    item3:registerScriptTapHandler(wx_authorize)
    local  item4 = cc.MenuItemFont:create("facebook授权"):setPosition(cc.p(300,280))
    item4:registerScriptTapHandler(facebook_authorize)
    local  item5 = cc.MenuItemFont:create("twitter授权"):setPosition(cc.p(300,210))
    item5:registerScriptTapHandler(twitter_authorize)
    local  item6 = cc.MenuItemFont:create("qq删除授权"):setPosition(cc.p(800,490))
    item6:registerScriptTapHandler(qq_del_authorize)
    local  item7 = cc.MenuItemFont:create("新浪删除授权"):setPosition(cc.p(800,420))
    item7:registerScriptTapHandler(sina_del_authorize)
    local  item8 = cc.MenuItemFont:create("微信删除授权"):setPosition(cc.p(800,350))
    item8:registerScriptTapHandler(wx_del_authorize)
    local  item9 = cc.MenuItemFont:create("facebook删除授权"):setPosition(cc.p(800,280))
    item9:registerScriptTapHandler(facebook_del_authorize)
    local  item10 = cc.MenuItemFont:create("twitter删除授权"):setPosition(cc.p(800,210))
    item10:registerScriptTapHandler(twitter_del_authorize)
    local label = cc.Label:createWithSystemFont("回调结果","Arial", 50)
    label:setPosition(cc.p(size.width/2,50))
    local  item11 = cc.MenuItemFont:create("返回"):setPosition(cc.p(cc.Director:getInstance():getWinSize().width-100,100))
	item11:registerScriptTapHandler(back)
    local  menu = cc.Menu:create()
	menu:addChild(item1)
    menu:addChild(item2)
    menu:addChild(item3)
    menu:addChild(item4)
    menu:addChild(item5)
    menu:addChild(item6)
    menu:addChild(item7)
    menu:addChild(item8)
    menu:addChild(item9)
    menu:addChild(item10)
    menu:addChild(item11)
    menu:setPosition(cc.p(0,0))
    local layer = cc.Layer:create()
    layer:addChild(menu)
    layer:addChild(label,lab_tag)
    scene:addChild(layer)
	return scene
end


return cc.exports.authorizescene
