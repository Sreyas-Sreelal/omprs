#pragma once

#include "../api.hpp"

OMPRS_API(void*, TextDrawCreate(Vector2 position, StringView text))
{
	ITextDrawsComponent* component = OMPRSComponent::Get()->GetTextDraws();
	if (component)
	{
		ITextDraw* textdraw = component->create(position, text);
		if (textdraw)
		{
			return textdraw;
		}
	}
	return nullptr;
}

OMPRS_API(void,TextDrawDestroy(void* textdraw))
{
	OMPRSComponent::Get()->GetTextDraws()->release(static_cast<ITextDraw*>(textdraw)->getID());
}

OMPRS_API(bool,IsTextDrawShownForPlayer(void* textdraw, void* player))
{
	return static_cast<ITextDraw*>(textdraw)->isShownForPlayer(*static_cast<IPlayer*>(player));
}

OMPRS_API(void,TextDrawSetLetterSize(void* textdraw, Vector2 size))
{
	static_cast<ITextDraw*>(textdraw)->setLetterSize(size);
}

OMPRS_API(void,TextDrawSetTextSize(void* textdraw, Vector2 size))
{
	static_cast<ITextDraw*>(textdraw)->setTextSize(size);
}

OMPRS_API(void, TextDrawSetAlignment(void* textdraw, TextDrawAlignmentTypes alignment))
{
	static_cast<ITextDraw*>(textdraw)->setAlignment(alignment);
}

OMPRS_API(void, TextDrawSetColor(void* textdraw, Colour colour))
{
	static_cast<ITextDraw*>(textdraw)->setColour(colour);
}

OMPRS_API(void,TextDrawUseBox(void* textdraw, bool use))
{
	static_cast<ITextDraw*>(textdraw)->useBox(use);
}

OMPRS_API(void, TextDrawSetBoxColor(void* textdraw, Colour colour))
{
	static_cast<ITextDraw*>(textdraw)->setBoxColour(colour);
}

OMPRS_API(void,TextDrawSetShadow(void* textdraw, int size))
{
	static_cast<ITextDraw*>(textdraw)->setShadow(size);
}

OMPRS_API(void,TextDrawSetOutline(void* textdraw, int size))
{
	static_cast<ITextDraw*>(textdraw)->setOutline(size);
}

OMPRS_API(void, TextDrawSetBackgroundColor(void* textdraw, Colour colour))
{
	static_cast<ITextDraw*>(textdraw)->setBackgroundColour(colour);
}

OMPRS_API(void, TextDrawSetStyle(void* textdraw, TextDrawStyle font))
{
	static_cast<ITextDraw*>(textdraw)->setStyle(font);
}

OMPRS_API(void,TextDrawSetProportional(void* textdraw, bool set))
{
	static_cast<ITextDraw*>(textdraw)->setProportional(set);
}

OMPRS_API(void,TextDrawSetSelectable(void* textdraw, bool set))
{
	static_cast<ITextDraw*>(textdraw)->setSelectable(set);
}

OMPRS_API(void,TextDrawShowForPlayer(void* textdraw, void* player))
{
	static_cast<ITextDraw*>(textdraw)->showForPlayer(*static_cast<IPlayer*>(player));
}

OMPRS_API(void,TextDrawHideForPlayer(void* textdraw, void* player))
{
	static_cast<ITextDraw*>(textdraw)->hideForPlayer(*static_cast<IPlayer*>(player));
}

OMPRS_API(void,TextDrawShowForAll(void* textdraw))
{
	IPlayerPool* pool = OMPRSComponent::Get()->GetPlayers();
	for (IPlayer* player : pool->entries())
	{
		static_cast<ITextDraw*>(textdraw)->showForPlayer(*static_cast<IPlayer*>(player));
	}
}

OMPRS_API(void,TextDrawHideForAll(void* textdraw))
{
	IPlayerPool* pool = OMPRSComponent::Get()->GetPlayers();
	for (IPlayer* player : pool->entries())
	{
		static_cast<ITextDraw*>(textdraw)->hideForPlayer(*static_cast<IPlayer*>(player));
	}
}

OMPRS_API(void,TextDrawSetString(void* textdraw, StringView text))
{
	static_cast<ITextDraw*>(textdraw)->setText(text);
}

OMPRS_API(void,TextDrawSetPreviewModel(void* textdraw, int model))
{
	static_cast<ITextDraw*>(textdraw)->setPreviewModel(model);
}

