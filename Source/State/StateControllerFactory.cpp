#include "StateControllerFactory.h"
#include "../State/StateController.h"
#include "../GameObject/GameObject.h"

std::shared_ptr<StateController> StateControllerFactory::CreateController(std::shared_ptr<GameObject> owner)
{
    auto controllerAssembly = CreateProduction();
    return controllerAssembly->Produce(owner);
}