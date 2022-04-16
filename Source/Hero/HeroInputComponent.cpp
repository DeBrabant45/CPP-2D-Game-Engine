#include "HeroInputComponent.h"
#include "../Input/InputHandler.h"
#include "../Character/Character.h"
#include <iostream>


HeroInputComponent::HeroInputComponent(std::shared_ptr<InputHandler> input) :
	_input{ input }
{

}

void HeroInputComponent::Update(Character& character, const float& deltaTime)
{
	_input->Update(deltaTime);
	character.Velocity = {0.f, 0.f};
	if (_input->IsJumpPressed() && character.IsGrounded && !character.IsAttacking)
	{
		character.Velocity.y = -95.f;
	}
	else if (_input->IsMoveRightPressed() && !character.IsAttacking)
	{
		character.Velocity.x = 95.f;
	}
	else if (_input->IsMoveLeftPressed() && !character.IsAttacking)
	{
		character.Velocity.x = -95.f;
	}
	else if (_input->IsAttackPressed() && character.IsGrounded)
	{
		character.AttackTimer = 40.f;
	}
}

void HeroInputComponent::Receive(int message)
{

}