OMPRS_API(void,TextDrawSetPreviewRotation(void* textdraw, Vector3 rotation, float zoom))
{
	static_cast<ITextDraw*>(textdraw)->setPreviewRotation(rotation);
	static_cast<ITextDraw*>(textdraw)->setPreviewZoom(zoom);
}

OMPRS_API(void,TextDrawSetPreviewVehColour(void* textdraw, int colour1, int colour2))
{
	static_cast<ITextDraw*>(textdraw)->setPreviewVehicleColour(colour1, colour2);
}

OMPRS_API(void,TextDrawSetPos(void* textdraw, Vector2 pos))
{
	static_cast<ITextDraw*>(textdraw)->setPosition(pos);
}

OMPRS_API(void,TextDrawGetString(void* textdraw, StringView* text))
{
	*text = static_cast<ITextDraw*>(textdraw)->getText();
}

OMPRS_API(void,TextDrawGetLetterSize(void* textdraw, Vector2* size))
{
	*size = static_cast<ITextDraw*>(textdraw)->getLetterSize();
}

OMPRS_API(void,TextDrawGetTextSize(void* textdraw, Vector2* size))
{
	*size = static_cast<ITextDraw*>(textdraw)->getTextSize();
}

OMPRS_API(void,TextDrawGetPos(void* textdraw, Vector2* pos))
{
	*pos = static_cast<ITextDraw*>(textdraw)->getPosition();
}

OMPRS_API(void,TextDrawGetColor(void* textdraw,Colour* colour))
{
	*colour =  static_cast<ITextDraw*>(textdraw)->getLetterColour();
}

OMPRS_API(void,TextDrawGetBoxColor(void* textdraw, Colour* colour))
{
	*colour = static_cast<ITextDraw*>(textdraw)->getBoxColour();
}

OMPRS_API(void, TextDrawGetBackgroundColor(void* textdraw, Colour* colour))
{
	*colour = static_cast<ITextDraw*>(textdraw)->getBackgroundColour();
}

OMPRS_API(int,TextDrawGetShadow(void* textdraw))
{
	return static_cast<ITextDraw*>(textdraw)->getShadow();
}

OMPRS_API(int,TextDrawGetOutline(void* textdraw))
{
	return static_cast<ITextDraw*>(textdraw)->getOutline();
}

OMPRS_API(int,TextDrawGetStyle(void* textdraw))
{
	return static_cast<uint8_t>(static_cast<ITextDraw*>(textdraw)->getStyle());
}

OMPRS_API(bool,TextDrawIsBox(void* textdraw))
{
	return static_cast<ITextDraw*>(textdraw)->hasBox();
}

OMPRS_API(bool,TextDrawIsProportional(void* textdraw))
{
	return static_cast<ITextDraw*>(textdraw)->isProportional();
}

OMPRS_API(bool,TextDrawIsSelectable(void* textdraw))
{
	return static_cast<ITextDraw*>(textdraw)->isSelectable();
}

OMPRS_API(TextDrawAlignmentTypes,TextDrawGetAlignment(void* textdraw))
{
	return static_cast<ITextDraw*>(textdraw)->getAlignment();
}

OMPRS_API(int,TextDrawGetPreviewModel(void* textdraw))
{
	return static_cast<ITextDraw*>(textdraw)->getPreviewModel();
}

OMPRS_API(void,TextDrawGetPreviewRotation(void* textdraw, Vector3* rotation, float* zoom))
{
	*rotation = static_cast<ITextDraw*>(textdraw)->getPreviewRotation();
	*zoom = static_cast<ITextDraw*>(textdraw)->getPreviewZoom();
}

OMPRS_API(void,TextDrawGetPreviewVehColour(void* textdraw, int* colour1, int* colour2))
{
	Pair<int, int> colours = static_cast<ITextDraw*>(textdraw)->getPreviewVehicleColour();
	*colour1 = colours.first;
	*colour2 = colours.second;
}

OMPRS_API(void,TextDrawSetStringForPlayer(void* textdraw, void* player,StringView text))
{
	static_cast<ITextDraw*>(textdraw)->setTextForPlayer(*static_cast<IPlayer*>(player), text);
}

OMPRS_API(int, TextDrawGetID(void* textdraw))
{
	return static_cast<ITextDraw*>(textdraw)->getID();
}

OMPRS_API(void*, TextDrawFromID(int textdrawid))
{
	ITextDrawsComponent* component = OMPRSComponent::Get()->GetTextDraws();
	if (component)
	{
		return component->get(textdrawid);
	}
	return nullptr;
}

