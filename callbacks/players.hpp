#pragma once

#include "../api.hpp"

typedef bool(FuncOnPlayerConnect)(int);

class PlayerEvents : public PlayerConnectEventHandler, public Singleton<PlayerEvents>
{
private:
	FuncOnPlayerConnect* funcOnPlayerConnect = nullptr;

public:
	PlayerEvents()
	{
		funcOnPlayerConnect = (FuncOnPlayerConnect*)OMPRSComponent::Get()->GetOMPRSCore()->get_callback_addr("OnPlayerConnect");
	}

	void onPlayerConnect(IPlayer& player) override
	{
		if (funcOnPlayerConnect != nullptr)
		{
			(*funcOnPlayerConnect)(player.getID());
		}
	}
};