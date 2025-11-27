#pragma once
#include <queue>
#include "Object.h"

#define SPAWNER Spawner::Instance()


class Spawner
{
public:
	static Spawner& Instance() 
	{
		static Spawner sp;
		return sp;
	}

	void SpawnObject(Object* obj) { spawnedObject.push(obj); }
	bool AreObjectsPendingSpawn() { return !spawnedObject.empty(); }
	
	Object* GetSpawnedObject() 
	{
		if (!AreObjectsPendingSpawn())
			return nullptr;
	
		Object* temp = spawnedObject.front();
		spawnedObject.pop();
		return temp;
	}

	void ClearSpawner() 
	{
		while (AreObjectsPendingSpawn()) 
		{
			delete spawnedObject.front();
			spawnedObject.pop();
		}
	}

private:
	Spawner() = default;
	Spawner(Spawner&) = delete;
	Spawner& operator =(const Spawner&) = delete;

	std::queue<Object*> spawnedObject;
};
