#include "HeroGraphicsComponent.h"
#include <iostream>
#include <raymath.h>

HeroGraphicsComponent::HeroGraphicsComponent()
{

}

void HeroGraphicsComponent::Update(GameObject& gameObject, std::shared_ptr<PhysicsComponent> physics, const float& deltaTime)
{
	SetLookDirection(gameObject);
	if (gameObject.Velocity.x != 0.0f)
	{
		_run.Draw(deltaTime, gameObject.GetPosition(), _lookDirection);
	}
	else if (!physics->IsGrounded())
	{
		_jump.Draw(deltaTime, gameObject.GetPosition(), _lookDirection);
	}
	else if (gameObject.IsAttacking)
	{
		_attack.Draw(deltaTime, gameObject.GetPosition(), _lookDirection);
	}
	else
	{
		idle.Draw(deltaTime, gameObject.GetPosition(), _lookDirection);
	}
}

void HeroGraphicsComponent::SetLookDirection(GameObject& gameObject)
{
	if (gameObject.Velocity.x > 0)
	{
		_lookDirection = 1.f;
	}
	else if (gameObject.Velocity.x < 0)
	{
		_lookDirection = -1.f;
	}
}