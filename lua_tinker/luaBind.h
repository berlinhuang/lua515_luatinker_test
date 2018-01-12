#ifndef _LUA_BIND_H_
#define _LUA_BIND_H_

#include "lua_tinker.h"

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};


template< typename T >
void RegisterMyFunc(lua_State* state, const char* func_name, lua_CFunction f)
{
	lua_tinker::push_meta(state, lua_tinker::class_name<T>::name());
	lua_pushstring(state, func_name);
	lua_pushcfunction(state, f);
	lua_settable(state, -3);
	lua_pop(state, 1);
}


bool StartLuaScriptEngine(lua_State* L);
int my_getpoint(lua_State* L);
bool customLuaLoader(lua_State* L);

template<typename Object>
class LuaClass
{
	lua_State*  m_state;
	bool		m_bCreated;
public:
	LuaClass(lua_State* state)
	{
		m_state = state;
		m_bCreated = false;
	}

	template<typename Func>
	inline LuaClass& def(const char* name, Func func)
	{
		lua_tinker::class_def<Object>(m_state, name, func);
		return *this;
	}

	inline LuaClass& def2(const char* name, lua_CFunction func)
	{
		RegisterMyFunc<Object>(m_state, name, func);
		return *this;
	}

	inline LuaClass& class_add(const char* name)
	{
		lua_tinker::class_add<Object>(m_state, name);
		return *this;
	}

	inline LuaClass& def_cpoint(const char* name = NULL)
	{
		if (name == NULL || !name)
		{
			return def2("cpoint", my_getpoint);
		}

		return def2(name, my_getpoint);
	}

	inline LuaClass& create(const char* name)
	{
		if (!m_bCreated)
		{
			lua_tinker::class_add<Object>(m_state, name);
			m_bCreated = true;
		}
		lua_tinker::class_con<Object>(m_state, lua_tinker::constructor<Object>);
		return *this;
	}

	template<typename T1>
	inline LuaClass& create(const char* name)
	{
		if (!m_bCreated)
		{
			lua_tinker::class_add<Object>(m_state, name);
			m_bCreated = true;
		}
		lua_tinker::class_con<Object>(m_state, lua_tinker::constructor<Object, T1>);
		return *this;
	}
	template<typename T1, typename T2>
	inline LuaClass& create(const char* name)
	{
		if (!m_bCreated)
		{
			lua_tinker::class_add<Object>(m_state, name);
			m_bCreated = true;
		}
		lua_tinker::class_con<Object>(m_state, lua_tinker::constructor<Object, T1, T2>);
		return *this;
	}
};


#endif