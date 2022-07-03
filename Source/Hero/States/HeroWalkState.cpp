#include "HeroWalkState.h"
#include "HeroIdleState.h"
#include "HeroJumpState.h"
#include "HeroFallState.h"
#include "HeroAttackState.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "../../Transform/Transformation.h"

HeroWalkState::HeroWalkState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	_owner{ owner },
	_controller{ controller }
{

}

void HeroWalkState::Start()
{
	_graphics = _owner->GetComponent<HeroGraphicsComponent>();
	_movement = _owner->GetComponent<MovementComponent>();
	_transform = _owner->GetComponent<Transformation>();
}

void HeroWalkState::OnEnter()
{
	_graphics->SetGraphics(AnimationAction::Run);
}

void HeroWalkState::OnUpdate()
{
	if (_movement->IsGrounded())
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
			_movement->SetXVelocity(_speed);
			_movement->SetLookDirection(1.f);
			_transform->SetDirection(1.f);
		}
		else if (IsKeyDown(KEY_A))
		{
			_movement->SetXVelocity(-_speed);
			_movement->SetLookDirection(-1.f);
			_transform->SetDirection(-1.f);
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