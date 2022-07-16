#pragma once
#include <memory>
#include "../../State/IAction.h"

class MovementComponent;
class GameObject;
class Transformation;

class FloatAction : public IAction
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<MovementComponent> _movement{};
	std::shared_ptr<Transformation> _transform{};
	float _speed;

public:
	FloatAction(std::shared_ptr<GameObject> owner);
	virtual void Start() override;
	virtual void DoAction() override;

};