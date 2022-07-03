#pragma once
#include <memory>
#include <raylib.h>
#include "../Component/IComponent.h"

class GameObject;
class b2World;
class Transformation;
class Rigidbody;

class MovementComponent : public IComponent
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<b2World> _world{};
	std::shared_ptr<Transformation> _transform{};
	std::shared_ptr<Rigidbody> _rigidbody{};
	float _lookDirection{ 1.f };
	Vector2 _velocity{ 0.f, 0.f };

public:
	MovementComponent(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
	const bool IsGrounded();
	void SetXVelocity(float xVelocity);
	void SetYVelocity(float yVelocity);
	void SetLookDirection(float direction);
	float GetLookDirection() const { return _lookDirection; }

private:
	void AddMovement();
};

