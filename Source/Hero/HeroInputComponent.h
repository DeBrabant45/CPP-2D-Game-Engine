#pragma once
#include <memory>
#include "../Component/IComponent.h"
#include "../GameObject/GameObject.h"
#include "../Hero/HeroPhysicsComponent.h"

class InputHandler;
class Character;

class HeroInputComponent : public IComponent
{
private:
	std::shared_ptr<GameObject> _owner;
	std::shared_ptr<InputHandler>  _input{};
	std::shared_ptr<HeroPhysicsComponent> _physics;
	float _inputDirection{ 1.0f };

public:
	HeroInputComponent(std::shared_ptr<GameObject> owner, std::shared_ptr<InputHandler> input);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
	virtual void Receive(int message) override;
	const float GetInputDirection() { return _inputDirection; }
};