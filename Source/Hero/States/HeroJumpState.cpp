#include "HeroJumpState.h"
#include "HeroFallState.h"
#include "HeroIdleState.h"
#include <raylib.h>
#include "../Graphics/HeroGraphicsComponent.h"
#include "../Physics/HeroPhysicsComponent.h"
#include "../../Transform/Transformation.h"


HeroJumpState::HeroJumpState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	_owner { owner },
	_controller { controller }
{

}

void HeroJumpState::Start()
{
	_graphics = _owner->GetComponent<HeroGraphicsComponent>();
	_movement = _owner->GetComponent<MovementComponent>();
	_transform = _owner->GetComponent<Transformation>();
}

void HeroJumpState::OnEnter()
{
	_timer = 9.f;
	_graphics->SetGraphics(AnimationAction::Jump);
	_movement->SetYVelocity(_jumpHeight);
}

void HeroJumpState::OnUpdate()
{
	_timer--;
	if (_timer <= 0)
	{
		_controller->TransitionToState(_controller->GetState<HeroFallState>());
		return;
	}
	else if (_movement->IsGrounded())
	{
		_controller->TransitionToState(_controller->GetState<HeroIdleState>());
		return;
	}
	else if (IsKeyDown(KEY_D) && !_movement->IsGrounded())
	{
		_movement->SetXVelocity(60);
		_transform->SetDirection(1.f);
	}
	else if (IsKeyDown(KEY_A) && !_movement->IsGrounded())
	{
		_movement->SetXVelocity(-60);
		_transform->SetDirection(-1.f);
	}
}

void HeroJumpState::OnExit()
{

}