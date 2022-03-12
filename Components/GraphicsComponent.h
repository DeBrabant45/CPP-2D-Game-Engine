#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H
#include "../GameObject/GameObject.h"
#include "PhysicsComponent.h"
#include <raylib.h>

class GraphicsComponent
{
protected:
	Texture2D Texture{};

public:
	virtual Vector2 GetSize() = 0;
	virtual void Update(GameObject& gameOjbect, std::shared_ptr<PhysicsComponent> physics, const float& deltaTime) = 0;

protected:
	virtual void Draw() = 0;
};
#endif