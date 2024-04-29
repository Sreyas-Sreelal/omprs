#pragma once

#include "../api.hpp"

OMPRS_API(void, SendClientMessage(void* player, Colour colour, StringView message))
{
	static_cast<IPlayer*>(player)->sendClientMessage(colour, message);
}

OMPRS_API(int, GetPlayerName(void* player, StringView* name))
{
	*name = static_cast<IPlayer*>(player)->getName();
	auto length = name->length();
	return length;
}

OMPRS_API(void, SendClientMessageToAll(Colour colour, StringView message))
{
	OMPRSComponent::Get()->GetPlayers()->sendClientMessageToAll(colour, message);
}

OMPRS_API(void, SetPlayerCameraPos(void* player, Vector3 pos))
{
	static_cast<IPlayer*>(player)->setCameraPosition(pos);
}

OMPRS_API(void, SetPlayerDrunkLevel(void* player, int level))
{
	static_cast<IPlayer*>(player)->setDrunkLevel(level);
}

OMPRS_API(void, SetPlayerInterior(void* player, int interiorid))
{
	static_cast<IPlayer*>(player)->setInterior(interiorid);
}

OMPRS_API(void, SetPlayerWantedLevel(void* player, int level))
{
	static_cast<IPlayer*>(player)->setWantedLevel(level);
}

OMPRS_API(void, SetPlayerWeather(void* player, int weatherid))
{
	static_cast<IPlayer*>(player)->setWeather(weatherid);
}

OMPRS_API(int, GetPlayerWeather(void* player))
{
	return static_cast<IPlayer*>(player)->getWeather();
}

OMPRS_API(void, SetPlayerSkin(void* player, int skinid))
{
	static_cast<IPlayer*>(player)->setSkin(skinid);
}

OMPRS_API(void, SetPlayerShopName(void* player, StringView shopname))
{
	static_cast<IPlayer*>(player)->setShopName(shopname);
}

OMPRS_API(void, GivePlayerMoney(void* player, int amount))
{
	static_cast<IPlayer*>(player)->giveMoney(amount);
}

OMPRS_API(void, SetPlayerCameraLookAt(void* player,Vector3 pos, int cut))
{
	static_cast<IPlayer*>(player)->setCameraLookAt(pos, cut);
}

OMPRS_API(void, SetCameraBehindPlayer(void* player))
{
	static_cast<IPlayer*>(player)->setCameraBehind();
}

OMPRS_API(void, CreateExplosionForPlayer(void* player, Vector3 pos, int type, float radius))
{
	static_cast<IPlayer*>(player)->createExplosion(pos, type, radius);
}

OMPRS_API(void, CreateExplosion(Vector3 pos, int type, float radius))
{
	OMPRSComponent::Get()->GetPlayers()->createExplosionForAll(pos, type, radius);
}

OMPRS_API(void, PlayAudioStreamForPlayer(void* player, StringView url,Vector3 pos, float distance, bool usePos))
{
	static_cast<IPlayer*>(player)->playAudio(url, usePos, pos, distance);
}

OMPRS_API(void, StopAudioStreamForPlayer(void* player))
{
	static_cast<IPlayer*>(player)->stopAudio();
}

OMPRS_API(void, SendDeathMessage(void* killer, void* killee, int weapon))
{
	if (killee)
	{
		OMPRSComponent::Get()->GetPlayers()->sendDeathMessageToAll(static_cast<IPlayer*>(killer), *static_cast<IPlayer*>(killee), weapon);
	}
	else
	{
		OMPRSComponent::Get()->GetPlayers()->sendEmptyDeathMessageToAll();
	}
}

OMPRS_API(void, TogglePlayerWidescreen(void* player, bool enable))
{
	static_cast<IPlayer*>(player)->useWidescreen(enable);
}

OMPRS_API(bool, IsPlayerWidescreenToggled(void* player))
{
	return static_cast<IPlayer*>(player)->hasWidescreen();
}

