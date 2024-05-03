#pragma once

#include "../api.hpp"
#include <math.h>
#include <sstream>
#include <iomanip>
#include <types.hpp>

OMPRS_API(void,Print(StringView text))
{
	OMPRSComponent::Get()->GetCore()->printLn("%s",text.to_string().c_str());
}

OMPRS_API(int,GetTickCount())
{
	return OMPRSComponent::Get()->GetCore()->getTickCount();
}

OMPRS_API(int,GetMaxPlayers())
{
	return *OMPRSComponent::Get()->GetCore()->getConfig().getInt("max_players");
}

OMPRS_API(float,VectorSize(Vector3 vector))
{
	return glm::length(vector);
}

OMPRS_API(int,GetPlayerPoolSize())
{
	int highestID = -1;
	for (IPlayer* player : OMPRSComponent::Get()->GetPlayers()->entries())
	{
		if (highestID < player->getID())
		{
			highestID = player->getID();
		}
	}
	return highestID;
}

OMPRS_API(int,GetVehiclePoolSize())
{
	IVehiclesComponent* vehicles = OMPRSComponent::Get()->GetVehicles();
	if (vehicles)
	{
		int highestID = -1;
		for (IVehicle* vehicle : *vehicles)
		{
			if (highestID < vehicle->getID())
			{
				highestID = vehicle->getID();
			}
		}
		return highestID;
	}
	return -1;
}

OMPRS_API(int,GetActorPoolSize())
{
	IActorsComponent* actors = OMPRSComponent::Get()->GetActors();
	if (actors)
	{
		int highestID = -1;
		for (IActor* actor : *actors)
		{
			if (highestID < actor->getID())
			{
				highestID = actor->getID();
			}
		}
		return highestID;
	}
	return -1;
}

OMPRS_API(bool,IsAdminTeleportAllowed())
{
	return *OMPRSComponent::Get()->GetCore()->getConfig().getBool("rcon.allow_teleport");
}

OMPRS_API(bool,AllowAdminTeleport(bool allow))
{
	*OMPRSComponent::Get()->GetCore()->getConfig().getBool("rcon.allow_teleport") = allow;
	return true;
}

OMPRS_API(bool,AreAllAnimationsEnabled())
{
	return *OMPRSComponent::Get()->GetCore()->getConfig().getBool("game.use_all_animations");
}

OMPRS_API(bool,EnableAllAnimations(bool allow))
{
	*OMPRSComponent::Get()->GetCore()->getConfig().getBool("game.use_all_animations") = allow;
	return true;
}

OMPRS_API(bool,IsValidAnimationLibrary(StringView name))
{
	return animationLibraryValid(name, false);
}

OMPRS_API(bool,AreInteriorWeaponsAllowed())
{
	return *OMPRSComponent::Get()->GetCore()->getConfig().getBool("game.allow_interior_weapons");
}

OMPRS_API(bool,AllowInteriorWeapons(bool allow))
{
	if (allow)
	{
		*OMPRSComponent::Get()->GetCore()->getConfig().getBool("game.allow_interior_weapons") = true;
	}
	else
	{
		IPlayerPool* players = OMPRSComponent::Get()->GetPlayers();
		for (IPlayer* player : players->entries())
		{
			if (player->getInterior() && player->areWeaponsAllowed())
			{
				// Because they are allowed weapons currently this will send a full client reset.
				player->resetWeapons();
			}
		}
		// By the time the player reports having no weapons, this is set and so we remember the old
		// ones still.
		*OMPRSComponent::Get()->GetCore()->getConfig().getBool("game.allow_interior_weapons") = false;
	}
	return true;
}

OMPRS_API(bool,BlockIpAddress(std::string const& ipAddress, int timeMS))
{
	if (ipAddress.empty())
	{
		return false;
	}
	BanEntry entry(ipAddress);
	for (INetwork* network : OMPRSComponent::Get()->GetCore()->getNetworks())
	{
		network->ban(entry, Milliseconds(timeMS));
	}
	return true;
}

