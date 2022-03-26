#pragma once
#ifndef IGAMEOBJECTCOMPONENT_H
#define IGAMEOBJECTCOMPONENT_H

class IGameObject;

class IGameObjectComponent
{

public:
	virtual void Update(IGameObject& gameObject, const float& deltaTime) = 0;
};
#endif