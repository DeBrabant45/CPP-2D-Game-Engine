#pragma once
#include "../Component/IComponent.h"
#include "../Character/Character.h"

class HealthComponent : public IComponent<Character>
{
private:
	float _maxAmount;
	float _currentAmount;

public:
	HealthComponent(float maxAmount);
	void Damage(float amount);
	void Add(float amount);
	virtual void Receive(int message) override;
	virtual void Update(Character& gameobject, const float& deltaTime) override;
};