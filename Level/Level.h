#pragma once
#include <raylib.h>
#include <vector>
#include <memory>
#include "../Camera/MainCamera.h"
#include "../Props/Prop.h"

class GameObject;

class Level
{

private:
	Texture2D _texture{ LoadTexture("./Assets/Map/Backbground/town.png") };
	const float _scale{ 2.0f };
	Vector2 _worldPosition{ 0.f, 0.f };
	std::vector<Prop> _props{};
	std::shared_ptr<GameObject> _hero{};
	std::unique_ptr<MainCamera> _mainCamera{};
	std::shared_ptr<b2World> _world{};

public:
	Level();
	void Update(float deltaTime);

private:
	void DrawMapToWorld();
};