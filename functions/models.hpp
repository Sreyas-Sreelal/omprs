#pragma once

#include "../api.hpp"

OMPRS_API bool OMPRS_AddCharModel(int baseid, int newid, const char* dffname, const char* txdname)
{
	auto models = OMPRSComponent::Get()->GetCustomModels();

	if (!models)
	{
		return false;
	}

	return models->addCustomModel(ModelType::Skin, newid, baseid, dffname, txdname);
}

OMPRS_API bool OMPRS_AddSimpleModel(int virtualworld, int baseid, int newid, const char* dffname, const char* txdname)
{
	auto models = OMPRSComponent::Get()->GetCustomModels();

	if (!models)
	{
		return false;
	}

	return OMPRSComponent::Get()->GetCustomModels()->addCustomModel(ModelType::Object, newid, baseid, dffname, txdname, virtualworld);
}

OMPRS_API bool OMPRS_AddSimpleModelTimed(int virtualworld, int baseid, int newid, const char* dffname, const char* txdname, int timeon, int timeoff)
{
	auto models = OMPRSComponent::Get()->GetCustomModels();

	if (!models)
	{
		return false;
	}

	return models->addCustomModel(ModelType::Object, newid, baseid, dffname, txdname, virtualworld, timeon, timeoff);
}

OMPRS_API int OMPRS_GetPlayerCustomSkin(int playerid)
{
	GET_PLAYER_CHECKED(player, playerid, 0);
	IPlayerCustomModelsData* data = queryExtension<IPlayerCustomModelsData>(player);
	
	if (!data)
	{
		return 0;
	}
	
	return data->getCustomSkin();
}

OMPRS_API bool OMPRS_RedirectDownload(int playerid, char const* url)
{
	GET_PLAYER_CHECKED(player, playerid, false);
	IPlayerCustomModelsData* data = queryExtension<IPlayerCustomModelsData>(player);

	if (!data)
	{
		return false;
	}

	if (!data->sendDownloadUrl(url))
	{
		OMPRSComponent::Get()->GetCore()->logLn(LogLevel::Warning, "This native can be used only within OnPlayerRequestDownload callback.");
		return false;
	}

	return true;
}

OMPRS_API bool OMPRS_FindModelFileNameFromCRC(int crc, char* output)
{
	auto models = OMPRSComponent::Get()->GetCustomModels();

	if (!models)
	{
		return false;
	}

	auto out = models->getModelNameFromChecksum(crc);
	auto length = out.length();
	out.copy(output, length);

	return length;
}