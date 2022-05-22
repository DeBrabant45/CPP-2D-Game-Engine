#pragma once
#include "../../State/IState.h"

class HeroAttackState : public IState
{
private:
	StateController* _controller{};
	float _attackTimer{ 25.f };

public:
	virtual void OnEnter(std::shared_ptr<GameObject> owner, StateController* controller) override;
	virtual void OnExit() override;
	virtual void OnUpdate() override;
};

