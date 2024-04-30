#pragma once

#include "../api.hpp"

struct MenuEvents : public MenuEventHandler, public Singleton<MenuEvents>
{
private:
	CALLBACK_DECL(void, onPlayerSelectedMenuRow, void*, int);
	CALLBACK_DECL(void, onPlayerExitedMenu, void*);

public:
	MenuEvents()
	{
		INIT_CALLBACK(onPlayerSelectedMenuRow);
		INIT_CALLBACK(onPlayerExitedMenu);
	}
	
	void onPlayerSelectedMenuRow(IPlayer& player, MenuRow row) override
	{
		EXEC_CALLBACK(onPlayerSelectedMenuRow, &player, row);
	}

	void onPlayerExitedMenu(IPlayer& player) override
	{
		EXEC_CALLBACK(onPlayerExitedMenu, &player);
	}
};