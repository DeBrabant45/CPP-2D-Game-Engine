#include "HeroStateComponent.h"
#include "../GameObject/GameObject.h"

HeroStateComponent::HeroStateComponent(std::shared_ptr<GameObject> owner) :
	_owner{ owner } 
{

}

void HeroStateComponent::Start()
{
	_physics = _owner->GetComponent<HeroPhysicsComponent>();
}

void HeroStateComponent::Update(const float& deltaTime)
{
	SetState();
}

void HeroStateComponent::SetState()
{
	if (_physics->Velocity.x != 0.0f && _physics->GetIsGrounded())
	{
		_currentState = CharacterState::Run;
	}
	else if (!_physics->GetIsGrounded())
	{
		_currentState = CharacterState::Jump;
	}
	else
	{
		_currentState = CharacterState::Idle;
	}
}

void HeroStateComponent::Receive(int message)
{

}