OMPRS_API(void, SetPlayerHealth(void* player, float health))
{
	static_cast<IPlayer*>(player)->setHealth(health);
}

OMPRS_API(float, GetPlayerHealth(void* player))
{
	return static_cast<IPlayer*>(player)->getHealth();
}

OMPRS_API(void, SetPlayerArmour(void* player, float armour))
{
	static_cast<IPlayer*>(player)->setArmour(armour);
}

OMPRS_API(float, GetPlayerArmour(void* player))
{
	return static_cast<IPlayer*>(player)->getArmour();
}

OMPRS_API(void, SetPlayerTeam(void* player, int teamid))
{
	static_cast<IPlayer*>(player)->setTeam(teamid);
}

OMPRS_API(int, GetPlayerTeam(void* player))
{
	return static_cast<IPlayer*>(player)->getTeam();
}

OMPRS_API(void, SetPlayerScore(void* player, int score))
{
	static_cast<IPlayer*>(player)->setScore(score);
}

OMPRS_API(int, GetPlayerScore(void* player))
{
	return static_cast<IPlayer*>(player)->getScore();
}

OMPRS_API(int, GetPlayerSkin(void* player))
{
	return static_cast<IPlayer*>(player)->getSkin();
}

OMPRS_API(void, SetPlayerColor(void* player, Colour colour))
{
	static_cast<IPlayer*>(player)->setColour(colour);
}

OMPRS_API(int, GetPlayerColor(void* player))
{
	return static_cast<IPlayer*>(player)->getColour().RGBA();
}

OMPRS_API(int, GetDefaultPlayerColour(void* player))
{
	return OMPRSComponent::Get()->GetPlayers()->getDefaultColour(static_cast<IPlayer*>(player)->getID()).RGBA();
}

OMPRS_API(int, GetPlayerDrunkLevel(void* player))
{
	return static_cast<IPlayer*>(player)->getDrunkLevel();
}

OMPRS_API(void, GivePlayerWeapon(void* player, WeaponSlotData data))
{
	static_cast<IPlayer*>(player)->giveWeapon(data);
}

OMPRS_API(void, RemovePlayerWeapon(void* player, uint8_t weaponid))
{
	static_cast<IPlayer*>(player)->removeWeapon(weaponid);
}

OMPRS_API(int, GetPlayerMoney(void* player))
{
	return static_cast<IPlayer*>(player)->getMoney();
}

OMPRS_API(void, ResetPlayerMoney(void* player))
{
	static_cast<IPlayer*>(player)->resetMoney();
}

OMPRS_API(EPlayerNameStatus, SetPlayerName(void* player, StringView name))
{
	return static_cast<IPlayer*>(player)->setName(name);
}

OMPRS_API(PlayerState, GetPlayerState(void* player))
{
	return static_cast<IPlayer*>(player)->getState();
}

OMPRS_API(int, GetPlayerPing(void* player))
{
	return static_cast<IPlayer*>(player)->getPing();
}

OMPRS_API(int, GetPlayerWeapon(void* player))
{
	return static_cast<IPlayer*>(player)->getArmedWeapon();
}

OMPRS_API(void, SetPlayerTime(void* player, int hour, int minute))
{
	static_cast<IPlayer*>(player)->setTime(std::chrono::hours(hour), std::chrono::minutes(minute));
}

OMPRS_API(void, GetPlayerTime(void* player, int* hour, int* minute))
{
	std::pair<std::chrono::hours, std::chrono::minutes> data = static_cast<IPlayer*>(player)->getTime();
	*hour = data.first.count();
	*minute = data.second.count();
}

OMPRS_API(void, TogglePlayerClock(void* player, bool enable))
{
	static_cast<IPlayer*>(player)->useClock(enable);
}

OMPRS_API(bool, PlayerHasClockEnabled(void* player))
{
	return static_cast<IPlayer*>(player)->hasClock();
}

OMPRS_API(void, ForceClassSelection(void* player))
{
	static_cast<IPlayer*>(player)->forceClassSelection();
}

