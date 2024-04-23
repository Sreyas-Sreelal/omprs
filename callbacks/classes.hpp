#pragma once

#include "../api.hpp"

struct ClassEvents : public ClassEventHandler, public Singleton<ClassEvents>
{
private:
	CALLBACK_DECL(bool, onPlayerRequestClass, void*,unsigned int classId);

public:
	ClassEvents()
	{
		INIT_CALLBACK(onPlayerRequestClass);
	}
	bool onPlayerRequestClass(IPlayer& player, unsigned int classId) override
	{
		EXEC_CALLBACK(onPlayerRequestClass, &player, classId);
		return true;
	}
};