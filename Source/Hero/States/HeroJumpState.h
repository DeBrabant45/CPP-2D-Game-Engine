#pragma once
#include "../../State/StateBase.h"
#include "../../Physics/MovementComponent.h"

class HeroGraphicsComponent;

class HeroJumpState : public StateBase
{
private:
	std::shared_ptr<HeroGraphicsComponent> _graphics{};
	std::shared_ptr<MovementComponent> _movement{};
	float _jumpHeight{ -195.f };
	float _timer{ 9.f };

public:
	HeroJumpState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller);
	virtual void Start() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void OnUpdate() override;
};

