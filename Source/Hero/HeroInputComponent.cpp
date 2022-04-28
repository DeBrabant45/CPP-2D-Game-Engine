#include "HeroInputComponent.h"
#include "../Input/InputHandler.h"
#include "../GameObject/GameObject.h"
#include "../Hero/HeroPhysicsComponent.h"
#include <iostream>


HeroInputComponent::HeroInputComponent(std::shared_ptr<GameObject> owner, std::shared_ptr<InputHandler> input) :
	_owner{ owner },
	_input{ input }
{

}

void HeroInputComponent::Start()
{
	_physics = _owner->GetComponent<HeroPhysicsComponent>();
}

void HeroInputComponent::Update(const float& deltaTime)
{
	_input->Update(deltaTime);
	_physics->Velocity = {0.f, 0.f};
	if (_input->IsJumpPressed() && _physics->GetIsGrounded())
	{
		_physics->Velocity.y = -95.f;
	}
	else if (_input->IsMoveRightPressed())
	{
		_physics->Velocity.x = 95.f;
		_inputDirection = 1.0f;
	}
	else if (_input->IsMoveLeftPressed())
	{
		_physics->Velocity.x = -95.f;
		_inputDirection = -1.0f;
	}
	else if (_input->IsAttackPressed())
	{
		_owner->Events(11);
	}
}