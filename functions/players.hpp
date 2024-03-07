#pragma once

#include "../api.hpp"

OMPRS_API(bool, SendClientMessage(int playerid, int colour, const char* message))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->sendClientMessage(Colour::FromRGBA(colour), message);
	return true;
}

OMPRS_API(int, GetPlayerName(int playerid, char* name))
{
	GET_PLAYER_CHECKED(player, playerid, 0);

	auto out = player->getName();
	auto length = out.length();

	out.copy(name, length);

	return length;
}

OMPRS_API(bool, SendClientMessageToAll(int colour, const char* message))
{
	OMPRSComponent::Get()->GetPlayers()->sendClientMessageToAll(Colour::FromRGBA(colour), message);
	return true;
}

OMPRS_API(bool, SetPlayerCameraPos(int playerid, float x, float y, float z))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setCameraPosition(Vector3(x, y, z));
	return true;
}

OMPRS_API(bool, SetPlayerDrunkLevel(int playerid, int level))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setDrunkLevel(level);
	return true;
}

OMPRS_API(bool, SetPlayerInterior(int playerid, int interiorid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setInterior(interiorid);
	return true;
}

OMPRS_API(bool, SetPlayerWantedLevel(int playerid, int level))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setWantedLevel(level);
	return true;
}

OMPRS_API(bool, SetPlayerWeather(int playerid, int weatherid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setWeather(weatherid);
	return true;
}

OMPRS_API(int, GetPlayerWeather(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	return player->getWeather();
}

OMPRS_API(bool, SetPlayerSkin(int playerid, int skinid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setSkin(skinid);
	return true;
}

OMPRS_API(bool, SetPlayerShopName(int playerid, const char* shopname))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setShopName(shopname);
	return true;
}

OMPRS_API(bool, GivePlayerMoney(int playerid, int amount))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->giveMoney(amount);
	return true;
}

OMPRS_API(bool, SetPlayerCameraLookAt(int playerid, float x, float y, float z, int cut))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setCameraLookAt(Vector3(x, y, z), cut);
	return true;
}

OMPRS_API(bool, SetCameraBehindPlayer(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setCameraBehind();
	return true;
}

OMPRS_API(bool, CreateExplosionForPlayer(int playerid, float x, float y, float z, int type, float radius))
{
	GET_PLAYER_CHECKED(player, playerid, true);
	player->createExplosion(Vector3(x, y, z), type, radius);
	return true;
}

OMPRS_API(bool, CreateExplosion(float x, float y, float z, int type, float radius))
{
	OMPRSComponent::Get()->GetPlayers()->createExplosionForAll(Vector3(x, y, z), type, radius);
	return true;
}

OMPRS_API(bool, PlayAudioStreamForPlayer(int playerid, const char* url, float x, float y, float z, float distance, bool usePos))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->playAudio(url, usePos, Vector3(x, y, z), distance);
	return true;
}

OMPRS_API(bool, StopAudioStreamForPlayer(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->stopAudio();
	return true;
}

OMPRS_API(bool, SendDeathMessage(int killerid, int playerid, int weapon))
{
	GET_PLAYER_CHECKED(killee, playerid, true);
	GET_PLAYER_CHECKED(killer, killerid, true);

	if (killee)
	{
		OMPRSComponent::Get()->GetPlayers()->sendDeathMessageToAll(killer, *killee, weapon);
	}
	else
	{
		OMPRSComponent::Get()->GetPlayers()->sendEmptyDeathMessageToAll();
	}

	return true;
}

OMPRS_API(bool, TogglePlayerWidescreen(int playerid, bool enable))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->useWidescreen(enable);
	return true;
}

OMPRS_API(bool, IsPlayerWidescreenToggled(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	return player->hasWidescreen();
}

OMPRS_API(bool, SetPlayerHealth(int playerid, float health))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setHealth(health);
	return true;
}

OMPRS_API(bool, GetPlayerHealth(int playerid, float* health))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	*health = player->getHealth();
	return true;
}

OMPRS_API(bool, SetPlayerArmour(int playerid, float armour))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setArmour(armour);
	return true;
}

OMPRS_API(bool, GetPlayerArmour(int playerid, float* armour))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	*armour = player->getArmour();
	return true;
}

