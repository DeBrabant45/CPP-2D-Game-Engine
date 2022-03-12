#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H
#include "PhysicsComponent.h"

class GameObject;

class InputComponent
{

public:
	virtual void Update(GameObject& gameOjbect, std::shared_ptr<PhysicsComponent> physics, const float& deltaTime) = 0;
};
#endif