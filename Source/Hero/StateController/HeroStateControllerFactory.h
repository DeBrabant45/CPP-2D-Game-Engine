#pragma once
#include "../../State/StateControllerFactory.h"

class HeroStateControllerFactory : public StateControllerFactory
{
public:
	virtual std::shared_ptr<IStateControllerProduction> CreateProduction() override;
};