#include "GroundGraphicsComponent.h"
#include "../GameObject/IGameObject.h"

GroundGraphicsComponent::GroundGraphicsComponent(const Texture2D texture, Vector2 size) :
	_ground{ texture, size, 1, 0}
{

}

void GroundGraphicsComponent::Update(IGameObject& gameObject, const float& deltaTime)
{
	_ground.Draw(deltaTime, gameObject.GetPosition(), 1.f);
}

void GroundGraphicsComponent::Receive(int message)
{
}
