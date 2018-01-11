// sample1.cpp : C++ �� Lua ��ȣ���� �Լ� ������ �˾ƺ���.
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
	lua_State* L = lua_open();//��ȡluaջ����
	luaopen_base(L); //��lua��
	lua_tinker::def(L, "cpp_func", cpp_func); //lua_tinker::defע��һ��C++ȫ�ֺ���
	lua_tinker::dofile(L, "sample1.lua");//��lua�ļ�
	int result = lua_tinker::call<int>(L, "lua_func", 3, 4);//ͨ��lua_tinker::call���õ�sample1.lua�����lua����
	printf("lua_func(3,4) = %d\n", result);
	lua_close(L);//�ر��ͷ�luaջ����
	system("pause");
}
