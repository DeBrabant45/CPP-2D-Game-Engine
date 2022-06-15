#pragma once
#include <memory>
#include "StateController.h"
#include "../GameObject/GameObject.h"

class IStateControllerProduction 
{
public:
	virtual std::shared_ptr<StateController> Produce(std::shared_ptr<GameObject> owner) = 0;
};