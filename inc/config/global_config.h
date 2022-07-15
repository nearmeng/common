#ifndef _GLOBAL_CONFIG_H_
#define _GLOBAL_CONFIG_H_

typedef int (*TOLUA_FUNC)(lua_State* tolua_S);

BOOL load_global_server_config(void* pConfig, const char* pcszConfigClassName,
	const char* pcszFileName, const char* pcszLuaObjName, std::vector<TOLUA_FUNC> vFuncs);

#endif	// _GLOBAL_CONFIG_H_
