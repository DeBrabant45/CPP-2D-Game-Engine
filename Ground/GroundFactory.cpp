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
	return std::make_shared<GameObject>(std::vector< std::shared_ptr<IComponent<IGameObject> > >
	{
		std::make_shared<GroundPhysicsComponent>(world, GroundType::Walkable, Vector2{ size.x, size.y - 20 }, Vector2{ position.x, position.y }),
		std::make_shared<GroundGraphicsComponent>(LoadTexture("./Assets/Ground/Graveyard-00.png"), Vector2{ size.x, size.y })
	});
}

std::shared_ptr<GameObject> GroundFactory::CreateGraveyardHazard(std::shared_ptr<b2World> world, Vector2 size, Vector2 position)
{
	return std::make_shared<GameObject>(std::vector< std::shared_ptr<IComponent<IGameObject> > >
	{
		std::make_shared<GroundPhysicsComponent>(world, GroundType::Hazard, Vector2{ size.x, size.y - 35 }, Vector2{ position.x, position.y }),
		std::make_shared<GroundGraphicsComponent>(LoadTexture("./Assets/Ground/Graveyard-hazard.png"), Vector2{ size.x, size.y })
	});
}