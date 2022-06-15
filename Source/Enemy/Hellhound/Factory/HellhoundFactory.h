#pragma once
#include "../../../GameObject/GameObjectFactory.h"

class HellhoundFactory : public GameObjectFactory
{
public:
	virtual std::shared_ptr<IGameObjectProduction> CreateProduction() override;
};