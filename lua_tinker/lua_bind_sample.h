#include "lua_bind.h"


bool luaBindClass(lua_State* state);
void lua_bind_sample();

struct A
{
	A(int v) : value(v) {}//���� ��value��ֵ value = v
	int value;
};

struct base
{
	base() {}//����
	const char* is_base(){ return "this is base"; }
};

class test : public base
{
public:
	test(int val) : _test(val) {}//���� ����Ա������ֵ _test = val
	~test() {}//���� 
	const char* is_test(){ return "this is test"; }
	void ret_void() {}
	int ret_int()				{ return _test; }// get _test
	int ret_mul(int m) const	{ return _test * m; }// get _test*m
	A get()						{ return A(_test); }// ����ʵ��������A
	void set(A a)				{ _test = a.value; }// set _test = A.value
	int _test;
};
