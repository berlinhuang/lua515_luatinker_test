// sample2.cpp : C + +和Lua相互之间的变量的访问。
//
#include "stdafx.h"
#include "sample2.h"
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};

#include "lua_tinker.h"

static int cpp_int = 100;//全局变量

void sample2()
{
	lua_State* L = lua_open();

	luaopen_base(L);

	lua_tinker::set(L, "cpp_int", cpp_int);// 注册全局变量

	lua_tinker::dofile(L, "sample2.lua");

	int lua_int = lua_tinker::get<int>(L, "lua_int");// 获取全局变量

	printf("lua_int = %d\n", lua_int);

	lua_close(L);
	system("pause");
}
