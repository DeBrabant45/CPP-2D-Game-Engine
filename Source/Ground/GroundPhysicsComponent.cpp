#include "GroundPhysicsComponent.h"
#include "../GameObject/GameObject.h"
#include "../Transform/Transformation.h"
#include <box2d/box2d.h>
#include <iostream>

GroundPhysicsComponent::GroundPhysicsComponent(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world, GroundType groundType, Vector2 size) :
	_owner{ owner },
	_world{ world },
	_rigidbody{ world }, 
	_groundType{ groundType },
	_size{ size }
{

}

void GroundPhysicsComponent::Start()
{
	_transform = _owner->GetComponent<Transformation>();
	_rigidbody.CreateDefinition(b2_staticBody, _transform->GetPosition());
	_rigidbody.AddToWorld();
	_rigidbody.CreateShape(_size);
	_rigidbody.CreateFixtureDefinition<GroundType>(0.f, 5.3f, _groundType);
}

void GroundPhysicsComponent::Update(const float& deltaTime)
{
	Vector2 position{ _rigidbody.GetPosition().x, _rigidbody.GetPosition().y };
	_transform->SetPosition(position);
}

void GroundPhysicsComponent::Receive(int message)
{

}