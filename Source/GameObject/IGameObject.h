#pragma once
#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H
#include "raylib.h"

class IGameObject
{
public:
	virtual void Start() = 0;
	virtual void Update(const float& deltaTime) = 0;
};
#endif