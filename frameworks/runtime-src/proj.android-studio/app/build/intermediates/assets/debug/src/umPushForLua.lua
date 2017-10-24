cc.exports.umPushForLua = {}

--[[ 添加tag,将标签绑定至该设备
	 @param tags 标签.
     @callback 回调接口
	 @return .
 ]]

function umPushForLua.addTags(tags,callback_str)
    umeng_addTags(tags,callback_str)
end

--[[ 删除tag,将标签从设备绑定中删除
     @param tags 标签.
     @callback 回调接口
     @return .
 ]]

function umPushForLua.deleteTags(tags,callback_str)
    umeng_deleteTags(tags,callback_str)
end

--[[
	获取tag列表
    @callback 回调接口
    @return .
]]
function umPushForLua.getTags(callback_str)
	-- body
	--print(umeng_getTags())
    umeng_getTags(callback_str)
end

--[[
    添加别名(addAlias),将某用户绑定至设备，老的绑定的设备还在
    @param name 用户名
    @param type 默认好的平台类型
    @callback 回调接口
    @return void.
]]
function umPushForLua.addAlias(name,type,callback_str)
	-- body
	umeng_addAlias(name,type,callback_str)
end

--[[
	设置别名(setAlias),将某用户绑定至设备,覆盖老的，一一对应
    @param name 用户名
    @param type 默认好的平台类型
    @callback 回调接口
    @return void.
]]
function umPushForLua.setAlias(name,type,callback_str)
	-- body
	umeng_setAlias(name,type,callback_str)
end

--[[ 
    删除别名(removeAlias),将用户的别名绑定删除     
    @param name 用户名
    @param type 默认好的平台类型
    @callback 回调接口
    @return void.
]]
function umPushForLua.removeAlias(name,type,callback_str)
    -- body
    umeng_removeAlias(name,type,callback_str)
end

return cc.exports.umPushForLua
