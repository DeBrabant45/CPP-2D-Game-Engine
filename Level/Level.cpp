#include "Level.h"
#include <raymath.h>
#include <iostream>
#include "../Hero/HeroPhysicsComponent.h"
#include "../Hero/HeroGraphicsComponent.h"
#include "../Hero/HeroInputComponent.h"
#include "../Input/InputHandler.h"
#include "../../box2d-main/include/box2d/box2d.h"
#include "../Ground/GroundPhysicsComponent.h"
#include "../Ground/GroundGraphicsComponent.h"

Level::Level()
{
	_world = std::make_shared<b2World>(b2Vec2(0.f, 99.8f));
	_props =
	{
		{ Vector2{ 100.f, 300.0f }, _world, LoadTexture("./Assets/Ground/Ground.png"), true },
	};
	_hero = 
	{
		std::make_shared<GameObject>
		(
			std::make_shared<HeroPhysicsComponent>(_world, Vector2{ 100.f, 200.f }),
			std::make_shared<HeroGraphicsComponent>(),
			std::make_shared<HeroInputComponent>(std::make_shared<InputHandler>())
		) 
	};
	_grounds =
	{
		{ std::make_shared<GroundPhysicsComponent>(_world, Vector2{120.f, 32.f}, Vector2{ 200.f, 300.f}), std::make_shared<GroundGraphicsComponent>(), std::make_shared<HeroInputComponent>(std::make_shared<InputHandler>()) },
	};
	_mainCamera = { std::make_unique<MainCamera>(_hero) };
}

void Level::Update(const float& deltaTime)
{
	_world->Step(deltaTime, 8, 2);
	_mainCamera->Update(deltaTime);
	BeginMode2D(_mainCamera->GetCamera());
	DrawMapToWorld();
	for (auto ground : _grounds)
	{
		ground.Update(deltaTime);
	}
	_hero->Update(deltaTime);
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