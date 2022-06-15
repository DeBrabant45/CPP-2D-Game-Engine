#include "HeroStateControllerProduction.h"
#include "../States/HeroAttackState.h"
#include "../States/HeroIdleState.h"
#include "../States/HeroWalkState.h"
#include "../States/HeroFallState.h"
#include "../States/HeroJumpState.h"

std::shared_ptr<StateController> HeroStateControllerProduction::Produce(std::shared_ptr<GameObject> owner)
{
    auto stateController = std::make_shared<StateController>(owner);
    stateController->AddState(std::make_shared<HeroAttackState>(owner, stateController));
    stateController->AddState(std::make_shared<HeroIdleState>(owner, stateController));
    stateController->AddState(std::make_shared<HeroWalkState>(owner, stateController));
    stateController->AddState(std::make_shared<HeroFallState>(owner, stateController));
    stateController->AddState(std::make_shared<HeroJumpState>(owner, stateController));
    stateController->DefaultState(stateController->GetState<HeroIdleState>());
    return stateController;
}