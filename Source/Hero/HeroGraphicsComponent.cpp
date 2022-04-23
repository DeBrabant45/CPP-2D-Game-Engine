#include "HeroGraphicsComponent.h"
#include "HeroInputComponent.h"
#include "../GameObject/GameObject.h"
#include "../Transform/Transformation.h"
#include <iostream>

HeroGraphicsComponent::HeroGraphicsComponent(std::shared_ptr<GameObject> owner) :
	_owner{ owner }
{

}

void HeroGraphicsComponent::Start()
{
	_state = _owner->GetComponent<HeroStateComponent>();
	_transform = _owner->GetComponent<Transformation>();
	_input = _owner->GetComponent<HeroInputComponent>();
}

void HeroGraphicsComponent::Update(const float& deltaTime)
{
	switch (_state->GetCurrentState())
	{
		case CharacterState::Run:
			_run.Draw(deltaTime, _transform->GetPosition(), _input->GetInputDirection());
			break;
		case CharacterState::Jump:
			_fall.Draw(deltaTime, _transform->GetPosition(), _input->GetInputDirection());
			break;
		case CharacterState::Attack:
			_attack.Draw(deltaTime, _transform->GetPosition(), _input->GetInputDirection());
			break;
		case CharacterState::Hurt:
			_hurt.Draw(deltaTime, _transform->GetPosition(), _input->GetInputDirection());
			break;
		case CharacterState::Idle:
			_idle.Draw(deltaTime, _transform->GetPosition(), _input->GetInputDirection());
			break;
	}
}

void HeroGraphicsComponent::Receive(int message)
{

}