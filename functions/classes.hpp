#pragma once

#include "../api.hpp"

OMPRS_API(int, CreateClass(uint8_t team, int skin, Vector3 spawnPosition, float angle, WeaponSlots slots))
{
	IClassesComponent* component = OMPRSComponent::Get()->GetClasses();
	if (component)
	{
		IClass* _class = component->create(skin, team, spawnPosition, angle, slots);
		if (_class)
		{
			return _class->getID();
		}
	}
	return 0;
}

OMPRS_API(void, SetSpawnInfo(void* player,PlayerClass player_class))
{
	IPlayerClassData* classData = queryExtension<IPlayerClassData>(static_cast<IPlayer*>(player));
	if (classData)
	{
		classData->setSpawnInfo(player_class);
	}
}

OMPRS_API(void,GetSpawnInfo(void* player, PlayerClass* data))
{
	IPlayerClassData* playerData = queryExtension<IPlayerClassData>(static_cast<IPlayer*>(player));
	if (playerData)
	{
		*data = playerData->getClass();
	}
}

OMPRS_API(int,GetAvailableClasses(void))
{
	IClassesComponent* component = OMPRSComponent::Get()->GetClasses();
	if (component)
	{
		return component->count();
	}
	return 0;
}

OMPRS_API(bool,GetClassData(int classid, PlayerClass* data))
{
	IClassesComponent* component = OMPRSComponent::Get()->GetClasses();
	if (component)
	{
		IClass* class_ = component->get(classid);
		if (class_)
		{
			*data = class_->getClass();
		}
	}
	return true;
}

OMPRS_API(void, EditClassData(int classid, PlayerClass data))
{
	IClassesComponent* component = OMPRSComponent::Get()->GetClasses();
	if (component)
	{
		IClass* class_ = component->get(classid);
		if (class_)
		{
			class_->setClass(data);
		}
	}
}