#pragma once
#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include "Transformation.h"
#include "../Component/IComponent.h"
#include "../Rigidbody/Rigidbody.h"
#include "../GameObject/GameObject.h"

class Transformation : public IComponent
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<Rigidbody> _rigidbody{};
	Vector2 _position{ 0, 0 };
	Vector2 _size{ 0, 0 };
	float _direction{ 1.f };

public:
	Transformation(std::shared_ptr<GameObject> owner, Vector2 position, Vector2 size);
	void SetPosition(Vector2 position);
	void SetDirection(float direction);
	const Vector2& GetPosition() { return _position; }
	const Vector2& GetSize() { return _size; }
	const float& GetDirection() { return _direction; }
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
};
#endif