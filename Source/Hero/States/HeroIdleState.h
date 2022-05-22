#pragma once
#include "../../State/IState.h"

class HeroPhysicsComponent;
class StateController;

class HeroIdleState : public IState
{
private:
	StateController* _controller;
	std::shared_ptr<HeroPhysicsComponent> _physics{};

public:
	virtual void OnEnter(std::shared_ptr<GameObject> owner, StateController* controller) override;
	virtual void OnExit() override;
	virtual void OnUpdate() override;
};

