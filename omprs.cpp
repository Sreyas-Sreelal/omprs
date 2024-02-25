#include "omprs.hpp"
#include "types.hpp"
#include "callbacks/players.hpp"

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
	players = &core_->getPlayers();

	core_->printLn("OMPRS loaded sucessfully!");

	core_->getPlayers().getPlayerConnectDispatcher().addEventHandler(PlayerEvents::Get());
}

void OMPRSComponent::onReady()
{
	auto gm_symbol = core_->getConfig().getString("omprs.gamemode");
	omprs_core = new OMPRSCore(gm_symbol.to_string());
	omprs_core->execute_callback<OnGameModeInit>("OMPRS_Main");
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
	componentList = componentList;
}

void OMPRSComponent::print(const char* text)
{
	core_->printLn(text);
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
