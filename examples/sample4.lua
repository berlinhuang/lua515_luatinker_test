-- 如何在C++中创建Lua环境的table，并被C++和Lua环境操作


-- C++ 注册的haha表
-- haha = { value =1, inside = { value = 2 } }
print(haha)

print(haha.value)
print(haha.inside)
print(haha.inside.value)

-- C++会获取 haha.test 注册
haha.test = "input from lua"

-- C++ 调用print_table 传入 temp = { name = "local table !!" }
function print_table(arg)
	print("arg = ", arg)
	print("arg.name = ", arg.name)
end

-- C++ 调用return_table  
function return_table(arg)
	local ret = {}
	ret.name = arg
	return ret
end