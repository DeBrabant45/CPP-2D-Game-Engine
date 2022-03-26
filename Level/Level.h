#pragma once
#include <raylib.h>
#include <vector>
#include <memory>
#include "../Camera/MainCamera.h"
#include "../Sprite/Sprite.h"
#include "../GameObject/IGameObject.h"
#include "../Character/Character.h"
#include "../Ground/Ground.h"

class b2World;

class Level
{

private:
	Texture2D _texture{ LoadTexture("./Assets/Map/Backbground/background.png") };
	const float _scale{ 2.0f };
	Vector2 _worldPosition{ 0.f, 0.f };
	std::vector<std::shared_ptr<Ground>> _grounds{};
	std::shared_ptr<Character> _hero{};
	std::unique_ptr<MainCamera> _mainCamera{};
	std::shared_ptr<b2World> _world{};

public:
	Level();
	void Update(const float& deltaTime);

private:
	void DrawMapToWorld();
};