#include "Character.h"
#include <iostream>

Character::Character(std::vector<std::shared_ptr<ICharacterComponent>> components) :
	_components{ components }
{

}

void Character::Update(const float& deltaTime)
{
	SetState();
	SetLookDirection();
	for (auto component :  _components)
	{
		component->Update(*this, deltaTime);
	}
}

void Character::SetState()
{
	if (Velocity.x != 0.0f && IsGrounded)
	{
		_currentState = CharacterState::Run;
	}
	else if (!IsGrounded)
	{
		_currentState = CharacterState::Jump;
	}
	else
	{
		_currentState = CharacterState::Idle;
	}
}

void Character::SetLookDirection()
{
	if (Velocity.x > 0)
	{
		_lookDirection = 1.f;
	}
	else if (Velocity.x < 0)
	{
		_lookDirection = -1.f;
	}
}

void Character::SetWorldPosition(Vector2& position)
{
	_worldPosition = position;
}