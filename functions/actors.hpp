#pragma once

#include "../api.hpp"

OMPRS_API(int, CreateActor(int skin, float x, float y, float z, float angle))
{
	auto actors = OMPRSComponent::Get()->GetActors();

	if (actors)
	{
		IActor* actor = actors->create(skin, Vector3(x, y, z), angle);
		if (actor)
		{
			return actor->getID();
		}
	}
	return INVALID_ACTOR_ID;
}

OMPRS_API(bool, DestroyActor(int actorid))
{
	if (OMPRSComponent::Get()->GetActors()->get(actorid) != nullptr)
	{
		OMPRSComponent::Get()->GetActors()->release(actorid);
		return true;
	}
	return false;
}

OMPRS_API(bool, IsActorStreamedIn(int actorid, int playerid))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	auto player = OMPRSComponent::Get()->GetPlayer(playerid);
	if (actor && player)
	{
		return actor->isStreamedInForPlayer(*player);
	}
	return false;
}

OMPRS_API(bool, SetActorVirtualWorld(int actorid, int virtualWorld))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	if (actor)
	{
		actor->setVirtualWorld(virtualWorld);
		return true;
	}
	return false;
}

OMPRS_API(int, GetActorVirtualWorld(int actorid))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	if (actor)
	{
		return actor->getVirtualWorld();
	}
	return 0;
}

OMPRS_API(bool, ApplyActorAnimation(int actorid, StringView animationLibrary, StringView animationName, float delta, bool loop, bool lockX, bool lockY, bool freeze, int time))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	if (actor)
	{
		const AnimationData animationData(delta, loop, lockX, lockY, freeze, time, animationLibrary, animationName);
		actor->applyAnimation(animationData);
		return true;
	}
	return false;
}

OMPRS_API(bool, ClearActorAnimations(int actorid))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	if (actor)
	{
		actor->clearAnimations();
		return true;
	}
	return false;
}

OMPRS_API(bool, SetActorPos(int actorid, float x, float y, float z))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	if (actor)
	{
		actor->setPosition(Vector3(x, y, z));
		return true;
	}
	return false;
}

OMPRS_API(bool, GetActorPos(int actorid, float* x, float* y, float* z))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	if (actor)
	{
		auto position = actor->getPosition();
		*x = position.x;
		*y = position.y;
		*z = position.z;
		return true;
	}
	return false;
}

OMPRS_API(bool, SetActorFacingAngle(int actorid, float angle))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	if (actor)
	{
		actor->setRotation(Vector3(0.0f, 0.0f, angle));
		return true;
	}
	return false;
}

OMPRS_API(bool, GetActorFacingAngle(int actorid, float* angle))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	if (actor)
	{
		*angle = actor->getRotation().ToEuler().z;
		return true;
	}
	return false;
}

OMPRS_API(bool, SetActorHealth(int actorid, float health))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	if (actor)
	{
		actor->setHealth(health);
		return true;
	}
	return false;
}

OMPRS_API(bool, GetActorHealth(int actorid, float* health))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	if (actor)
	{
		*health = actor->getHealth();
		return true;
	}
	return false;
}

OMPRS_API(bool, SetActorInvulnerable(int actorid, bool invulnerable))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	if (actor)
	{
		actor->setInvulnerable(invulnerable);
		return true;
	}
	return false;
}

OMPRS_API(bool, IsActorInvulnerable(int actorid))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	if (actor)
	{
		return actor->isInvulnerable();
	}
	return false;
}

OMPRS_API(bool, IsValidActor(int actorid))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	return actor != nullptr;
}

OMPRS_API(bool, SetActorSkin(int actorid, int skin))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	if (actor)
	{
		actor->setSkin(skin);
		return true;
	}
	return false;
}

OMPRS_API(int, GetActorSkin(int actorid))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	if (actor)
	{
		return actor->getSkin();
	}
	return -1;
}

OMPRS_API(bool, GetActorAnimation(int actorid, StringView* animationLibrary, StringView* animationName,  float* delta, bool* loop, bool* lockX, bool* lockY, bool* freeze, unsigned int* time))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	if (actor)
	{
		const AnimationData& anim = actor->getAnimation();
		OMPRSComponent::Get()->GetCore()->printLn("name is %s lib is %s", anim.name.data(), anim.lib.data());
		*animationLibrary= anim.lib;
		*animationName= anim.name;
		*delta = anim.delta;
		*loop = anim.loop;
		*lockX = anim.lockX;
		*lockY = anim.lockY;
		*freeze = anim.freeze;
		*time = anim.time;

		return true;
	}
	return false;
}

OMPRS_API(bool, GetActorSpawnInfo(int actorid, int* skin, float* x, float* y, float* z, float* angle))
{
	auto actor = OMPRSComponent::Get()->GetActor(actorid);
	if (actor)
	{
		const ActorSpawnData& spawnData = actor->getSpawnData();
		auto position = spawnData.position;

		*x = position.x;
		*y = position.y;
		*z = position.z;
		*angle = spawnData.facingAngle;
		*skin = spawnData.skin;

		return true;
	}
	return false;
}