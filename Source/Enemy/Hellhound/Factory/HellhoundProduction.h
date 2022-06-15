#pragma once
#include "../../../GameObject/IGameObjectProduction.h"

class HellhoundProduction : public IGameObjectProduction
{
public:
	virtual std::shared_ptr<GameObject> Produce(std::shared_ptr<b2World> world, Vector2 position) override;
};