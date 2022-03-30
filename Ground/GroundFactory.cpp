#include "GroundFactory.h"
#include "Ground.h"
#include "GroundGraphicsComponent.h"
#include "GroundPhysicsComponent.h"

std::shared_ptr<Ground> GroundFactory::Create(std::shared_ptr<b2World> world, Vector2 size, Vector2 position)
{
	return std::make_shared<Ground>(std::vector<std::shared_ptr<IGameObjectComponent>> {
			std::make_shared<GroundPhysicsComponent>(world, GroundType::Walkable, Vector2{ size.x, size.y }, Vector2{ position.x, position.y }),
			std::make_shared<GroundGraphicsComponent>(LoadTexture("./Assets/Ground/Graveyard-00.png"), Vector2{ size.x, size.y })}, 
			GroundType::Walkable);
}

std::shared_ptr<Ground> GroundFactory::CreateGraveyard(std::shared_ptr<b2World> world, Vector2 size, Vector2 position)
{
	return std::make_shared<Ground>(std::vector<std::shared_ptr<IGameObjectComponent>> {
			std::make_shared<GroundPhysicsComponent>(world, GroundType::Walkable, Vector2{ size.x, size.y - 20 }, Vector2{ position.x, position.y }),
			std::make_shared<GroundGraphicsComponent>(LoadTexture("./Assets/Ground/Graveyard-00.png"), Vector2{ size.x, size.y })},
		GroundType::Walkable);
}

std::shared_ptr<Ground> GroundFactory::CreateGraveyardHazard(std::shared_ptr<b2World> world, Vector2 size, Vector2 position)
{
	return std::make_shared<Ground>(std::vector<std::shared_ptr<IGameObjectComponent>> {
			std::make_shared<GroundPhysicsComponent>(world, GroundType::Hazard, Vector2{ size.x, size.y - 35 }, Vector2{ position.x, position.y }),
			std::make_shared<GroundGraphicsComponent>(LoadTexture("./Assets/Ground/Graveyard-hazard.png"), Vector2{ size.x, size.y })},
		GroundType::Hazard);
}