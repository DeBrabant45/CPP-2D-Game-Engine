#pragma once
#include "HeroBaseState.h"
#include <memory>

class HeroGraphicsComponent;

class HeroFallState : public HeroBaseState
{
private:
	std::shared_ptr<HeroGraphicsComponent> _graphics{};

public:
	HeroFallState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller);
	virtual void Start() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void OnUpdate() override;
};