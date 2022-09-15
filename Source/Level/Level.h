#pragma once
#include <raylib.h>
#include <vector>
#include <memory>
#include "../Sprite/Sprite.h"
#include "../Camera/MainCamera.h"
#include "../Ground/GroundFactory.h"
#include "../GameObject/GameObjectRegistry.h"

class b2World;

class Level
{

private:
	Texture2D _texture1 { LoadTexture("./Assets/Map/Backbground/Back-ground.png") };
	const float _scale{ 2.0f };
	Vector2 _worldPosition{ 0.f, 0.f };
	GroundFactory _groundFactory{};
	MainCamera _mainCamera{};
	std::shared_ptr<b2World> _world{};
	GameObjectRegistry _registry;

public:
	Level();
	void Start();
	void Update(const float& deltaTime);

private:
	void DrawMapToWorld();
};