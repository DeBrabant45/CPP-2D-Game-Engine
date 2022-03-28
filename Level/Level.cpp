#include "Level.h"
#include <raymath.h>
#include <iostream>
#include "../Hero/HeroPhysicsComponent.h"
#include "../Hero/HeroGraphicsComponent.h"
#include "../Hero/HeroInputComponent.h"
#include "../Input/InputHandler.h"
#include "../../box2d-main/include/box2d/box2d.h"
#include "../GameObject/IGameObjectComponent.h"
#include "../GameObject/IGameObject.h"

Level::Level()
{
	_world = std::make_shared<b2World>(b2Vec2(0.f, 199.8f));
	_hero = std::make_shared<Character>(std::vector<std::shared_ptr<ICharacterComponent>>
	{
		std::make_shared<HeroPhysicsComponent>(_world, Vector2{ 100.f, 200.f }),
		std::make_shared<HeroGraphicsComponent>(),
		std::make_shared<HeroInputComponent>(std::make_shared<InputHandler>())
	});
	_grounds =
	{
		_groundFactory.Create(_world, Vector2{ 100.f, 32.f }, Vector2{ 100.f, 300.f}),
		_groundFactory.Create(_world, Vector2{ 100.f, 32.f }, Vector2{ 230.f, 300.f})
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
		ground->Update(deltaTime);
	}
	_hero->Update(deltaTime);
	EndMode2D();
}

void Level::DrawMapToWorld()
{
	DrawTextureEx(_texture, _worldPosition, 0.0f, _scale, WHITE);
}