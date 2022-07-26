#pragma once
#include "../../GameObject/Factory/GameObjectFactory.h"

class HeroFactory : public GameObjectFactory
{
public:
	virtual std::shared_ptr<IGameObjectProduction> CreateProduction() override;
};