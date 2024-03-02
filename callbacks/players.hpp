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
		auto poop = OMPRSComponent::Get()->GetOMPRSCore()->get_callback_addr("OnPlayerConnect");
		
		if (poop != nullptr)
		{
			funcOnPlayerConnect = (FuncOnPlayerConnect*)poop;
		}
	}
	void onPlayerConnect(IPlayer& player) override
	{
		if (funcOnPlayerConnect != nullptr)
		{
			(*funcOnPlayerConnect)(player.getID());
		}
	}
};