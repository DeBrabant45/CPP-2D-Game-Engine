#pragma once
class IHittable
{
public:
	virtual void TakeDamage(int value) = 0;
};