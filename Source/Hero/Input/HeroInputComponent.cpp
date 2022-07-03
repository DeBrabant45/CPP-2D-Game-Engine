#include "HeroInputComponent.h"
#include "../../Input/InputHandler.h"
#include "../../GameObject/GameObject.h"
#include "../Physics/HeroPhysicsComponent.h"
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
	if (_input->IsJumpPressed() && _physics->GetIsGrounded())
	{
		_owner->Events(40);
	}
	else if (_input->IsMoveRightPressed())
	{
		_owner->Events(20);
		_inputDirection = 1.0f;
	}
	else if (_input->IsMoveLeftPressed())
	{
		_inputDirection = -1.0f;
		_owner->Events(30);
	}
	else if (_input->IsAttackPressed())
	{
		_owner->Events(11);
	}
}