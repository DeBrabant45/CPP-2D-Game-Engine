#pragma once
#ifndef HEROSTATECOMPONENT_H
#define HEROSTATECOMPONENT_H
#include <memory>
#include "../Component/IComponent.h"
#include "../Character/CharacterState.h"
#include "../Hero/HeroPhysicsComponent.h"

class GameObject;

class HeroStateComponent : public IComponent
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<HeroPhysicsComponent> _physics{};
	CharacterState _currentState{ CharacterState::Idle };

public:
	HeroStateComponent(std::shared_ptr<GameObject> owner);
	virtual void Receive(int message) override;
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
	const CharacterState& GetCurrentState() { return _currentState; }

private:
	void SetState();
};
#endif