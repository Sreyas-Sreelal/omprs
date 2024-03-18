#pragma once

#include "../api.hpp"

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
		EXEC_CALLBACK(OnPlayerFinishedDownloading, player.getID(), player.getVirtualWorld());
	}

	bool onPlayerRequestDownload(IPlayer& player, ModelDownloadType type, uint32_t checksum) override
	{
		EXEC_CALLBACK(OnPlayerRequestDownload, player.getID(), static_cast<int>(type), checksum);
		return true;
	}
};