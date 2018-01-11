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
//���÷��������ʱ�� ��һ��㷵�أ����صĲ������ݸ�show_error

void sample5()
{

	lua_State* L = lua_open();


	luaopen_base(L);



	printf("%s\n", "-------------------------- current stack");
	lua_tinker::enum_stack(L);//�û�ö��luaջ�е�����


	lua_pushnumber(L, 1);


	printf("%s\n", "-------------------------- stack after push '1'");
	lua_tinker::enum_stack(L);



	lua_tinker::dofile(L, "sample5.lua");


	printf("%s\n", "-------------------------- calling test_error()");
	lua_tinker::call<void>(L, "test_error");


	printf("%s\n", "-------------------------- calling test_error_3()");
	lua_tinker::call<void>(L, "test_error_3");

	//ע��C++����show_error , lua�ļ��п�����_ALERT������
	lua_tinker::def(L, "_ALERT", show_error);//�����handle | Lua�еĺ����� | C++�к���ָ��

	lua_tinker::call<void>(L, "_ALERT", "test !!!");//������lua�ļ��е��ã�_ALERT( "test !!!" )


	printf("%s\n", "-------------------------- calling test_error()");
	lua_tinker::call<void>(L, "test_error");//ģ��lua�ļ��е���



	lua_close(L);

	system("pause");
}

