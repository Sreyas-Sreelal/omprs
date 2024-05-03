#pragma once

#include "../api.hpp"

struct CoreEvents : public ConsoleEventHandler, public Singleton<CoreEvents>
{
private:
	CALLBACK_DECL(bool, OnRconCommand, StringView);
	CALLBACK_DECL(void, OnRconLoginAttempt,void*, StringView, StringView, bool);

public:
	CoreEvents()
	{
		INIT_CALLBACK(OnRconCommand);
		INIT_CALLBACK(OnRconLoginAttempt);
	}
	bool onConsoleText(StringView command, StringView parameters, const ConsoleCommandSenderData& sender) override
	{
		std::string fullCommand = std::string(command.data(), command.length());
		if (!parameters.empty())
		{
			fullCommand.append(" ");
			fullCommand.append(parameters.data());
		}
		EXEC_CALLBACK(OnRconCommand, StringView(fullCommand));
		return false;
	}

	void onRconLoginAttempt(IPlayer& player, StringView password, bool success) override
	{
		PeerNetworkData data = player.getNetworkData();
		PeerAddress::AddressString addressString;
		PeerAddress::ToString(data.networkID.address, addressString);
		StringView addressStringView = StringView(addressString.data(), addressString.length());
		EXEC_CALLBACK(OnRconLoginAttempt, &player, addressStringView, password, success);
	}
};