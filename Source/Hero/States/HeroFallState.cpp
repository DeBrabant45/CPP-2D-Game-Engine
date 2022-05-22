#include "HeroFallState.h"
#include "../../State/StateController.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "../Physics/HeroPhysicsComponent.h"
#include "HeroIdleState.h"

void HeroFallState::OnEnter(std::shared_ptr<GameObject> owner, StateController* controller)
{
	_controller = { controller };
	_graphics = owner->GetComponent<HeroGraphicsComponent>();
	_graphics->SetGraphics(AnimationAction::Fall);
	_physics = owner->GetComponent<HeroPhysicsComponent>();
}

void HeroFallState::OnExit()
{

}

void HeroFallState::OnUpdate()
{
	if (_physics->GetIsGrounded())
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