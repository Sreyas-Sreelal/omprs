#pragma once

#include "../api.hpp"

struct ObjectEvents : public ObjectEventHandler, public Singleton<ObjectEvents>
{
private:
	CALLBACK_DECL(void, onObjectMoved, void*);
	CALLBACK_DECL(void, onPlayerObjectMoved, void*,void*);
	CALLBACK_DECL(void, onPlayerEditObject, void*, void*, ObjectEditResponse, Vector3, Vector3);
	CALLBACK_DECL(void, onPlayerObjectEdited, void*, void* object, ObjectEditResponse, Vector3, Vector3);
	CALLBACK_DECL(void, onPlayerEditAttachedObject, void*, int, bool, ObjectAttachmentSlotData);
	CALLBACK_DECL(void, onPlayerSelectObject, void*, void*, int, Vector3);
	CALLBACK_DECL(void, onPlayerObjectSelected, void* player, void* object, int, Vector3);

public:
	ObjectEvents()
	{
		INIT_CALLBACK(onObjectMoved);
		INIT_CALLBACK(onPlayerObjectMoved);
		INIT_CALLBACK(onPlayerEditObject);
		INIT_CALLBACK(onPlayerObjectEdited);
		INIT_CALLBACK(onPlayerEditAttachedObject);
		INIT_CALLBACK(onPlayerSelectObject);
		INIT_CALLBACK(onPlayerObjectSelected);
	}
	void onMoved(IObject& object) override
	{
		EXEC_CALLBACK(onObjectMoved, &object);
	}

	void onPlayerObjectMoved(IPlayer& player, IPlayerObject& object) override
	{
		EXEC_CALLBACK(onPlayerObjectMoved, &player, &object);
	}

	void onObjectEdited(IPlayer& player, IObject& object, ObjectEditResponse response, Vector3 offset, Vector3 rotation) override
	{
		EXEC_CALLBACK(onPlayerEditObject, &player, &object, response, offset, rotation);
	}

	void onPlayerObjectEdited(IPlayer& player, IPlayerObject& object, ObjectEditResponse response, Vector3 offset, Vector3 rotation) override
	{
		EXEC_CALLBACK(onPlayerObjectEdited, &player, &object, response, offset, rotation);
	}

	void onPlayerAttachedObjectEdited(IPlayer& player, int index, bool saved, const ObjectAttachmentSlotData& data) override
	{
		EXEC_CALLBACK(onPlayerEditAttachedObject, &player, index, saved, data);
	}

	void onObjectSelected(IPlayer& player, IObject& object, int model, Vector3 position) override
	{
		EXEC_CALLBACK(onPlayerSelectObject, &player, &object, model, position);
	}

	void onPlayerObjectSelected(IPlayer& player, IPlayerObject& object, int model, Vector3 position) override
	{
		EXEC_CALLBACK(onPlayerObjectSelected,&player,&object,model,position);
	}
};