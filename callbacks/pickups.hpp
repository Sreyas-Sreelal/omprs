#pragma once

#include "../api.hpp"

struct PickupEvents : public PickupEventHandler, public Singleton<PickupEvents>
{
private:
	CALLBACK_DECL(void, onPlayerPickUpPickup, void*, void*);

public:
	PickupEvents()
	{
		INIT_CALLBACK(onPlayerPickUpPickup);
	}
	void onPlayerPickUpPickup(IPlayer& player, IPickup& pickup) override
	{
		EXEC_CALLBACK(onPlayerPickUpPickup, &player, &pickup);
	}
};