#pragma once
#include <memory>
#include "IStateControllerProduction.h"

class StateController;
class GameObject;

class StateControllerFactory
{
public:
	std::shared_ptr<StateController> CreateController(std::shared_ptr<GameObject> owner);
	virtual std::shared_ptr<IStateControllerProduction> CreateProduction() = 0;
};