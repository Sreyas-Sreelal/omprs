#include "omprs.hpp"
#include "types.hpp"
#include "callbacks/players.hpp"
#include "callbacks/models.hpp"
#include "callbacks/actors.hpp"
#include "callbacks/checkpoints.hpp"
#include "callbacks/classes.hpp"
#include "callbacks/dialogs.hpp"
#include "callbacks/gangzones.hpp"
#include "callbacks/menus.hpp"
#include "callbacks/objects.hpp"
#include "callbacks/pickups.hpp"
#include "callbacks/textdraws.hpp"
#include "callbacks/vehicles.hpp"
#include "callbacks/utils.hpp"

StringView OMPRSComponent::componentName() const
{
	return "OMPRS";
}

SemanticVersion OMPRSComponent::componentVersion() const
{
	return SemanticVersion(1,0, 0, 0);
}

void OMPRSComponent::onFree(IComponent* component)
{
}

void OMPRSComponent::onLoad(ICore* c)
{
	core_ = c;
	core_->printLn("OMPRS loaded sucessfully!");
}

void OMPRSComponent::onReady()
{
	OnGameModeInit* entry_func = (OnGameModeInit*)omprs_core->get_callback_addr("Main");
	if(entry_func)
	{
		(*entry_func)();
	}
	else
	{
		core_->logLn(Error,"Unable to find entrypoint in the gamemode!");
	}
	
}

void OMPRSComponent::free()
{
	delete this;
}

void OMPRSComponent::reset()
{
}

void OMPRSComponent::onInit(IComponentList* components)
{
	auto gm_symbol = core_->getConfig().getString("rust.gamemode");
	omprs_core = new OMPRSCore(gm_symbol.to_string());
	componentList = components;
	players = &core_->getPlayers();
	custommodels = componentList->queryComponent<ICustomModelsComponent>();
	actors = componentList->queryComponent<IActorsComponent>();
	checkpoints = componentList->queryComponent<ICheckpointsComponent>();
	classes = componentList->queryComponent<IClassesComponent>();
	dialogs = componentList->queryComponent<IDialogsComponent>();
	gangzones = componentList->queryComponent<IGangZonesComponent>();
	menus = componentList->queryComponent<IMenusComponent>();
	objects = componentList->queryComponent<IObjectsComponent>();
	pickups = componentList->queryComponent<IPickupsComponent>();
	textdraws = componentList->queryComponent<ITextDrawsComponent>();
	textlabels = componentList->queryComponent<ITextLabelsComponent>();
	vehicles = componentList->queryComponent<IVehiclesComponent>();
	console = componentList->queryComponent<IConsoleComponent>();

	if (players)
	{
		players->getPlayerConnectDispatcher().addEventHandler(PlayerEvents::Get());
		players->getPlayerStreamDispatcher().addEventHandler(PlayerEvents::Get());
		players->getPlayerSpawnDispatcher().addEventHandler(PlayerEvents::Get());
		players->getPlayerTextDispatcher().addEventHandler(PlayerEvents::Get());
		players->getPlayerShotDispatcher().addEventHandler(PlayerEvents::Get());
		players->getPlayerChangeDispatcher().addEventHandler(PlayerEvents::Get());
		players->getPlayerDamageDispatcher().addEventHandler(PlayerEvents::Get());
		players->getPlayerClickDispatcher().addEventHandler(PlayerEvents::Get());
		players->getPlayerCheckDispatcher().addEventHandler(PlayerEvents::Get());
		players->getPlayerUpdateDispatcher().addEventHandler(PlayerEvents::Get());
	}

	if (custommodels)
	{
		custommodels->getEventDispatcher().addEventHandler(ModelEvents::Get());
	}

	if (actors) 
	{
		actors->getEventDispatcher().addEventHandler(ActorEvents::Get());
	}
	
	if (checkpoints)
	{
		checkpoints->getEventDispatcher().addEventHandler(CheckPointEvents::Get());
	}

	if (classes)
	{
		classes->getEventDispatcher().addEventHandler(ClassEvents::Get());
	}

	if (dialogs)
	{
		dialogs->getEventDispatcher().addEventHandler(DialogEvents::Get());
	}

	if (gangzones)
	{
		gangzones->getEventDispatcher().addEventHandler(GangZoneEvents::Get());
	}

	if (menus)
	{
		menus->getEventDispatcher().addEventHandler(MenuEvents::Get());
	}

	if (objects) 
	{
		objects->getEventDispatcher().addEventHandler(ObjectEvents::Get());
	}

	if (pickups)
	{
		pickups->getEventDispatcher().addEventHandler(PickupEvents::Get());
	}

	if (textdraws)
	{
		textdraws->getEventDispatcher().addEventHandler(TextDrawEvents::Get());
	}

	if (vehicles)
	{
		vehicles->getEventDispatcher().addEventHandler(VehicleEvents::Get());
	}

	if (console) 
	{
		console->getEventDispatcher().addEventHandler(CoreEvents::Get());
	}
}

void OMPRSComponent::print(const char* text)
{
	core_->printLn("%s", text);
}

ICore* OMPRSComponent::GetCore()
{
	return core_;
}

IPlayerPool* OMPRSComponent::GetPlayers()
{
	return players;
}

template <typename ComponentType>
ComponentType* OMPRSComponent::GetComponent()
{
	return componentList->queryComponent<ComponentType>();
}

IPickupsComponent* OMPRSComponent::GetPickups()
{
	return pickups;
}

IObjectsComponent* OMPRSComponent::GetObjects()
{
	return objects;
}

IVehiclesComponent* OMPRSComponent::GetVehicles()
{
	return vehicles;
}

ITextLabelsComponent* OMPRSComponent::GetTextLabels()
{
	return textlabels;
}

IActorsComponent* OMPRSComponent::GetActors()
{
	return actors;
}

ICustomModelsComponent* OMPRSComponent::GetCustomModels()
{
	return custommodels;
}

IClassesComponent* OMPRSComponent::GetClasses()
{
	return classes;
}

IGangZonesComponent* OMPRSComponent::GetGangZones()
{
	return gangzones;
}

IMenusComponent* OMPRSComponent::GetMenus()
{
	return menus;
}

ITextDrawsComponent* OMPRSComponent::GetTextDraws()
{
	return textdraws;
}

IConsoleComponent* OMPRSComponent::GetConsole()
{
	return console;
}

OMPRSCore* OMPRSComponent::GetOMPRSCore()
{
	return omprs_core;
}
