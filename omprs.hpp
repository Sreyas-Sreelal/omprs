#pragma once

#include <sdk.hpp>
#include "core.hpp"
#include "singleton.hpp"
#include <Server/Components/Pickups/pickups.hpp>
#include <Server/Components/Objects/objects.hpp>
#include <Server/Components/TextLabels/textlabels.hpp>
#include <Server/Components/Vehicles/vehicles.hpp>
#include <Server/Components/Vehicles/vehicle_components.hpp>
#include <Server/Components/Vehicles/vehicle_colours.hpp>
#include <Server/Components/Vehicles/vehicle_models.hpp>
#include <Server/Components/Vehicles/vehicle_seats.hpp>
#include <Server/Components/Actors/actors.hpp>
#include <Server/Components/CustomModels/custommodels.hpp>
#include <Server/Components/TextDraws/textdraws.hpp>
#include <Server/Components/Console/console.hpp>
#include <Server/Components/Checkpoints/checkpoints.hpp>
#include <Server/Components/Classes/classes.hpp>
#include <Server/Components/Dialogs/dialogs.hpp>
#include <Server/Components/GangZones/gangzones.hpp>
#include <Server/Components/Menus/menus.hpp>

class OMPRSComponent : public IComponent, public Singleton<OMPRSComponent>
{
private:
	ICore* core_ = nullptr;
	IComponentList* componentList = nullptr;
	IPlayerPool* players = nullptr;
	IPickupsComponent* pickups = nullptr;
	IObjectsComponent* objects = nullptr;
	ITextLabelsComponent* textlabels = nullptr;
	IVehiclesComponent* vehicles = nullptr;
	IActorsComponent* actors = nullptr;
	ICustomModelsComponent* custommodels = nullptr;
	ICheckpointsComponent* checkpoints = nullptr;
	IClassesComponent* classes = nullptr;
	IDialogsComponent* dialogs = nullptr;
	IGangZonesComponent* gangzones = nullptr;
	IMenusComponent* menus = nullptr;
	ITextDrawsComponent* textdraws = nullptr;
	IConsoleComponent* console = nullptr;
	
	OMPRSCore* omprs_core = nullptr;

public:
	PROVIDE_UID(0xA3CF477F384DEAFC);

	StringView componentName() const override;

	SemanticVersion componentVersion() const override;

	void onFree(IComponent* component) override;

	void onLoad(ICore* c) override;

	void onReady() override;

	void free() override;

	void reset() override;

	void onInit(IComponentList* components) override;

	void print(const char* text);

	// most of these helper methods are extracted from open.mp gdk

	ICore* GetCore();

	IPlayerPool* GetPlayers();

	template <typename ComponentType>
	ComponentType* GetComponent();

	IPickupsComponent* GetPickups();

	IObjectsComponent* GetObjects();

	IVehiclesComponent* GetVehicles();

	ITextLabelsComponent* GetTextLabels();

	IActorsComponent* GetActors();

	ICustomModelsComponent* GetCustomModels();
	
	IClassesComponent* OMPRSComponent::GetClasses();

	IGangZonesComponent* OMPRSComponent::GetGangZones();
	
	IMenusComponent* OMPRSComponent::GetMenus();

	ITextDrawsComponent* OMPRSComponent::GetTextDraws();
	
	IConsoleComponent* OMPRSComponent::GetConsole();
	
	OMPRSCore* GetOMPRSCore();

	inline IPlayer* GetPlayer(int playerid)
	{
		if (players == nullptr)
		{
			return nullptr;
		}

		return players->get(playerid);
	}

	template <typename PlayerDataType>
	inline PlayerDataType* GetPlayerData(int playerid)
	{
		IPlayer* player = GetPlayer(playerid);
		if (player == nullptr)
		{
			return nullptr;
		}

		return queryExtension<PlayerDataType>(*player);
	}

	template <typename PlayerEntityPoolType, typename EntityType>
	inline EntityType* GetPlayerEntity(int playerid, int entity_id)
	{
		PlayerEntityPoolType* pool = GetPlayerData<PlayerEntityPoolType>(playerid);
		if (pool == nullptr)
		{
			return nullptr;
		}

		return pool->get(entity_id);
	}

	template <typename EntityType, typename EntityPoolType>
	inline EntityType* GetEntity(int entity_id)
	{
		EntityPoolType* pool = GetComponent<EntityPoolType>();
		if (pool == nullptr)
		{
			return nullptr;
		}

		return pool->get(entity_id);
	}

	template <typename EntityType>
	inline EntityType* GetEntity(int entity_id)
	{
		return nullptr;
	}

	template <>
	inline IPickup* GetEntity<IPickup>(int entity_id)
	{
		IPickupsComponent* pickups = GetPickups();
		if (pickups == nullptr)
		{
			return nullptr;
		}

		return pickups->get(entity_id);
	}

	template <>
	inline IVehicle* GetEntity<IVehicle>(int entity_id)
	{
		if (vehicles == nullptr)
		{
			return nullptr;
		}

		return vehicles->get(entity_id);
	}

	template <>
	inline IActor* GetEntity<IActor>(int entity_id)
	{
		if (actors == nullptr)
		{
			return nullptr;
		}

		return actors->get(entity_id);
	}

	template <>
	inline IObject* GetEntity<IObject>(int entity_id)
	{
		if (objects == nullptr)
		{
			return nullptr;
		}

		return objects->get(entity_id);
	}

	inline IActor* GetActor(int actorid)
	{
		if (actors == nullptr)
		{
			return nullptr;
		}
		return actors->get(actorid);
	}
};