OMPRS_API(bool,UnBlockIpAddress(std::string const& ipAddress))
{
	BanEntry entry(ipAddress);
	for (INetwork* network : OMPRSComponent::Get()->GetCore()->getNetworks())
	{
		network->unban(entry);
	}
	return true;
}

OMPRS_API(bool,ConnectNPC(std::string const& name, std::string const& script))
{
	OMPRSComponent::Get()->GetCore()->connectBot(name, script);
	return true;
}

OMPRS_API(bool,DisableInteriorEnterExits())
{
	*OMPRSComponent::Get()->GetCore()->getConfig().getBool("game.use_entry_exit_markers") = false;
	return true;
}

OMPRS_API(bool,DisableNameTagLOS())
{
	*OMPRSComponent::Get()->GetCore()->getConfig().getBool("game.use_nametag_los") = false;
	return true;
}

OMPRS_API(bool,EnableTirePopping(bool enable))
{
	OMPRSComponent::Get()->GetCore()->logLn(LogLevel::Warning, "EnableTirePopping() function is removed.");
	return true;
}

OMPRS_API(bool,EnableZoneNames(bool enable))
{
	*OMPRSComponent::Get()->GetCore()->getConfig().getBool("game.use_zone_names") = enable;
	return true;
}

OMPRS_API(void,GameTextForAll(StringView msg, int time, int style))
{
	OMPRSComponent::Get()->GetPlayers()->sendGameTextToAll(msg, Milliseconds(time), style);
}

OMPRS_API(void,HideGameTextForAll(int style))
{
	OMPRSComponent::Get()->GetPlayers()->hideGameTextForAll(style);
}

// This functions is extracted from open.mp PAWN component
// Server/Components/Pawn/Scripting/Core/Natives.cpp
int getConfigOptionAsInt(StringView cvar)
{
	IConfig& config = OMPRSComponent::Get()->GetCore()->getConfig();
	auto res = config.getNameFromAlias(cvar);
	bool* v0 = nullptr;
	int* v1 = nullptr;
	if (!res.second.empty())
	{
		if (res.first)
		{
			OMPRSComponent::Get()->GetCore()->logLn(LogLevel::Warning, "Deprecated console variable \"%s\", use \"%.*s\" instead.", cvar.to_string().c_str(), PRINT_VIEW(res.second));
		}
		if (!(v1 = config.getInt(res.second)))
		{
			v0 = config.getBool(res.second);
		}
	}
	else
	{
		if (!(v1 = config.getInt(cvar)))
		{
			v0 = config.getBool(cvar);
		}
	}
	if (v1)
	{
		return *v1;
	}
	else if (v0)
	{
		OMPRSComponent::Get()->GetCore()->logLn(LogLevel::Warning, "Boolean console variable \"%s\" retreived as integer.", cvar.to_string().c_str());
		return *v0;
	}
	else
	{
		return 0;
	}
}

// This functions is extracted from open.mp PAWN component
// Server/Components/Pawn/Scripting/Core/Natives.cpp
bool getConfigOptionAsBool(StringView cvar)
{
	IConfig& config = OMPRSComponent::Get()->GetCore()->getConfig();
	auto res = config.getNameFromAlias(cvar);
	bool* v0 = nullptr;
	int* v1 = nullptr;
	if (!res.second.empty())
	{
		if (res.first)
		{
			OMPRSComponent::Get()->GetCore()->logLn(LogLevel::Warning, "Deprecated console variable \"%s\", use \"%.*s\" instead.", cvar.to_string().c_str(), PRINT_VIEW(res.second));
		}
		if (!(v0 = config.getBool(res.second)))
		{
			v1 = config.getInt(res.second);
		}
	}
	else
	{
		if (!(v0 = config.getBool(cvar)))
		{
			v1 = config.getInt(cvar);
		}
	}
	if (v0)
	{
		return *v0;
	}
	else if (v1)
	{
		OMPRSComponent::Get()->GetCore()->logLn(LogLevel::Warning, "Integer console variable \"%s\" retreived as boolean.", cvar.to_string().c_str());
		return *v1 != 0;
	}
	else
	{
		return false;
	}
}

