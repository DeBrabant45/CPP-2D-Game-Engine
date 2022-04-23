#include "GroundFactory.h"
#include "GroundGraphicsComponent.h"
#include "GroundPhysicsComponent.h"
#include "../GameObject/GameObject.h"
#include <iostream>

std::shared_ptr<GameObject> GroundFactory::Create(GroundType groundtype, std::shared_ptr<b2World> world, Vector2 size, Vector2 position)
{
	switch (groundtype)
	{
	case GroundType::Hazard:
		return CreateGraveyardHazard(world, size, position);
	case GroundType::Walkable:
		return CreateGraveyard(world, size, position);
	default:
		std::cout << "You did not provide a valid ground type!!";
		break;
	}
}

std::shared_ptr<GameObject> GroundFactory::CreateGraveyard(std::shared_ptr<b2World> world, Vector2 size, Vector2 position)
{
	auto _graveyardGround = std::make_shared<GameObject>();
	_graveyardGround->AddComponent(std::make_shared<Transformation>(position));
	_graveyardGround->AddComponent(std::make_shared<GroundPhysicsComponent>(_graveyardGround, world, GroundType::Walkable, Vector2{ size.x, size.y - 20 }));
	_graveyardGround->AddComponent(std::make_shared<GroundGraphicsComponent>(_graveyardGround, LoadTexture("./Assets/Ground/Graveyard-00.png"), Vector2{ size.x, size.y }));
	return _graveyardGround;
}

std::shared_ptr<GameObject> GroundFactory::CreateGraveyardHazard(std::shared_ptr<b2World> world, Vector2 size, Vector2 position)
{
	auto _graveyardHazard = std::make_shared<GameObject>();
	_graveyardHazard->AddComponent(std::make_shared<Transformation>(position));
	_graveyardHazard->AddComponent(std::make_shared<GroundPhysicsComponent>(_graveyardHazard, world, GroundType::Hazard, Vector2{ size.x, size.y - 35 }));
	_graveyardHazard->AddComponent(std::make_shared<GroundGraphicsComponent>(_graveyardHazard, LoadTexture("./Assets/Ground/Graveyard-hazard.png"), Vector2{ size.x, size.y }));
	return _graveyardHazard;
}