OMPRS_API(int, GetPlayerWantedLevel(void* player))
{
	return static_cast<IPlayer*>(player)->getWantedLevel();
}

OMPRS_API(void, SetPlayerFightingStyle(void* player, PlayerFightingStyle style))
{
	static_cast<IPlayer*>(player)->setFightingStyle(style);
}

OMPRS_API(PlayerFightingStyle, GetPlayerFightingStyle(void* player))
{
	return static_cast<IPlayer*>(player)->getFightingStyle();
}

OMPRS_API(void, SetPlayerVelocity(void* player,Vector3 pos))
{
	static_cast<IPlayer*>(player)->setVelocity(pos);
}

OMPRS_API(void, GetPlayerVelocity(void* player,Vector3* pos))
{
	*pos = static_cast<IPlayer*>(player)->getVelocity();
}

OMPRS_API(void, GetPlayerCameraPos(void* player,Vector3* pos))
{
	*pos =  static_cast<IPlayer*>(player)->getAimData().camPos;
}

OMPRS_API(float, GetPlayerDistanceFromPoint(void* player, Vector3 pos))
{
	Vector3 playerCoords = static_cast<IPlayer*>(player)->getPosition();
	return glm::distance(playerCoords, pos);
}

OMPRS_API(int, GetPlayerInterior(void* player))
{
	return static_cast<IPlayer*>(player)->getInterior();
}

OMPRS_API(void, SetPlayerPos(void* player, Vector3 pos))
{
	static_cast<IPlayer*>(player)->setPosition(pos);
}

OMPRS_API(void, GetPlayerPos(void* player,Vector3* pos))
{
	*pos =  static_cast<IPlayer*>(player)->getPosition();
}

OMPRS_API(int, GetPlayerVirtualWorld(void* player))
{
	return static_cast<IPlayer*>(player)->getVirtualWorld();
}

OMPRS_API(bool, IsPlayerNPC(void* player))
{
	return static_cast<IPlayer*>(player)->isBot();
}

OMPRS_API(bool, IsPlayerStreamedIn(void* player, void* other))
{
	return static_cast<IPlayer*>(player)->isStreamedInForPlayer(*static_cast<IPlayer*>(other));
}

OMPRS_API(void, PlayerPlaySound(void* player, uint32_t sound, Vector3 pos))
{
	static_cast<IPlayer*>(player)->playSound(sound, pos);
}

OMPRS_API(void, PlayerSpectatePlayer(void* player, void* target, PlayerSpectateMode mode))
{
	static_cast<IPlayer*>(player)->spectatePlayer(*static_cast<IPlayer*>(target), mode);
}

OMPRS_API(void, PlayerSpectateVehicle(void* player, void* vehicle, PlayerSpectateMode mode))
{
	static_cast<IPlayer*>(player)->spectateVehicle(*static_cast<IVehicle*>(vehicle), mode);
}

OMPRS_API(void, SetPlayerVirtualWorld(void* player, int vw))
{
	static_cast<IPlayer*>(player)->setVirtualWorld(vw);
}

OMPRS_API(void, SetPlayerWorldBounds(void* player, Vector4 coords))
{
	static_cast<IPlayer*>(player)->setWorldBounds(coords);
}

OMPRS_API(void, ClearPlayerWorldBounds(void* player))
{
	static_cast<IPlayer*>(player)->setWorldBounds(Vector4(MAX_WORLD_BOUNDS, MIN_WORLD_BOUNDS, MAX_WORLD_BOUNDS, MIN_WORLD_BOUNDS));
}

OMPRS_API(void,GetPlayerWorldBounds(void* player,Vector4* pos))
{
	*pos =  static_cast<IPlayer*>(player)->getWorldBounds();
}

OMPRS_API(void, ClearAnimations(void* player, PlayerAnimationSyncType syncType))
{
	static_cast<IPlayer*>(player)->clearTasks(syncType);
}

OMPRS_API(PlayerBulletData, GetPlayerLastShotVectors(void* player))
{
	return static_cast<IPlayer*>(player)->getBulletData();
}

