#pragma once
#include "HeroBaseState.h"

class HeroGraphicsComponent;
class StateController;
class ITransition;
class GameObejct;

class HeroWalkState : public HeroBaseState
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<HeroGraphicsComponent> _graphics{};
	std::shared_ptr<StateController> _controller{};

public:
	HeroWalkState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller);
	virtual void Start() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};