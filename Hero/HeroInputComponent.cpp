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
	if (_input->IsJumpPressed() && character.IsGrounded)
	{
		character.Velocity.y = -95.f;
	}
	else if (_input->IsMoveRightPressed())
	{
		character.Velocity.x = 95.f;
	}
	else if (_input->IsMoveLeftPressed())
	{
		character.Velocity.x = -95.f;
	}
	else if (_input->IsAttackPressed())
	{

	}
}