OMPRS_API(void*, GetPlayerCameraTargetPlayer(void* player))
{
	return static_cast<IPlayer*>(player)->getCameraTargetPlayer();
}

OMPRS_API(void*, GetPlayerCameraTargetActor(void* player))
{
	return static_cast<IPlayer*>(player)->getCameraTargetActor();
}

OMPRS_API(void*, GetPlayerCameraTargetObject(void* player))
{
	return static_cast<IPlayer*>(player)->getCameraTargetObject();	
}

OMPRS_API(void*, GetPlayerCameraTargetVehicle(void* player))
{
	return static_cast<IPlayer*>(player)->getCameraTargetVehicle();
}

OMPRS_API(void, PutPlayerInVehicle(void* player, void* vehicle, int seatID))
{
	static_cast<IVehicle*>(vehicle)->putPlayer(*static_cast<IPlayer*>(player), seatID);
}

OMPRS_API(void, RemoveBuildingForPlayer(void* player, int model,Vector3 pos, float radius))
{
	static_cast<IPlayer*>(player)->removeDefaultObjects(model, pos, radius);
}

OMPRS_API(int, GetPlayerBuildingsRemoved(void* player))
{
	return static_cast<IPlayer*>(player)->getDefaultObjectsRemoved();
}

OMPRS_API(void, RemovePlayerFromVehicle(void* player, bool force))
{
	static_cast<IPlayer*>(player)->removeFromVehicle(force);
}

OMPRS_API(void, RemovePlayerMapIcon(void* player, int iconID))
{
	static_cast<IPlayer*>(player)->unsetMapIcon(iconID);
}

OMPRS_API(void, SetPlayerMapIcon(void* player, int iconID, Vector3 pos, int type, Colour colour, MapIconStyle style))
{
	static_cast<IPlayer*>(player)->setMapIcon(iconID, pos, type,colour, style);
}

OMPRS_API(void, ResetPlayerWeapons(void* player))
{
	static_cast<IPlayer*>(player)->resetWeapons();
}

OMPRS_API(void, SetPlayerAmmo(void* player, WeaponSlotData data))
{
	static_cast<IPlayer*>(player)->setWeaponAmmo(data);
}

OMPRS_API(void, SetPlayerArmedWeapon(void* player, int weapon))
{
	static_cast<IPlayer*>(player)->setArmedWeapon(weapon);
}

OMPRS_API(void, SetPlayerChatBubble(void* player, StringView text, Colour colour, float drawdistance, int expiretime))
{
	static_cast<IPlayer*>(player)->setChatBubble(text, colour, drawdistance, std::chrono::milliseconds(expiretime));
}

OMPRS_API(void, SetPlayerPosFindZ(void* player, Vector3 pos))
{
	static_cast<IPlayer*>(player)->setPositionFindZ(pos);
}

OMPRS_API(void, SetPlayerSkillLevel(void* player, PlayerWeaponSkill weapon, int level))
{
	static_cast<IPlayer*>(player)->setSkillLevel(weapon, level);
}

OMPRS_API(void, SetPlayerSpecialAction(void* player, PlayerSpecialAction action))
{
	static_cast<IPlayer*>(player)->setAction(action);
}

OMPRS_API(void, ShowPlayerNameTagForPlayer(void* player, void* other, bool enable))
{
	static_cast<IPlayer*>(player)->toggleOtherNameTag(*static_cast<IPlayer*>(other), enable);
}

OMPRS_API(void, TogglePlayerControllable(void* player, bool enable))
{
	static_cast<IPlayer*>(player)->setControllable(enable);
}

OMPRS_API(void, TogglePlayerSpectating(void* player, bool enable))
{
	static_cast<IPlayer*>(player)->setSpectating(enable);
}

