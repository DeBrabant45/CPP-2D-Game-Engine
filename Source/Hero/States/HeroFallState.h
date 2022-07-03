#pragma once
#include "../../State/IState.h"
#include <memory>

class HeroGraphicsComponent;
class MovementComponent;
class Transformation;

class HeroFallState : public IState
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<StateController> _controller{};
	std::shared_ptr<HeroGraphicsComponent> _graphics{};
	std::shared_ptr<MovementComponent> _movement{};
	std::shared_ptr<Transformation> _transform{};

public:
	HeroFallState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller);
	virtual void Start() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void OnUpdate() override;
};