#include "HeroJumpState.h"
#include "HeroFallState.h"
#include "HeroIdleState.h"
#include <raylib.h>
#include "../Graphics/HeroGraphicsComponent.h"
#include "../Physics/HeroPhysicsComponent.h"

void HeroJumpState::OnEnter(std::shared_ptr<GameObject> owner, StateController* controller)
{
	_controller = { controller };
	_graphics = owner->GetComponent<HeroGraphicsComponent>();
	_graphics->SetGraphics(AnimationAction::Jump);
	_physics = owner->GetComponent<HeroPhysicsComponent>();
	_physics->Velocity.y += _jumpHeight;
}

void HeroJumpState::OnUpdate()
{
	_timer--;
	if (_timer <= 0)
	{
		_controller->TransitionToState(std::make_shared<HeroFallState>());
	}
	else if (_physics->GetIsGrounded())
	{
		_controller->TransitionToState(std::make_shared<HeroIdleState>());
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