OMPRS_API(bool, SetPlayerTeam(int playerid, int teamid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setTeam(teamid);
	return true;
}

OMPRS_API(int, GetPlayerTeam(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	return player->getTeam();
}

OMPRS_API(bool, SetPlayerScore(int playerid, int score))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setScore(score);
	return true;
}

OMPRS_API(int, GetPlayerScore(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	return player->getScore();
}

OMPRS_API(int, GetPlayerSkin(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	return player->getSkin();
}

OMPRS_API(bool, SetPlayerColor(int playerid, uint32_t colour))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setColour(Colour::FromRGBA(colour));
	return true;
}

OMPRS_API(int, GetPlayerColor(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	return player->getColour().RGBA();
}

OMPRS_API(int, GetDefaultPlayerColour(int playerid))
{
	return OMPRSComponent::Get()->GetPlayers()->getDefaultColour(playerid).RGBA();
}

OMPRS_API(int, GetPlayerDrunkLevel(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	return player->getDrunkLevel();
}

OMPRS_API(bool, GivePlayerWeapon(int playerid, int weaponid, int ammo))
{
	GET_PLAYER_CHECKED(player, playerid, false);

	WeaponSlotData data;
	data.id = weaponid;
	data.ammo = ammo;

	player->giveWeapon(data);

	return true;
}

OMPRS_API(bool, RemovePlayerWeapon(int playerid, uint8_t weaponid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->removeWeapon(weaponid);
	return true;
}

OMPRS_API(int, GetPlayerMoney(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	return player->getMoney();
}

OMPRS_API(bool, ResetPlayerMoney(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->resetMoney();
	return true;
}

OMPRS_API(int, SetPlayerName(int playerid, const char* name))
{
	GET_PLAYER_CHECKED(player, playerid, 0);
	EPlayerNameStatus status = player->setName(name);
	return status == EPlayerNameStatus::Updated ? 1 : (status == EPlayerNameStatus::Invalid ? -1 : 0);
}

OMPRS_API(int, GetPlayerState(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	return player->getState();
}

OMPRS_API(int, GetPlayerPing(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	return player->getPing();
}

OMPRS_API(int, GetPlayerWeapon(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	return player->getArmedWeapon();
}

OMPRS_API(bool, SetPlayerTime(int playerid, int hour, int minute))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setTime(std::chrono::hours(hour), std::chrono::minutes(minute));
	return true;
}

OMPRS_API(bool, GetPlayerTime(int playerid, int* hour, int* minute))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	std::pair<std::chrono::hours, std::chrono::minutes> data = player->getTime();
	*hour = data.first.count();
	*minute = data.second.count();
	return true;
}

OMPRS_API(bool, TogglePlayerClock(int playerid, bool enable))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->useClock(enable);
	return true;
}

OMPRS_API(bool, PlayerHasClockEnabled(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	return player->hasClock();
}

OMPRS_API(bool, ForceClassSelection(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->forceClassSelection();
	return true;
}

OMPRS_API(int, GetPlayerWantedLevel(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	return player->getWantedLevel();
}

OMPRS_API(bool, SetPlayerFightingStyle(int playerid, int style))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setFightingStyle(PlayerFightingStyle(style));
	return true;
}

OMPRS_API(int, GetPlayerFightingStyle(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, PlayerFightingStyle_Normal);
	return player->getFightingStyle();
}

OMPRS_API(bool, SetPlayerVelocity(int playerid, float x, float y, float z))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setVelocity(Vector3(x, y, z));
	return true;
}

OMPRS_API(bool, GetPlayerVelocity(int playerid, float* x, float* y, float* z))
{
	GET_PLAYER_CHECKED(player, playerid, false);

	auto velocity = player->getVelocity();
	*x = velocity.x;
	*y = velocity.y;
	*z = velocity.z;

	return true;
}

OMPRS_API(bool, GetPlayerCameraPos(int playerid, float* x, float* y, float* z))
{
	GET_PLAYER_CHECKED(player, playerid, false);

	auto pos = player->getAimData().camPos;
	*x = pos.x;
	*y = pos.y;
	*z = pos.z;

	return true;
}

OMPRS_API(float, GetPlayerDistanceFromPoint(int playerid, float x, float y, float z))
{
	GET_PLAYER_CHECKED(player, playerid, -1.0);
	Vector3 playerCoords = player->getPosition();
	return glm::distance(playerCoords, Vector3(x, y, z));
}

OMPRS_API(int, GetPlayerInterior(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	return player->getInterior();
}

OMPRS_API(bool, SetPlayerPos(int playerid, float x, float y, float z))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setPosition(Vector3(x, y, z));
	return true;
}

OMPRS_API(bool, GetPlayerPos(int playerid, float* x, float* y, float* z))
{
	GET_PLAYER_CHECKED(player, playerid, false);

	auto pos = player->getPosition();
	*x = pos.x;
	*y = pos.y;
	*z = pos.z;

	return true;
}

OMPRS_API(int, GetPlayerVirtualWorld(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	return player->getVirtualWorld();
}

OMPRS_API(bool, IsPlayerNPC(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	return player->isBot();
}

OMPRS_API(bool, IsPlayerStreamedIn(int playerid, int otherid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	GET_PLAYER_CHECKED(other, otherid, false);
	return player->isStreamedInForPlayer(*other);
}

OMPRS_API(bool, PlayerPlaySound(int playerid, uint32_t sound, float x, float y, float z))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->playSound(sound, Vector3(x, y, z));
	return true;
}

OMPRS_API(bool, PlayerSpectatePlayer(int playerid, IPlayer& target, int mode))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->spectatePlayer(target, PlayerSpectateMode(mode));
	return true;
}

OMPRS_API(bool, PlayerSpectateVehicle(int playerid, int targetvehicleid, int mode))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	GET_VEHICLE_CHECKED(vehicle, targetvehicleid, false);
	player->spectateVehicle(*vehicle, PlayerSpectateMode(mode));
	return true;
}

OMPRS_API(bool, SetPlayerVirtualWorld(int playerid, int vw))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setVirtualWorld(vw);
	return true;
}

OMPRS_API(bool, SetPlayerWorldBounds(int playerid, float xMax, float xMin, float yMax, float yMin))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	Vector4 coords = { xMax, xMin, yMax, yMin };
	player->setWorldBounds(coords);
	return true;
}

OMPRS_API(bool, ClearPlayerWorldBounds(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setWorldBounds(Vector4(MAX_WORLD_BOUNDS, MIN_WORLD_BOUNDS, MAX_WORLD_BOUNDS, MIN_WORLD_BOUNDS));
	return true;
}

OMPRS_API(bool, GetPlayerWorldBounds(int playerid, float* xMax, float* xMin, float* yMax, float* yMin))
{
	GET_PLAYER_CHECKED(player, playerid, false);

	auto bounds = player->getWorldBounds();
	*xMax = bounds.x;
	*xMin = bounds.y;
	*yMax = bounds.z;
	*yMin = bounds.w;

	return true;
}

OMPRS_API(bool, ClearAnimations(int playerid, int syncType))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->clearTasks(PlayerAnimationSyncType(syncType));
	return true;
}

OMPRS_API(bool, GetPlayerLastShotVectors(int playerid, float* fOriginX, float* fOriginY, float* fOriginZ, float* fHitPosX, float* fHitPosY, float* fHitPosZ))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	PlayerBulletData data = player->getBulletData();

	*fOriginX = data.origin.x;
	*fOriginY = data.origin.y;
	*fOriginZ = data.origin.z;

	*fHitPosX = data.hitPos.x;
	*fHitPosY = data.hitPos.y;
	*fHitPosZ = data.hitPos.z;

	return true;
}

OMPRS_API(int, GetPlayerCameraTargetPlayer(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, INVALID_PLAYER_ID);
	IPlayer* target = player->getCameraTargetPlayer();

	if (target)
	{
		return target->getID();
	}

	return INVALID_PLAYER_ID;
}

OMPRS_API(int, GetPlayerCameraTargetActor(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, INVALID_ACTOR_ID);
	IActor* target = player->getCameraTargetActor();

	if (target)
	{
		return target->getID();
	}

	return INVALID_ACTOR_ID;
}

OMPRS_API(int, GetPlayerCameraTargetObject(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, INVALID_OBJECT_ID);
	IObject* target = player->getCameraTargetObject();

	if (target)
	{
		return target->getID();
	}

	return INVALID_OBJECT_ID;
}

OMPRS_API(int, GetPlayerCameraTargetVehicle(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, INVALID_VEHICLE_ID);
	IVehicle* target = player->getCameraTargetVehicle();

	if (target)
	{
		return target->getID();
	}

	return INVALID_VEHICLE_ID;
}

OMPRS_API(bool, IsPlayerConnected(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	return true;
}

OMPRS_API(bool, PutPlayerInVehicle(int playerid, int vehicleid, int seatID))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	GET_VEHICLE_CHECKED(vehicle, vehicleid, false);

	vehicle->putPlayer(*player, seatID);

	return true;
}

OMPRS_API(bool, RemoveBuildingForPlayer(int playerid, int model, float x, float y, float z, float radius))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->removeDefaultObjects(model, Vector3(x, y, z), radius);
	return true;
}

OMPRS_API(int, GetPlayerBuildingsRemoved(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	return player->getDefaultObjectsRemoved();
}

OMPRS_API(bool, RemovePlayerFromVehicle(int playerid, bool force))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->removeFromVehicle(force);
	return true;
}

OMPRS_API(bool, RemovePlayerMapIcon(int playerid, int iconID))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->unsetMapIcon(iconID);
	return true;
}

OMPRS_API(bool, SetPlayerMapIcon(int playerid, int iconID, Vector3 pos, int type, uint32_t colour, int style))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setMapIcon(iconID, pos, type, Colour::FromRGBA(colour), MapIconStyle(style));
	return true;
}

OMPRS_API(bool, ResetPlayerWeapons(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->resetWeapons();
	return true;
}

OMPRS_API(bool, SetPlayerAmmo(int playerid, uint8_t id, uint32_t ammo))
{
	GET_PLAYER_CHECKED(player, playerid, false);

	WeaponSlotData data;
	data.id = id;
	data.ammo = ammo;

	player->setWeaponAmmo(data);

	return true;
}

OMPRS_API(bool, SetPlayerArmedWeapon(int playerid, int weapon))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setArmedWeapon(weapon);
	return true;
}

OMPRS_API(bool, SetPlayerChatBubble(int playerid, char const* text, int colour, float drawdistance, int expiretime))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setChatBubble(text, Colour::FromRGBA(colour), drawdistance, std::chrono::milliseconds(expiretime));
	return true;
}

OMPRS_API(bool, SetPlayerPosFindZ(int playerid, float x, float y, float z))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setPositionFindZ(Vector3(x, y, z));
	return true;
}

