#include "JumpTransition.h"
#include "../../Physics/MovementComponent.h"
#include "../../GameObject/GameObject.h"
#include "../../State/StateController.h"
#include "../States/HeroJumpState.h"

JumpTransition::JumpTransition(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	_owner{ owner },
	_controller{ controller }
{

}

void JumpTransition::Start()
{
	_movement = _owner->GetComponent<MovementComponent>();
}

void JumpTransition::PerformTransition()
{
	_controller->TransitionToState(_controller->GetState<HeroJumpState>());
}

bool JumpTransition::IsAbleToTransition()
{
	return (IsKeyDown(KEY_SPACE) && _movement->IsGrounded());
}
