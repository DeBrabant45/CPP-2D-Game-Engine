#include "HeroWalkState.h"
#include "HeroIdleState.h"
#include "HeroJumpState.h"
#include "HeroFallState.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "../Physics/HeroPhysicsComponent.h"

void HeroWalkState::OnEnter(std::shared_ptr<GameObject> owner, StateController* controller)
{
	_controller = controller;
	_graphics = owner->GetComponent<HeroGraphicsComponent>();
	_graphics->SetGraphics(AnimationAction::Run);
	_physics = owner->GetComponent<HeroPhysicsComponent>();
}

void HeroWalkState::OnExit()
{

}

void HeroWalkState::OnUpdate()
{
	if (_physics->GetIsGrounded())
	{
		if (IsKeyDown(KEY_D))
		{
			_physics->Velocity.x = _speed;
			_graphics->SetLookDirection(1.f);
		}
		else if (IsKeyDown(KEY_A))
		{
			_physics->Velocity.x = -_speed;
			_graphics->SetLookDirection(-1.f);
		}
		else
		{
			_controller->TransitionToState(std::make_shared<HeroIdleState>());
		}
		if (IsKeyDown(KEY_SPACE))
		{
			_controller->TransitionToState(std::make_shared<HeroJumpState>());
		}

	}
	else
	{
		_controller->TransitionToState(std::make_shared<HeroFallState>());
	}

}