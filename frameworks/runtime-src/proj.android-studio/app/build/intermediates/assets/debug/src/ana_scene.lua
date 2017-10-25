cc.exports.anascene = {}

local mobclick = require "MobClickForLua"
local function back(sender)
    -- body
    cc.Director:getInstance():popScene()
end
local function start(sender)
    -- body
    mobclick.startLevel("start")
end
local function endLevel(sender)
    -- body
    mobclick.finishLevel("start")
end
local function fail(sender)
    -- body
    mobclick.failLevel("start")
end
local function use(sender)
    -- body
    mobclick.use("magic_bottle", 2, 50)
    mobclick.setUserLevel(11)
end
local function bonus(sender)
    -- body
    mobclick.bonus(5.0,10)
end
local function signIn(sender)
    -- body
    mobclick.profileSignIn("lua")
end
local function signoff(sender)
    -- body
    mobclick.profileSignOff()
end
local function buy(sender)
    -- body
    mobclick.buy("buy",2,4)
end
local function bugvir(sender)
    -- body
    mobclick.pay(2.22,3,"pay",10,4)
end
local function exchange(sender)
    -- body
    mobclick.pay(1.11,2,2.3)
end
local function indent(sender)
    -- body
    mobclick.exchange("test_order",648.0,"CNY",6480,1)
end
local function define(sender)
    -- body
    mobclick.event("event_1")
    mobclick.event("event_2","test")
    local lucky= {john="chips" ,jane ="lemonade",jolene="egg salad" }
    mobclick.event("__submit_payment",lucky)

    mobclick.event("__finish_payment",lucky,10)
end
local function track(sender)
    -- body
    mobclick.track("test")
    local lucky= {john="chips" ,jane ="lemonade",jolene="egg salad" }
    mobclick.track("test_1",lucky)
end
local function SuperProperty(sender)
    -- body
    local lucky= {john="chips" ,jane ="lemonade",jolene="egg salad" }
    mobclick.registerSuperProperty(lucky)
    mobclick.unregisterSuperProperty("john")
    print(mobclick.getSuperProperty("jane"))
    print(mobclick.getSuperProperties())
    mobclick.clearSuperProperties()
    local first = {"Lua", "Tutorial"}
    mobclick.setFirstLaunchEvent(first)
end

function anascene.create()
	local scene = cc.Scene:create()
	local  item1 = cc.MenuItemFont:create("关卡开始"):setPosition(cc.p(300,490))
    item1:registerScriptTapHandler(start)
    local  item2 = cc.MenuItemFont:create("关卡失败"):setPosition(cc.p(300,420))
    item2:registerScriptTapHandler(fail)
    local  item3 = cc.MenuItemFont:create("关卡结束"):setPosition(cc.p(300,350))
    item3:registerScriptTapHandler(endLevel)
    local  item4 = cc.MenuItemFont:create("使用物品"):setPosition(cc.p(300,280))
    item4:registerScriptTapHandler(use)
    local  item5 = cc.MenuItemFont:create("游戏奖励"):setPosition(cc.p(300,210))
    item5:registerScriptTapHandler(bonus)
    local  item6 = cc.MenuItemFont:create("用户登入"):setPosition(cc.p(300,140))
    item6:registerScriptTapHandler(signIn)
    local  item7 = cc.MenuItemFont:create("用户登出"):setPosition(cc.p(300,70))
    item7:registerScriptTapHandler(signoff)
    local  item8 = cc.MenuItemFont:create("充值付费"):setPosition(cc.p(800,490))
    item8:registerScriptTapHandler(exchange)
    local  item9 = cc.MenuItemFont:create("购买物品（真实消费）"):setPosition(cc.p(800,420))
    item9:registerScriptTapHandler(buy)
    local  item10 = cc.MenuItemFont:create("购买物品（虚拟消费）"):setPosition(cc.p(800,350))
    item10:registerScriptTapHandler(bugvir)
    local  item11 = cc.MenuItemFont:create("订单充值"):setPosition(cc.p(800,280))
    item11:registerScriptTapHandler(indent)
    local  item12 = cc.MenuItemFont:create("自定义事件"):setPosition(cc.p(800,210))
    item12:registerScriptTapHandler(define)
    local  item13 = cc.MenuItemFont:create("track"):setPosition(cc.p(800,140))
    item13:registerScriptTapHandler(track)
    local  item14 = cc.MenuItemFont:create("超级属性"):setPosition(cc.p(800,70))
    item14:registerScriptTapHandler(SuperProperty)
    local  item15 = cc.MenuItemFont:create("返回"):setPosition(cc.p(cc.Director:getInstance():getWinSize().width-100,100))
	item15:registerScriptTapHandler(back)
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
    menu:addChild(item12)
    menu:addChild(item13)
    menu:addChild(item14)
    menu:addChild(item15)
    menu:setPosition(cc.p(0,0))
    scene:addChild(cc.Layer:create():addChild(menu))
	return scene
end


return cc.exports.anascene