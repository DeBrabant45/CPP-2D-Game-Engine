#pragma once
#include "../../State/IState.h"
#include "../../State/StateController.h"

class HeroPhysicsComponent;
class HeroGraphicsComponent;

class HeroWalkState : public IState
{
private:
	StateController* _controller{};
	std::shared_ptr<HeroPhysicsComponent> _physics{};
	std::shared_ptr<HeroGraphicsComponent> _graphics{};
	float _speed{ 95.f };

public:
	virtual void OnEnter(std::shared_ptr<GameObject> owner, StateController* controller) override;
	virtual void OnExit() override;
	virtual void OnUpdate() override;
};