#pragma once
#include <memory>
#include "../GameObject.h"
#include "IGameObjectProduction.h"

class b2World;

class GameObjectFactory
{
public:
	std::shared_ptr<GameObject> CreateGameObject(std::shared_ptr<b2World> world, Vector2 position);

protected:
	virtual std::shared_ptr<IGameObjectProduction> CreateProduction() = 0;
};