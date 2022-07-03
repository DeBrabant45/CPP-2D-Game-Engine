#include "MovementComponent.h"
#include <box2d/b2_world.h>
#include "../GameObject/GameObject.h"
#include "../Transform/Transformation.h"
#include "../Rigidbody/Rigidbody.h"
#include "RayCastCallback.h"

MovementComponent::MovementComponent(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world) :
	_owner{ owner },
	_world{ world }
{

}

void MovementComponent::Start()
{
	_transform = _owner->GetComponent<Transformation>();
	_rigidbody = _owner->GetComponent<Rigidbody>();
}

const bool MovementComponent::IsGrounded()
{
	b2Vec2 rayDistance{ 0.f, 0.1f };
	b2Vec2 beginRayCastPoint = _rigidbody->GetWorldPoint(rayDistance);
	b2Vec2 target = beginRayCastPoint - _rigidbody->GetWorldCenter();
	target.Normalize();
	target *= 30.0;
	target = beginRayCastPoint + target;
	RayCastCallback rayCastToFloor;
	_world->RayCast(&rayCastToFloor, _rigidbody->GetPosition(), target);
	if (rayCastToFloor.m_fixture)
	{
		return true;
	}
	return false;
}

void MovementComponent::Update(const float& deltaTime)
{
	AddMovement();
}

void MovementComponent::AddMovement()
{
	float velocityChange = _velocity.x - _rigidbody->GetLinearVelocity().x;
	float impulse = _rigidbody->GetMass() * velocityChange;
	float jumpImpluse = _rigidbody->GetMass() * _velocity.y;
	_rigidbody->ApplyLinearImpulseToCenter(b2Vec2(impulse, jumpImpluse), true);
	_velocity = { 0.f, 0.f };
}

void MovementComponent::SetXVelocity(float xVelocity)
{
	_velocity.x += xVelocity;
}

void MovementComponent::SetYVelocity(float yVelocity)
{
	_velocity.y += yVelocity;
}


void MovementComponent::SetLookDirection(float direction)
{
	_lookDirection = direction;
}