#pragma once
#if _WIN32
#include <Windows.h>
#else
#include <dlfcn.h>
#endif
#include <string>

class OMPRSCore
{
private:
	void* proc_handle;

#ifdef __unix__
	void* component_handle;
#endif

public:
	OMPRSCore(const std::string& gamemode_name);

	void* get_callback_addr(std::string);
	~OMPRSCore();
};