// This functions is extracted from open.mp PAWN component
// Server/Components/Pawn/Scripting/Core/Natives.cpp
float getConfigOptionAsFloat(StringView cvar)
{
	IConfig& config = OMPRSComponent::Get()->GetCore()->getConfig();
	auto res = config.getNameFromAlias(cvar);
	float* var = nullptr;
	if (!res.second.empty())
	{
		if (res.first)
		{
			OMPRSComponent::Get()->GetCore()->logLn(LogLevel::Warning, "Deprecated console variable \"%s\", use \"%.*s\" instead.", cvar.to_string().c_str(), PRINT_VIEW(res.second));
		}
		var = config.getFloat(res.second);
	}
	else
	{
		var = config.getFloat(cvar);
	}
	if (var)
	{
		return *var;
	}
	else
	{
		return 0.0f;
	}
}


int getConfigOptionAsString(StringView cvar, StringView* buffer)
{
	IConfig& config = OMPRSComponent::Get()->GetCore()->getConfig();
	auto res = config.getNameFromAlias(cvar);
	if (!res.second.empty())
	{
		if (res.first)
		{
			OMPRSComponent::Get()->GetCore()->logLn(LogLevel::Warning, "Deprecated console variable \"%s\", use \"%.*s\" instead.", cvar.to_string().c_str(), PRINT_VIEW(res.second));
		}
		else
		{
			*buffer = config.getString(res.second);
		}
	}
	else
	{
		*buffer = config.getString(cvar);
	}
	return buffer->length();
}

OMPRS_API(bool,GetConsoleVarAsBool(StringView cvar))
{
	return getConfigOptionAsBool(cvar);
}

OMPRS_API(int, GetConsoleVarAsInt(StringView cvar))
{
	return getConfigOptionAsInt(cvar);
}

OMPRS_API(float, GetConsoleVarAsFloat(StringView cvar))
{
	return getConfigOptionAsFloat(cvar);
}

OMPRS_API(int, GetConsoleVarAsString(StringView cvar, StringView* buffer))
{
	return getConfigOptionAsString(cvar, buffer);
}

OMPRS_API(void,GetNetworkStats(StringView* output))
{
	std::stringstream stream;
	NetworkStats stats;

	for (INetwork* network : OMPRSComponent::Get()->GetCore()->getNetworks())
	{
		if (network->getNetworkType() == ENetworkType::ENetworkType_RakNetLegacy)
		{
			stats = network->getStatistics();
		}
	}

	stream
		<< "Server Ticks: " << OMPRSComponent::Get()->GetCore()->tickRate() << std::endl
		<< "Messages in Send buffer: " << stats.messageSendBuffer << std::endl
		<< "Messages sent: " << stats.messagesSent << std::endl
		<< "Bytes sent: " << stats.totalBytesSent << std::endl
		<< "Acks sent: " << stats.acknowlegementsSent << std::endl
		<< "Acks in send buffer: " << stats.acknowlegementsPending << std::endl
		<< "Messages waiting for ack: " << stats.messagesOnResendQueue << std::endl
		<< "Messages resent: " << stats.messageResends << std::endl
		<< "Bytes resent: " << stats.messagesTotalBytesResent << std::endl
		<< "Packetloss: " << std::setprecision(1) << std::fixed << stats.packetloss << "%" << std::endl
		<< "Messages received: " << stats.messagesReceived << std::endl
		<< "Bytes received: " << stats.bytesReceived << std::endl
		<< "Acks received: " << stats.acknowlegementsReceived << std::endl
		<< "Duplicate acks received: " << stats.duplicateAcknowlegementsReceived << std::endl
		<< "Inst. KBits per second: " << std::setprecision(1) << (stats.bitsPerSecond / 1000.0) << std::endl
		<< "KBits per second sent: " << std::setprecision(1) << (stats.bpsSent / 1000.0) << std::endl
		<< "KBits per second received: " << std::setprecision(1) << (stats.bpsReceived / 1000.0) << std::endl;

	*output = stream.str();
}

