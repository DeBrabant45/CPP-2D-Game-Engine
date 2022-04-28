#include "HeroStateComponent.h"
#include "../GameObject/GameObject.h"

HeroStateComponent::HeroStateComponent(std::shared_ptr<GameObject> owner) :
	_owner{ owner } 
{

}

void HeroStateComponent::Start()
{
	_physics = _owner->GetComponent<HeroPhysicsComponent>();
	_transform = _owner->GetComponent<Transformation>();
	_owner->Events.connect([&](int e)
	{
		if (e == 10)
		{
			DrawText("10", _transform->GetPosition().x, _transform->GetPosition().y - 40, 20, RED);
		}
	});
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