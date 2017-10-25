cc.exports.pushscene = {}

local umpush = require "umPushForLua"

local function back(sender)
    -- body
    cc.Director:getInstance():popScene()
end
function cc.exports.callback(stCode,remain)
    print("stCode is "..stCode)
    print("remain is "..remain)
end

function cc.exports.tagCallBack(stCode, listdata)
    print("stCode is "..stCode)
    print("#listdata:"..#(listdata))       -->4  
    for i = 1, #(listdata) do  
        print(listdata[i])  -->1 2 3 4  
    end 
end
function cc.exports.aliasCallback(stCode)
    print("stCode is "..stCode)
end


local function addtags(sender)
    -- body
    umpush.addTags("addtags","callback")
end
local function deltags(sender)
    -- body
    umpush.deleteTags("addtags","callback")
end
local function addalias(sender)
    -- body
    umpush.addAlias("addalias","test","aliasCallback")
end
local function delalias(sender)
    -- body
    umpush.removeAlias("addalias","test","aliasCallback")
end
local function alias_type(sender)
    -- body
end
local function serialnet(sender)
    -- body
end
local function listtags(sender)
    -- body
    umpush.getTags("tagCallBack")
end
local function add_exclisive_alias(sender)
    -- body
    umpush.setAlias("addalias","test","aliasCallback")
end
local function appinfo(sender)
    -- body
end

function pushscene.create()
	local scene = cc.Scene:create()
	local  item1 = cc.MenuItemFont:create("addtags"):setPosition(cc.p(300,490))
    item1:registerScriptTapHandler(addtags)
    local  item2 = cc.MenuItemFont:create("deltags"):setPosition(cc.p(300,420))
    item2:registerScriptTapHandler(deltags)
    local  item3 = cc.MenuItemFont:create("addalias"):setPosition(cc.p(300,350))
    item3:registerScriptTapHandler(addalias)
    local  item4 = cc.MenuItemFont:create("delalias"):setPosition(cc.p(300,280))
    item4:registerScriptTapHandler(delalias)
    local  item7 = cc.MenuItemFont:create("listtags"):setPosition(cc.p(300,70))
    item7:registerScriptTapHandler(listtags)
    local  item8 = cc.MenuItemFont:create("add exclisive alias"):setPosition(cc.p(800,490))
    item8:registerScriptTapHandler(add_exclisive_alias)
    local  item15 = cc.MenuItemFont:create("返回"):setPosition(cc.p(cc.Director:getInstance():getWinSize().width-100,100))
	item15:registerScriptTapHandler(back)
    local  menu = cc.Menu:create()
	menu:addChild(item1)
    menu:addChild(item2)
    menu:addChild(item3)
    menu:addChild(item4)
    menu:addChild(item7)
    menu:addChild(item8)
    menu:addChild(item15)
    menu:setPosition(cc.p(0,0))
    scene:addChild(cc.Layer:create():addChild(menu))
	return scene
end


return cc.exports.pushscene
