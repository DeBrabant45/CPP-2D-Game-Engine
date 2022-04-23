#pragma once
#include <raylib.h>
#include <vector>
#include <memory>
#include "../Sprite/Sprite.h"
#include "../Camera/MainCamera.h"
#include "../Ground/GroundFactory.h"
#include "../GameObject/GameObject.h"
#include "../Character/CharacterFactory.h"

class b2World;

class Level
{

private:
	Texture2D _texture{ LoadTexture("./Assets/Map/Backbground/background.png") };
	const float _scale{ 2.0f };
	Vector2 _worldPosition{ 0.f, 0.f };
	GroundFactory _groundFactory{};
	CharacterFactory _characterFactory{};
	MainCamera _mainCamera{};
	std::vector<std::shared_ptr<GameObject>> _grounds{};
	std::shared_ptr<GameObject> _hero{};
	std::shared_ptr<b2World> _world{};

public:
	Level();
	void Start();
	void Update(const float& deltaTime);

private:
	void DrawMapToWorld();
};