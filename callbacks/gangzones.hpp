#pragma once

#include "../api.hpp"

struct GangZoneEvents : public GangZoneEventHandler, public Singleton<GangZoneEvents>
{
private:
	CALLBACK_DECL(void, onPlayerEnterGangZone, void*, void*);
	CALLBACK_DECL(void, onPlayerLeaveGangZone, void*, void*);
	CALLBACK_DECL(void, onPlayerClickGangZone, void*, void*);

public:
	GangZoneEvents()
	{
		INIT_CALLBACK(onPlayerEnterGangZone);
		INIT_CALLBACK(onPlayerLeaveGangZone);
		INIT_CALLBACK(onPlayerClickGangZone);
	}

	void onPlayerEnterGangZone(IPlayer& player, IGangZone& zone) override
	{
		EXEC_CALLBACK(onPlayerEnterGangZone, &player, &zone);
	}

	void onPlayerLeaveGangZone(IPlayer& player, IGangZone& zone) override
	{
		EXEC_CALLBACK(onPlayerLeaveGangZone, &player, &zone);
	}

	void onPlayerClickGangZone(IPlayer& player, IGangZone& zone) override
	{
		EXEC_CALLBACK(onPlayerClickGangZone, &player, &zone);
	}
};