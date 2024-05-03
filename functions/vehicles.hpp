#pragma once

#include "../api.hpp"

OMPRS_API(void*, CreateVehicle(int modelid, Vector3 pos, float rotation, int colour1, int colour2, int respawnDelay, bool addSiren))
{
	IVehiclesComponent* vehicles = OMPRSComponent::Get()->GetVehicles();
	if (vehicles)
	{
		IVehicle* vehicle = vehicles->create(false, modelid, pos, rotation, colour1, colour2, Seconds(respawnDelay), addSiren);
		if (vehicle)
		{
			return vehicle;
		}
	}
	return nullptr;
}

OMPRS_API(int,GetVehicleSeats(int modelid))
{
	return Impl::getVehiclePassengerSeats(modelid);
}

OMPRS_API(void,DestroyVehicle(void* vehicle))
{
	OMPRSComponent::Get()->GetVehicles()->release(static_cast<IVehicle*>(vehicle)->getID());
}

OMPRS_API(bool,IsVehicleStreamedIn(void* vehicle, void* player))
{
	return static_cast<IVehicle*>(vehicle)->isStreamedInForPlayer(*static_cast<IPlayer*>(player));
}

OMPRS_API(void,GetVehiclePos(void* vehicle, Vector3* pos))
{
	*pos = static_cast<IVehicle*>(vehicle)->getPosition();
}

OMPRS_API(void,SetVehiclePos(void* vehicle, Vector3 pos))
{
	static_cast<IVehicle*>(vehicle)->setPosition(pos);
}

