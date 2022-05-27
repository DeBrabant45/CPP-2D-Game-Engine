#include "HeroFallState.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "../Physics/HeroPhysicsComponent.h"
#include "HeroIdleState.h"

HeroFallState::HeroFallState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	_owner { owner },
	_controller { controller }
{

}

void HeroFallState::Start()
{
	_physics = _owner->GetComponent<HeroPhysicsComponent>();
	_graphics = _owner->GetComponent<HeroGraphicsComponent>();
}

void HeroFallState::OnEnter()
{
	_graphics->SetGraphics(AnimationAction::Fall);
}

void HeroFallState::OnUpdate()
{
	if (_physics->GetIsGrounded())
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

void HeroFallState::OnExit()
{

}