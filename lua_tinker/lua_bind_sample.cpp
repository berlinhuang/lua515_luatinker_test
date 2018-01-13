
#include "stdafx.h"
#include "lua_bind_sample.h"


test g_t(11);

bool luaBindClass(lua_State* state)
{
	LuaClass<base>(state)
		.create("base")
		.def("is_base", &base::is_base);

	LuaClass<test,base>(state).create_inh("test")// ������ �����������ʵ��
	//lua_tinker::class_add<test>(state, "test");
	//lua_tinker::class_inh<test, base>(state);//ע����̳й�ϵ
	//lua_tinker::class_con<test>(state, lua_tinker::constructor<test, int>); //cons
	//LuaClass<test>(state)
		.def("is_test", &test::is_test)
		.def("ret_void", &test::ret_void)
		.def("ret_int", &test::ret_int)
		.def("ret_mul", &test::ret_mul)
		.def("get", &test::get)
		.def("set", &test::set)
		.mem("_test", &test::_test);

	//lua_tinker::class_mem<test>(state, "_test", &test::_test);//��Ա
	lua_tinker::set(state, "g_test", &g_t);//ע��ȫ�ֱ���
	return true;
}


void lua_bind_sample()
{
	lua_State* L = lua_open();
	luaopen_base(L);//������
	luaopen_string(L);//�ַ�����
	luaBindClass(L);
	lua_tinker::dofile(L, "./../examples/lua_bind_sample.lua");

	lua_close(L);
	system("pause");
}