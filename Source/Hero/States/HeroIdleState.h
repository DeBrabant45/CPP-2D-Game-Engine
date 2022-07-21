#pragma once
#ifndef HEROIDLESTATE_H
#define HEROIDLESTATE_H
#include "../../State/StateBase.h"

class HeroGraphicsComponent;
class GameObject;

class HeroIdleState : public StateBase
{
private:
	std::shared_ptr<HeroGraphicsComponent> _graphics{};

public:
	HeroIdleState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller);
	virtual void Start() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};
#endif