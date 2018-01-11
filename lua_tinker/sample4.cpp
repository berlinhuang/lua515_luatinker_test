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


	lua_tinker::table haha(L, "haha");//建立表haha


	haha.set("value", 1);//给表变量赋值haha = { value = 1 }


	haha.set("inside", lua_tinker::table(L));//表中建表haha = { value =1, inside = { }}


	lua_tinker::table inside = haha.get<lua_tinker::table>("inside");//获取inside表 inside = { }


	inside.set("value", 2);//给表变量赋值 haha = { value = 1, inside = { value =2 } }


	lua_tinker::dofile(L, "./../examples/sample4.lua");


	const char* test = haha.get<const char*>("test");//获取haha.test 该值在sample4.lua中已赋
	printf("haha.test = %s\n", test);


	lua_tinker::table temp(L);//建立表temp = { }


	temp.set("name", "local table !!");// temp = { name = "local table !!" }


	lua_tinker::call<void>(L, "print_table", temp);//执行sample4中的print_table函数

	//执行simple4.lua中的取值函数arg= "give me a table !!"， ret = { name = "give me a table !!"}
	lua_tinker::table ret = lua_tinker::call<lua_tinker::table>(L, "return_table", "give me a table !!");
	printf("ret.name =\t%s\n", ret.get<const char*>("name"));


	lua_close(L);

	system("pause");
}