OMPRS_API(bool, SetPlayerSkillLevel(int playerid, int weapon, int level))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setSkillLevel(PlayerWeaponSkill(weapon), level);
	return true;
}

OMPRS_API(bool, SetPlayerSpecialAction(int playerid, uint32_t action))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setAction(PlayerSpecialAction(action));
	return true;
}

OMPRS_API(bool, ShowPlayerNameTagForPlayer(int playerid, int otherid, bool enable))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	GET_PLAYER_CHECKED(other, otherid, false);
	player->toggleOtherNameTag(*other, enable);
	return true;
}

OMPRS_API(bool, TogglePlayerControllable(int playerid, bool enable))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setControllable(enable);
	return true;
}

OMPRS_API(bool, TogglePlayerSpectating(int playerid, bool enable))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setSpectating(enable);
	return true;
}

OMPRS_API(bool, ApplyAnimation(int playerid, const char* animlib, const char* animname, float delta, bool loop, bool lockX, bool lockY, bool freeze, int time, int sync))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	const AnimationData animationData(delta, loop, lockX, lockY, freeze, time, animlib, animname);
	player->applyAnimation(animationData, PlayerAnimationSyncType(sync));
	return true;
}

OMPRS_API(bool, GetAnimationName(int index, char* lib, char* name))
{
	Pair<StringView, StringView> anim = splitAnimationNames(index);
	anim.first.copy(lib, anim.first.length());
	anim.second.copy(name, anim.second.length());
	return true;
}

