#pragma once
#include ".././Components/PhysicsComponent.h"

class b2Body;

class GroundPhysicsComponent : public PhysicsComponent
{
private:
	b2Body* _body{};

public:
	GroundPhysicsComponent(std::shared_ptr<b2World> world, Vector2 size, Vector2 worldPosition);
	virtual void Update(GameObject& gameObject, const float& deltaTime) override;
	virtual b2Body* GetBody() override { return _body; };
	virtual bool IsGrounded() override { return true; };
};