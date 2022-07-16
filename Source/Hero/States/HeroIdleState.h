#pragma once
#ifndef HEROIDLESTATE_H
#define HEROIDLESTATE_H
#include "HeroBaseState.h"
#include <memory>

class HeroGraphicsComponent;
class GameObject;

class HeroIdleState : public HeroBaseState
{
private:
	std::shared_ptr<HeroGraphicsComponent> _graphics{};

public:
	HeroIdleState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller);
	virtual void Start() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void OnUpdate() override;
};
#endif