OMPRS_API(void,GetPlayerNetworkStats(void* player, StringView* output))
{
	std::stringstream stream;
	NetworkStats stats = static_cast<IPlayer*>(player)->getNetworkData().network->getStatistics(static_cast<IPlayer*>(player));

	stream
		<< "Network Active: " << int(stats.isActive) << std::endl
		<< "Network State: " << stats.connectMode << std::endl
		<< "Messages in Send buffer: " << stats.messageSendBuffer << std::endl
		<< "Messages sent: " << stats.messagesSent << std::endl
		<< "Bytes sent: " << stats.totalBytesSent << std::endl
		<< "Acks sent: " << stats.acknowlegementsSent << std::endl
		<< "Acks in send buffer: " << stats.acknowlegementsPending << std::endl
		<< "Messages waiting for ack: " << stats.messagesOnResendQueue << std::endl
		<< "Messages resent: " << stats.messageResends << std::endl
		<< "Bytes resent: " << stats.messagesTotalBytesResent << std::endl
		<< "Packetloss: " << std::setprecision(1) << std::fixed << stats.packetloss << "%" << std::endl
		<< "Messages received: " << stats.messagesReceived << std::endl
		<< "Bytes received: " << stats.bytesReceived << std::endl
		<< "Acks received: " << stats.acknowlegementsReceived << std::endl
		<< "Duplicate acks received: " << stats.duplicateAcknowlegementsReceived << std::endl
		<< "Inst. KBits per second: " << std::setprecision(1) << (stats.bitsPerSecond / 1000.0) << std::endl
		<< "KBits per second sent: " << std::setprecision(1) << (stats.bpsSent / 1000.0) << std::endl
		<< "KBits per second received: " << std::setprecision(1) << (stats.bpsReceived / 1000.0) << std::endl;

	*output = stream.str();
}

OMPRS_API(int,GetServerTickRate())
{
	return OMPRSComponent::Get()->GetCore()->tickRate();
}

OMPRS_API(bool,GetServerVarAsBool(StringView cvar))
{
	return getConfigOptionAsBool(cvar);
}

OMPRS_API(int, GetServerVarAsInt(StringView cvar))
{
	return getConfigOptionAsInt(cvar);
}

OMPRS_API(float, GetServerVarAsFloat(StringView cvar))
{
	return getConfigOptionAsFloat(cvar);
}

OMPRS_API(int,GetServerVarAsString(StringView cvar, StringView* buffer))
{
	return getConfigOptionAsString(cvar, buffer);
}

OMPRS_API(void, GetWeaponName(int weaponid, StringView* weapon))
{
	*weapon = OMPRSComponent::Get()->GetCore()->getWeaponName(PlayerWeapon(weaponid));
}

OMPRS_API(void,LimitGlobalChatRadius(float chatRadius))
{
	*OMPRSComponent::Get()->GetCore()->getConfig().getBool("game.use_chat_radius") = true;
	*OMPRSComponent::Get()->GetCore()->getConfig().getFloat("game.chat_radius") = chatRadius;
}

OMPRS_API(void,LimitPlayerMarkerRadius(float markerRadius))
{
	*OMPRSComponent::Get()->GetCore()->getConfig().getBool("game.use_player_marker_draw_radius") = true;
	*OMPRSComponent::Get()->GetCore()->getConfig().getFloat("game.player_marker_draw_radius") = markerRadius;
}

