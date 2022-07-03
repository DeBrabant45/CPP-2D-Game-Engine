#include "HeroFallState.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "../Physics/HeroPhysicsComponent.h"
#include "../../Physics/MovementComponent.h"
#include "../../Transform/Transformation.h"
#include "HeroIdleState.h"

HeroFallState::HeroFallState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	_owner { owner },
	_controller { controller }
{

}

void HeroFallState::Start()
{
	_graphics = _owner->GetComponent<HeroGraphicsComponent>();
	_movement = _owner->GetComponent<MovementComponent>();
	_transform = _owner->GetComponent<Transformation>();
}

void HeroFallState::OnEnter()
{
	_graphics->SetGraphics(AnimationAction::Fall);
}

void HeroFallState::OnUpdate()
{
	if (_movement->IsGrounded())
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

void HeroFallState::OnExit()
{

}