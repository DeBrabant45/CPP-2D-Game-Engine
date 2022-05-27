#include "HeroWalkState.h"
#include "HeroIdleState.h"
#include "HeroJumpState.h"
#include "HeroFallState.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "../Physics/HeroPhysicsComponent.h"
#include "HeroAttackState.h"

HeroWalkState::HeroWalkState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	_owner{ owner },
	_controller{ controller }
{

}

void HeroWalkState::Start()
{
	_graphics = _owner->GetComponent<HeroGraphicsComponent>();
	_physics = _owner->GetComponent<HeroPhysicsComponent>();
}

void HeroWalkState::OnEnter()
{
	_graphics->SetGraphics(AnimationAction::Run);
}

void HeroWalkState::OnUpdate()
{
	if (_physics->GetIsGrounded())
	{
		if (IsKeyDown(KEY_SPACE))
		{
			_controller->TransitionToState(_controller->GetState<HeroJumpState>());
			return;
		}
		if (IsMouseButtonPressed(0))
		{
			_controller->TransitionToState(_controller->GetState<HeroAttackState>());
			return;
		}
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
			_controller->TransitionToState(_controller->GetState<HeroIdleState>());
			return;
		}
	}
	else
	{
		_controller->TransitionToState(_controller->GetState<HeroFallState>());
		return;
	}

}

void HeroWalkState::OnExit()
{

}