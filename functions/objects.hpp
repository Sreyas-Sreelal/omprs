#pragma once

#include "../api.hpp"

OMPRS_API(void*,CreateObject(int modelid, Vector3 position, Vector3 rotation, float drawDistance))
{
	IObjectsComponent* component = OMPRSComponent::Get()->GetObjects();
	if (component)
	{
		IObject* object = component->create(modelid, position, rotation, drawDistance);
		if (object)
		{
			return object;
		}
	}
	return nullptr;
}

OMPRS_API(bool,DestroyObject(void* object))
{
	OMPRSComponent::Get()->GetObjects()->release(static_cast<IObject*>(object)->getID());
	return true;
}

OMPRS_API(void,AttachObjectToVehicle(void* object, void* vehicle, Vector3 offset, Vector3 rotation))
{
	if (vehicle)
	{
		static_cast<IObject*>(object)->attachToVehicle(*static_cast<IVehicle*>(vehicle), offset, rotation);
	}
	else
	{
		static_cast<IObject*>(object)->resetAttachment();
	}
}

OMPRS_API(void,AttachObjectToObject(void* object, void* objAttachedTo, Vector3 offset, Vector3 rotation, bool syncRotation))
{
	if (objAttachedTo)
	{
		static_cast<IObject*>(object)->attachToObject(*static_cast<IObject*>(objAttachedTo), offset, rotation, syncRotation);
	}
	else
	{
		static_cast<IObject*>(object)->resetAttachment();
	}
}

OMPRS_API(void,AttachObjectToPlayer(void* object, void* player, Vector3 offset, Vector3 rotation))
{
	if (player)
	{
		static_cast<IObject*>(object)->attachToPlayer(*static_cast<IPlayer*>(player), offset, rotation);
	}
	else
	{
		static_cast<IObject*>(object)->resetAttachment();
	}
}

OMPRS_API(void,SetObjectPos(void* object, Vector3 position))
{
	static_cast<IObject*>(object)->setPosition(position);
}

OMPRS_API(void,GetObjectPos(void* object, Vector3* position))
{
	*position = static_cast<IObject*>(object)->getPosition();
}

OMPRS_API(void,SetObjectRot(void* object, Vector3 rotation))
{
	static_cast<IObject*>(object)->setRotation(rotation);
}

OMPRS_API(void,GetObjectRot(void* object, Vector3* rotation))
{
	*rotation = static_cast<IObject*>(object)->getRotation().ToEuler();
}

OMPRS_API(int,GetObjectModel(void* object))
{
	if (!object) 
	{
		return INVALID_OBJECT_MODEL_ID;
	}	
	return static_cast<IObject*>(object)->getModel();
}

OMPRS_API(void,SetObjectNoCameraCol(void* object))
{
	static_cast<IObject*>(object)->setCameraCollision(false);
}

OMPRS_API(bool,IsValidObject(void* object))
{
	return object != nullptr;
}

OMPRS_API(int, MoveObject(void* object, ObjectMoveData data))
{
	static_cast<IObject*>(object)->move(data);
	float estimatedTime = (glm::length(data.targetPos - static_cast<IObject*>(object)->getPosition()) / data.speed) * 1000.0f;
	return static_cast<int>(estimatedTime);
}

OMPRS_API(void,StopObject(void* object))
{
	static_cast<IObject*>(object)->stop();
}

OMPRS_API(bool,IsObjectMoving(void* object))
{
	return static_cast<IObject*>(object)->isMoving();
}

OMPRS_API(void,EditObject(void* player, void* object))
{
	IPlayerObjectData* data = queryExtension<IPlayerObjectData>(static_cast<IPlayer*>(player));
	if (data)
	{
		data->beginEditing(*static_cast<IObject*>(object));
	}
}

OMPRS_API(void,SelectObject(void* player))
{
	IPlayerObjectData* data = queryExtension<IPlayerObjectData>(static_cast<IPlayer*>(player));
	if (data)
	{
		data->beginSelecting();
	}
}

OMPRS_API(void,EndObjectEditing(void* player))
{
	IPlayerObjectData* data = queryExtension<IPlayerObjectData>(static_cast<IPlayer*>(player));
	if (data)
	{
		data->endEditing();
	}
}

OMPRS_API(void, SetObjectMaterial(void* object, int materialIndex, int modelId, StringView textureLibrary, StringView textureName, Colour materialColour))
{
	static_cast<IObject*>(object)->setMaterial(materialIndex, modelId, textureLibrary, textureName, materialColour);
}

OMPRS_API(void, SetObjectMaterialText(void* object, StringView text, int materialIndex, ObjectMaterialSize materialSize, StringView fontface, int fontsize, bool bold, Colour fontColour, Colour backgroundColour, ObjectMaterialTextAlign textalignment))
{
	static_cast<IObject*>(object)->setMaterialText(materialIndex, text, materialSize, fontface, fontsize, bold, fontColour, backgroundColour, textalignment);
}

