// sample2.cpp : C + +��Lua�໥֮��ı����ķ��ʡ�
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

static int cpp_int = 100;//ȫ�ֱ���

void sample2()
{
	lua_State* L = lua_open();

	luaopen_base(L);

	lua_tinker::set(L, "cpp_int", cpp_int); //��Lua��������һ��ȫ�ֱ���cpp_int,��ֵ100

	lua_tinker::dofile(L, "./../examples/sample2.lua"); //���벢ִ��lua�ű� 

	int lua_int = lua_tinker::get<int>(L, "lua_int"); //��ȡLua�����е�ȫ�ֱ���lua_int  

	printf("lua_int = %d\n", lua_int);

	lua_close(L);
	system("pause");
}
