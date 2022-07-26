#include "Level.h"
#include <raymath.h>
#include <iostream>
#include <box2d/box2d.h>
#include "../Ground/GroundType.h"
#include "../Component/IComponent.h"
#include "../GameObject/Factory/GameObjectFactory.h"
#include "../Hero/Factory/HeroFactory.h"
#include "../Enemy/Hellhound/Factory/HellhoundFactory.h"

Level::Level()
{
	_world = std::make_shared<b2World>(b2Vec2(0.f, 129.8f));
	std::shared_ptr<GameObjectFactory> heroFactory = std::make_shared<HeroFactory>();
	std::shared_ptr<GameObjectFactory> hellhoundFactory = std::make_shared<HellhoundFactory>();
	_hero = heroFactory->CreateGameObject(_world, Vector2{ 100.f, 266.f });
	_hellHound = hellhoundFactory->CreateGameObject(_world, Vector2{ 200.f, 266.f });
	_grounds =
	{
		_groundFactory.CreateGameObject(GroundType::Hazard, _world, Vector2{ 600.f, 41.f }, Vector2{ 0.f, 300.f}),
		_groundFactory.CreateGameObject(GroundType::Walkable, _world, Vector2{ 300.f, 41.f }, Vector2{ 190.f, 300.f}),
		_groundFactory.CreateGameObject(GroundType::Hazard, _world, Vector2{ 100.f, 41.f }, Vector2{ 390.f, 300.f}),
		_groundFactory.CreateGameObject(GroundType::Walkable, _world, Vector2{ 300.f, 41.f }, Vector2{ 590.f, 300.f}),
	};
}

void Level::Start()
{
	_hero->Start();
	_hellHound->Start();
	for (auto ground : _grounds)
	{
		ground->Start();
	}
	_mainCamera.SetTarget(_hero);
}

void Level::Update(const float& deltaTime)
{
	_world->Step(deltaTime, 8, 2);
	_mainCamera.Update(deltaTime);
	BeginMode2D(_mainCamera.GetCamera());
	DrawMapToWorld();
	for (auto ground : _grounds)
	{
		ground->Update(deltaTime);
	}
	_hero->Update(deltaTime);
	_hellHound->Update(deltaTime);
	DrawRectangle(0.f, 320.f, 5000.f, 60.f, BLACK);
	EndMode2D();
}

void Level::DrawMapToWorld()
{
	DrawTextureEx(_texture1, _worldPosition, 0.0f, 1.f, WHITE);
}