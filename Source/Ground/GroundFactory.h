#pragma once
#ifndef GROUNDFACTORY_H
#define GROUNDFACTORY_H
#include <raylib.h>
#include <memory>
#include "../Ground/GroundType.h"

class b2World;
class GameObject;

class GroundFactory
{
private:
	std::shared_ptr<GameObject> CreateGraveyard(std::shared_ptr<b2World> world, Vector2 size, Vector2 position);
	std::shared_ptr<GameObject> CreateGraveyardHazard(std::shared_ptr<b2World> world, Vector2 size, Vector2 position);

public:
	std::shared_ptr<GameObject> CreateGameObject(GroundType groundtype, std::shared_ptr<b2World> world, Vector2 size, Vector2 position);
};
#endif