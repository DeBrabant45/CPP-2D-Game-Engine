#include "Level.h"
#include <raymath.h>
#include <iostream>
#include "../Components/Hero/HeroPhysicsComponent.h"
#include "../Components/Hero/HeroGraphicsComponent.h"
#include "../Components/Hero/HeroInputComponent.h"
#include "../Input/InputHandler.h"
#include "../GameObject/GameObject.h"
#include "../../box2d-main/include/box2d/box2d.h"

Level::Level()
{
	_world = std::make_shared<b2World>(b2Vec2(0.f, 9.f));
	_props =
	{
		{ Vector2{ 110.f, 300.0f }, _world, LoadTexture("./Assets/Props/Ground/Ground.png"), true },
		{ Vector2{ 210.f, 300.f }, _world, LoadTexture("./Assets/Props/Ground/Ground.png"), true },
		{ Vector2{ 310.f, 300.f }, _world, LoadTexture("./Assets/Props/Ground/Ground.png"), true },
		{ Vector2{ 410.f, 300.f }, _world, LoadTexture("./Assets/Props/Ground/Ground.png"), true },
		{ Vector2{ 510.f, 300.f }, _world, LoadTexture("./Assets/Props/Ground/Ground.png"), true },
		{ Vector2{ 610.f, 300.f }, _world, LoadTexture("./Assets/Props/Ground/Ground.png"), true },
	};
	_hero = 
	{
		std::make_shared<GameObject>(Vector2{ 200.f, 0.f },
		std::make_shared<HeroPhysicsComponent>(_world),
		std::make_shared<HeroGraphicsComponent>(),
		std::make_shared<HeroInputComponent>(std::make_shared<InputHandler>())) 
	};
	_mainCamera = { std::make_unique<MainCamera>(_hero) };
}

void Level::Update(float deltaTime)
{
	_world->Step(deltaTime, 8, 2);
	_mainCamera->Update(deltaTime);
	BeginMode2D(_mainCamera->GetCamera());
	DrawMapToWorld();
	_hero->Update(_props, deltaTime);
	for (auto prop : _props)
	{
		prop.Update(deltaTime);
	}
	EndMode2D();
}

void Level::DrawMapToWorld()
{
	DrawTextureEx(_texture, _worldPosition, 0.0f, _scale, WHITE);
}