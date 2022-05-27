#include "HeroJumpState.h"
#include "HeroFallState.h"
#include "HeroIdleState.h"
#include <raylib.h>
#include "../Graphics/HeroGraphicsComponent.h"
#include "../Physics/HeroPhysicsComponent.h"


HeroJumpState::HeroJumpState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	_owner { owner },
	_controller { controller }
{

}

void HeroJumpState::Start()
{
	_graphics = _owner->GetComponent<HeroGraphicsComponent>();
	_physics = _owner->GetComponent<HeroPhysicsComponent>();
}

void HeroJumpState::OnEnter()
{
	_timer = 9.f;
	_graphics->SetGraphics(AnimationAction::Jump);
	_physics->Velocity.y += _jumpHeight;
}

void HeroJumpState::OnUpdate()
{
	_timer--;
	if (_timer <= 0)
	{
		_controller->TransitionToState(_controller->GetState<HeroFallState>());
		return;
	}
	else if (_physics->GetIsGrounded())
	{
		_controller->TransitionToState(_controller->GetState<HeroIdleState>());
		return;
	}
	else if (IsKeyDown(KEY_D) && !_physics->GetIsGrounded())
	{
		_physics->Velocity.x += 60;
		_graphics->SetLookDirection(1.f);
	}
	else if (IsKeyDown(KEY_A) && !_physics->GetIsGrounded())
	{
		_physics->Velocity.x += -60;
		_graphics->SetLookDirection(-1.f);
	}
}

void HeroJumpState::OnExit()
{

}