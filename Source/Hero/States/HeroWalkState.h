#pragma once
#include "../../State/IState.h"
#include "../../State/StateController.h"

class HeroPhysicsComponent;
class HeroGraphicsComponent;

class HeroWalkState : public IState
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<HeroGraphicsComponent> _graphics{};
	std::shared_ptr<HeroPhysicsComponent> _physics{};
	std::shared_ptr<StateController> _controller{};
	float _speed{ 95.f };

public:
	HeroWalkState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller);
	virtual void Start() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void OnUpdate() override;
};