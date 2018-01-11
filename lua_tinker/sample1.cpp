// sample1.cpp : C++ 客 Lua 惑龋埃狼 窃荐 角青阑 舅酒夯促.
//

#include "stdafx.h"
#include "sample1.h"

extern "C" 
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
};

#include "lua_tinker.h"

int cpp_func(int arg1, int arg2)
{
	return arg1 + arg2;
}

void sample1()
{
	lua_State* L = lua_open();//获取lua栈对象
	luaopen_base(L); //打开lua库
	lua_tinker::def(L, "cpp_func", cpp_func); //lua_tinker::def注册一个C++全局函数
	lua_tinker::dofile(L, "sample1.lua");//打开lua文件
	int result = lua_tinker::call<int>(L, "lua_func", 3, 4);//通过lua_tinker::call调用到sample1.lua里面的lua函数
	printf("lua_func(3,4) = %d\n", result);
	lua_close(L);//关闭释放lua栈对象
	system("pause");
}
