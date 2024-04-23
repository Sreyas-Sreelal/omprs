#pragma once

#include "../api.hpp"

struct CheckPointEvents : public PlayerCheckpointEventHandler, public Singleton<CheckPointEvents>
{
private:
	CALLBACK_DECL(void, onPlayerEnterCheckpoint, void*);
	CALLBACK_DECL(void, onPlayerLeaveCheckpoint, void*);
	CALLBACK_DECL(void, onPlayerEnterRaceCheckpoint, void*);
	CALLBACK_DECL(void, onPlayerLeaveRaceCheckpoint, void*);

public:
	CheckPointEvents()
	{
		INIT_CALLBACK(onPlayerEnterCheckpoint);
		INIT_CALLBACK(onPlayerLeaveCheckpoint);
		INIT_CALLBACK(onPlayerEnterRaceCheckpoint);
		INIT_CALLBACK(onPlayerLeaveRaceCheckpoint);
	}
	void onPlayerEnterCheckpoint(IPlayer& player) override
	{
		EXEC_CALLBACK(onPlayerEnterCheckpoint, &player);
	}

	void onPlayerLeaveCheckpoint(IPlayer& player) override
	{
		EXEC_CALLBACK(onPlayerLeaveCheckpoint, &player);
	}

	void onPlayerEnterRaceCheckpoint(IPlayer& player) override
	{
		EXEC_CALLBACK(onPlayerEnterRaceCheckpoint, &player);
	}

	void onPlayerLeaveRaceCheckpoint(IPlayer& player) override
	{
		EXEC_CALLBACK(onPlayerLeaveRaceCheckpoint, &player);
	}
};