// player textdraws

OMPRS_API(void*,CreatePlayerTextDraw(void* player, Vector2 position, StringView text))
{
	IPlayerTextDrawData* playerTextDraws = queryExtension<IPlayerTextDrawData>(*static_cast<IPlayer*>(player));
	if (playerTextDraws)
	{
		IPlayerTextDraw* textdraw = playerTextDraws->create(position, text);
		if (textdraw)
		{
			return textdraw;
		}
	}
	return nullptr;
}

OMPRS_API(void,PlayerTextDrawDestroy(void* player, void* textdraw))
{
	IPlayerTextDrawData* playerTextDraws = queryExtension<IPlayerTextDrawData>(*static_cast<IPlayer*>(player));
	if (playerTextDraws)
	{
		playerTextDraws->release(static_cast<IPlayerTextDraw*>(textdraw)->getID());
	}
}

OMPRS_API(bool,IsPlayerTextDrawShown(void* textdraw))
{
	return static_cast<IPlayerTextDraw*>(textdraw)->isShown();
}

OMPRS_API(void,PlayerTextDrawSetLetterSize(void* textdraw, Vector2 size))
{
	static_cast<IPlayerTextDraw*>(textdraw)->setLetterSize(size);
}

OMPRS_API(void,PlayerTextDrawSetTextSize(void* textdraw, Vector2 size))
{
	static_cast<IPlayerTextDraw*>(textdraw)->setTextSize(size);
}

OMPRS_API(void, PlayerTextDrawAlignment(void* textdraw, TextDrawAlignmentTypes alignment))
{
	static_cast<IPlayerTextDraw*>(textdraw)->setAlignment(alignment);
}

OMPRS_API(void,PlayerTextDrawColor(void* textdraw, Colour colour))
{
	static_cast<IPlayerTextDraw*>(textdraw)->setColour(colour);
}

OMPRS_API(void,PlayerTextDrawUseBox(void* textdraw, bool use))
{
	static_cast<IPlayerTextDraw*>(textdraw)->useBox(use);
}

OMPRS_API(void,PlayerTextDrawSetBoxColor(void* textdraw, Colour colour))
{
	static_cast<IPlayerTextDraw*>(textdraw)->setBoxColour(colour);
}

OMPRS_API(void,PlayerTextDrawSetShadow(void* textdraw, int size))
{
	static_cast<IPlayerTextDraw*>(textdraw)->setShadow(size);
}

OMPRS_API(void,PlayerTextDrawSetOutline(void* textdraw, int size))
{
	static_cast<IPlayerTextDraw*>(textdraw)->setOutline(size);
}

OMPRS_API(void,PlayerTextDrawBackgroundColor(void* textdraw, Colour colour))
{
	static_cast<IPlayerTextDraw*>(textdraw)->setBackgroundColour(colour);
}

OMPRS_API(void,PlayerTextDrawSetStyle(void* textdraw, TextDrawStyle font))
{
	static_cast<IPlayerTextDraw*>(textdraw)->setStyle(font);
}

OMPRS_API(void,PlayerTextDrawSetProportional(void* textdraw, bool set))
{
	static_cast<IPlayerTextDraw*>(textdraw)->setProportional(set);
}

OMPRS_API(void,PlayerTextDrawSetSelectable(void* textdraw, bool set))
{
	static_cast<IPlayerTextDraw*>(textdraw)->setSelectable(set);
}

OMPRS_API(void,PlayerTextDrawShow(void* textdraw))
{
	static_cast<IPlayerTextDraw*>(textdraw)->show();
}

OMPRS_API(void,PlayerTextDrawHide(void* textdraw))
{
	static_cast<IPlayerTextDraw*>(textdraw)->hide();
}

OMPRS_API(void,PlayerTextDrawSetString(void* textdraw, StringView text))
{
	static_cast<IPlayerTextDraw*>(textdraw)->setText(text);
}

OMPRS_API(void,PlayerTextDrawSetPreviewModel(void* textdraw, int model))
{
	static_cast<IPlayerTextDraw*>(textdraw)->setPreviewModel(model);
}

OMPRS_API(void,PlayerTextDrawSetPreviewRotation(void* textdraw, Vector3 rotation, float zoom))
{
	static_cast<IPlayerTextDraw*>(textdraw)->setPreviewRotation(rotation);
	static_cast<IPlayerTextDraw*>(textdraw)->setPreviewZoom(zoom);
}

