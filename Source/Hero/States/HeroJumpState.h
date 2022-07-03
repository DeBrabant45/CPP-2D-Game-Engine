#pragma once
#include "../../State/IState.h"
#include <memory>
#include "../../Physics/MovementComponent.h"

class HeroGraphicsComponent;
class Transformation;

class HeroJumpState : public IState
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<HeroGraphicsComponent> _graphics{};
	std::shared_ptr<StateController> _controller{};
	std::shared_ptr<MovementComponent> _movement{};
	std::shared_ptr<Transformation> _transform{};
	float _jumpHeight{ -95.f };
	float _timer{ 9.f };

public:
	HeroJumpState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller);
	virtual void Start() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void OnUpdate() override;
};

