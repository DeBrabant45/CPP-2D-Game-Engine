#pragma once
#include <memory>
#include <raylib.h>
#include "../../Component/IComponent.h"
#include "../../Rigidbody/Rigidbody.h"

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
	std::shared_ptr<Rigidbody> _rigidbody{};
	bool _isGrounded{ true };
	float _lookDirection{ 1.f };

public:
	HeroPhysicsComponent(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
	void AddAttackDetection();
	const bool GetIsGrounded() { return _isGrounded; }
	void SetLookDirection(float direction) { _lookDirection = direction; }

private:
	void GroundedCheck(b2Contact* contact);
	void ApplyDamage(b2Contact* contact);
	void ContactCheck();
};