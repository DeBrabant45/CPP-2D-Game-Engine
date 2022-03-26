#include "GroundGraphicsComponent.h"

void GroundGraphicsComponent::Update(IGameObject& gameObject, const float& deltaTime)
{
	_ground.Draw(deltaTime, gameObject.GetPosition(), 1.f);
}