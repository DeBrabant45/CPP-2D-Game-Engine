#include "DeathTransition.h"
#include "../../GameObject/GameObject.h"
#include "../../State/StateController.h"
#include "../States/HeroDeathState.h"

DeathTransition::DeathTransition(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	_owner{ owner },
	_controller{ controller }
{

}

void DeathTransition::Start()
{
	_health = _owner->GetComponent<HealthComponent>();
}

void DeathTransition::PerformTransition()
{
	_controller->TransitionToState(_controller->GetState<HeroDeathState>());
}

bool DeathTransition::IsAbleToTransition()
{
	return (_health <= 0) ? true : false;
}
