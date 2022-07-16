#include "AttackTransition.h"
#include <raylib.h>
#include "../../Physics/MovementComponent.h"
#include "../../GameObject/GameObject.h"
#include "../../State/StateController.h"
#include "../States/HeroAttackState.h"

AttackTransition::AttackTransition(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	_owner{ owner },
	_controller{ controller }
{

}

void AttackTransition::Start()
{
	_movement = _owner->GetComponent<MovementComponent>();
}

void AttackTransition::PerformTransition()
{
	_controller->TransitionToState(_controller->GetState<HeroAttackState>());
}

bool AttackTransition::IsAbleToTransition()
{
	return (IsMouseButtonPressed(0) && _movement->IsGrounded());
}
