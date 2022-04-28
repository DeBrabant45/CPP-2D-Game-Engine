#pragma once
#include <memory>
#include <raylib.h>
#include "../Component/IComponent.h"
#include "../Rigidbody/Rigidbody.h"

class b2World;
class b2Contact;
class GameObject;
class Transformation;

class HeroPhysicsComponent : public IComponent
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<b2World> _world{};
	std::shared_ptr<Transformation> _transform{};
	Rigidbody _rigidbody;
	bool _isGrounded{ true };

public:
	HeroPhysicsComponent(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
	Vector2 Velocity{ 0.f, 0.f };
	const bool GetIsGrounded() { return _isGrounded; }

private:
	void GroundedCheck(b2Contact* contact);
	void ApplyDamage(b2Contact* contact);
	void ContactCheck();
};