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
#include "../Enemy/Hellhound/HellhoundGraphicsComponent.h"
#include "../Enemy/Hellhound/HellhoundPhysicsComponent.h"

std::shared_ptr<GameObject> CharacterFactory::Create(CharacterType characterType, std::shared_ptr<b2World> world, Vector2 position)
{
	switch (characterType)
	{
	case CharacterType::Hero:
		return CreateHero(world, position);
	case CharacterType::Hellhound:
		return CreateHellhound(world, position);
	default:
		std::cout << "Character type is invalid!!";
		break;
	}
}

std::shared_ptr<GameObject> CharacterFactory::CreateHero(std::shared_ptr<b2World> world, Vector2 position)
{
	std::shared_ptr<GameObject> hero = std::make_shared<GameObject>();
	hero->AddComponent(std::make_shared<Transformation>(position));
	hero->AddComponent(std::make_shared<HeroStateComponent>(hero));
	hero->AddComponent(std::make_shared<HeroPhysicsComponent>(hero, world));
	hero->AddComponent(std::make_shared<HeroGraphicsComponent>(hero));
	hero->AddComponent(std::make_shared<HeroInputComponent>(hero, std::make_shared<InputHandler>()));
	hero->AddComponent(std::make_shared<HealthComponent>(100.f));
	return hero;
}

std::shared_ptr<GameObject> CharacterFactory::CreateHellhound(std::shared_ptr<b2World> world, Vector2 position)
{
	std::shared_ptr<GameObject> hellHound = std::make_shared<GameObject>();
	hellHound->AddComponent(std::make_shared<Transformation>(position));
	hellHound->AddComponent(std::make_shared<HellhoundGraphicsComponent>(hellHound));
	hellHound->AddComponent(std::make_shared<HellhoundPhysicsComponent>(hellHound, world));
	return hellHound;
}
