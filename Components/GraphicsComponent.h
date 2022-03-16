#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H
#include "../GameObject/GameObject.h"
#include "PhysicsComponent.h"
#include <raylib.h>

class GraphicsComponent
{
public:
	virtual void Update(GameObject& gameOjbect, std::shared_ptr<PhysicsComponent> physics, const float& deltaTime) = 0;
};
#endif