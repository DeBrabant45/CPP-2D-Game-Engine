#include "Character.h"
#include <iostream>
#include "../Observer/ISender.h"

Character::Character(std::vector<std::shared_ptr<IComponent<Character>>> components) :
	_components{ components }
{

}

void Character::Update(const float& deltaTime)
{
	IsAttacking = (AttackTimer > 0) ? true : false;
	SetState();
	SetLookDirection();
	for (auto component :  _components)
	{
		component->Update(*this, deltaTime);
	}
}

void Character::SetState()
{
	if (Velocity.x != 0.0f && IsGrounded && !IsAttacking)
	{
		_currentState = CharacterState::Run;
	}
	else if (!IsGrounded && !IsAttacking)
	{
		_currentState = CharacterState::Jump;
	}
	else if (IsAttacking)
	{
		_currentState = CharacterState::Attack;
		AttackTimer--;
	}
	else if (HurtTimer > 0)
	{
		_currentState = CharacterState::Hurt;
		HurtTimer--;
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

void Character::SetPosition(Vector2& position)
{
	_worldPosition = position;
}

void Character::Send(int message)
{
	_messages.push_back(message);
	for (auto message : _messages)
	{
		for (auto component : _components)
		{
			if (component != nullptr)
			{
				component->Receive(message);
			}
		}
		_messages.erase(_messages.begin());
	}
}