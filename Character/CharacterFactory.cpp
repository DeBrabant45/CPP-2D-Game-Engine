#include <vector>
#include <iostream>
#include "CharacterFactory.h"
#include "Character.h"
#include "../Input/InputHandler.h"
#include "../Component/IComponent.h"
#include "../Hero/HeroPhysicsComponent.h"
#include "../Hero/HeroGraphicsComponent.h"
#include "../Hero/HeroInputComponent.h"
#include "../Health/HealthComponent.h"

std::shared_ptr<Character> CharacterFactory::Create(CharacterType characterType, std::shared_ptr<b2World> world, Vector2 position)
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

std::shared_ptr<Character> CharacterFactory::CreateHero(std::shared_ptr<b2World> world, Vector2 position)
{
	return std::make_shared<Character>(std::vector<std::shared_ptr<IComponent<Character>>> 
	{
		std::make_shared<HeroPhysicsComponent>(world, Vector2{ position.x, position.y }),
		std::make_shared<HeroGraphicsComponent>(),
		std::make_shared<HeroInputComponent>(std::make_shared<InputHandler>()),
		std::make_shared<HealthComponent>(100.f)
	});
}