OMPRS_API(bool, EditAttachedObject(int playerid, int index))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	IPlayerObjectData* data = queryExtension<IPlayerObjectData>(player);
	data->editAttachedObject(index);
	return true;
}

OMPRS_API(bool, EnablePlayerCameraTarget(int playerid, bool enable))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->useCameraTargeting(enable);
	return true;
}

OMPRS_API(bool, EnableStuntBonusForPlayer(int playerid, bool enable))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->useStuntBonuses(enable);
	return true;
}

OMPRS_API(bool, EnableStuntBonusForAll(bool enable))
{
	OMPRSComponent::Get()->GetCore()->useStuntBonuses(enable);
	return true;
}

OMPRS_API(int, GetPlayerAmmo(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, 0);
	return player->getArmedWeaponAmmo();
}

OMPRS_API(int, GetPlayerAnimationIndex(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, 0);
	return player->getAnimationData().ID;
}

OMPRS_API(bool, GetPlayerFacingAngle(int playerid, float& angle))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	GTAQuat quat = player->getRotation();
	angle = quat.ToEuler().z;
	return true;
}

OMPRS_API(int, GetPlayerIp(int playerid, char* ip))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	PeerNetworkData data = player->getNetworkData();

	if (!data.networkID.address.ipv6)
	{
		PeerAddress::AddressString addressString;
		if (PeerAddress::ToString(data.networkID.address, addressString))
		{
			auto addressView = StringView(addressString);
			addressView.copy(ip, addressView.length());
			return addressView.length();
		}
	}

	return -1;
}

