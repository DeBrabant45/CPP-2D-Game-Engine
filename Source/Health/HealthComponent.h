#pragma once
#include "../Component/IComponent.h"

class HealthComponent : public IComponent
{
private:
	float _maxAmount;
	float _currentAmount;

public:
	HealthComponent(float maxAmount);
	virtual void Start() override;
	virtual void Receive(int message) override;
	virtual void Update(const float& deltaTime) override;
	void Damage(float amount);
	void Add(float amount);
};