#include "FallTransition.h"
#include "../../Physics/MovementComponent.h"
#include "../../GameObject/GameObject.h"
#include "../../State/StateController.h"
#include "../States/HeroFallState.h"

FallTransition::FallTransition(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	_owner{ owner },
	_controller{ controller } 
{

}

void FallTransition::Start()
{
	_movement = _owner->GetComponent<MovementComponent>();
}

void FallTransition::PerformTransition()
{
	_controller->TransitionToState(_controller->GetState<HeroFallState>());
}

bool FallTransition::IsAbleToTransition()
{
	return (!_movement->IsGrounded());
}
