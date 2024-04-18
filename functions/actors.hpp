#pragma once

#include "../api.hpp"

OMPRS_API(void*, CreateActor(int skin, Vector3 pos, float angle))
{
	auto actors = OMPRSComponent::Get()->GetActors();

	if (actors)
	{
		IActor* actor = actors->create(skin, pos, angle);
		if (actor)
		{
			return static_cast<IActor*>(actor);
		}
	}
	return nullptr;
}

OMPRS_API(void, DestroyActor(void* actor))
{
	if (actor)
	{
		OMPRSComponent::Get()->GetActors()->release(static_cast<IActor*>(actor)->getID());
	
	}
}

OMPRS_API(bool, IsActorStreamedIn(void* actor, void* player))
{
	if (actor && player)
	{
		return static_cast<IActor*>(actor)->isStreamedInForPlayer(*static_cast<IPlayer*>(player));
	}
	return false;
}

OMPRS_API(void, SetActorVirtualWorld(void* actor, int virtualWorld))
{
	if (actor)
	{
		static_cast<IActor*>(actor)->setVirtualWorld(virtualWorld);
	}
}

OMPRS_API(int, GetActorVirtualWorld(void* actor))
{
	if (actor)
	{
		return static_cast<IActor*>(actor)->getVirtualWorld();
	}
	return 0;
}

OMPRS_API(void, ApplyActorAnimation(void* actor, StringView animationLibrary, StringView animationName, float delta, bool loop, bool lockX, bool lockY, bool freeze, int time))
{

	if (actor)
	{
		const AnimationData animationData(delta, loop, lockX, lockY, freeze, time, animationLibrary, animationName);
		static_cast<IActor*>(actor)->applyAnimation(animationData);
	}
}

OMPRS_API(bool, ClearActorAnimations(void* actor))
{
	
	if (actor)
	{
		static_cast<IActor*>(actor)->clearAnimations();
		return true;
	}
	return false;
}

OMPRS_API(void, SetActorPos(void* actor, Vector3 pos))
{
	if (actor)
	{
		static_cast<IActor*>(actor)->setPosition(pos);
	}
}

OMPRS_API(void, GetActorPos(void* actor, Vector3* position))
{
	if (actor)
	{
		*position = static_cast<IActor*>(actor)->getPosition();
	}
}

OMPRS_API(void, SetActorFacingAngle(void* actor, float angle))
{
	
	if (actor)
	{
		static_cast<IActor*>(actor)->setRotation(Vector3(0.0f, 0.0f, angle));
	}
}

OMPRS_API(float, GetActorFacingAngle(void* actor))
{
	if (actor)
	{
		return static_cast<IActor*>(actor)->getRotation().ToEuler().z;
	}
	return std::numeric_limits<float>::quiet_NaN();
}

OMPRS_API(void, SetActorHealth(void* actor, float health))
{
	if (actor)
	{
		static_cast<IActor*>(actor)->setHealth(health);
	}
}

OMPRS_API(float, GetActorHealth(void* actor))
{
	
	if (actor)
	{
		return static_cast<IActor*>(actor)->getHealth();
		
	}
	return std::numeric_limits<float>::quiet_NaN();
}

OMPRS_API(void, SetActorInvulnerable(void* actor, bool invulnerable))
{
	if (actor)
	{
		static_cast<IActor*>(actor)->setInvulnerable(invulnerable);
	
	}
}

OMPRS_API(bool, IsActorInvulnerable(void* actor))
{
	if (actor)
	{
		return static_cast<IActor*>(actor)->isInvulnerable();
	}
	return false;
}

OMPRS_API(bool, IsValidActor(void* actor))
{
	return actor != nullptr;
}

OMPRS_API(void, SetActorSkin(void* actor, int skin))
{
	if (actor)
	{
		static_cast<IActor*>(actor)->setSkin(skin);
	}
}

OMPRS_API(int, GetActorSkin(void* actor))
{
	if (actor)
	{
		return static_cast<IActor*>(actor)->getSkin();
	}
	return -1;
}

OMPRS_API(void, GetActorAnimation(void* actor, StringView* animationLibrary, StringView* animationName, float* delta, bool* loop, bool* lockX, bool* lockY, bool* freeze, unsigned int* time))
{

	if (actor)
	{
		const AnimationData& anim = static_cast<IActor*>(actor)->getAnimation();
		*animationLibrary = anim.lib;
		*animationName = anim.name;
		*delta = anim.delta;
		*loop = anim.loop;
		*lockX = anim.lockX;
		*lockY = anim.lockY;
		*freeze = anim.freeze;
		*time = anim.time;
	}
}


OMPRS_API(void, GetActorSpawnInfo(void* actor, ActorSpawnData* spawnData))
{
	if (actor)
	{
		*spawnData = static_cast<IActor*>(actor)->getSpawnData();
	}
}

OMPRS_API(IActorsComponent*, GetActorsComponent(void))
{
	return OMPRSComponent::Get()->GetActors();
}