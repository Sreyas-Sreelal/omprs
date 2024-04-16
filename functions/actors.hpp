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
			return static_cast<IActor*>(actor)->getID();
		}
	}
	return INVALID_ACTOR_ID;
}

OMPRS_API(bool, DestroyActor(void* actor))
{
	if (actor)
	{
		OMPRSComponent::Get()->GetActors()->release(static_cast<IActor*>(actor)->getID());
		return true;
	}
	return false;
}

OMPRS_API(bool, IsActorStreamedIn(void* actor, void* player))
{
	if (actor && player)
	{
		return static_cast<IActor*>(actor)->isStreamedInForPlayer(*static_cast<IPlayer*>(player));
	}
	return false;
}

OMPRS_API(bool, SetActorVirtualWorld(void* actor, int virtualWorld))
{
	if (actor)
	{
		static_cast<IActor*>(actor)->setVirtualWorld(virtualWorld);
		return true;
	}
	return false;
}

OMPRS_API(int, GetActorVirtualWorld(void* actor))
{
	if (actor)
	{
		return static_cast<IActor*>(actor)->getVirtualWorld();
	}
	return 0;
}

OMPRS_API(bool, ApplyActorAnimation(void* actor, StringView animationLibrary, StringView animationName, float delta, bool loop, bool lockX, bool lockY, bool freeze, int time))
{
	
	if (actor)
	{
		const AnimationData animationData(delta, loop, lockX, lockY, freeze, time, animationLibrary, animationName);
		static_cast<IActor*>(actor)->applyAnimation(animationData);
		return true;
	}
	return false;
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

OMPRS_API(bool, SetActorPos(void* actor, float x, float y, float z))
{
	
	if (actor)
	{
		static_cast<IActor*>(actor)->setPosition(Vector3(x, y, z));
		return true;
	}
	return false;
}

OMPRS_API(bool, GetActorPos(void* actor, float* x, float* y, float* z))
{
	
	if (actor)
	{
		auto position = static_cast<IActor*>(actor)->getPosition();
		*x = position.x;
		*y = position.y;
		*z = position.z;
		return true;
	}
	return false;
}

OMPRS_API(bool, SetActorFacingAngle(void* actor, float angle))
{
	
	if (actor)
	{
		static_cast<IActor*>(actor)->setRotation(Vector3(0.0f, 0.0f, angle));
		return true;
	}
	return false;
}

OMPRS_API(bool, GetActorFacingAngle(void* actor, float* angle))
{
	
	if (actor)
	{
		*angle = static_cast<IActor*>(actor)->getRotation().ToEuler().z;
		return true;
	}
	return false;
}

OMPRS_API(bool, SetActorHealth(void* actor, float health))
{
	
	if (actor)
	{
		static_cast<IActor*>(actor)->setHealth(health);
		return true;
	}
	return false;
}

OMPRS_API(bool, GetActorHealth(void* actor, float* health))
{
	
	if (actor)
	{
		*health = static_cast<IActor*>(actor)->getHealth();
		return true;
	}
	return false;
}

OMPRS_API(bool, SetActorInvulnerable(void* actor, bool invulnerable))
{
	
	if (actor)
	{
		static_cast<IActor*>(actor)->setInvulnerable(invulnerable);
		return true;
	}
	return false;
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

OMPRS_API(bool, SetActorSkin(void* actor, int skin))
{
	
	if (actor)
	{
		static_cast<IActor*>(actor)->setSkin(skin);
		return true;
	}
	return false;
}

OMPRS_API(int, GetActorSkin(void* actor))
{
	
	if (actor)
	{
		return static_cast<IActor*>(actor)->getSkin();
	}
	return -1;
}

OMPRS_API(bool, GetActorAnimation(void* actor, StringView* animationLibrary, StringView* animationName,  float* delta, bool* loop, bool* lockX, bool* lockY, bool* freeze, unsigned int* time))
{
	
	if (actor)
	{
		const AnimationData& anim = static_cast<IActor*>(actor)->getAnimation();
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

OMPRS_API(bool, GetActorSpawnInfo(void* actor, int* skin, float* x, float* y, float* z, float* angle))
{
	
	if (actor)
	{
		const ActorSpawnData& spawnData = static_cast<IActor*>(actor)->getSpawnData();
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

OMPRS_API(IActorsComponent*, GetActorsComponent(void))
{
	return OMPRSComponent::Get()->GetActors();
}