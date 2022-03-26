#pragma once
#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H
#include "raylib.h"

class IGameObject
{
public:
	virtual void Update(const float& deltaTime) = 0;
	virtual const Vector2& GetPosition() = 0;
	Vector2 Velocity{ };
};
#endif