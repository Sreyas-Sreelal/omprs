#pragma once

#include "../api.hpp"

OMPRS_API(void*,CreatePickup(int model, int type, Vector3 position, int virtualWorld))
{
	IPickupsComponent* component = OMPRSComponent::Get()->GetPickups();
	if (component)
	{
		return component->create(model, type, position, virtualWorld, false);
	}
	return nullptr;
}

OMPRS_API(void*,AddStaticPickup(int model, int type, Vector3 position, int virtualWorld))
{
	IPickupsComponent* component = OMPRSComponent::Get()->GetPickups();
	if (component)
	{
		return component->create(model, type, position, virtualWorld, true);
	}
	return nullptr;
}

OMPRS_API(void,DestroyPickup(void* pickup))
{
	IPickupsComponent* component = OMPRSComponent::Get()->GetPickups();
	if (component)
	{
		int id = static_cast<IPickup*>(pickup)->getID();
		if (id)
		{
			component->release(id);
		}
	}
}

OMPRS_API(bool,IsPickupStreamedIn(void* pickup, void* player))
{
	return static_cast<IPickup*>(pickup)->isStreamedInForPlayer(*static_cast<IPlayer*>(player));
}

OMPRS_API(void,GetPickupPos(void* pickup, Vector3* pos))
{
	*pos = static_cast<IPickup*>(pickup)->getPosition();
}

OMPRS_API(int,GetPickupModel(void* pickup))
{
	return static_cast<IPickup*>(pickup)->getModel();
}

OMPRS_API(int,GetPickupType(void* pickup))
{
	return static_cast<IPickup*>(pickup)->getType();
}

OMPRS_API(int,GetPickupVirtualWorld(void* pickup))
{
	return static_cast<IPickup*>(pickup)->getVirtualWorld();
}

OMPRS_API(void,SetPickupPos(void* pickup, Vector3 pos, bool update))
{
	if (update)
	{
		static_cast<IPickup*>(pickup)->setPosition(pos);
	}
	else
	{
		static_cast<IPickup*>(pickup)->setPositionNoUpdate(pos);
	}
}

OMPRS_API(void,SetPickupModel(void* pickup, int model, bool update))
{
	static_cast<IPickup*>(pickup)->setModel(model, update);
}

OMPRS_API(void,SetPickupType(void* pickup, int type, bool update))
{
	static_cast<IPickup*>(pickup)->setType(type, update);
}

OMPRS_API(void,SetPickupVirtualWorld(void* pickup, int virtualworld))
{
	static_cast<IPickup*>(pickup)->setVirtualWorld(virtualworld);
}

OMPRS_API(void,ShowPickupForPlayer(void* pickup,void* player))
{
	static_cast<IPickup*>(pickup)->setPickupHiddenForPlayer(*static_cast<IPlayer*>(player), false);
}

OMPRS_API(void,HidePickupForPlayer(void* pickup, void* player))
{
	static_cast<IPickup*>(pickup)->setPickupHiddenForPlayer(*static_cast<IPlayer*>(player), true);
}

OMPRS_API(bool,IsPickupHiddenForPlayer(void* pickup, void* player))
{
	return static_cast<IPickup*>(pickup)->isPickupHiddenForPlayer(*static_cast<IPlayer*>(player));
}

OMPRS_API(int, GetPickupID(void* pickup))
{
	return static_cast<IPickup*>(pickup)->getID();
}

OMPRS_API(void*, GetPickupFromID(int pickupid))
{
	IPickupsComponent* component = OMPRSComponent::Get()->GetPickups();
	if (component)
	{
		component->get(pickupid);
	}
	return nullptr;
}