#pragma once

#include <string>

class OMPRSCore
{
private:
	void* proc_handle;

public:
	OMPRSCore(const std::string& gamemode_name);

	template <typename F, typename... Args>
	void execute_callback(char* symbol, Args... args);
};

template <typename callback_signature, typename... Args>
void OMPRSCore::execute_callback(char* symbol, Args... args)
{
	if (this->proc_handle != 0)
	{
#if _WIN32
		callback_signature* cb = (callback_signature*)GetProcAddress((HMODULE)this->proc_handle, symbol);
#else
		callback_signature* cb = (callback_signature*)dlsym(this->proc_handle, symbol);
#endif
		if (cb != 0)
		{
			(*cb)(std::forward<Args>(args)...);
		}
	}
}
