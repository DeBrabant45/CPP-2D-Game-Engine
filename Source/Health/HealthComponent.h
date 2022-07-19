#pragma once
#include "../Component/IComponent.h"
#include "../Combat/IHurt.h"

class HealthComponent : public IComponent, public IHurt
{
private:
	float _maxAmount;
	float _currentAmount;

public:
	HealthComponent(float maxAmount);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
	void Add(float amount);
	virtual void TakeDamage(float value) override;
	float GetCurrentAmount() const { return _currentAmount; }
};