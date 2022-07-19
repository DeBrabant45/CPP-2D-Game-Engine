#pragma once
#include "HeroBaseState.h"

class HeroGraphicsComponent;

class HeroDeathState : public HeroBaseState
{
private:
	std::shared_ptr<HeroGraphicsComponent> _graphics{};

public:
	HeroDeathState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller);
	virtual void Start() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};