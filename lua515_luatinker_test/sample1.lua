  --lua调用C++函数 cpp_func要先注册
result = cpp_func(1, 2)

print("cpp_func(1,2) = "..result)


 -- C++调用lua函数 arg1, arg2 是C++中传入的
function lua_func(arg1, arg2)
	return arg1 + arg2
end


