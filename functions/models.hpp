#pragma once

#include "../api.hpp"

OMPRS_API(bool, AddCharModel(int baseid, int newid, const char* dffname, const char* txdname))
{
	auto models = OMPRSComponent::Get()->GetCustomModels();

	if (!models)
	{
		return false;
	}

	return models->addCustomModel(ModelType::Skin, newid, baseid, dffname, txdname);
}

OMPRS_API(bool,AddSimpleModel(int virtualworld, int baseid, int newid, const char* dffname, const char* txdname))
{
	auto models = OMPRSComponent::Get()->GetCustomModels();

	if (!models)
	{
		return false;
	}

	return OMPRSComponent::Get()->GetCustomModels()->addCustomModel(ModelType::Object, newid, baseid, dffname, txdname, virtualworld);
}

OMPRS_API(bool,AddSimpleModelTimed(int virtualworld, int baseid, int newid, const char* dffname, const char* txdname, int timeon, int timeoff))
{
	auto models = OMPRSComponent::Get()->GetCustomModels();

	if (!models)
	{
		return false;
	}

	return models->addCustomModel(ModelType::Object, newid, baseid, dffname, txdname, virtualworld, timeon, timeoff);
}

OMPRS_API(int,GetPlayerCustomSkin(int playerid))
{
	GET_PLAYER_CHECKED(player, playerid, 0);
	IPlayerCustomModelsData* data = queryExtension<IPlayerCustomModelsData>(player);

	if (!data)
	{
		return 0;
	}

	return data->getCustomSkin();
}

OMPRS_API(bool,RedirectDownload(int playerid, char const* url))
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

OMPRS_API(bool,FindModelFileNameFromCRC(int crc, char* output))
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

OMPRS_API(bool,FindTextureFileNameFromCRC(int crc, char* output))
{
	return OMPRS_FindModelFileNameFromCRC(crc, output);
}

OMPRS_API(bool,IsValidCustomModel(int modelid))
{
	auto models = OMPRSComponent::Get()->GetCustomModels();

	if (!models)
	{
		return false;
	}

	return models->isValidCustomModel(modelid);
}

OMPRS_API(bool,GetCustomModelPath(int modelid, char* dffPath, char* txdPath))
{
	auto models = OMPRSComponent::Get()->GetCustomModels();

	if (!models)
	{
		return false;
	}

	StringView dffPathSV {};
	StringView txdPathSV {};

	auto status = models->getCustomModelPath(modelid, dffPathSV, txdPathSV);

	dffPathSV.copy(dffPath, dffPathSV.length());
	txdPathSV.copy(txdPath, txdPathSV.length());

	return status;
}