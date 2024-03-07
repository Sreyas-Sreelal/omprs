#pragma once

#include "../api.hpp"

typedef void(FuncOnPlayerFinishedDownloading)(int, int);
typedef bool(FuncOnPlayerRequestDownload)(int, int, int);

struct ModelEvents : public PlayerModelsEventHandler, public Singleton<ModelEvents>
{
private:
	FuncOnPlayerFinishedDownloading* funcOnPlayerFinishedDownloading = nullptr;
	FuncOnPlayerRequestDownload* funcOnPlayerRequestDownload = nullptr;

public:
	ModelEvents()
	{
		auto omprs_core = OMPRSComponent::Get()->GetOMPRSCore();
		funcOnPlayerFinishedDownloading = (FuncOnPlayerFinishedDownloading*)omprs_core->get_callback_addr("OnPlayerFinishedDownloading");
		funcOnPlayerRequestDownload = (FuncOnPlayerRequestDownload*)omprs_core->get_callback_addr("OnPlayerRequestDownload");
	}
	void onPlayerFinishedDownloading(IPlayer& player) override
	{
		if (funcOnPlayerFinishedDownloading != nullptr)
		{
			auto omprs_core = OMPRSComponent::Get()->GetOMPRSCore();
			auto playerid = player.getID();
			auto virtualworld = player.getVirtualWorld();
			(*funcOnPlayerFinishedDownloading)(playerid, virtualworld);
		}
		
	}
	bool onPlayerRequestDownload(IPlayer& player, ModelDownloadType type, uint32_t checksum) override
	{
		if (funcOnPlayerRequestDownload != nullptr)
		{
			auto omprs_core = OMPRSComponent::Get()->GetOMPRSCore();
			auto playerid = player.getID();
			(*funcOnPlayerRequestDownload)(playerid, static_cast<int>(type), checksum);
		}
		
		return true;
	}
};