OMPRS_API(int,NetStats_BytesReceived(void* player))
{
	NetworkStats stats = static_cast<IPlayer*>(player)->getNetworkData().network->getStatistics(static_cast<IPlayer*>(player));
	return stats.bytesReceived;
}

OMPRS_API(int,NetStats_BytesSent(void* player))
{
	NetworkStats stats = static_cast<IPlayer*>(player)->getNetworkData().network->getStatistics(static_cast<IPlayer*>(player));
	return stats.totalBytesSent;
}

OMPRS_API(int, NetStats_ConnectionStatus(void* player))
{
	NetworkStats stats = static_cast<IPlayer*>(player)->getNetworkData().network->getStatistics(static_cast<IPlayer*>(player));
	return stats.connectMode;
}

OMPRS_API(int,NetStats_GetConnectedTime(void* player))
{
	NetworkStats stats = static_cast<IPlayer*>(player)->getNetworkData().network->getStatistics(static_cast<IPlayer*>(player));
	return stats.connectionElapsedTime;
}

OMPRS_API(void, NetStats_GetIpPort(void* player, StringView* output))
{
	PeerNetworkData data = static_cast<IPlayer*>(player)->getNetworkData();
	PeerAddress::AddressString addressString;
	if (PeerAddress::ToString(data.networkID.address, addressString))
	{
		Impl::String ip_port((StringView(addressString)));
		ip_port += ":";
		ip_port += std::to_string(data.networkID.port);
		*output = ip_port;
	}
}

OMPRS_API(int,NetStats_MessagesReceived(void* player))
{
	NetworkStats stats = static_cast<IPlayer*>(player)->getNetworkData().network->getStatistics(static_cast<IPlayer*>(player));
	return stats.messagesReceived;
}

OMPRS_API(int,NetStats_MessagesRecvPerSecond(void* player))
{
	NetworkStats stats = static_cast<IPlayer*>(player)->getNetworkData().network->getStatistics(static_cast<IPlayer*>(player));
	return stats.messagesReceivedPerSecond;
}

OMPRS_API(int, NetStats_MessagesSent(void* player))
{
	NetworkStats stats = static_cast<IPlayer*>(player)->getNetworkData().network->getStatistics(static_cast<IPlayer*>(player));
	return stats.messagesSent;
}

OMPRS_API(float,NetStats_PacketLossPercent(void* player))
{
	NetworkStats stats = static_cast<IPlayer*>(player)->getNetworkData().network->getStatistics(static_cast<IPlayer*>(player));
	return stats.packetloss;
}

OMPRS_API(void,SendPlayerMessageToAll(void* player, StringView message))
{
	OMPRSComponent::Get()->GetPlayers()->sendChatMessageToAll(*static_cast<IPlayer*>(player), message);
}

OMPRS_API(void,SendRconCommand(StringView command))
{
	IConsoleComponent* console = OMPRSComponent::Get()->GetConsole();
	if (console)
	{
		console->send(command);
	}
}

OMPRS_API(void,SetDeathDropAmount(int amount))
{
	*OMPRSComponent::Get()->GetCore()->getConfig().getInt("game.death_drop_amount") = amount;
}

OMPRS_API(void,SetGameModeText(StringView string))
{
	OMPRSComponent::Get()->GetCore()->setData(SettableCoreDataType::ModeText, string);
}

OMPRS_API(void,SetGravity(float gravity))
{
	OMPRSComponent::Get()->GetCore()->setGravity(gravity);
}

OMPRS_API(float,GetGravity())
{
	return OMPRSComponent::Get()->GetCore()->getGravity();
}

OMPRS_API(void,SetNameTagDrawDistance(float distance))
{
	*OMPRSComponent::Get()->GetCore()->getConfig().getFloat("game.nametag_draw_radius") = distance;
}

OMPRS_API(void,SetWeather(int weatherid))
{
	OMPRSComponent::Get()->GetCore()->setWeather(weatherid);
}

