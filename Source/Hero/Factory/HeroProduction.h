#pragma once
#include "../../GameObject/Factory/IGameObjectProduction.h"
#include "../../State/StateControllerFactory.h"

class HeroProduction : public IGameObjectProduction
{
public:
	virtual std::shared_ptr<GameObject> Produce(std::shared_ptr<b2World> world, Vector2 position) override;
};