OMPRS_API(void,PlayerTextDrawSetPreviewVehColour(void* textdraw, int colour1, int colour2))
{
	static_cast<IPlayerTextDraw*>(textdraw)->setPreviewVehicleColour(colour1, colour2);
}

OMPRS_API(void,PlayerTextDrawSetPos(void* textdraw, Vector2 pos))
{
	static_cast<IPlayerTextDraw*>(textdraw)->setPosition(pos);
}

OMPRS_API(void,PlayerTextDrawGetString(void* textdraw, StringView* text))
{
	*text = static_cast<IPlayerTextDraw*>(textdraw)->getText();
}

OMPRS_API(void,PlayerTextDrawGetLetterSize(void* textdraw, Vector2* size))
{
	*size = static_cast<IPlayerTextDraw*>(textdraw)->getLetterSize();
}

OMPRS_API(void,PlayerTextDrawGetTextSize(void* textdraw, Vector2* size))
{
	*size = static_cast<IPlayerTextDraw*>(textdraw)->getTextSize();
}

OMPRS_API(void,PlayerTextDrawGetPos(void* textdraw, Vector2* pos))
{
	*pos = static_cast<IPlayerTextDraw*>(textdraw)->getPosition();
}

OMPRS_API(void,PlayerTextDrawGetColor(void* textdraw,Colour* colour))
{
	*colour =  static_cast<IPlayerTextDraw*>(textdraw)->getLetterColour();
}

OMPRS_API(void,PlayerTextDrawGetBoxColor(void* textdraw,Colour* colour))
{
	*colour = static_cast<IPlayerTextDraw*>(textdraw)->getBoxColour();
}

OMPRS_API(void, PlayerTextDrawGetBackgroundColour(void* textdraw, Colour* colour))
{
	*colour = static_cast<IPlayerTextDraw*>(textdraw)->getBackgroundColour();
}

OMPRS_API(int,PlayerTextDrawGetShadow(void* textdraw))
{
	return static_cast<IPlayerTextDraw*>(textdraw)->getShadow();
}

OMPRS_API(int,PlayerTextDrawGetOutline(void* textdraw))
{
	return static_cast<IPlayerTextDraw*>(textdraw)->getOutline();
}

OMPRS_API(int,PlayerTextDrawGetStyle(void* textdraw))
{
	return static_cast<uint8_t>(static_cast<IPlayerTextDraw*>(textdraw)->getStyle());
}

OMPRS_API(bool,PlayerTextDrawIsBox(void* textdraw))
{
	return static_cast<IPlayerTextDraw*>(textdraw)->hasBox();
}

OMPRS_API(bool,PlayerTextDrawIsProportional(void* textdraw))
{
	return static_cast<IPlayerTextDraw*>(textdraw)->isProportional();
}

OMPRS_API(bool,PlayerTextDrawIsSelectable(void* textdraw))
{
	return static_cast<IPlayerTextDraw*>(textdraw)->isSelectable();
}

OMPRS_API(TextDrawAlignmentTypes,PlayerTextDrawGetAlignment(void* textdraw))
{
	return static_cast<IPlayerTextDraw*>(textdraw)->getAlignment();
}

OMPRS_API(int,PlayerTextDrawGetPreviewModel(void* textdraw))
{
	return static_cast<IPlayerTextDraw*>(textdraw)->getPreviewModel();
}

OMPRS_API(void,PlayerTextDrawGetPreviewRotation(void* textdraw, Vector3* rotation, float* zoom))
{
	*rotation = static_cast<IPlayerTextDraw*>(textdraw)->getPreviewRotation();
	*zoom = static_cast<IPlayerTextDraw*>(textdraw)->getPreviewZoom();
}

OMPRS_API(void,PlayerTextDrawGetPreviewVehColour(void* textdraw, int* colour1, int* colour2))
{
	Pair<int, int> colours = static_cast<IPlayerTextDraw*>(textdraw)->getPreviewVehicleColour();
	*colour1 = colours.first;
	*colour2 = colours.second;
}

OMPRS_API(int, PlayerTextDrawGetID(void* textdraw))
{
	return static_cast<IPlayerTextDraw*>(textdraw)->getID();
}

OMPRS_API(void*, PlayerTextDrawFromID(int textdrawid,void* player))
{
	IPlayerTextDrawData* playerTextDraws = queryExtension<IPlayerTextDrawData>(*static_cast<IPlayer*>(player));
	if (playerTextDraws)
	{
		return playerTextDraws->get(textdrawid);
	}
	return nullptr;
}