#include "GroundGraphicsComponent.h"
#include "../GameObject/GameObject.h"

GroundGraphicsComponent::GroundGraphicsComponent(std::shared_ptr<GameObject> owner, const Texture2D texture, Vector2 size) :
	_owner{ owner },
	_ground{ texture, size, 1, 0}
{

}

void GroundGraphicsComponent::Start()
{
	_transform = _owner->GetComponent<Transformation>();
}

void GroundGraphicsComponent::Update(const float& deltaTime)
{
	_ground.Draw(deltaTime, _transform->GetPosition(), 1.f);
}