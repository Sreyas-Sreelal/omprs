#pragma once

#include "../api.hpp"

struct TextDrawEvents : public TextDrawEventHandler, public Singleton<TextDrawEvents>
{
private:
	CALLBACK_DECL(bool, onPlayerCancelTextDrawSelection, void*);
	CALLBACK_DECL(bool, onPlayerCancelPlayerTextDrawSelection, void*);
	CALLBACK_DECL(void, onPlayerClickTextDraw, void*, void*);
	CALLBACK_DECL(void, onPlayerClickPlayerTextDraw, void*, void*);

public:
	TextDrawEvents()
	{
		INIT_CALLBACK(onPlayerCancelTextDrawSelection);
		INIT_CALLBACK(onPlayerCancelPlayerTextDrawSelection);
		INIT_CALLBACK(onPlayerClickTextDraw);
		INIT_CALLBACK(onPlayerClickPlayerTextDraw);
	}

	virtual bool onPlayerCancelTextDrawSelection(IPlayer& player) override
	{
		EXEC_CALLBACK(onPlayerCancelTextDrawSelection, &player);
		return true;
	}

	virtual bool onPlayerCancelPlayerTextDrawSelection(IPlayer& player) override
	{
		EXEC_CALLBACK(onPlayerCancelPlayerTextDrawSelection, &player);
		return true;

	}

	void onPlayerClickTextDraw(IPlayer& player, ITextDraw& td) override
	{
		EXEC_CALLBACK(onPlayerClickTextDraw, &player,&td);
	}

	void onPlayerClickPlayerTextDraw(IPlayer& player, IPlayerTextDraw& td) override
	{
		EXEC_CALLBACK(onPlayerClickPlayerTextDraw, &player, &td);
	}
};