#pragma once
#ifndef HEROIDLESTATE_H
#define HEROIDLESTATE_H
#include "../../State/IState.h"
#include <memory>

class HeroGraphicsComponent;
class MovementComponent;
class GameObject;

class HeroIdleState : public IState
{
private:
	std::shared_ptr<StateController> _controller{};
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<HeroGraphicsComponent> _graphics{};
	std::shared_ptr<MovementComponent> _movement{};

public:
	HeroIdleState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller);
	virtual void Start() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void OnUpdate() override;
};
#endif