#include "HeroInputComponent.h"
#include "../Input/InputHandler.h"
#include "../GameObject/GameObject.h"
#include <raymath.h>
#include <iostream>


HeroInputComponent::HeroInputComponent(std::shared_ptr<InputHandler> input) :
	_input{ input }
{

}

void HeroInputComponent::Update(GameObject& gameObject, std::shared_ptr<PhysicsComponent> physics, const float& deltaTime)
{
	_input->Update(deltaTime);
	gameObject.Velocity = { 0.f, 0.f };
	if (_input->IsJumpPressed() && physics->IsGrounded())
	{
		gameObject.Velocity.y = -95.f;
		gameObject.IsJumping = true;
	}
	if (IsKeyReleased(KEY_SPACE))
	{
		gameObject.IsJumping = false;
	}
	if (_input->IsMoveRightPressed())
	{
		gameObject.Velocity.x = 95.f;
	}
	if (_input->IsMoveLeftPressed())
	{
		gameObject.Velocity.x = -95.f;
	}
	if (_input->IsAttackPressed())
	{
		gameObject.IsAttacking = true;
	}
	if (IsMouseButtonReleased(0))
	{
		gameObject.IsAttacking = false;
	}
}