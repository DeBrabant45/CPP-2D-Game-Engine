#pragma once
#include <memory>
#include <raylib.h>
#include "../Ground/GroundType.h"
#include "../Component/IComponent.h"
#include "../GameObject/IGameObject.h"

class b2Body;
class b2World;

class GroundPhysicsComponent : public IComponent<IGameObject>
{
private:
	b2Body* _body{};
	std::shared_ptr<b2World> _world{};

public:
	GroundPhysicsComponent(std::shared_ptr<b2World> world, GroundType groundType, Vector2 size, Vector2 worldPosition);
	virtual void Update(IGameObject& gameObject, const float& deltaTime) override;
};