OMPRS_API(void,SetWorldTime(int hour))
{
	OMPRSComponent::Get()->GetCore()->setWorldTime(Hours(hour));
}

OMPRS_API(void,ShowNameTags(bool show))
{
	*OMPRSComponent::Get()->GetCore()->getConfig().getBool("game.use_nametags") = show;
}

OMPRS_API(void,ShowPlayerMarkers(int mode))
{
	*OMPRSComponent::Get()->GetCore()->getConfig().getInt("game.player_marker_mode") = mode;
}

OMPRS_API(void,UsePlayerPedAnims())
{
	*OMPRSComponent::Get()->GetCore()->getConfig().getBool("game.use_player_ped_anims") = true;
}

OMPRS_API(int,GetWeather())
{
	return *OMPRSComponent::Get()->GetCore()->getConfig().getInt("game.weather");
}

OMPRS_API(int,GetWorldTime())
{
	return *OMPRSComponent::Get()->GetCore()->getConfig().getInt("game.time");
}

OMPRS_API(void,ToggleChatTextReplacement(bool enable))
{
	*OMPRSComponent::Get()->GetCore()->getConfig().getBool("chat_input_filter") = enable;
}

OMPRS_API(bool,ChatTextReplacementToggled())
{
	return *OMPRSComponent::Get()->GetCore()->getConfig().getBool("chat_input_filter");
}

OMPRS_API(bool,IsValidNickName(StringView name))
{
	return OMPRSComponent::Get()->GetPlayers()->isNameValid(name);
}

OMPRS_API(void,AllowNickNameCharacter(int character, bool allow))
{
	OMPRSComponent::Get()->GetPlayers()->allowNickNameCharacter(character, allow);
}

OMPRS_API(bool,IsNickNameCharacterAllowed(char character))
{
	return OMPRSComponent::Get()->GetPlayers()->isNickNameCharacterAllowed(character);
}

OMPRS_API(void,ClearBanList())
{
	ICore* core = OMPRSComponent::Get()->GetCore();
	if (core)
	{
		core->getConfig().clearBans();
	}
}

OMPRS_API(bool,IsBanned(StringView ip))
{
	ICore* core = OMPRSComponent::Get()->GetCore();
	if (!core)
	{
		return false;
	}
	BanEntry entry(ip);
	return core->getConfig().isBanned(entry);
}

OMPRS_API(int,GetWeaponSlot(uint8_t weapon))
{
	return WeaponSlotData { weapon }.slot();
}

void addRule(StringView name, StringView value)
{
	ICore* core = OMPRSComponent::Get()->GetCore();
	if (!core)
	{
		return;
	}

	for (INetwork* network : core->getNetworks())
	{
		INetworkQueryExtension* query = queryExtension<INetworkQueryExtension>(network);

		if (query)
		{
			query->addRule(name, value);
		}
	}
}

OMPRS_API(void, AddServerRule(StringView name, StringView value))
{
	addRule(name, value);
}

OMPRS_API(void, SetServerRule(StringView name, StringView value))
{
	return addRule(name, value);
}

OMPRS_API(bool,IsValidServerRule(StringView name))
{
	ICore* core = OMPRSComponent::Get()->GetCore();
	if (!core)
	{
		return false;
	}

	for (INetwork* network : core->getNetworks())
	{
		INetworkQueryExtension* query = queryExtension<INetworkQueryExtension>(network);

		if (query)
		{
			return query->isValidRule(name);
		}
	}
	return false;
}

OMPRS_API(void,RemoveServerRule(StringView name))
{
	ICore* core = OMPRSComponent::Get()->GetCore();
	if (core)
	{

		for (INetwork* network : core->getNetworks())
		{
			INetworkQueryExtension* query = queryExtension<INetworkQueryExtension>(network);

			if (query)
			{
				query->removeRule(name);
			}
		}
	}
}
