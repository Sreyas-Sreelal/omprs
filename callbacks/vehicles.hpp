#pragma once

#include "../api.hpp"

struct VehicleEvents : public VehicleEventHandler, public Singleton<VehicleEvents>
{
private:
	CALLBACK_DECL(void, onVehicleStreamIn, void*, void*);
	CALLBACK_DECL(void, onVehicleStreamOut, void*, void*);
	CALLBACK_DECL(void, onVehicleDeath, void*, void*);
	CALLBACK_DECL(void, onPlayerEnterVehicle, void*, void*,bool);
	CALLBACK_DECL(void, onPlayerExitVehicle, void*, void*);
	CALLBACK_DECL(void, onVehicleDamageStatusUpdate, void*, void*);
	CALLBACK_DECL(bool, onVehiclePaintJob,void*, void*, int);
	CALLBACK_DECL(bool, onVehicleMod,void*,void*,int);
	CALLBACK_DECL(bool, onVehicleRespray,void*,void*, int, int);
	CALLBACK_DECL(void, onEnterExitModShop, void*, bool, int);
	CALLBACK_DECL(void, onVehicleSpawn, void*);
	CALLBACK_DECL(bool, onUnoccupiedVehicleUpdate, void*, void*, UnoccupiedVehicleUpdate);
	CALLBACK_DECL(bool, onTrailerUpdate,void*,void*);
	CALLBACK_DECL(bool, onVehicleSirenStateChange,void*,void*, uint8_t);

public:
	VehicleEvents() 
	{
		INIT_CALLBACK(onVehicleStreamIn);
		INIT_CALLBACK(onVehicleStreamOut);
		INIT_CALLBACK(onVehicleDeath);
		INIT_CALLBACK(onPlayerEnterVehicle);
		INIT_CALLBACK(onPlayerExitVehicle);
		INIT_CALLBACK(onVehicleDamageStatusUpdate);
		INIT_CALLBACK(onVehiclePaintJob);
		INIT_CALLBACK(onVehicleMod);
		INIT_CALLBACK(onVehicleRespray);
		INIT_CALLBACK(onEnterExitModShop);
		INIT_CALLBACK(onVehicleSpawn);
		INIT_CALLBACK(onUnoccupiedVehicleUpdate);
		INIT_CALLBACK(onTrailerUpdate);
		INIT_CALLBACK(onVehicleSirenStateChange);
	}
	void onVehicleStreamIn(IVehicle& vehicle, IPlayer& player) override
	{
		EXEC_CALLBACK(onVehicleStreamIn, &vehicle, &player);
	}

	void onVehicleStreamOut(IVehicle& vehicle, IPlayer& player) override
	{
		EXEC_CALLBACK(onVehicleStreamOut, &vehicle, &player);
	}

	void onVehicleDeath(IVehicle& vehicle, IPlayer& player) override
	{
		EXEC_CALLBACK(onVehicleDeath, &vehicle, &player);
	}

	void onPlayerEnterVehicle(IPlayer& player, IVehicle& vehicle, bool passenger) override
	{
		EXEC_CALLBACK(onPlayerEnterVehicle, &player, &vehicle, passenger);
	}

	void onPlayerExitVehicle(IPlayer& player, IVehicle& vehicle) override
	{
		EXEC_CALLBACK(onPlayerExitVehicle, &player, &vehicle);
	}

	void onVehicleDamageStatusUpdate(IVehicle& vehicle, IPlayer& player) override
	{
		EXEC_CALLBACK(onVehicleDamageStatusUpdate, &vehicle, &player);
	}

	bool onVehiclePaintJob(IPlayer& player, IVehicle& vehicle, int paintJob) override
	{
		EXEC_CALLBACK(onVehiclePaintJob,&player, &vehicle, paintJob);
		return true;
	}

	bool onVehicleMod(IPlayer& player, IVehicle& vehicle, int component) override
	{
		EXEC_CALLBACK(onVehicleMod, &player, &vehicle, component);
		return true;
	}

	bool onVehicleRespray(IPlayer& player, IVehicle& vehicle, int colour1, int colour2) override
	{
		EXEC_CALLBACK(onVehicleRespray, &player, &vehicle, colour1, colour2);
		return true;
	}

	void onEnterExitModShop(IPlayer& player, bool enterexit, int interiorID) override
	{
		EXEC_CALLBACK(onEnterExitModShop, &player, enterexit, interiorID);
	}

	void onVehicleSpawn(IVehicle& vehicle) override
	{
		EXEC_CALLBACK(onVehicleSpawn, &vehicle);
	}

	bool onUnoccupiedVehicleUpdate(IVehicle& vehicle, IPlayer& player, UnoccupiedVehicleUpdate const updateData) override
	{
		EXEC_CALLBACK(onUnoccupiedVehicleUpdate,&vehicle,&player,updateData);
		return true;
	}

	bool onTrailerUpdate(IPlayer& player, IVehicle& trailer) override
	{
		EXEC_CALLBACK(onTrailerUpdate, &player, &trailer);
		return true;
	}

	bool onVehicleSirenStateChange(IPlayer& player, IVehicle& vehicle, uint8_t sirenState) override
	{
		EXEC_CALLBACK(onVehicleSirenStateChange,&player,&vehicle,sirenState);
		return true;
	}
};
