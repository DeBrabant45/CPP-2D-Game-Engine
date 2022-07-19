#pragma once
#include "../../State/IState.h"

class ITransition;
class IAction;
class GameObject;
class StateController;

class HeroBaseState : public IState
{
private:
	std::vector<std::shared_ptr<ITransition>> _transitions{};
	std::vector<std::shared_ptr<IAction>> _actions{};

protected:
	std::shared_ptr<GameObject> Owner{};
	std::shared_ptr<StateController> Controller{};

public:
	HeroBaseState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller);
	virtual void Start() override;
	virtual void OnUpdate() override;

protected:
	void AddTransition(std::shared_ptr<ITransition> transition);
	void AddAction(std::shared_ptr<IAction> action);

private:
	void DoActions();
	void CheckTransitions();
};

