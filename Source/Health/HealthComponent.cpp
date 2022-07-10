#include "HealthComponent.h"
#include <algorithm> 
#include <iostream>

HealthComponent::HealthComponent(float maxAmount) :
	_maxAmount{ maxAmount },
	_currentAmount{ maxAmount }
{

}

void HealthComponent::Start()
{

}

void HealthComponent::Add(float amount)
{
	if (_currentAmount < _maxAmount)
	{
		_currentAmount += amount;
	}
}

void HealthComponent::TakeDamage(float value)
{
	_currentAmount -= value;
	std::cout << "You hit me" << std::endl;
}

void HealthComponent::Update(const float& deltaTime)
{

}