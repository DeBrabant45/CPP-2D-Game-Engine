#pragma once
#include <memory>
#include "../../State/ITransition.h"
#include "../../Health/HealthComponent.h"

class GameObject;
class StateController;

class DeathTransition : public ITransition
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<StateController> _controller{};
	std::shared_ptr<HealthComponent> _health{};

public:
	DeathTransition(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller);
	virtual void Start() override;
	virtual void PerformTransition() override;
	virtual bool IsAbleToTransition() override;
};