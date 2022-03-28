#include "GroundFactory.h"
#include "Ground.h"
#include "GroundGraphicsComponent.h"
#include "GroundPhysicsComponent.h"

std::shared_ptr<Ground> GroundFactory::Create(std::shared_ptr<b2World> world, Vector2 size, Vector2 position)
{
	return std::make_shared<Ground>(std::vector<std::shared_ptr<IGameObjectComponent>> {
			std::make_shared<GroundPhysicsComponent>(world, Vector2{ size.x, size.y }, Vector2{ position.x, position.y }),
			std::make_shared<GroundGraphicsComponent>(LoadTexture("./Assets/Ground/Ground.png"), Vector2{ size.x, size.y })}, 
			GroundType::Walkable);
}