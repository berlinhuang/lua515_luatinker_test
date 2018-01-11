-- 把C++中定义的类打入lua环境供Lua代码使用
-- 在C++中为Lua环境添加全局变量（类实例对象）


print(g_test._test) -- 打印g_test的成员变量_test
print(g_test:is_test())
print(g_test:ret_int())



temp = test(4) -- 创建一个test类
print(temp._test) -- 打印test的_test成员

a = g_test:get()

temp:set(a)
print(temp._test)
print(temp:is_base())
print(temp:is_test())



-- 绢栋茄 按眉狼 metatable阑 烹秦 殿废等 努贰胶客 弊 窃荐甸阑 混旗焊绰 窃荐
-------------------------------------------------------------------------------
function objinfo(obj)
	local meta = getmetatable(obj)
	if meta ~= nil then
		metainfo(meta)
	else
		print("no object infomation !!")
	end
end

function metainfo(meta)
	if meta ~= nil then
		local name = meta["__name"]
		if name ~= nil then
			metainfo(meta["__parent"])
			print("<"..name..">")
			for key,value in pairs(meta) do 
				if not string.find(key, "__..") then 
					if type(value) == "function" then
						print("\t[f] "..name..":"..key.."()") 
					elseif type(value) == "userdata" then
						print("\t[v] "..name..":"..key)
					end
				end
			end
		end
	end
end
-------------------------------------------------------------------------------

-- Lua 俊辑 按眉绰 userdata肺 牢侥等促.
print("g_test	-> ", g_test)
print("temp	-> ", temp)
print("a	-> ", a)

-- C++ 俊辑 殿废茄 g_test 狼 按眉 沥焊甫 混旗夯促.
print("objinfo(g_test)")
objinfo(g_test)

-- constructor 甫 烹秦 积己茄 temp 按眉 沥焊甫 混旗夯促.
print("objinfo(temp)")
objinfo(temp)

-- 殿废窍瘤 臼篮 A 备炼眉 屈狼 a 按眉 沥焊甫 混旗夯促.
print("objinfo(a)")
objinfo(a)

