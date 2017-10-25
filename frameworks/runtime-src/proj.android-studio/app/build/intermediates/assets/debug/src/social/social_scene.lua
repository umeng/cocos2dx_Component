cc.exports.socialscene = {}


local function back(sender)
    -- body
    cc.Director:getInstance():popScene()
end

local function authorize(sender)
    local a_scene = require "social.authorize_scene"
    cc.Director:getInstance():pushScene(a_scene.create())
end

local function social(sender)
    local s_scene = require "social.soc_scene"
    cc.Director:getInstance():pushScene(s_scene.create())
end

local function getUserInfo(sender)
    local g_scene = require "social.getuserinfo_scene"
    cc.Director:getInstance():pushScene(g_scene.create())
end


function socialscene.create()
	local scene = cc.Scene:create()
    local size = cc.Director:getInstance():getWinSize()
	local  item1 = cc.MenuItemFont:create("授权"):setPosition(cc.p(size.width/2,size.height/2+100))
    item1:registerScriptTapHandler(authorize)
    local  item2 = cc.MenuItemFont:create("分享"):setPosition(cc.p(size.width/2,size.height/2))
    item2:registerScriptTapHandler(social)
    local  item3 = cc.MenuItemFont:create("获取用户信息"):setPosition(cc.p(size.width/2,size.height/2-100))
    item3:registerScriptTapHandler(getUserInfo)
    local  item4 = cc.MenuItemFont:create("返回"):setPosition(cc.p(cc.Director:getInstance():getWinSize().width-100,100))
	item4:registerScriptTapHandler(back)
    local  menu = cc.Menu:create()
	menu:addChild(item1)
    menu:addChild(item2)
    menu:addChild(item3)
    menu:addChild(item4)
    menu:setPosition(cc.p(0,0))
    scene:addChild(cc.Layer:create():addChild(menu))
	return scene
end


return cc.exports.socialscene