OMPRS_API(int, GetPlayerSpecialAction(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	return player->getAction();
}

OMPRS_API(int, GetPlayerVehicleID(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, INVALID_VEHICLE_ID);
	IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(player);
	IVehicle* vehicle = data->getVehicle();

	if (vehicle)
	{
		return vehicle->getID();
	}

	return 0;
}

OMPRS_API(int, GetPlayerVehicleSeat(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, SEAT_NONE);
	IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(player);
	return data->getSeat();
}

OMPRS_API(bool, GetPlayerWeaponData(int playerid, int slot, int* weaponid, int* ammo))
{
	GET_PLAYER_CHECKED(player, playerid, false);

	if (slot < 0 || slot >= MAX_WEAPON_SLOTS)
	{
		return false;
	}

	const WeaponSlotData& weapon = player->getWeaponSlot(slot);
	*weaponid = weapon.id;
	*ammo = weapon.ammo;

	return true;
}

OMPRS_API(int, GetPlayerWeaponState(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, 0);
	return player->getAimData().weaponState;
}

OMPRS_API(bool, InterpolateCameraPos(int playerid, float FromX, float FromY, float FromZ, float ToX, float ToY, float ToZ, int time, int cut))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->interpolateCameraPosition(Vector3(FromX, FromY, FromZ), Vector3(ToX, ToY, ToZ), time, PlayerCameraCutType(cut));
	return true;
}

OMPRS_API(bool, InterpolateCameraLookAt(int playerid, float FromX, float FromY, float FromZ, float ToX, float ToY, float ToZ, int time, int cut))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->interpolateCameraLookAt(Vector3(FromX, FromY, FromZ), Vector3(ToX, ToY, ToZ), time, PlayerCameraCutType(cut));
	return true;
}

OMPRS_API(bool, IsPlayerAttachedObjectSlotUsed(int playerid, int index))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	IPlayerObjectData* data = queryExtension<IPlayerObjectData>(player);
	return data->hasAttachedObject(index);
}