OMPRS_API(void, ApplyAnimation(void* player, StringView animlib, StringView animname, float delta, bool loop, bool lockX, bool lockY, bool freeze, uint32_t time, PlayerAnimationSyncType sync))
{
	const AnimationData animationData(delta, loop, lockX, lockY, freeze, time, animlib, animname);
	static_cast<IPlayer*>(player)->applyAnimation(animationData, PlayerAnimationSyncType(sync));
}

OMPRS_API(void, GetAnimationName(int index, StringView* lib, StringView* name))
{
	Pair<StringView, StringView> anim = splitAnimationNames(index);
	*lib = anim.first;
	*name = anim.second;
}

OMPRS_API(void, EditAttachedObject(void* player, int index))
{
	IPlayerObjectData* data = queryExtension<IPlayerObjectData>(static_cast<IPlayer*>(player));
	data->editAttachedObject(index);
}

OMPRS_API(void, EnablePlayerCameraTarget(void* player, bool enable))
{
	static_cast<IPlayer*>(player)->useCameraTargeting(enable);
}

OMPRS_API(void, EnableStuntBonusForPlayer(void* player, bool enable))
{
	static_cast<IPlayer*>(player)->useStuntBonuses(enable);
}

OMPRS_API(void, EnableStuntBonusForAll(bool enable))
{
	OMPRSComponent::Get()->GetCore()->useStuntBonuses(enable);
}

OMPRS_API(int, GetPlayerAmmo(void* player))
{
	return static_cast<IPlayer*>(player)->getArmedWeaponAmmo();
}

OMPRS_API(int, GetPlayerAnimationIndex(void* player))
{
	return static_cast<IPlayer*>(player)->getAnimationData().ID;
}

OMPRS_API(float, GetPlayerFacingAngle(void* player))
{
	GTAQuat quat = static_cast<IPlayer*>(player)->getRotation();
	return quat.ToEuler().z;
}

OMPRS_API(int, GetPlayerIp(void* player, StringView* ip))
{
	PeerNetworkData data = static_cast<IPlayer*>(player)->getNetworkData();

	if (!data.networkID.address.ipv6)
	{
		PeerAddress::AddressString addressString;
		if (PeerAddress::ToString(data.networkID.address, addressString))
		{
			auto addressView = StringView(addressString);
			*ip = addressView;
			return addressView.length();
		}
	}

	return -1;
}

OMPRS_API(PlayerSpecialAction, GetPlayerSpecialAction(void* player))
{
	return static_cast<IPlayer*>(player)->getAction();
}

OMPRS_API(int, GetPlayerVehicleID(void* player))
{
	IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(static_cast<IPlayer*>(player));
	IVehicle* vehicle = data->getVehicle();

	if (vehicle)
	{
		return vehicle->getID();
	}

	return 0;
}

OMPRS_API(int, GetPlayerVehicleSeat(void* player))
{
	IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(static_cast<IPlayer*>(player));
	return data->getSeat();
}

OMPRS_API(void, GetPlayerWeaponData(void* player, int slot, WeaponSlotData* weapon))
{
	*weapon = static_cast<IPlayer*>(player)->getWeaponSlot(slot);
}

OMPRS_API(int, GetPlayerWeaponState(void* player))
{
	return static_cast<IPlayer*>(player)->getAimData().weaponState;
}

OMPRS_API(void, InterpolateCameraPos(void* player, Vector3 from, Vector3 to, int time, PlayerCameraCutType cut))
{
	static_cast<IPlayer*>(player)->interpolateCameraPosition(from, to, time, cut);
}

OMPRS_API(bool, InterpolateCameraLookAt(void* player, Vector3 from, Vector3 to, int time, PlayerCameraCutType cut))
{
	static_cast<IPlayer*>(player)->interpolateCameraLookAt(from, to, time, cut);
	return true;
}

OMPRS_API(bool, IsPlayerAttachedObjectSlotUsed(void* player, int index))
{
	IPlayerObjectData* data = queryExtension<IPlayerObjectData>(static_cast<IPlayer*>(player));
	return data->hasAttachedObject(index);
}

