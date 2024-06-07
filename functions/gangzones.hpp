#pragma once

#include "../api.hpp"

OMPRS_API(void*, GangZoneCreate(GangZonePos pos))
{
	IGangZonesComponent* component = OMPRSComponent::Get()->GetGangZones();
	if (component)
	{
		int id = component->reserveLegacyID();
		if (id == INVALID_GANG_ZONE_ID)
		{
			return nullptr;
		}

		IGangZone* gz = component->create(pos);
		if (gz)
		{
			component->setLegacyID(id, gz->getID());
			return gz;
		}
		else
		{
			component->releaseLegacyID(id);
		}
	}
	return nullptr;
}

OMPRS_API(void,GangZoneDestroy(void* gangzone))
{
	auto pool = OMPRSComponent::Get()->GetGangZones();
	if (pool)
	{
		int id = static_cast<IGangZone*>(gangzone)->getID();
		if (id)
		{
			pool->release(id);
			pool->releaseLegacyID(pool->toLegacyID(id));
		}
	}
}

OMPRS_API(void, GangZoneShowForPlayer(void* gangzone,void* player, Colour colour))
{
	static_cast<IGangZone*>(gangzone)->showForPlayer(*static_cast<IPlayer*>(player), colour);
}

OMPRS_API(void, GangZoneShowForAll(void* gangzone, Colour colour))
{
	IPlayerPool* pool = OMPRSComponent::Get()->GetPlayers();
	for (IPlayer* player : pool->entries())
	{
		static_cast<IGangZone*>(gangzone)->showForPlayer(*player, colour);
	}
}

OMPRS_API(void, GangZoneHideForPlayer(void* gangzone,void* player))
{
	static_cast<IGangZone*>(gangzone)->hideForPlayer(*static_cast<IPlayer*>(player));
}

OMPRS_API(void,GangZoneHideForAll(void* gangzone))
{
	IPlayerPool* pool = OMPRSComponent::Get()->GetPlayers();
	for (IPlayer* player : pool->entries())
	{
		static_cast<IGangZone*>(gangzone)->hideForPlayer(*player);
	}
}

OMPRS_API(void, GangZoneFlashForPlayer(void* gangzone,void* player, Colour colour))
{
	static_cast<IGangZone*>(gangzone)->flashForPlayer(*static_cast<IPlayer*>(player), colour);
}

OMPRS_API(void,GangZoneFlashForAll(void* gangzone, Colour colour))
{
	IPlayerPool* pool = OMPRSComponent::Get()->GetPlayers();
	for (IPlayer* player : pool->entries())
	{
		static_cast<IGangZone*>(gangzone)->flashForPlayer(*player, colour);
	}
}

OMPRS_API(void, GangZoneStopFlashForPlayer(void* gangzone, void* player))
{
	static_cast<IGangZone*>(gangzone)->stopFlashForPlayer(*static_cast<IPlayer*>(player));
}

OMPRS_API(void,GangZoneStopFlashForAll(void* gangzone))
{
	IPlayerPool* pool = OMPRSComponent::Get()->GetPlayers();
	for (IPlayer* player : pool->entries())
	{
		static_cast<IGangZone*>(gangzone)->stopFlashForPlayer(*player);
	}
}

OMPRS_API(bool,IsValidGangZoneID(int gangzoneid))
{
	IGangZonesComponent* component = OMPRSComponent::Get()->GetGangZones();
	if (component)
	{
		return !!component->fromLegacyID(gangzoneid);
	}
	return false;
}

OMPRS_API(bool,IsPlayerInGangZone(void* gangzone, void* player))
{
	return static_cast<IGangZone*>(gangzone)->isPlayerInside(*static_cast<IPlayer*>(player));
}

OMPRS_API(bool,IsGangZoneVisibleForPlayer(void* gangzone, void* player))
{
	return static_cast<IGangZone*>(gangzone)->isShownForPlayer(*static_cast<IPlayer*>(player));
}

OMPRS_API(int,GangZoneGetColorForPlayer(void* gangzone, void* playerptr))
{
	auto zone = static_cast<IGangZone*>(gangzone);
	auto player = static_cast<IPlayer*>(playerptr);
	if (zone->isShownForPlayer(*player))
	{
		return zone->getColourForPlayer(*player).RGBA();
	}
	return 0;
}

OMPRS_API(int, GangZoneGetFlashColorForPlayer(void* gangzone, void* playerptr))
{
	auto zone = static_cast<IGangZone*>(gangzone);
	auto player = static_cast<IPlayer*>(playerptr);
	if (zone->isShownForPlayer(*player))
	{
		return zone->getFlashingColourForPlayer(*player).RGBA();
	}
	return 0;
}

OMPRS_API(bool,IsGangZoneFlashingForPlayer(void* gangzone, void* player))
{
	return static_cast<IGangZone*>(gangzone)->isFlashingForPlayer(*static_cast<IPlayer*>(player));
}

OMPRS_API(void, GangZoneGetPos(void* gangzone, GangZonePos* pos))
{
	*pos = static_cast<IGangZone*>(gangzone)->getPosition();
}

OMPRS_API(void,UseGangZoneCheck(void* gangzone, bool enable))
{
	IGangZonesComponent* component = OMPRSComponent::Get()->GetGangZones();
	if (component)
	{
		component->useGangZoneCheck(*static_cast<IGangZone*>(gangzone), enable);
	}
}

OMPRS_API(int, GetGangZoneID(void* gangzone))
{
	IGangZonesComponent* component = OMPRSComponent::Get()->GetGangZones();
	if (component)
	{
		return component->toLegacyID(static_cast<IGangZone*>(gangzone)->getID());
	}
	return INVALID_GANG_ZONE_ID;
}

OMPRS_API(void*, GetGangZoneFromID(int gangzoneid))
{
	IGangZonesComponent* component = OMPRSComponent::Get()->GetGangZones();
	if (component)
	{
		int realid =  component->fromLegacyID(gangzoneid);
		if (realid)
		{
			return component->get(realid);
		}
	}
	return nullptr;
}