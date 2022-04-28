#pragma once
#ifndef ICOMPONENT_H
#define ICOMPONENT_H

class IComponent
{
public:
	virtual void Start() = 0;
	virtual void Update(const float& deltaTime) = 0;
};
#endif