OMPRS_API(void, AttachCameraToObject(void* player, void* object))
{
	static_cast<IPlayer*>(player)->attachCameraToObject(*static_cast<IObject*>(object));
}

OMPRS_API(void, AttachCameraToPlayerObject(void* player, void* object))
{
	static_cast<IPlayer*>(player)->attachCameraToObject(*static_cast<IPlayerObject*>(object));
}

OMPRS_API(PlayerAimData, GetPlayerAimData(void* player))
{
	return static_cast<IPlayer*>(player)->getAimData();
}

OMPRS_API(PlayerKeyData, GetPlayerKeys(void* player, int* keys, int* updown, int* leftright))
{
	return static_cast<IPlayer*>(player)->getKeyData();
}

OMPRS_API(PlayerSurfingData, GetPlayerSurfingData(void* player))
{
	return static_cast<IPlayer*>(player)->getSurfingData();
}

OMPRS_API(void*, GetPlayerTargetPlayer(void* player))
{
	return static_cast<IPlayer*>(player)->getTargetPlayer();
}

OMPRS_API(void*, GetPlayerTargetActor(void* player))
{
	return static_cast<IPlayer*>(player)->getTargetActor();
}

OMPRS_API(bool, IsPlayerInVehicle(void* player, void* targetVehicle))
{
	IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(static_cast<IPlayer*>(player));
	IVehicle* vehicle = data->getVehicle();
	return vehicle == targetVehicle;
}

OMPRS_API(bool, IsPlayerInAnyVehicle(void* player))
{
	IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(static_cast<IPlayer*>(player));
	return data->getVehicle() != nullptr;
}

OMPRS_API(bool, IsPlayerInRangeOfPoint(void* player, float range, Vector3 coord))
{
	return range >= glm::distance(static_cast<IPlayer*>(player)->getPosition(), coord);
}

OMPRS_API(bool, PlayCrimeReportForPlayer(void* player, void* suspect, int crime))
{
	return static_cast<IPlayer*>(player)->playerCrimeReport(*static_cast<IPlayer*>(suspect), crime);
}

OMPRS_API(void, RemovePlayerAttachedObject(void* player, int index))
{
	IPlayerObjectData* data = queryExtension<IPlayerObjectData>(static_cast<IPlayer*>(player));
	data->removeAttachedObject(index);
}

OMPRS_API(void, SetPlayerAttachedObject(void* player, int index, ObjectAttachmentSlotData attachment))
{
	IPlayerObjectData* data = queryExtension<IPlayerObjectData>(static_cast<IPlayer*>(player));
	data->setAttachedObject(index, attachment);
}

OMPRS_API(ObjectAttachmentSlotData, GetPlayerAttachedObject(void* player, int index))
{
	IPlayerObjectData* data = queryExtension<IPlayerObjectData>(static_cast<IPlayer*>(player));
	return data->getAttachedObject(index);
}

OMPRS_API(void, SetPlayerFacingAngle(void* player, float angle))
{
	Vector3 rotation = static_cast<IPlayer*>(player)->getRotation().ToEuler();
	rotation.z = angle;
	static_cast<IPlayer*>(player)->setRotation(rotation);
}

OMPRS_API(void, SetPlayerMarkerForPlayer(void* player, void* other, Colour colour))
{
	static_cast<IPlayer*>(player)->setOtherColour(*static_cast<IPlayer*>(other), colour);
}

OMPRS_API(int, GetPlayerMarkerForPlayer(void* player, void* other))
{
	Colour colour;
	bool hasPlayerSpecificColour = static_cast<IPlayer*>(player)->getOtherColour(*static_cast<IPlayer*>(other), colour);

	if (!hasPlayerSpecificColour)
	{
		colour = static_cast<IPlayer*>(other)->getColour();
	}

	return colour.RGBA();
}

OMPRS_API(void, AllowPlayerTeleport(void* player, bool allow))
{
	return static_cast<IPlayer*>(player)->allowTeleport(allow);
}

OMPRS_API(bool, IsPlayerTeleportAllowed(void* player))
{
	return static_cast<IPlayer*>(player)->isTeleportAllowed();
}

