#include "GameObjectFactory.h"
#include <box2d/box2d.h>

std::shared_ptr<GameObject> GameObjectFactory::CreateGameObject(std::shared_ptr<b2World> world, Vector2 position)
{
	auto gameObjectProduction = CreateProduction();
	return gameObjectProduction->Produce(world, position);
}