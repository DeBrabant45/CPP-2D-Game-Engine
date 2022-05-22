#pragma once
#include <memory>
#include "../Component/IComponent.h"
#include "../GameObject/GameObject.h"

class IState;

class StateController : public IComponent
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<IState> _currentState{};

public:
	StateController(std::shared_ptr<GameObject> owner, std::shared_ptr<IState> startState);
	void TransitionToState(std::shared_ptr<IState> state);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
};