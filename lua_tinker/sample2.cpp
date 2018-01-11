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

	lua_tinker::set(L, "cpp_int", cpp_int); //往Lua环境导入一个全局变量cpp_int,赋值100

	lua_tinker::dofile(L, "./../examples/sample2.lua"); //编译并执行lua脚本 

	int lua_int = lua_tinker::get<int>(L, "lua_int"); //获取Lua环境中的全局变量lua_int  

	printf("lua_int = %d\n", lua_int);

	lua_close(L);
	system("pause");
}
