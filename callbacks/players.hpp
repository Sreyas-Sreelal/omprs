#pragma once

#include "../api.hpp"

typedef bool(OnPlayerConnect)(int);

class PlayerEvents : public PlayerConnectEventHandler, public Singleton<PlayerEvents>
{
public:
	void onPlayerConnect(IPlayer& player) override
	{
		OMPRSComponent::Get()->GetOMPRSCore()->execute_callback<OnPlayerConnect, int>("OnPlayerConnect", player.getID());
	}
};