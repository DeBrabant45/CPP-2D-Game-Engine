#pragma once
#include "../../State/IStateControllerProduction.h"

class HeroStateControllerProduction : public IStateControllerProduction
{
public:
	virtual std::shared_ptr<StateController> Produce(std::shared_ptr<GameObject> owner) override;
};