OMPRS_API(bool, AttachCameraToObject(int playerid, int objectid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	GET_ENTITY_CHECKED(object, IObject, objectid, false);
	player->attachCameraToObject(*object);
	return true;
}

OMPRS_API(bool, AttachCameraToPlayerObject(int playerid, int objectid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	GET_ENTITY_CHECKED(object, IObject, objectid, false);
	player->attachCameraToObject(*object);
	return true;
}

OMPRS_API(float, GetPlayerCameraAspectRatio(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, 0.0);
	return player->getAimData().aspectRatio;
}

OMPRS_API(bool, GetPlayerCameraFrontVector(int playerid, float* x, float* y, float* z))
{
	GET_PLAYER_CHECKED(player, playerid, false);

	auto vector = player->getAimData().camFrontVector;
	*x = vector.x;
	*y = vector.y;
	*z = vector.z;

	return true;
}

OMPRS_API(int, GetPlayerCameraMode(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	return player->getAimData().camMode;
}

OMPRS_API(bool, GetPlayerKeys(int playerid, int* keys, int* updown, int* leftright))
{
	GET_PLAYER_CHECKED(player, playerid, false);

	const PlayerKeyData& keyData = player->getKeyData();
	*keys = keyData.keys;
	*updown = keyData.upDown;
	*leftright = keyData.leftRight;

	return true;
}

OMPRS_API(int, GetPlayerSurfingVehicleID(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, INVALID_VEHICLE_ID);
	PlayerSurfingData data = player->getSurfingData();

	if (player->getState() == PlayerState_OnFoot && data.type == PlayerSurfingData::Type::Vehicle)
	{
		IVehiclesComponent* vehicles = OMPRSComponent::Get()->GetVehicles();
		if (vehicles && vehicles->get(data.ID))
		{
			return data.ID;
		}
	}

	return INVALID_VEHICLE_ID;
}

OMPRS_API(int, GetPlayerSurfingObjectID(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, INVALID_OBJECT_ID);
	PlayerSurfingData data = player->getSurfingData();

	if (player->getState() == PlayerState_OnFoot && data.type == PlayerSurfingData::Type::Object)
	{
		IObjectsComponent* objects = OMPRSComponent::Get()->GetObjects();
		if (objects && objects->get(data.ID))
		{
			return data.ID;
		}
	}

	return INVALID_OBJECT_ID;
}

OMPRS_API(int, GetPlayerTargetPlayer(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, INVALID_PLAYER_ID);
	IPlayer* target = player->getTargetPlayer();

	if (target)
	{
		return target->getID();
	}

	return INVALID_PLAYER_ID;
}

OMPRS_API(int, GetPlayerTargetActor(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, INVALID_PLAYER_ID);
	IActor* target = player->getTargetActor();

	if (target)
	{
		return target->getID();
	}

	return INVALID_PLAYER_ID;
}

OMPRS_API(bool, IsPlayerInVehicle(int playerid, int vehicleid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	GET_ENTITY_CHECKED(targetVehicle, IVehicle, vehicleid, false);

	IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(player);
	IVehicle* vehicle = data->getVehicle();

	return vehicle == targetVehicle;
}

OMPRS_API(bool, IsPlayerInAnyVehicle(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(player);
	return data->getVehicle() != nullptr;
}

OMPRS_API(bool, IsPlayerInRangeOfPoint(int playerid, float range, float x, float y, float z))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	return range >= glm::distance(player->getPosition(), Vector3(x, y, z));
}

OMPRS_API(bool, PlayCrimeReportForPlayer(int playerid, int suspectid, int crime))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	GET_PLAYER_CHECKED(suspect, suspectid, false);
	return player->playerCrimeReport(*suspect, crime);
}

OMPRS_API(bool, RemovePlayerAttachedObject(int playerid, int index))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	IPlayerObjectData* data = queryExtension<IPlayerObjectData>(player);
	data->removeAttachedObject(index);
	return true;
}

OMPRS_API(bool, SetPlayerAttachedObject(int playerid, int index, int modelid, int bone, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ, float fScaleX, float fScaleY, float fScaleZ, uint32_t materialcolor1, uint32_t materialcolor2))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	IPlayerObjectData* data = queryExtension<IPlayerObjectData>(player);

	ObjectAttachmentSlotData attachment;
	attachment.model = modelid;
	attachment.bone = bone;
	attachment.offset = Vector3(fOffsetX, fOffsetY, fOffsetZ);
	attachment.rotation = Vector3(fRotX, fRotY, fRotZ);
	attachment.scale = Vector3(fScaleX, fScaleY, fScaleZ);
	attachment.colour1 = Colour::FromARGB(materialcolor1);
	attachment.colour2 = Colour::FromARGB(materialcolor2);

	data->setAttachedObject(index, attachment);

	return true;
}

OMPRS_API(bool, GetPlayerAttachedObject(int playerid, int index, int* modelid, int* bone, float* fOffsetX, float* fOffsetY, float* fOffsetZ, float* fRotX, float* fRotY, float* fRotZ, float* fScaleX, float* fScaleY, float* fScaleZ, int* materialcolor1, int* materialcolor2))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	IPlayerObjectData* data = queryExtension<IPlayerObjectData>(player);
	ObjectAttachmentSlotData attachment = data->getAttachedObject(index);

	*modelid = attachment.model;
	*bone = attachment.bone;

	*fOffsetX = attachment.offset.x;
	*fOffsetY = attachment.offset.y;
	*fOffsetZ = attachment.offset.z;

	*fRotX = attachment.rotation.x;
	*fRotY = attachment.rotation.y;
	*fRotZ = attachment.rotation.z;

	*fScaleX = attachment.scale.x;
	*fScaleY = attachment.scale.y;
	*fScaleZ = attachment.scale.z;

	*materialcolor1 = attachment.colour1.ARGB();
	*materialcolor2 = attachment.colour2.ARGB();

	return true;
}

