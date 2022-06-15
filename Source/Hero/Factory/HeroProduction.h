#pragma once
#include "../../GameObject/IGameObjectProduction.h"
#include "../../State/StateControllerFactory.h"
#include "../StateController/HeroStateControllerFactory.h"

class HeroProduction : public IGameObjectProduction
{
private:
	HeroStateControllerFactory _stateFactory{};

public:
	virtual std::shared_ptr<GameObject> Produce(std::shared_ptr<b2World> world, Vector2 position) override;
};