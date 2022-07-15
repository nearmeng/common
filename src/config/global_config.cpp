#include "stdafx.h"
#include "config/global_config.h"

#include "file/ifile.h"
#include "lua/lua_script.h"
#include "string/string_ex.h"

#define LOAD_FILE_FUNC_NAME "load_file"

static CLuaScript g_ConfigScript;

BOOL load_global_server_config(void* pConfig, const char* pcszConfigClassName,
	const char* pcszFileName, const char* pcszLuaObjName, std::vector<TOLUA_FUNC> vFuncs)
{
	int32_t nRetCode = 0;

	LOG_PROCESS_ERROR(pConfig);
	LOG_PROCESS_ERROR(pcszConfigClassName);
	LOG_PROCESS_ERROR(pcszFileName);
	LOG_PROCESS_ERROR(pcszLuaObjName);

	{
		g_ConfigScript.uninit();

		nRetCode = g_ConfigScript.init();
		LOG_PROCESS_ERROR(nRetCode);
		
		for (int32_t i = 0; i < vFuncs.size(); i++)
		{
			vFuncs[i](g_ConfigScript.get_lua_state());
		}

		nRetCode = g_ConfigScript.load_from_file(pcszFileName, TRUE);
		LOG_PROCESS_ERROR(nRetCode);

		nRetCode = g_ConfigScript.call_function(LOAD_FILE_FUNC_NAME, "os", pConfig, pcszConfigClassName, pcszLuaObjName);
		LOG_PROCESS_ERROR(nRetCode);
	}

	g_ConfigScript.uninit();

	return TRUE;
Exit0:
	g_ConfigScript.uninit();
	return FALSE;
}
