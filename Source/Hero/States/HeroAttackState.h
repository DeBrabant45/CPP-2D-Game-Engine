#pragma once
#include <memory>
#include "../../State/IState.h"

class HeroGraphicsComponent;
class HeroPhysicsComponent;

class HeroAttackState : public IState
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<HeroGraphicsComponent> _graphics{};
	std::shared_ptr<HeroPhysicsComponent> _physics{};
	std::shared_ptr<StateController> _controller{};
	float _attackTimer{ 25.f };

public:
	HeroAttackState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> _controller);
	virtual void Start() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void OnUpdate() override;
};

