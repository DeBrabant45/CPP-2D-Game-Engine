#include "HeroIdleState.h"
#include <raylib.h>
#include "HeroAttackState.h"
#include "HeroFallState.h"
#include "HeroWalkState.h"
#include "HeroJumpState.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "../Physics/HeroPhysicsComponent.h"

void HeroIdleState::OnEnter(std::shared_ptr<GameObject> owner, StateController* controller)
{
	_controller = { controller };
	auto animation = owner->GetComponent<HeroGraphicsComponent>();
	animation->SetGraphics(AnimationAction::Idle);
	_physics = owner->GetComponent<HeroPhysicsComponent>();
}

void HeroIdleState::OnExit()
{

}

void HeroIdleState::OnUpdate()
{
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_A))
	{
		_controller->TransitionToState(std::make_shared<HeroWalkState>());
	}
	else if (IsKeyDown(KEY_SPACE) && _physics->GetIsGrounded())
	{
		_controller->TransitionToState(std::make_shared<HeroJumpState>());
	}
	else if (IsMouseButtonPressed(0))
	{
		_controller->TransitionToState(std::make_shared<HeroAttackState>());
	}
	else if (!_physics->GetIsGrounded())
	{
		_controller->TransitionToState(std::make_shared<HeroFallState>());
	}
}