OMPRS_API(bool, SetPlayerFacingAngle(int playerid, float angle))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	Vector3 rotation = player->getRotation().ToEuler();
	rotation.z = angle;
	player->setRotation(rotation);
	return true;
}

OMPRS_API(bool, SetPlayerMarkerForPlayer(int playerid, int otherid, int colour))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	GET_PLAYER_CHECKED(other, otherid, false);
	player->setOtherColour(*other, Colour::FromRGBA(colour));
	return true;
}

OMPRS_API(int, GetPlayerMarkerForPlayer(int playerid, int otherid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	GET_PLAYER_CHECKED(other, otherid, false);
	Colour colour;
	bool hasPlayerSpecificColour = player->getOtherColour(*other, colour);

	if (!hasPlayerSpecificColour)
	{
		colour = other->getColour();
	}

	return colour.RGBA();
}

OMPRS_API(bool, AllowPlayerTeleport(int playerid, bool allow))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->allowTeleport(allow);
	return true;
}

OMPRS_API(bool, IsPlayerTeleportAllowed(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	return player->isTeleportAllowed();
}

OMPRS_API(bool, DisableRemoteVehicleCollisions(int playerid, bool disable))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setRemoteVehicleCollisions(!disable);
	return true;
}

OMPRS_API(float, GetPlayerCameraZoom(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	return player->getAimData().camZoom;
}

OMPRS_API(bool, SelectTextDraw(int playerid, uint32_t hoverColour))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	IPlayerTextDrawData* data = queryExtension<IPlayerTextDrawData>(player);
	data->beginSelection(Colour::FromRGBA(hoverColour));
	return true;
}

OMPRS_API(bool, CancelSelectTextDraw(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	IPlayerTextDrawData* data = queryExtension<IPlayerTextDrawData>(player);
	data->endSelection();
	return true;
}

OMPRS_API(bool, SendClientCheck(int playerid, int actionType, int address, int offset, int count))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->sendClientCheck(actionType, address, offset, count);
	return true;
}

OMPRS_API(bool, SpawnPlayer(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->spawn();
	return true;
}

OMPRS_API(int, gpci(int playerid, char* output))
{
	GET_PLAYER_CHECKED(player, playerid, false);

	auto serial = player->getSerial();
	serial.copy(output, serial.length());

	return serial.length();
}

OMPRS_API(bool, IsPlayerAdmin(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	IPlayerConsoleData* data = queryExtension<IPlayerConsoleData>(player);
	return data->hasConsoleAccess();
}

OMPRS_API(bool, Kick(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->kick();
	return true;
}

OMPRS_API(bool, GameTextForPlayer(int playerid, char const* msg, int time, int style))
{
	GET_PLAYER_CHECKED(player, playerid, false);

	auto string = std::string(msg);
	if (string.empty())
	{
		return false;
	}

	player->sendGameText(string, Milliseconds(time), style);

	return true;
}

OMPRS_API(bool, HideGameTextForPlayer(int playerid, int style))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->hideGameText(style);
	return true;
}

OMPRS_API(bool, HasGameText(int playerid, int style))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	return player->hasGameText(style);
}

OMPRS_API(bool, GetGameText(int playerid, int style, char* message, int time, int remaining))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	Milliseconds mt;
	Milliseconds mr;
	StringView ms;

	if (player->getGameText(style, ms, mt, mr))
	{
		ms.copy(message, ms.length());
		time = (int)mt.count();
		remaining = (int)mr.count();
		return true;
	}

	return false;
}

OMPRS_API(bool, Ban(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->ban();
	return true;
}

OMPRS_API(bool, BanEx(int playerid, char const* msg))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->ban(msg);
	return true;
}

OMPRS_API(bool, SendDeathMessageToPlayer(int playerid, int killerid, int killeeid, int weapon))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	GET_PLAYER_CHECKED(killer, killerid, false);
	auto killee = OMPRSComponent::Get()->GetPlayer(killeeid);

	if (killee != nullptr)
	{
		player->sendDeathMessage(*killee, killer, weapon);
	}
	else
	{
		player->sendEmptyDeathMessage();
	}

	return true;
}

OMPRS_API(bool, SendPlayerMessageToPlayer(int playerid, int senderid, const char* message))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	GET_PLAYER_CHECKED(sender, senderid, false);
	player->sendChatMessage(*sender, message);
	return true;
}

