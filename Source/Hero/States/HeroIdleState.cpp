#include "HeroIdleState.h"
#include <raylib.h>
#include "HeroAttackState.h"
#include "HeroFallState.h"
#include "HeroWalkState.h"
#include "HeroJumpState.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "../Physics/HeroPhysicsComponent.h"
#include "../../GameObject/GameObject.h"

HeroIdleState::HeroIdleState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	_owner{ owner },
	_controller{ controller }
{

}

void HeroIdleState::Start()
{
	_graphics = _owner->GetComponent<HeroGraphicsComponent>();
	_movement = _owner->GetComponent<MovementComponent>();
}

void HeroIdleState::OnEnter()
{
	_graphics->SetGraphics(AnimationAction::Idle);
}

void HeroIdleState::OnUpdate()
{
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_A))
	{
		_controller->TransitionToState(_controller->GetState<HeroWalkState>());
		return;
	}
	else if (IsKeyDown(KEY_SPACE) && _movement->IsGrounded())
	{
		_controller->TransitionToState(_controller->GetState<HeroJumpState>());
		return;
	}
	else if (IsMouseButtonPressed(0))
	{
		_controller->TransitionToState(_controller->GetState<HeroAttackState>());
		return;
	}
	else if (!_movement->IsGrounded())
	{
		_controller->TransitionToState(_controller->GetState<HeroFallState>());
		return;
	}
}

void HeroIdleState::OnExit()
{

}