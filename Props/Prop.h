#pragma once
#include "raylib.h"
#include <memory>

class b2World;
class b2Body;

class Prop
{

private:
	Vector2 _worldPosition{};
	std::shared_ptr<b2World> _world{};
	b2Body* _body{};
	Texture2D _texture{};
	Vector2 boxSize = { 120, 32 };
	float _scale{ 1.0f };
	bool _isWalkable{ false };

public:
	Prop(Vector2 position, std::shared_ptr<b2World> world, Texture2D texture, bool isWalkable);
	void Render();
	Rectangle GetRectangleCollision();
	bool GetIsWalkable() const { return _isWalkable; }
	Vector2 GetWorldPosition() const { return _worldPosition; }
	void Update(const float& deltaTime);
};