OMPRS_API(bool, SendPlayerMessageToPlayerf(int playerid, int senderid, const char* message))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	GET_PLAYER_CHECKED(sender, senderid, false);
	player->sendChatMessage(*sender, message);
	return true;
}

OMPRS_API(int, GetPlayerVersion(int playerid, char* version))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	auto player_version = player->getClientVersionName();
	player_version.copy(version, player_version.length());
	return player_version.length();
}

OMPRS_API(int, GetPlayerSkillLevel(int playerid, int skill))
{
	GET_PLAYER_CHECKED(player, playerid, 0);
	auto& skills = player->getSkillLevels();

	if (skill >= 11 || skill < 0)
	{
		return 0;
	}

	return skills[skill];
}

OMPRS_API(float, GetPlayerZAim(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	return player->getAimData().aimZ;
}

OMPRS_API(bool, GetPlayerSurfingOffsets(int playerid, float* x, float* y, float* z))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	const PlayerSurfingData& data = player->getSurfingData();

	if (data.type != PlayerSurfingData::Type::None)
	{
		*x = data.offset.x;
		*y = data.offset.y;
		*z = data.offset.z;
	}

	return true;
}

OMPRS_API(bool, GetPlayerRotationQuat(int playerid, float* w, float* x, float* y, float* z))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	glm::quat rotQuat = player->getRotation().q;

	*w = rotQuat.w;
	*x = rotQuat.x;
	*y = rotQuat.y;
	*z = rotQuat.z;

	return true;
}

OMPRS_API(int, GetPlayerSpectateID(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, INVALID_PLAYER_ID);
	return player->getSpectateData().spectateID;
}

OMPRS_API(int, GetPlayerSpectateType(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, INVALID_PLAYER_ID);
	return int(player->getSpectateData().type);
}

OMPRS_API(int, GetPlayerRawIp(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, 0);
	return player->getNetworkData().networkID.address.v4;
}

OMPRS_API(bool, SetPlayerGravity(int playerid, float gravity))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->setGravity(gravity);
	return true;
}

OMPRS_API(float, GetPlayerGravity(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, 0.0);
	return player->getGravity();
}

OMPRS_API(bool, SetPlayerAdmin(int playerid, bool set))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	IPlayerConsoleData* data = queryExtension<IPlayerConsoleData>(player);
	data->setConsoleAccessibility(set);
	return true;
}

OMPRS_API(bool, IsPlayerSpawned(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	PlayerState state = player->getState();

	switch (state)
	{
	case PlayerState_OnFoot:
	case PlayerState_Driver:
	case PlayerState_Passenger:
	case PlayerState_Spawned:
	{
		return true;
	}
	default:
		return false;
	}
}

OMPRS_API(bool, IsPlayerControllable(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	return player->getControllable();
}

OMPRS_API(bool, IsPlayerCameraTargetEnabled(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	return player->hasCameraTargeting();
}

OMPRS_API(bool, TogglePlayerGhostMode(int playerid, bool toggle))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->toggleGhostMode(toggle);
	return true;
}

OMPRS_API(bool, GetPlayerGhostMode(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	return player->isGhostModeEnabled();
}

OMPRS_API(bool, AllowPlayerWeapons(int playerid, bool allow))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	player->allowWeapons(allow);
	return true;
}

OMPRS_API(bool, ArePlayerWeaponsAllowed(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	return player->areWeaponsAllowed();
}

OMPRS_API(int, IsPlayerUsingOfficialClient(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	return player->isUsingOfficialClient();
}

OMPRS_API(int, GetPlayerAnimFlags(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);
	PlayerAnimationData data = player->getAnimationData();
	return data.flags;
}

OMPRS_API(int, GetPlayerAnimationFlags(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, -1);

	return player->getAnimationData().flags;
}

OMPRS_API(bool, IsPlayerInDriveByMode(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(player);
	return data->isInDriveByMode();
}

OMPRS_API(bool, IsPlayerCuffed(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, false);
	if (player->getState() == PlayerState_OnFoot)
	{
		return player->getAction() == SpecialAction_Cuffed;
	}
	else if (player->getState() == PlayerState_Passenger)
	{
		IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(player);
		if (data)
		{
			return data->isCuffed();
		}
	}
	return false;
}