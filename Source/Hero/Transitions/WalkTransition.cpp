#include "WalkTransition.h"
#include "../../Physics/MovementComponent.h"
#include "../../GameObject/GameObject.h"
#include "../../State/StateController.h"
#include "../States/HeroWalkState.h"

WalkTransition::WalkTransition(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	_owner{ owner },
	_controller { controller }
{

}

void WalkTransition::Start()
{
	_movement = _owner->GetComponent<MovementComponent>();
}

void WalkTransition::PerformTransition()
{
	_controller->TransitionToState(_controller->GetState<HeroWalkState>());
}

bool WalkTransition::IsAbleToTransition()
{
	return (IsKeyDown(KEY_D) || IsKeyDown(KEY_A) && _movement->IsGrounded());
}
