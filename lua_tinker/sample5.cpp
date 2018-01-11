// sample5.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "sample5.h"
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};

#include "lua_tinker.h"

void show_error(const char* error)
{
	printf("_ALERT -> %s\n", error);
}
//调用发生错误的时候 会一层层返回，返回的参数传递给show_error

void sample5()
{

	lua_State* L = lua_open();


	luaopen_base(L);



	printf("%s\n", "-------------------------- current stack");
	lua_tinker::enum_stack(L);//用户枚举lua栈中的内容


	lua_pushnumber(L, 1);


	printf("%s\n", "-------------------------- stack after push '1'");
	lua_tinker::enum_stack(L);



	lua_tinker::dofile(L, "sample5.lua");


	printf("%s\n", "-------------------------- calling test_error()");
	lua_tinker::call<void>(L, "test_error");


	printf("%s\n", "-------------------------- calling test_error_3()");
	lua_tinker::call<void>(L, "test_error_3");

	//注册C++函数show_error , lua文件中可以用_ALERT来调用
	lua_tinker::def(L, "_ALERT", show_error);//虚拟机handle | Lua中的函数名 | C++中函数指针

	lua_tinker::call<void>(L, "_ALERT", "test !!!");//等于在lua文件中调用：_ALERT( "test !!!" )


	printf("%s\n", "-------------------------- calling test_error()");
	lua_tinker::call<void>(L, "test_error");//模拟lua文件中调用



	lua_close(L);

	system("pause");
}

