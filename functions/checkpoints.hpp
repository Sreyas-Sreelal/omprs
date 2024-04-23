#pragma once

#include "../api.hpp"

OMPRS_API(void,SetPlayerCheckpoint(void* player,Vector3 centrePosition, float radius))
{
	IPlayerCheckpointData* data = queryExtension<IPlayerCheckpointData>(static_cast<IPlayer*>(player));
	ICheckpointData& cp = data->getCheckpoint();
	cp.setPosition(centrePosition);
	cp.setRadius(radius);
	cp.enable();
}

OMPRS_API(void, DisablePlayerCheckpoint(void* player))
{
	IPlayerCheckpointData* data = queryExtension<IPlayerCheckpointData>(static_cast<IPlayer*>(player));
	ICheckpointData& cp = data->getCheckpoint();
	cp.disable();
}

OMPRS_API(bool,IsPlayerInCheckpoint(void* player))
{
	IPlayerCheckpointData* data = queryExtension<IPlayerCheckpointData>(static_cast<IPlayer*>(player));
	ICheckpointData& cp = data->getCheckpoint();
	if (cp.isEnabled())
	{
		return cp.isPlayerInside();
	}
	return false;
}

OMPRS_API(void,SetPlayerRaceCheckpoint(void* player,int type, Vector3 centrePosition, Vector3 nextPosition, float radius))
{
	IPlayerCheckpointData* data = queryExtension<IPlayerCheckpointData>(static_cast<IPlayer*>(player));
	IRaceCheckpointData& cp = data->getRaceCheckpoint();
	if (type >= 0 && type <= 8)
	{
		cp.setType(RaceCheckpointType(type));
		cp.setPosition(centrePosition);
		cp.setNextPosition(nextPosition);
		cp.setRadius(radius);
		cp.enable();
	}
}

OMPRS_API(void,DisablePlayerRaceCheckpoint(void* player))
{
	IPlayerCheckpointData* data = queryExtension<IPlayerCheckpointData>(static_cast<IPlayer*>(player));
	IRaceCheckpointData& cp = data->getRaceCheckpoint();
	cp.disable();
}

OMPRS_API(bool,IsPlayerInRaceCheckpoint(void* player))
{
	IPlayerCheckpointData* data = queryExtension<IPlayerCheckpointData>(static_cast<IPlayer*>(player));
	IRaceCheckpointData& cp = data->getRaceCheckpoint();
	if (cp.getType() != RaceCheckpointType::RACE_NONE && cp.isEnabled())
	{
		return cp.isPlayerInside();
	}
	return false;
}

OMPRS_API(bool,IsPlayerCheckpointActive(void* player))
{
	IPlayerCheckpointData* data = queryExtension<IPlayerCheckpointData>(static_cast<IPlayer*>(player));
	return data->getCheckpoint().isEnabled();
}

OMPRS_API(void,GetPlayerCheckpoint(void* player, Vector3* centrePosition, float* radius))
{
	IPlayerCheckpointData* data = queryExtension<IPlayerCheckpointData>(static_cast<IPlayer*>(player));
	const ICheckpointData& cp = data->getCheckpoint();
	*centrePosition = cp.getPosition();
	*radius = cp.getRadius();
}

OMPRS_API(bool,IsPlayerRaceCheckpointActive(void* player))
{
	IPlayerCheckpointData* data = queryExtension<IPlayerCheckpointData>(static_cast<IPlayer*>(player));
	return data->getRaceCheckpoint().isEnabled();
}

OMPRS_API(void,GetPlayerRaceCheckpoint(void* player,Vector3* centrePosition, Vector3* nextPosition, float* radius))
{
	IPlayerCheckpointData* data = queryExtension<IPlayerCheckpointData>(static_cast<IPlayer*>(player));
	const IRaceCheckpointData& cp = data->getRaceCheckpoint();
	*centrePosition = cp.getPosition();
	*nextPosition = cp.getNextPosition();
	*radius = cp.getRadius();
}