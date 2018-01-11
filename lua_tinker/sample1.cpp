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
	// 初始化Lua
	lua_State* L = lua_open();

	// 初始化lua基本库
	luaopen_base(L);

	// LuaTinker 在L栈中注册C++函数
	lua_tinker::def(L, "cpp_func", cpp_func);//虚拟机handle | Lua中的函数名 | C++中函数指针
	/*
	template //模板函数
	void def(lua_State* L, const char* name, F func)
	{
	lua_pushstring(L, name); //cpp_func压栈
	lua_pushlightuserdata(L, (void*)func); //userdata传入函数指针

	//func 带有两个参数，所以会找到	void push_functor(lua_State *L, RVal (*func)(T1,T2))
	push_functor(L, func); //cpp_func=function  cpp_func ...end

	//void lua_settable (lua_State *L, int index);
	//做一个等价于t[k] = v的操作， 这里t是给出的索引处的值， v是栈顶的那个值， k是栈顶之下的值。
	lua_settable(L, LUA_GLOBALSINDEX); //LUA_GLOBLSINDEX表示在全局表中设置

	}
	*/

	// sample1.lua 加载lua文件
	lua_tinker::dofile(L, "sample1.lua");

	// sample1.lua 调用lua中的function lua_func.
	int result = lua_tinker::call<int>(L, "lua_func", 3, 4);
	/*
	template//模板函数，棒子模板用的真实牛逼
	RVal call(lua_State* L, const char* name, T1 arg1, T2 arg2) //call(L,luafunc,3,4)
	{
	lua_pushcclosure(L, on_error, 0);
	int errfunc = lua_gettop(L); //错误处理

	lua_pushstring(L, name); //name=luafunc入栈
	lua_gettable(L, LUA_GLOBALSINDEX); //取全局表
	//lua_pushstring,lua_gettable合起来的作用是取lua_func的实际值，即为函数lua_func
	//这两句话组合起来就是lua_getglobal(L,name)


	if(lua_isfunction(L,-1)) //判断luafunc在sample1.lua中是不是函数
	{
	push(L, arg1); //压栈参数3
	push(L, arg2); //压栈参数4 此时栈底到栈顶依次是 luafunc  3  4
	if(lua_pcall(L, 2, 1, errfunc) != 0) //调用samle1.lua函数luafucn 两个参数，一个返回值
	{
	lua_pop(L, 1); //出错的话，清栈
	}
	}
	else
	{
	print_error(L, "lua_tinker::call() attempt to call global '%s' (not a function)", name);
	}
	lua_remove(L, -2); //移除从栈顶数第二个元素
	return pop(L); //pop函数中包括了一个lua_tonumber(L,-1)取栈顶结果
	}

	*/

	// lua_func(3,4) 返回lua的执行结果
	printf("lua_func(3,4) = %d\n", result);

	// 关闭L
	lua_close(L);
	system("pause");

}

