#pragma once
#include <memory>
#include "../../../Component/IComponent.h"
#include "../../../Rigidbody/Rigidbody.h"
#include "../../../IHittable.h"


class b2World;
class GameObject;
class Transformation;

class HellhoundPhysicsComponent : public IComponent
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<b2World> _world{};
	std::shared_ptr<Transformation> _transform{};
	Rigidbody _rigidbody;
	IHittable* _hit;

public:
	HellhoundPhysicsComponent(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
};