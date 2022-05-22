#pragma once
#include "../../State/IState.h"

class HeroPhysicsComponent;
class HeroGraphicsComponent;

class HeroJumpState : public IState
{
private:
	StateController* _controller;
	std::shared_ptr<HeroPhysicsComponent> _physics{};
	std::shared_ptr<HeroGraphicsComponent> _graphics{};
	float _jumpHeight{ -95.f };
	float _timer{ 9.f };

public:
	virtual void OnEnter(std::shared_ptr<GameObject> owner, StateController* controller) override;
	virtual void OnExit() override;
	virtual void OnUpdate() override;
};

