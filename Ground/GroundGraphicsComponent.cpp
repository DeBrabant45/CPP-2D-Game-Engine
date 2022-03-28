#include "GroundGraphicsComponent.h"

GroundGraphicsComponent::GroundGraphicsComponent(const Texture2D texture, Vector2 size) :
	_ground{ texture, size, 1, 0}
{

}

void GroundGraphicsComponent::Update(IGameObject& gameObject, const float& deltaTime)
{
	_ground.Draw(deltaTime, gameObject.GetPosition(), 1.f);
}