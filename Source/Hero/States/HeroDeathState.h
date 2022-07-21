#pragma once
#include "../../State/StateBase.h"

class HeroGraphicsComponent;

class HeroDeathState : public StateBase
{
private:
	std::shared_ptr<HeroGraphicsComponent> _graphics{};

public:
	HeroDeathState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller);
	virtual void Start() override;
	virtual void OnEnter() override;
};