#include "core.hpp"

OMPRSCore::OMPRSCore(const std::string& gamemode_name)
{
#if _WIN32
	proc_handle = LoadLibrary(("omprsgamemode\\" + gamemode_name + ".dll").c_str());
#else
	proc_handle = dlopen(("omprsgamemode/" + gamemode_name + ".so").c_str(),RTLD_LAZY);
#endif
}
