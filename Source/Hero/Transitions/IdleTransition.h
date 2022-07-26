#pragma once
#include <memory>
#include "../../State/ITransition.h"

class GameObject;
class StateController;
class MovementComponent;

class IdleTransition : public ITransition
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<StateController> _controller{};
	std::shared_ptr<MovementComponent> _movement{};

public:
	IdleTransition(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller);
	virtual void Start() override;
	virtual void PerformTransition() override;
	virtual bool IsAbleToTransition() override;
};