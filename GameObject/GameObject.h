#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <memory>
#include "raylib.h"
#include <vector>

class PhysicsComponent;
class GraphicsComponent;
class InputComponent;
class Prop;

class GameObject
{

private:
	std::shared_ptr<PhysicsComponent> _physics;
	std::shared_ptr<GraphicsComponent> _graphics;
	std::shared_ptr<InputComponent> _input;
	float _scale{ 1.0f };

public:
	GameObject(std::shared_ptr<PhysicsComponent> physics, std::shared_ptr<GraphicsComponent> graphics, std::shared_ptr<InputComponent> input);
	void Update(const float& deltaTime);
	const Vector2& GetPosition();
	float GetScale() const { return _scale; }
	Vector2 Velocity{ 0.f };
	bool IsAttacking{ false };
	bool IsJumping{ false };
};
#endif