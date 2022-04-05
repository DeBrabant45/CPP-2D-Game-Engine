#pragma once
#ifndef ICOMPONENT_H
#define ICOMPONENT_H

template<class T>
class IComponent
{
public:
	virtual void Update(T& gameobject, const float& deltaTime) = 0;
};
#endif