OMPRS_API(float,GetVehicleZAngle(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->getZAngle();
}

OMPRS_API(void,GetVehicleRotationQuat(void* vehicle, Vector4* rotation))
{
	auto quat = static_cast<IVehicle*>(vehicle)->getRotation();
	rotation->w = quat.q.w;
	rotation->x = quat.q.x;
	rotation->y = quat.q.y;
	rotation->z = quat.q.z;
}

OMPRS_API(float,GetVehicleDistanceFromPoint(void* vehicle, Vector3 pos))
{
	return glm::distance(static_cast<IVehicle*>(vehicle)->getPosition(), pos);
}

OMPRS_API(void,SetVehicleZAngle(void* vehicle, float angle))
{
	static_cast<IVehicle*>(vehicle)->setZAngle(angle);
}

OMPRS_API(void, SetVehicleParamsForPlayer(void* vehicle, void* player, VehicleParams params))
{
	static_cast<IVehicle*>(vehicle)->setParamsForPlayer(*static_cast<IPlayer*>(player), params);
}

OMPRS_API(void,SetManualVehicleEngineAndLights(bool set))
{	
	*OMPRSComponent::Get()->GetCore()->getConfig().getBool("game.use_manual_engine_and_lights") = set;
}

OMPRS_API(void, SetVehicleParams(void* vehicle, VehicleParams params))
{
	static_cast<IVehicle*>(vehicle)->setParams(params);
}

OMPRS_API(void,GetVehicleParams(void* vehicle, VehicleParams* params))
{
	*params = static_cast<IVehicle*>(vehicle)->getParams();
}

OMPRS_API(void,SetVehicleToRespawn(void* vehicle))
{
	static_cast<IVehicle*>(vehicle)->respawn();
}

OMPRS_API(void,LinkVehicleToInterior(void* vehicle, int interiorid))
{
	static_cast<IVehicle*>(vehicle)->setInterior(interiorid);
}

OMPRS_API(void,AddVehicleComponent(void* vehicle, int componentid))
{
	static_cast<IVehicle*>(vehicle)->addComponent(componentid);
}

OMPRS_API(void,RemoveVehicleComponent(void* vehicle, int componentid))
{
	static_cast<IVehicle*>(vehicle)->removeComponent(componentid);
}

OMPRS_API(void,ChangeVehicleColor(void* vehicle, int colour1, int colour2))
{
	static_cast<IVehicle*>(vehicle)->setColour(colour1, colour2);
}

OMPRS_API(void,ChangeVehiclePaintjob(void* vehicle, int paintjobid))
{
	static_cast<IVehicle*>(vehicle)->setPaintJob(paintjobid);
}

OMPRS_API(void,SetVehicleHealth(void* vehicle, float health))
{
	static_cast<IVehicle*>(vehicle)->setHealth(health);
}

OMPRS_API(float,GetVehicleHealth(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->getHealth();
}

OMPRS_API(void,AttachTrailerToVehicle(void* vehicle,void *trailer))
{
	static_cast<IVehicle*>(vehicle)->attachTrailer(*static_cast<IVehicle*>(trailer));
}

OMPRS_API(void,DetachTrailerFromVehicle(void* vehicle))
{
	static_cast<IVehicle*>(vehicle)->detachTrailer();
}

OMPRS_API(bool,IsTrailerAttachedToVehicle(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->getTrailer() != nullptr;
}

OMPRS_API(void*,GetVehicleTrailer(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->getTrailer();
}

OMPRS_API(void,SetVehicleNumberPlate(void* vehicle, StringView numberPlate))
{
	static_cast<IVehicle*>(vehicle)->setPlate(numberPlate);
}

OMPRS_API(int,GetVehicleModel(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->getModel();
}

OMPRS_API(int,GetVehicleComponentInSlot(void* vehicle, int slot))
{
	return static_cast<IVehicle*>(vehicle)->getComponentInSlot(slot);
}

OMPRS_API(int,GetVehicleComponentType(int componentid))
{
	return Impl::getVehicleComponentSlot(componentid);
}

OMPRS_API(bool,VehicleCanHaveComponent(int modelid, int componentid))
{
	return Impl::isValidComponentForVehicleModel(modelid, componentid);
}

OMPRS_API(void,GetRandomCarColPair(int modelid, int* colour1, int* colour2, int* colour3, int* colour4))
{
	int ref_colour1, ref_colour2, ref_colour3, ref_colour4;
	Impl::getRandomVehicleColour(modelid, ref_colour1, ref_colour2, ref_colour3, ref_colour4);
	*colour1 = ref_colour1;
	*colour2 = ref_colour2;
	*colour3 = ref_colour3; 
	*colour4 = ref_colour4;
}

OMPRS_API(int,CarColIndexToColour(int colourIndex, int alpha))
{
	return Impl::carColourIndexToColour(colourIndex, alpha);
}

OMPRS_API(void,RepairVehicle(void* vehicle))
{
	static_cast<IVehicle*>(vehicle)->repair();
}

OMPRS_API(void,GetVehicleVelocity(void* vehicle, Vector3* velocity))
{
	*velocity = static_cast<IVehicle*>(vehicle)->getVelocity();
}

OMPRS_API(void,SetVehicleVelocity(void* vehicle, Vector3 velocity))
{
	static_cast<IVehicle*>(vehicle)->setVelocity(velocity);
}

OMPRS_API(void,SetVehicleAngularVelocity(void* vehicle, Vector3 velocity))
{
	static_cast<IVehicle*>(vehicle)->setAngularVelocity(velocity);
}

OMPRS_API(void,GetVehicleDamageStatus(void* vehicle, int* panels, int* doors, int* lights, int* tires))
{
	int ref_panels, ref_doors, ref_lights, ref_tires;
	static_cast<IVehicle*>(vehicle)->getDamageStatus(ref_panels, ref_doors, ref_lights, ref_tires);
	*panels = ref_panels;
	*doors = ref_doors;
	*lights = ref_lights;
	*tires = ref_tires;
}

OMPRS_API(void,UpdateVehicleDamageStatus(void* vehicle, int panels, int doors, int lights, int tires))
{
	static_cast<IVehicle*>(vehicle)->setDamageStatus(panels, doors, lights, tires);
}

OMPRS_API(void,GetVehicleModelInfo(int vehiclemodel, int infotype, Vector3* pos))
{
	auto ref_pos = Vector3(0, 0, 0);
	Impl::getVehicleModelInfo(vehiclemodel, VehicleModelInfoType(infotype), ref_pos);
	*pos = ref_pos;
}

OMPRS_API(void,SetVehicleVirtualWorld(void* vehicle, int virtualWorld))
{
	static_cast<IVehicle*>(vehicle)->setVirtualWorld(virtualWorld);
}

OMPRS_API(int,GetVehicleVirtualWorld(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->getVirtualWorld();
}

OMPRS_API(int,GetVehicleLandingGearState(void* vehicle))
{
	return !static_cast<IVehicle*>(vehicle)->getLandingGearState();
}

OMPRS_API(void*,AddStaticVehicle(int modelid, Vector3 spawn, float angle, int colour1, int colour2, int respawnDelay,bool addSiren))
{
	IVehiclesComponent* vehicles = OMPRSComponent::Get()->GetVehicles();
	if (vehicles)
	{
		IVehicle* vehicle = vehicles->create(true, modelid, spawn, angle, colour1, colour2, Seconds(respawnDelay), addSiren);
		if (vehicle)
		{
			return vehicle;
		}
	}
	return nullptr;
}

OMPRS_API(void,EnableVehicleFriendlyFire(bool set))
{
	*OMPRSComponent::Get()->GetCore()->getConfig().getBool("game.use_vehicle_friendly_fire") = set;
}

OMPRS_API(void, GetVehicleSpawnInfo(void* vehicle, Vector3* position, float* rotation, int* colour1, int* colour2, int* respawnDelay,int* modelID,bool* siren,int* interior))
{
	const VehicleSpawnData& data = static_cast<IVehicle*>(vehicle)->getSpawnData();

	*position = data.position;
	*rotation = data.zRotation;
	*colour1 = data.colour1;
	*colour2 = data.colour2;
	*modelID = data.modelID;
	*siren = data.siren;
	*interior = data.interior;
	*respawnDelay = data.respawnDelay.count();
}

OMPRS_API(void,SetVehicleSpawnInfo(void* vehicle, int modelid, Vector3 position, float rotation, int colour1, int colour2, int respawn_time, int interior))
{
	const VehicleSpawnData& data = static_cast<IVehicle*>(vehicle)->getSpawnData();

	static_cast<IVehicle*>(vehicle)->setSpawnData({ respawn_time >= -1 ? Seconds(respawn_time) : data.respawnDelay, modelid, position, rotation, colour1, colour2, data.siren, interior != -2 ? interior : data.interior });
}

OMPRS_API(int,GetVehicleModelCount(int modelid))
{
	if (modelid < 400 || modelid > 611)
		return 0;

	auto& models = OMPRSComponent::Get()->GetVehicles()->models();
	return models[modelid - 400];
}

OMPRS_API(int,GetVehicleModelsUsed(void))
{
	auto& vehicle_models = OMPRSComponent::Get()->GetVehicles()->models();

	return std::count_if(vehicle_models.begin(), vehicle_models.end(), [](uint8_t model_instances)
	{
		return model_instances > 0;
	});
}

OMPRS_API(int,GetVehiclePaintjob(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->getPaintJob();
}

OMPRS_API(void,GetVehicleColor(void* vehicle, int* colour1, int* colour2))
{
	Pair<int, int> colors = static_cast<IVehicle*>(vehicle)->getColour();

	*colour1 = colors.first;
	*colour2 = colors.second;
}

OMPRS_API(int,GetVehicleInterior(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->getInterior();
}

OMPRS_API(void,GetVehicleNumberPlate(void* vehicle, StringView* number_plate))
{
	*number_plate = static_cast<IVehicle*>(vehicle)->getPlate();
}

OMPRS_API(void,SetVehicleRespawnDelay(void* vehicle, int respawn_delay))
{
	if (respawn_delay < -1)
		return;
	static_cast<IVehicle*>(vehicle)->setRespawnDelay(Seconds(respawn_delay));
}

OMPRS_API(int,GetVehicleRespawnDelay(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->getRespawnDelay().count();
}

OMPRS_API(void*,GetVehicleCab(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->getCab();	
}

OMPRS_API(int,GetVehicleOccupiedTick(void* vehicle))
{
	return std::chrono::duration_cast<Milliseconds>(Time::now() - static_cast<IVehicle*>(vehicle)->getLastOccupiedTime()).count();
}

OMPRS_API(int,GetVehicleRespawnTick(void* vehicle))
{
	return std::chrono::duration_cast<Milliseconds>(Time::now() - static_cast<IVehicle*>(vehicle)->getLastSpawnTime()).count();
}

OMPRS_API(bool,HasVehicleBeenOccupied(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->hasBeenOccupied();
}

OMPRS_API(bool,IsVehicleOccupied(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->isOccupied();
}

OMPRS_API(bool,IsVehicleDead(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->isDead();
}

OMPRS_API(void,ToggleVehicleSirenEnabled(void* vehicle, bool status))
{
	static_cast<IVehicle*>(vehicle)->setSiren(status);
}

OMPRS_API(bool,IsVehicleSirenEnabled(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->getSpawnData().siren;
}

OMPRS_API(int,GetVehicleLastDriver(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->getLastDriverPoolID();
}

OMPRS_API(void*,GetVehicleDriver(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->getDriver();
}

OMPRS_API(bool,IsPlayerInModShop(void* player))
{
	IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(*static_cast<IPlayer*>(player));
	if (!data) 
	{
		return false;
	}
	return data->isInModShop();
}

OMPRS_API(int, GetPlayerSirenState(void* player))
{
	IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(*static_cast<IPlayer*>(player));
	if (data)
	{
		IVehicle* vehicle = data->getVehicle();
		if (vehicle)
		{
			return vehicle->getSirenState();
		}
	}
	
	return 0;
}

OMPRS_API(int, GetPlayerLandingGearState(void* player))
{
	IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(*static_cast<IPlayer*>(player));
	if (data)
	{
		IVehicle* vehicle = data->getVehicle();
		if (vehicle)
		{
			return vehicle->getLandingGearState();
		}
	}
	return 0;
}

OMPRS_API(int, GetPlayerHydraReactorAngle(void* player))
{
	IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(*static_cast<IPlayer*>(player));
	if (data)
	{
		IVehicle* vehicle = data->getVehicle();
		if (vehicle)
		{
			return vehicle->getHydraThrustAngle();
		}
	}
	return 0;
}

OMPRS_API(float, GetPlayerTrainSpeed(void* player))
{
	IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(*static_cast<IPlayer*>(player));
	if (data)
	{
		IVehicle* vehicle = data->getVehicle();
		if (vehicle)
		{
			return vehicle->getTrainSpeed();
		}
	}
	return 0.0f;
}

OMPRS_API(int,GetVehicleSirenState(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->getSirenState();
}

OMPRS_API(int,GetVehicleHydraReactorAngle(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->getHydraThrustAngle();
}

OMPRS_API(float,GetVehicleTrainSpeed(void* vehicle))
{
	return static_cast<IVehicle*>(vehicle)->getTrainSpeed();
}

OMPRS_API(void,GetVehicleMatrix(void* vehicle, Vector3* right, Vector3* up, Vector3* at))
{
	glm::mat3 mat = glm::transpose(glm::mat3_cast(static_cast<IVehicle*>(vehicle)->getRotation().q));

	*right = mat[0];
	*up = mat[1];
	*at = mat[2];
}

OMPRS_API(void*,GetVehicleOccupant(void* vehicle, int seat))
{
	IPlayer* driver = static_cast<IVehicle*>(vehicle)->getDriver();
	if (seat == 0)
	{
		return driver;
	}
	else
	{
		const FlatHashSet<IPlayer*>& passengers = static_cast<IVehicle*>(vehicle)->getPassengers();
		for (auto& passenger : passengers)
		{
			if (passenger)
			{
				IPlayerVehicleData* data = queryExtension<IPlayerVehicleData>(passenger);
				if (data && data->getSeat() == seat)
				{
					return passenger;
				}
			}
		}
	}
	return nullptr;
}

OMPRS_API(int,GetVehicleMaxPassengers(int model))
{
	return Impl::getVehiclePassengerSeats(model);
}

OMPRS_API(int,CountVehicleOccupants(void* vehicle))
{
	IPlayer* driver = static_cast<IVehicle*>(vehicle)->getDriver();
	const FlatHashSet<IPlayer*>& passengers = static_cast<IVehicle*>(vehicle)->getPassengers();
	int occupants = 0;

	if (driver)
	{
		occupants++;
	}

	occupants += passengers.size();
	return occupants;
}

OMPRS_API(void*, GetVehicleFromID(int id))
{
	IVehiclesComponent* vehicles = OMPRSComponent::Get()->GetVehicles();
	if (vehicles)
	{
		return vehicles->get(id);
	}
	return nullptr;
}

OMPRS_API(int, GetVehicleID(void* vehicle))
{
	if (vehicle)
	{
		return static_cast<IVehicle*>(vehicle)->getID();
	}
	return INVALID_VEHICLE_ID;
}