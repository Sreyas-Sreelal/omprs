#pragma once

#include "../api.hpp"

typedef void(OnPlayerFinishedDownloading)(int, int);
typedef bool(OnPlayerRequestDownload)(int, int, int);

struct ModelEvents : public PlayerModelsEventHandler, public Singleton<ModelEvents>
{
public:
	void onPlayerFinishedDownloading(IPlayer& player) override
	{
		auto omprs_core = OMPRSComponent::Get()->GetOMPRSCore();
		auto playerid = player.getID();
		auto virtualworld = player.getVirtualWorld();

		omprs_core->execute_callback<OnPlayerFinishedDownloading, int, int>("OnPlayerFinishedDownloading", playerid, virtualworld);
	}
	bool onPlayerRequestDownload(IPlayer& player, ModelDownloadType type, uint32_t checksum) override
	{
		auto omprs_core = OMPRSComponent::Get()->GetOMPRSCore();
		auto playerid = player.getID();

		omprs_core->execute_callback<OnPlayerRequestDownload, int, int, int>("OnPlayerRequestDownload", playerid, static_cast<int>(type), checksum);
		return true;
	}
};