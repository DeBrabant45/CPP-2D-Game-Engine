#pragma once
#include "../../../GameObject/Factory/IGameObjectProduction.h"

class HellhoundProduction : public IGameObjectProduction
{
public:
	virtual std::shared_ptr<GameObject> Produce(std::shared_ptr<b2World> world, Vector2 position) override;
};