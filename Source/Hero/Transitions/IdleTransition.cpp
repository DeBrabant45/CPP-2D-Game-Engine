#include "IdleTransition.h"
#include "../../Physics/MovementComponent.h"
#include "../../GameObject/GameObject.h"
#include "../../State/StateController.h"
#include "../States/HeroIdleState.h"

IdleTransition::IdleTransition(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	_owner{ owner },
	_controller{ controller }
{

}

void IdleTransition::Start()
{
	_movement = _owner->GetComponent<MovementComponent>();
}

void IdleTransition::PerformTransition()
{
	_controller->TransitionToState(_controller->GetState<HeroIdleState>());
}

bool IdleTransition::IsAbleToTransition()
{
	return !_movement->IsMoving() && _movement->IsGrounded();
}
