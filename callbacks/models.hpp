#pragma once

#include "../api.hpp"

typedef void(FuncOnPlayerFinishedDownloading)(int, int);
typedef bool(FuncOnPlayerRequestDownload)(int, int, int);

struct ModelEvents : public PlayerModelsEventHandler, public Singleton<ModelEvents>
{
private:
	CALLBACK_DECL(OnPlayerFinishedDownloading, int, int);
	CALLBACK_DECL(OnPlayerRequestDownload, int, int, int);

public:
	ModelEvents()
	{
		INIT_CALLBACK(OnPlayerFinishedDownloading);
		INIT_CALLBACK(OnPlayerRequestDownload);
	}
	void onPlayerFinishedDownloading(IPlayer& player) override
	{
		auto omprs_core = OMPRSComponent::Get()->GetOMPRSCore();
		auto playerid = player.getID();
		auto virtualworld = player.getVirtualWorld();
		EXEC_CALLBACK(OnPlayerFinishedDownloading, playerid, virtualworld);
	}
	bool onPlayerRequestDownload(IPlayer& player, ModelDownloadType type, uint32_t checksum) override
	{
		auto omprs_core = OMPRSComponent::Get()->GetOMPRSCore();
		auto playerid = player.getID();
		EXEC_CALLBACK(OnPlayerRequestDownload, playerid, static_cast<int>(type), checksum);
		return true;
	}
};