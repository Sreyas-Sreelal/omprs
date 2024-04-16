#pragma once

#include "../api.hpp"

class PlayerEvents : public PlayerConnectEventHandler, public PlayerStreamEventHandler, public PlayerSpawnEventHandler, public PlayerTextEventHandler, public PlayerShotEventHandler, public PlayerChangeEventHandler, public PlayerDamageEventHandler, public PlayerClickEventHandler, public PlayerCheckEventHandler, public PlayerUpdateEventHandler, public Singleton<PlayerEvents>
{
private:
	CALLBACK_DECL(void, OnPlayerConnect, void*);
	CALLBACK_DECL(void, OnIncomingConnection, void*, const char*, int);
	CALLBACK_DECL(void, OnPlayerDisconnect, void*, int);
	CALLBACK_DECL(void, OnPlayerStreamIn, void*, void*);
	CALLBACK_DECL(void, OnPlayerStreamOut, void*, void*);
	CALLBACK_DECL(bool, OnPlayerRequestSpawn, void*);
	CALLBACK_DECL(void, OnPlayerSpawn, void*);
	CALLBACK_DECL(bool, OnPlayerText, void*, const char*);
	CALLBACK_DECL(bool, OnPlayerCommandText, void*, const char*);
	CALLBACK_DECL(void, OnPlayerInteriorChange, void*, int, int);
	CALLBACK_DECL(void, OnPlayerStateChange, void*, int, int);
	CALLBACK_DECL(void, OnPlayerKeyStateChange, void*, int, int);
	CALLBACK_DECL(void, OnPlayerDeath, void*, void*, int);
	CALLBACK_DECL(void, OnPlayerTakeDamage, void*, void*, float, int, int);
	CALLBACK_DECL(void, OnPlayerGiveDamage, void*, void*, float, int, int);
	CALLBACK_DECL(void, OnPlayerClickMap, void*, float, float, float);
	CALLBACK_DECL(void, OnPlayerClickPlayer, void*, void*, int);
	CALLBACK_DECL(void, OnClientCheckResponse, void*, int, int, int);
	CALLBACK_DECL(bool, OnPlayerUpdate, void*);

public:
	PlayerEvents()
	{
		INIT_CALLBACK(OnPlayerConnect);
		INIT_CALLBACK(OnIncomingConnection);
		INIT_CALLBACK(OnPlayerDisconnect);
		INIT_CALLBACK(OnPlayerStreamIn);
		INIT_CALLBACK(OnPlayerStreamOut);
		INIT_CALLBACK(OnPlayerRequestSpawn);
		INIT_CALLBACK(OnPlayerSpawn);
		INIT_CALLBACK(OnPlayerText);
		INIT_CALLBACK(OnPlayerCommandText);
		INIT_CALLBACK(OnPlayerInteriorChange);
		INIT_CALLBACK(OnPlayerStateChange);
		INIT_CALLBACK(OnPlayerKeyStateChange);
		INIT_CALLBACK(OnPlayerDeath);
		INIT_CALLBACK(OnPlayerTakeDamage);
		INIT_CALLBACK(OnPlayerGiveDamage);
		INIT_CALLBACK(OnPlayerClickMap);
		INIT_CALLBACK(OnPlayerClickPlayer);
		INIT_CALLBACK(OnClientCheckResponse);
		INIT_CALLBACK(OnPlayerUpdate);
	}

	void onPlayerConnect(IPlayer& player) override
	{
		EXEC_CALLBACK(OnPlayerConnect, &player);
	}

	void onIncomingConnection(IPlayer& player, StringView ipAddress, unsigned short port)
	{
		EXEC_CALLBACK(OnIncomingConnection, &player, ipAddress.to_string().c_str(), port);
	}

	void onPlayerDisconnect(IPlayer& player, PeerDisconnectReason reason)
	{
		EXEC_CALLBACK(OnPlayerDisconnect, &player, reason);
	}

