#include "HealthComponent.h"
#include <algorithm> 
#include <iostream>

HealthComponent::HealthComponent(float maxAmount) :
	_maxAmount{ maxAmount },
	_currentAmount{ maxAmount }
{

}

void HealthComponent::Damage(float amount)
{
	_currentAmount -= amount;
}

void HealthComponent::Add(float amount)
{
	if (_currentAmount < _maxAmount)
	{
		// Todo: Needs to be clamped
		_currentAmount += amount;
	}
}

void HealthComponent::Receive(int message)
{
	if (message == 5)
	{
		Damage(1);
	}
	std::cout << _currentAmount << std::endl;
}

void HealthComponent::Update(Character& character, const float& deltaTime)
{
	if (_currentAmount <= 0.f)
	{

	}
}