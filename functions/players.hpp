#pragma once

#include "../api.hpp"

OMPRS_API int OMPRS_SendClientMessage(int playerid, int colour, const char* message)
{
	GET_PLAYER_CHECKED(player, playerid, INVALID_PLAYER_ID);
	player->sendClientMessage(Colour::FromRGBA(colour), message);
	return 1;
}

OMPRS_API int OMPRS_GetPlayerName(int playerid, char* name)
{
	GET_PLAYER_CHECKED(player, playerid, 0);
	
	auto out = player->getName();
	auto length = out.length();

	out.copy(name, length);
	
	return length;
}