#pragma once

#include "../api.hpp"

struct DialogEvents : public PlayerDialogEventHandler, public Singleton<DialogEvents>
{
private:
	CALLBACK_DECL(void, onDialogResponse, void*, short, DialogResponse, int, StringView);

public:
	DialogEvents()
	{
		INIT_CALLBACK(onDialogResponse);
	}
	void onDialogResponse(IPlayer& player, int dialogId, DialogResponse response, int listItem, StringView inputText) override
	{
		EXEC_CALLBACK(onDialogResponse, &player, dialogId, response, listItem, inputText);
	}
};