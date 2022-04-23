#include <vector>
#include <iostream>
#include "CharacterFactory.h"
#include "../Input/InputHandler.h"
#include "../Component/IComponent.h"
#include "../Hero/HeroPhysicsComponent.h"
#include "../Hero/HeroGraphicsComponent.h"
#include "../Hero/HeroInputComponent.h"
#include "../Health/HealthComponent.h"
#include "../GameObject/GameObject.h"

std::shared_ptr<GameObject> CharacterFactory::Create(CharacterType characterType, std::shared_ptr<b2World> world, Vector2 position)
{
	switch (characterType)
	{
	case CharacterType::Hero:
		return CreateHero(world, position);
	default:
		std::cout << "Character type is invalid!!";
		break;
	}
}

std::shared_ptr<GameObject> CharacterFactory::CreateHero(std::shared_ptr<b2World> world, Vector2 position)
{
	std::shared_ptr<GameObject> _hero = std::make_shared<GameObject>();
	_hero->AddComponent(std::make_shared<Transformation>(position));
	_hero->AddComponent(std::make_shared<HeroStateComponent>(_hero));
	_hero->AddComponent(std::make_shared<HeroPhysicsComponent>(_hero, world));
	_hero->AddComponent(std::make_shared<HeroGraphicsComponent>(_hero));
	_hero->AddComponent(std::make_shared<HeroInputComponent>(_hero, std::make_shared<InputHandler>()));
	_hero->AddComponent(std::make_shared<HealthComponent>(100.f));
	return _hero;
}