#pragma once
#include <memory>
#include <raylib.h>
#include "../Ground/GroundType.h"
#include "../Component/IComponent.h"
#include "../Rigidbody/Rigidbody.h"

class b2World;
class GameObject;
class Transformation;

class GroundPhysicsComponent : public IComponent
{
private:
	std::shared_ptr<GameObject> _owner;
	std::shared_ptr<Transformation> _transform;
	std::shared_ptr<b2World> _world{};
	Rigidbody _rigidbody;
	GroundType _groundType{};
	Vector2 _size{};

public:
	GroundPhysicsComponent(std::shared_ptr<GameObject> _owner, std::shared_ptr<b2World> world, GroundType groundType, Vector2 size);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
	virtual void Receive(int message) override;
};