	void onPlayerStreamIn(IPlayer& player, IPlayer& forPlayer)
	{
		EXEC_CALLBACK(OnPlayerStreamIn, &player, &forPlayer);
	}

	void onPlayerStreamOut(IPlayer& player, IPlayer& forPlayer)
	{
		EXEC_CALLBACK(OnPlayerStreamOut, &player, &forPlayer);
	}

	bool onPlayerRequestSpawn(IPlayer& player)
	{
		EXEC_CALLBACK(OnPlayerRequestSpawn, &player);
		return true;
	}

	void onPlayerSpawn(IPlayer& player)
	{
		EXEC_CALLBACK(OnPlayerSpawn, &player);
	}

	bool onPlayerText(IPlayer& player, StringView message)
	{
		EXEC_CALLBACK(OnPlayerText, &player, message.to_string().c_str());
		return true;
	}

	bool onPlayerCommandText(IPlayer& player, StringView message)
	{
		EXEC_CALLBACK(OnPlayerCommandText, &player, message.to_string().c_str());
		return false;
	}

	// bool onPlayerShotMissed(IPlayer& player, const PlayerBulletData& bulletData)
	//{
	//	return true;
	// }

	// bool onPlayerShotPlayer(IPlayer& player, IPlayer& target, const PlayerBulletData& bulletData)
	//{
	//	return true;
	// }

	// bool onPlayerShotVehicle(IPlayer& player, IVehicle& target, const PlayerBulletData& bulletData)
	//{
	//	return true;
	// }

	// bool onPlayerShotObject(IPlayer& player, IObject& target, const PlayerBulletData& bulletData)
	//{
	//	return true;
	// }

	// bool onPlayerShotPlayerObject(IPlayer& player, IPlayerObject& target, const PlayerBulletData& bulletData)
	//{
	//	return true;
	// }

	// void onPlayerScoreChange(IPlayer& player, int score) { }

	// void onPlayerNameChange(IPlayer& player, StringView oldName) { }

	void onPlayerInteriorChange(IPlayer& player, unsigned newInterior, unsigned oldInterior)
	{
		EXEC_CALLBACK(OnPlayerInteriorChange, &player, newInterior, oldInterior);
	}

	void onPlayerStateChange(IPlayer& player, PlayerState newState, PlayerState oldState)
	{
		EXEC_CALLBACK(OnPlayerStateChange, &player, newState, oldState);
	}

	void onPlayerKeyStateChange(IPlayer& player, uint32_t newKeys, uint32_t oldKeys)
	{
		EXEC_CALLBACK(OnPlayerKeyStateChange, &player, newKeys, oldKeys);
	}

	void onPlayerDeath(IPlayer& player, IPlayer* killer, int reason)
	{
		EXEC_CALLBACK(OnPlayerDeath, &player, killer, reason);
	}

	void onPlayerTakeDamage(IPlayer& player, IPlayer* from, float amount, unsigned weapon, BodyPart part)
	{
		EXEC_CALLBACK(OnPlayerTakeDamage, &player, from, amount, weapon, part);
	}

	void onPlayerGiveDamage(IPlayer& player, IPlayer& to, float amount, unsigned weapon, BodyPart part)
	{
		EXEC_CALLBACK(OnPlayerGiveDamage, &player, &to, amount, weapon, part);
	}

	void onPlayerClickMap(IPlayer& player, Vector3 pos)
	{
		EXEC_CALLBACK(OnPlayerClickMap, &player, pos.x, pos.y, pos.z);
	}

	void onPlayerClickPlayer(IPlayer& player, IPlayer& clicked, PlayerClickSource source)
	{
		EXEC_CALLBACK(OnPlayerClickPlayer, &player, &clicked, source);
	}

	void onClientCheckResponse(IPlayer& player, int actionType, int address, int results)
	{
		EXEC_CALLBACK(OnClientCheckResponse, &player, actionType, address, results);
	}

	bool onPlayerUpdate(IPlayer& player, TimePoint now)
	{
		EXEC_CALLBACK(OnPlayerUpdate, &player);
		return true;
	}
};