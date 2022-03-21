#include "GroundGraphicsComponent.h"

void GroundGraphicsComponent::Update(GameObject& gameOjbect, std::shared_ptr<PhysicsComponent> physics, const float& deltaTime)
{
	_ground.Draw(deltaTime, gameOjbect.GetPosition(), 1.f);
}