OMPRS_API(void, SetRemoteVehicleCollisions(void* player, bool collide))
{
	static_cast<IPlayer*>(player)->setRemoteVehicleCollisions(collide);
}

OMPRS_API(void, SelectTextDraw(void* player, Colour hoverColour))
{
	IPlayerTextDrawData* data = queryExtension<IPlayerTextDrawData>(static_cast<IPlayer*>(player));
	data->beginSelection(hoverColour);
}

OMPRS_API(void, CancelSelectTextDraw(void* player))
{
	IPlayerTextDrawData* data = queryExtension<IPlayerTextDrawData>(static_cast<IPlayer*>(player));
	data->endSelection();
}

OMPRS_API(void, SendClientCheck(void* player, int actionType, int address, int offset, int count))
{
	static_cast<IPlayer*>(player)->sendClientCheck(actionType, address, offset, count);
}

OMPRS_API(void, SpawnPlayer(void* player))
{
	static_cast<IPlayer*>(player)->spawn();
}

OMPRS_API(void, gpci(void* player, StringView* output))
{
	*output =  static_cast<IPlayer*>(player)->getSerial();
}

OMPRS_API(bool, IsPlayerAdmin(void* player))
{
	IPlayerConsoleData* data = queryExtension<IPlayerConsoleData>(static_cast<IPlayer*>(player));
	return data->hasConsoleAccess();
}

OMPRS_API(void, Kick(void* player))
{
	static_cast<IPlayer*>(player)->kick();
}

OMPRS_API(void, GameTextForPlayer(void* player, StringView msg, int time, int style))
{
	static_cast<IPlayer*>(player)->sendGameText(msg, Milliseconds(time), style);
}

OMPRS_API(void, HideGameTextForPlayer(void* player, int style))
{
	static_cast<IPlayer*>(player)->hideGameText(style);
}

OMPRS_API(bool, HasGameText(void* player, int style))
{
	return static_cast<IPlayer*>(player)->hasGameText(style);
}

OMPRS_API(bool, GetGameText(void* player, int style, StringView* message, int* time, int* remaining))
{
	Milliseconds mt;
	Milliseconds mr;
	StringView ms;

	if (static_cast<IPlayer*>(player)->getGameText(style, ms, mt, mr))
	{
		*message = ms;
		*time = (int)mt.count();
		*remaining = (int)mr.count();
		return true;
	}

	return false;
}

OMPRS_API(void, Ban(void* player))
{
	static_cast<IPlayer*>(player)->ban();
}

OMPRS_API(void, BanEx(void* player, StringView msg))
{
	static_cast<IPlayer*>(player)->ban(msg);
}

OMPRS_API(void, SendDeathMessageToPlayer(void* player, void* killer, void* killee, int weapon))
{
	
	
	if (static_cast<IPlayer*>(killee) != nullptr)
	{
		static_cast<IPlayer*>(player)->sendDeathMessage(*static_cast<IPlayer*>(killee), static_cast<IPlayer*> (killer), weapon);
	}
	else
	{
		static_cast<IPlayer*>(player)->sendEmptyDeathMessage();
	}

}

OMPRS_API(void, SendPlayerMessageToPlayer(void* player, void* sender, StringView message))
{
	static_cast<IPlayer*>(player)->sendChatMessage(*static_cast<IPlayer*>(sender), message);
}

OMPRS_API(void, GetPlayerVersion(void* player, StringView* output))
{
	*output = static_cast<IPlayer*>(player)->getClientVersionName();	
}

OMPRS_API(int, GetPlayerSkillLevel(void* player, int skill))
{
	auto& skills = static_cast<IPlayer*>(player)->getSkillLevels();

	if (skill >= 11 || skill < 0)
	{
		return 0;
	}

	return skills[skill];
}

OMPRS_API(int, GetPlayerSpectateID(void* player))
{
	return static_cast<IPlayer*>(player)->getSpectateData().spectateID;
}

