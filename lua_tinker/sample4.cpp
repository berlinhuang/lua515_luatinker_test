// sample4.cpp :

#include "stdafx.h"
#include "sample4.h"
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};

#include "lua_tinker.h"

void sample4()
{
	lua_State* L = lua_open();


	luaopen_base(L);//


	lua_tinker::table haha(L, "haha");//������haha


	haha.set("value", 1);//���������ֵhaha = { value = 1 }


	haha.set("inside", lua_tinker::table(L));//���н���haha = { value =1, inside = { }}


	lua_tinker::table inside = haha.get<lua_tinker::table>("inside");//��ȡinside�� inside = { }


	inside.set("value", 2);//���������ֵ haha = { value = 1, inside = { value =2 } }


	lua_tinker::dofile(L, "./../examples/sample4.lua");


	const char* test = haha.get<const char*>("test");//��ȡhaha.test ��ֵ��sample4.lua���Ѹ�
	printf("haha.test = %s\n", test);


	lua_tinker::table temp(L);//������temp = { }


	temp.set("name", "local table !!");// temp = { name = "local table !!" }


	lua_tinker::call<void>(L, "print_table", temp);//ִ��sample4�е�print_table����

	//ִ��simple4.lua�е�ȡֵ����arg= "give me a table !!"�� ret = { name = "give me a table !!"}
	lua_tinker::table ret = lua_tinker::call<lua_tinker::table>(L, "return_table", "give me a table !!");
	printf("ret.name =\t%s\n", ret.get<const char*>("name"));


	lua_close(L);

	system("pause");
}