OMPRS_API(void,SetObjectsDefaultCameraCol(bool disable))
{
	IObjectsComponent* objects = OMPRSComponent::Get()->GetObjects();
	if (objects)
	{
		objects->setDefaultCameraCollision(!disable);
	}
}

OMPRS_API(float,GetObjectDrawDistance(void* object))
{
	return static_cast<IObject*>(object)->getDrawDistance();
}

OMPRS_API(float,GetObjectMoveSpeed(void* object))
{
	return static_cast<IObject*>(object)->getMovingData().speed;
}

OMPRS_API(void, GetObjectMoveData(void* object, ObjectMoveData* data))
{
	*data = static_cast<IObject*>(object)->getMovingData();
}

OMPRS_API(void, GetObjectAttachedData(void* object, ObjectAttachmentData* data))
{
	*data = static_cast<IObject*>(object)->getAttachmentData();
}

OMPRS_API(bool,IsObjectMaterialSlotUsed(void* object, int materialIndex))
{
	const ObjectMaterialData* data = nullptr;
	bool result = static_cast<IObject*>(object)->getMaterialData(materialIndex, data);
	if (result)
	{
		return data->used;
	}
	return result;
}

OMPRS_API(void, GetObjectMaterialData(void* object, int materialIndex, int* modelid, StringView* textureLibrary, StringView* textureName, Colour* materialColour, StringView* text, int* materialSize, StringView* fontFace, int* fontSize, bool* bold, Colour* fontColour, Colour* backgroundColour, int* textAlignment))
{
	const ObjectMaterialData* data = nullptr;
	bool result = static_cast<IObject*>(object)->getMaterialData(materialIndex, data);
	if (result)
	{
		*modelid = data->model;
		*textureLibrary = data->textOrTXD;
		*textureName = data->fontOrTexture;
		*materialColour = data->materialColour;
		*text = data->textOrTXD;
		*materialSize = data->materialSize;
		*fontFace = data->fontOrTexture;
		*fontSize = data->fontSize;
		*bold = data->bold;
		*fontColour = data->fontColour;
		*backgroundColour = data->backgroundColour;
		*textAlignment = data->alignment;
	}
}

OMPRS_API(bool,IsObjectNoCameraCol(void* object))
{
	return !static_cast<IObject*>(object)->getCameraCollision();
}

OMPRS_API(int,GetObjectID(void* object))
{
	if (object)
	{
		return static_cast<IObject*>(object)->getID();
	}
	return INVALID_OBJECT_ID;
}

// player object functions

OMPRS_API(void*,CreatePlayerObject(void* player, int modelid, Vector3 position, Vector3 rotation, float drawDistance))
{
	IPlayerObjectData* data = queryExtension<IPlayerObjectData>(static_cast<IPlayer*>(player));
	if (data)
	{
		IPlayerObject* object = data->create(modelid, position, rotation, drawDistance);
		if (object)
		{
			return object;
		}
	}
	return nullptr;
}

OMPRS_API(void,DestroyPlayerObject(void* player, void* object))
{
	IPlayerObjectData* data = queryExtension<IPlayerObjectData>(static_cast<IPlayer*>(player));
	if (data)
	{
		data->release(static_cast<IPlayerObject*>(object)->getID());
	}
}

OMPRS_API(void,AttachPlayerObjectToVehicle(void* object, void* vehicle, Vector3 offset, Vector3 rotation))
{
	if (vehicle)
	{
		static_cast<IPlayerObject*>(object)->attachToVehicle(*static_cast<IVehicle*>(vehicle), offset, rotation);
	}
	else
	{
		static_cast<IPlayerObject*>(object)->resetAttachment();
	}
}

OMPRS_API(void,AttachPlayerObjectToPlayer(void* object, void* playerAttachedTo, Vector3 offset, Vector3 rotation))
{
	if (playerAttachedTo)
	{
		static_cast<IPlayerObject*>(object)->attachToPlayer(*static_cast<IPlayer*>(playerAttachedTo), offset, rotation);
	}
	else
	{
		static_cast<IPlayerObject*>(object)->resetAttachment();
	}
}

OMPRS_API(void,AttachPlayerObjectToObject(void* object, void* attachedTo, Vector3 offset, Vector3 rotation))
{
	if (attachedTo)
	{
		static_cast<IPlayerObject*>(object)->attachToObject(*static_cast<IPlayerObject*>(attachedTo), offset, rotation);
	}
	else
	{
		static_cast<IPlayerObject*>(object)->resetAttachment();
	}
}

OMPRS_API(void,SetPlayerObjectPos(void* object, Vector3 position))
{
	static_cast<IPlayerObject*>(object)->setPosition(position);
}

OMPRS_API(void,GetPlayerObjectPos(void* object, Vector3* position))
{
	*position = static_cast<IPlayerObject*>(object)->getPosition();
}

