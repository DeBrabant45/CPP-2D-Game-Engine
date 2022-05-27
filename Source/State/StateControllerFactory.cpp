#include "StateControllerFactory.h"
#include "../Hero/States/HeroAttackState.h"
#include "../State/StateController.h"
#include "../GameObject/GameObject.h"
#include "../Hero/States/HeroIdleState.h"
#include "../Hero/States/HeroWalkState.h"
#include "../Hero/States/HeroFallState.h"
#include "../Hero/States/HeroJumpState.h"

std::shared_ptr<StateController> StateControllerFactory::CreateController(std::shared_ptr<GameObject> owner, CharacterType character)
{
    switch (character)
    {
    case CharacterType::Hero:
        return CreateHeroStateController(owner);
        break;
    }
}

std::shared_ptr<StateController> StateControllerFactory::CreateHeroStateController(std::shared_ptr<GameObject> owner)
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
