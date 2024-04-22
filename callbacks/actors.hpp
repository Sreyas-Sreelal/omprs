#pragma once

#include "../api.hpp"

struct ActorEvents : public ActorEventHandler, public Singleton<ActorEvents>
{
private:
	CALLBACK_DECL(void, onPlayerGiveDamageActor, void*,void*,float,unsigned,BodyPart);
	CALLBACK_DECL(void, onActorStreamIn, void*, void*);
	CALLBACK_DECL(void, onActorStreamOut, void*, void*);

public:
	ActorEvents()
	{
		INIT_CALLBACK(onPlayerGiveDamageActor);
		INIT_CALLBACK(onActorStreamIn);
		INIT_CALLBACK(onActorStreamOut);
	}
	void onPlayerGiveDamageActor(IPlayer& player, IActor& actor, float amount, unsigned weapon, BodyPart part) override
	{
		EXEC_CALLBACK(onPlayerGiveDamageActor, &player,&actor,amount,weapon,part);
	}

	void onActorStreamIn(IActor& actor, IPlayer& forPlayer) override
	{
		EXEC_CALLBACK(onActorStreamIn, &actor, &forPlayer);
	}

	void onActorStreamOut(IActor& actor, IPlayer& forPlayer) override
	{
		EXEC_CALLBACK(onActorStreamOut, &actor, &forPlayer);
	}
};