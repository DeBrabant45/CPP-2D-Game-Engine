#pragma once
#ifndef ICOMPONENT_H
#define ICOMPONENT_H
#include "../Observer/IReceiver.h"

template<class T>
class IComponent : public IReceiver
{
public:
	virtual void Update(T& gameobject, const float& deltaTime) = 0;
};
#endif