#pragma once

#include "../api.hpp"

class PlayerEvents : public PlayerConnectEventHandler, public Singleton<PlayerEvents>
{
private:
	CALLBACK_DECL(OnPlayerConnect, int);
	CALLBACK_DECL(OnIncomingConnection, int, const char*, int);

public:
	PlayerEvents()
	{
		INIT_CALLBACK(OnPlayerConnect);
		INIT_CALLBACK(OnIncomingConnection);
	}

	void onPlayerConnect(IPlayer& player) override
	{
		EXEC_CALLBACK(OnPlayerConnect, player.getID());
	}

	void onIncomingConnection(IPlayer& player, StringView ipAddress, unsigned short port)
	{
		EXEC_CALLBACK(OnIncomingConnection, player.getID(), ipAddress.to_string().c_str(), port);
	}
};