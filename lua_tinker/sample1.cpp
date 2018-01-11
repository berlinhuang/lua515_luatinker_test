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
	// ��ʼ��Lua
	lua_State* L = lua_open();

	// ��ʼ��lua������
	luaopen_base(L);

	// LuaTinker ��Lջ��ע��C++����
	lua_tinker::def(L, "cpp_func", cpp_func);//�����handle | Lua�еĺ����� | C++�к���ָ��
	/*
	template //ģ�庯��
	void def(lua_State* L, const char* name, F func)
	{
	lua_pushstring(L, name); //cpp_funcѹջ
	lua_pushlightuserdata(L, (void*)func); //userdata���뺯��ָ��

	//func �����������������Ի��ҵ�	void push_functor(lua_State *L, RVal (*func)(T1,T2))
	push_functor(L, func); //cpp_func=function  cpp_func ...end

	//void lua_settable (lua_State *L, int index);
	//��һ���ȼ���t[k] = v�Ĳ����� ����t�Ǹ�������������ֵ�� v��ջ�����Ǹ�ֵ�� k��ջ��֮�µ�ֵ��
	lua_settable(L, LUA_GLOBALSINDEX); //LUA_GLOBLSINDEX��ʾ��ȫ�ֱ�������

	}
	*/

	// sample1.lua ����lua�ļ�
	lua_tinker::dofile(L, "sample1.lua");

	// sample1.lua ����lua�е�function lua_func.
	int result = lua_tinker::call<int>(L, "lua_func", 3, 4);
	/*
	template//ģ�庯��������ģ���õ���ʵţ��
	RVal call(lua_State* L, const char* name, T1 arg1, T2 arg2) //call(L,luafunc,3,4)
	{
	lua_pushcclosure(L, on_error, 0);
	int errfunc = lua_gettop(L); //������

	lua_pushstring(L, name); //name=luafunc��ջ
	lua_gettable(L, LUA_GLOBALSINDEX); //ȡȫ�ֱ�
	//lua_pushstring,lua_gettable��������������ȡlua_func��ʵ��ֵ����Ϊ����lua_func
	//�����仰�����������lua_getglobal(L,name)


	if(lua_isfunction(L,-1)) //�ж�luafunc��sample1.lua���ǲ��Ǻ���
	{
	push(L, arg1); //ѹջ����3
	push(L, arg2); //ѹջ����4 ��ʱջ�׵�ջ�������� luafunc  3  4
	if(lua_pcall(L, 2, 1, errfunc) != 0) //����samle1.lua����luafucn ����������һ������ֵ
	{
	lua_pop(L, 1); //����Ļ�����ջ
	}
	}
	else
	{
	print_error(L, "lua_tinker::call() attempt to call global '%s' (not a function)", name);
	}
	lua_remove(L, -2); //�Ƴ���ջ�����ڶ���Ԫ��
	return pop(L); //pop�����а�����һ��lua_tonumber(L,-1)ȡջ�����
	}

	*/

	// lua_func(3,4) ����lua��ִ�н��
	printf("lua_func(3,4) = %d\n", result);

	// �ر�L
	lua_close(L);
	system("pause");

}

