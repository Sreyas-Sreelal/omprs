#pragma once
#include "../api.hpp"

OMPRS_API(void, ShowPlayerDialog(void* player, short dialog, DialogStyle style, StringView title, StringView body, StringView button1, StringView button2))
{
	IPlayerDialogData* data = queryExtension<IPlayerDialogData>(static_cast<IPlayer*>(player));

	if (!data)
	{
		return;
	}

	if (dialog == INVALID_DIALOG_ID)
	{
		data->hide(*static_cast<IPlayer*>(player));
		return;
	}

	data->show(*static_cast<IPlayer*>(player), dialog, style, title, body, button1, button2);
}

OMPRS_API(short,GetPlayerDialogID(void* player))
{
	IPlayerDialogData* data = queryExtension<IPlayerDialogData>(static_cast<IPlayer*>(player));
	if (!data)
	{
		return INVALID_DIALOG_ID;
	}
	return data->getActiveID();
}

OMPRS_API(bool,HidePlayerDialog(void* player))
{
	IPlayerDialogData* data = queryExtension<IPlayerDialogData>(static_cast<IPlayer*>(player));
	if (data && data->getActiveID() != INVALID_DIALOG_ID)
	{
		data->hide(*static_cast<IPlayer*>(player));
		return true;
	}
	return false;
}