// lua515_luatinker_test.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
using namespace std;
#include "sample1.h"
#include "sample2.h"
#include "sample3.h"
#include "sample4.h"
#include "sample5.h"
#include "lua_bind_sample.h"
int _tmain(int argc, _TCHAR* argv[])
{
	lua_bind_sample();
	return 0;
}