OMPRS_API(void,SetPlayerObjectRot(void* object, Vector3 rotation))
{
	static_cast<IPlayerObject*>(object)->setRotation(rotation);
}

OMPRS_API(void,GetPlayerObjectRot(void* object, Vector3* rotation))
{
	*rotation = static_cast<IPlayerObject*>(object)->getRotation().ToEuler();
}

OMPRS_API(int,GetPlayerObjectModel(void* object))
{
	if (!object)
	{
		return INVALID_OBJECT_MODEL_ID;
	}
	return static_cast<IPlayerObject*>(object)->getModel();
}

OMPRS_API(void,SetPlayerObjectNoCameraCol(void* object))
{
	static_cast<IPlayerObject*>(object)->setCameraCollision(false);
}

OMPRS_API(int, MovePlayerObject(void* object, ObjectMoveData data))
{
	static_cast<IPlayerObject*>(object)->move(data);
	float estimatedTime = (glm::length(data.targetPos - static_cast<IPlayerObject*>(object)->getPosition()) / data.speed) * 1000.0f;
	return static_cast<int>(estimatedTime);
}

OMPRS_API(void,StopPlayerObject(void* object))
{
	static_cast<IPlayerObject*>(object)->stop();
}

OMPRS_API(bool,IsPlayerObjectMoving(void* object))
{
	return static_cast<IPlayerObject*>(object)->isMoving();
}

OMPRS_API(void,EditPlayerObject(void* player, void* object))
{
	IPlayerObjectData* data = queryExtension<IPlayerObjectData>(static_cast<IPlayer*>(player));
	if (data)
	{
		data->beginEditing(*static_cast<IPlayerObject*>(object));
	}
}

OMPRS_API(void,SetPlayerObjectMaterial(void* object, int materialIndex, int modelId, StringView textureLibrary, StringView textureName, Colour materialColour))
{
	static_cast<IPlayerObject*>(object)->setMaterial(materialIndex, modelId, textureLibrary, textureName, materialColour);
}

OMPRS_API(void,SetPlayerObjectMaterialText(void* object, StringView text, int materialIndex, int materialSize, StringView fontface, int fontsize, bool bold, Colour fontColour, Colour backgroundColour, ObjectMaterialTextAlign textalignment))
{
	static_cast<IPlayerObject*>(object)->setMaterialText(materialIndex, text, ObjectMaterialSize(materialSize), fontface, fontsize, bold, fontColour, backgroundColour, textalignment);
}

OMPRS_API(float,GetPlayerObjectDrawDistance(void* object))
{
	return static_cast<IPlayerObject*>(object)->getDrawDistance();
}

OMPRS_API(float,GetPlayerObjectMoveSpeed(void* object))
{
	return static_cast<IPlayerObject*>(object)->getMovingData().speed;
}

OMPRS_API(void, GetPlayerObjectMovingData(void* object, ObjectMoveData* data))
{
	*data = static_cast<IPlayerObject*>(object)->getMovingData();
}

OMPRS_API(void,GetPlayerObjectAttachedData(void* object, ObjectAttachmentData* data))
{
	*data = static_cast<IPlayerObject*>(object)->getAttachmentData();
}


OMPRS_API(bool,IsPlayerObjectMaterialSlotUsed(void* object, int materialIndex))
{
	const ObjectMaterialData* data = nullptr;
	bool result = static_cast<IPlayerObject*>(object)->getMaterialData(materialIndex, data);
	if (result)
	{
		return data->used;
	}
	return result;
}

OMPRS_API(void, GetPlayerObjectMaterialData(void* object, int materialIndex, int* modelid, StringView* textureLibrary, StringView* textureName, Colour* materialColour, StringView* text, int* materialSize, StringView* fontFace, int* fontSize, bool* bold, Colour* fontColour, Colour* backgroundColour, int* textAlignment))
{
	const ObjectMaterialData* data = nullptr;
	bool result = static_cast<IPlayerObject*>(object)->getMaterialData(materialIndex, data);
	if (result)
	{
		*modelid = data->model;
		*textureLibrary = data->textOrTXD;
		*textureName = data->fontOrTexture;
		*materialColour = data->materialColour;
		*text = data->textOrTXD;
		*materialSize = data->materialSize;
		*fontFace = data->fontOrTexture;
		*fontSize = data->fontSize;
		*bold = data->bold;
		*fontColour = data->fontColour;
		*backgroundColour = data->backgroundColour;
		*textAlignment = data->alignment;
	}
}

OMPRS_API(bool,IsPlayerObjectNoCameraCol(void* object))
{
	return !static_cast<IPlayerObject*>(object)->getCameraCollision();
}


OMPRS_API(int, GetPlayerObjectID(void* object))
{
	if (object)
	{
		return static_cast<IPlayerObject*>(object)->getID();
	}
	return INVALID_OBJECT_ID;
}