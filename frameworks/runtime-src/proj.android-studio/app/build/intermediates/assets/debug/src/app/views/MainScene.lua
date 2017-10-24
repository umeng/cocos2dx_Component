--require "push_scene"
--require "share_scene"

local MainScene = class("MainScene", cc.load("mvc").ViewBase)


local function Game(sender)
    local a_scene = require "ana_scene"
    cc.Director:getInstance():pushScene(a_scene.create())
    print("Game item is clicked.")
end

local function push(sender)
    local p_scene = require "push_scene"
    cc.Director:getInstance():pushScene(p_scene.create())
end

local function social(sender)
    local s_scene = require "social.social_scene"
    cc.Director:getInstance():pushScene(s_scene.create())
end

function MainScene:onCreate()
    local size = cc.Director:getInstance():getWinSize()
    local  item7 = cc.MenuItemFont:create("统计")
                    :setPosition(cc.p(size.width/2,size.height/2+100))
    local  item8 = cc.MenuItemFont:create("推送")
                    :setPosition(cc.p(size.width/2,size.height/2))
    local  item9 = cc.MenuItemFont:create("分享")
                    :setPosition(cc.p(size.width/2,size.height/2-100))
    local  menu = cc.Menu:create()
    item7:registerScriptTapHandler(Game)
    item8:registerScriptTapHandler(push)
    item9:registerScriptTapHandler(social)
    menu:addChild(item7)
    menu:addChild(item8)
    menu:addChild(item9)
    menu:setPosition(cc.p(0,0))
    cc.Layer:create():addChild(menu):addTo(self)
end

return MainScene
