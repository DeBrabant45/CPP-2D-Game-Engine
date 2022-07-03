#pragma once
#include "../../State/IState.h"
#include "../../State/StateController.h"
#include "../../Physics/MovementComponent.h"

class HeroGraphicsComponent;
class Transformation;

class HeroWalkState : public IState
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<HeroGraphicsComponent> _graphics{};
	std::shared_ptr<StateController> _controller{};
	std::shared_ptr<MovementComponent> _movement{};
	std::shared_ptr<Transformation> _transform{};
	float _speed{ 95.f };

public:
	HeroWalkState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller);
	virtual void Start() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void OnUpdate() override;
};