#include "omprs.hpp"
#include "types.hpp"
#include "callbacks/players.hpp"
#include "callbacks/models.hpp"

StringView OMPRSComponent::componentName() const
{
	return "OMPRS";
}

SemanticVersion OMPRSComponent::componentVersion() const
{
	return SemanticVersion(0, 0, 1, 0);
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
	(*entry_func)();
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
	auto gm_symbol = core_->getConfig().getString("omprs.gamemode");
	omprs_core = new OMPRSCore(gm_symbol.to_string());
	componentList = components;
	players = &core_->getPlayers();
	custommodels = componentList->queryComponent<ICustomModelsComponent>();

	if (players)
	{
		players->getPlayerConnectDispatcher().addEventHandler(PlayerEvents::Get());
		players->getPlayerStreamDispatcher().addEventHandler(PlayerEvents::Get());
		players->getPlayerSpawnDispatcher().addEventHandler(PlayerEvents::Get());
		players->getPlayerTextDispatcher().addEventHandler(PlayerEvents::Get());
		//players->getPlayerShotDispatcher().addEventHandler(PlayerEvents::Get());
		players->getPlayerChangeDispatcher().addEventHandler(PlayerEvents::Get());
		players->getPlayerDamageDispatcher().addEventHandler(PlayerEvents::Get());
		players->getPlayerClickDispatcher().addEventHandler(PlayerEvents::Get());
		players->getPlayerCheckDispatcher().addEventHandler(PlayerEvents::Get());
	}

	if (custommodels)
	{
		custommodels->getEventDispatcher().addEventHandler(ModelEvents::Get());
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

OMPRSCore* OMPRSComponent::GetOMPRSCore()
{
	return omprs_core;
}
