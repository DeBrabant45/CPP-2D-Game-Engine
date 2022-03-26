#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H
#include "../GameObject/GameObject.h"
#include <vector>
#include <memory>

class b2World;
class b2Body;

class PhysicsComponent
{
protected:
	std::shared_ptr<b2World> World{};

public:
	PhysicsComponent(std::shared_ptr<b2World> world);
	virtual void Update(GameObject& gameObject, const float& deltaTime) = 0;
	virtual b2Body* GetBody() = 0;
	virtual bool IsGrounded() = 0;
};
#endif