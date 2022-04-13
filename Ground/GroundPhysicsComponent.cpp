#include "GroundPhysicsComponent.h"
#include "../GameObject/IGameObject.h"
#include "../../box2d-main/include/box2d/box2d.h"
#include <iostream>

GroundPhysicsComponent::GroundPhysicsComponent(std::shared_ptr<b2World> world, GroundType groundType, Vector2 size, Vector2 worldPosition) :
	_world{ world },
	_rigidbody{ world }
{
	_rigidbody.CreateDefinition(b2_staticBody, worldPosition);
	_rigidbody.AddToWorld();
	_rigidbody.CreateShape(size);
	_rigidbody.CreateFixtureDefinition<GroundType>(0.f, 5.3f, groundType);
}

void GroundPhysicsComponent::Update(IGameObject& gameObject, const float& deltaTime)
{
	Vector2 position{ _rigidbody.GetPosition().x, _rigidbody.GetPosition().y };
	gameObject.SetPosition(position);
}

void GroundPhysicsComponent::Receive(int message)
{
}
