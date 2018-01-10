// sample3.cpp :
//

#include "stdafx.h"
#include "sample3.h"

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};

#include "lua_tinker.h"

struct A
{
	A(int v) : value(v) {}//构造 给value赋值 value = v
	int value;
};

struct base
{
	base() {}//构造

	const char* is_base(){ return "this is base"; }
};

class test : public base
{
public:
	test(int val) : _test(val) {}//构造 给成员变量赋值 _test = val
	~test() {}//析构 

	const char* is_test(){ return "this is test"; }

	void ret_void() {}
	int ret_int()				{ return _test; }// get _test
	int ret_mul(int m) const	{ return _test * m; }// get _test*m
	A get()						{ return A(_test); }// 返回实例化对象A
	void set(A a)				{ _test = a.value; }// set _test = A.value

	int _test;
};

test g_test(11);

void sample3()
{
	lua_State* L = lua_open();

	luaopen_base(L);//基础库

	luaopen_string(L);//字符串库

	lua_tinker::class_add<base>(L, "base");//注册C++类

	lua_tinker::class_def<base>(L, "is_base", &base::is_base);//注册类方法

	lua_tinker::class_add<test>(L, "test");

	lua_tinker::class_inh<test, base>(L);//注册类继承关系

	lua_tinker::class_con<test>(L, lua_tinker::constructor<test, int>);//注册构造函数

	lua_tinker::class_def<test>(L, "is_test", &test::is_test);//类方法
	lua_tinker::class_def<test>(L, "ret_void", &test::ret_void);//类方法
	lua_tinker::class_def<test>(L, "ret_int", &test::ret_int);//类方法
	lua_tinker::class_def<test>(L, "ret_mul", &test::ret_mul);//类方法
	lua_tinker::class_def<test>(L, "get", &test::get);//类方法
	lua_tinker::class_def<test>(L, "set", &test::set);//类方法
	lua_tinker::class_mem<test>(L, "_test", &test::_test);//类方法


	lua_tinker::set(L, "g_test", &g_test);//注册全局变量


	lua_tinker::dofile(L, "sample3.lua");


	lua_close(L);

	system("pause");
}

