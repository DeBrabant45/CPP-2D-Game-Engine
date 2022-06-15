#pragma once
#include "../../GameObject/GameObjectFactory.h"

class HeroFactory : public GameObjectFactory
{
public:
	virtual std::shared_ptr<IGameObjectProduction> CreateProduction() override;
};