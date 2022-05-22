#pragma once
#include "../../State/IState.h"
#include <memory>

class StateController;
class HeroPhysicsComponent;
class HeroGraphicsComponent;

class HeroFallState : public IState
{
private:
	StateController* _controller{};
	std::shared_ptr<HeroPhysicsComponent> _physics{};
	std::shared_ptr<HeroGraphicsComponent> _graphics{};

public:
	virtual void OnEnter(std::shared_ptr<GameObject> owner, StateController* controller) override;
	virtual void OnExit() override;
	virtual void OnUpdate() override;
};