OMPRS_API(PlayerSpectateData, GetPlayerSpectateData(void* player))
{
	return static_cast<IPlayer*>(player)->getSpectateData();
}

OMPRS_API(int, GetPlayerRawIp(void* player))
{
	return static_cast<IPlayer*>(player)->getNetworkData().networkID.address.v4;
}

OMPRS_API(void, SetPlayerGravity(void* player, float gravity))
{
	static_cast<IPlayer*>(player)->setGravity(gravity);
}

OMPRS_API(float, GetPlayerGravity(void* player))
{
	return static_cast<IPlayer*>(player)->getGravity();
}

OMPRS_API(void, SetPlayerAdmin(void* player, bool set))
{
	IPlayerConsoleData* data = queryExtension<IPlayerConsoleData>(static_cast<IPlayer*>(player));
	data->setConsoleAccessibility(set);
}

OMPRS_API(bool, IsPlayerSpawned(void* player))
{
	PlayerState state = static_cast<IPlayer*>(player)->getState();

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

OMPRS_API(bool, IsPlayerControllable(void* player))
{
	return static_cast<IPlayer*>(player)->getControllable();
}

OMPRS_API(bool, IsPlayerCameraTargetEnabled(void* player))
{
	return static_cast<IPlayer*>(player)->hasCameraTargeting();
}

OMPRS_API(void, TogglePlayerGhostMode(void* player, bool toggle))
{
	static_cast<IPlayer*>(player)->toggleGhostMode(toggle);
}

OMPRS_API(bool, GetPlayerGhostMode(void* player))
{
	return static_cast<IPlayer*>(player)->isGhostModeEnabled();
}

OMPRS_API(void, AllowPlayerWeapons(void* player, bool allow))
{
	static_cast<IPlayer*>(player)->allowWeapons(allow);
}

OMPRS_API(bool, ArePlayerWeaponsAllowed(void* player))
{
	return static_cast<IPlayer*>(player)->areWeaponsAllowed();
}

OMPRS_API(bool, IsPlayerUsingOfficialClient(void* player))
{
	return static_cast<IPlayer*>(player)->isUsingOfficialClient();
}

OMPRS_API(PlayerAnimationData, GetPlayerAnimationData(void* player))
{
	return static_cast<IPlayer*>(player)->getAnimationData();
}


OMPRS_API(bool, IsPlayerInDriveByMode(void* player))
{
	IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(static_cast<IPlayer*>(player));
	return data->isInDriveByMode();
}

OMPRS_API(bool, IsPlayerCuffed(void* player))
{
	if (static_cast<IPlayer*>(player)->getState() == PlayerState_OnFoot)
	{
		return static_cast<IPlayer*>(player)->getAction() == SpecialAction_Cuffed;
	}
	else if (static_cast<IPlayer*>(player)->getState() == PlayerState_Passenger)
	{
		IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(static_cast<IPlayer*>(player));
		if (data)
		{
			return data->isCuffed();
		}
	}
	return false;
}

OMPRS_API(int, GetPlayerCustomSkin(void* player))
{
	IPlayerCustomModelsData* data = queryExtension<IPlayerCustomModelsData>(static_cast<IPlayer*>(player));

	if (!data)
	{
		return 0;
	}

	return data->getCustomSkin();
}

OMPRS_API(bool, RedirectDownload(void* player, char const* url))
{
	IPlayerCustomModelsData* data = queryExtension<IPlayerCustomModelsData>(static_cast<IPlayer*>(player));

	if (!data)
	{
		return false;
	}

	if (!data->sendDownloadUrl(url))
	{
		OMPRSComponent::Get()->GetCore()->logLn(LogLevel::Warning, "This method can be used only within OnPlayerRequestDownload callback.");
		return false;
	}

	return true;
}


OMPRS_API(unsigned, GetPlayerID(void* player)) 
{
	if (player)
	{
		return static_cast<IPlayer*>(player)->getID();
	}
	return INVALID_PLAYER_ID;
}