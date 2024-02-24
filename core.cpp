#include "core.hpp"
#if _WIN32
#include <Windows.h>
#else
#include <dlfcn.h>
#endif

OMPRSCore::OMPRSCore(const std::string& gamemode_name)
{
#if _WIN32
	proc_handle = LoadLibrary(("omprsgamemode\\" + gamemode_name + ".dll").c_str());
#else
	proc_handle = dlopen(("omprsgamemode/" + gamemode_name + ".so").c_str());
#endif
}
