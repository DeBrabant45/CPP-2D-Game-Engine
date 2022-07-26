#pragma once
#include <memory>
#include "../GameObject.h"
#include <box2d/box2d.h>

class IGameObjectProduction
{
public:
	virtual std::shared_ptr<GameObject> Produce(std::shared_ptr<b2World> world, Vector2 position) = 0;
};