#pragma once
#include "../../../GameObject/Factory/GameObjectFactory.h"

class HellhoundFactory : public GameObjectFactory
{
public:
	virtual std::shared_ptr<IGameObjectProduction> CreateProduction() override;
};