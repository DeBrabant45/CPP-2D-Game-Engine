#include "HeroProduction.h"
#include "../../Transform/Transformation.h"
#include "../Physics/HeroPhysicsComponent.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "../../Health/HealthComponent.h"
#include "../../Character/CharacterType.h"
#include "../../State/StateController.h"
#include "../../Rigidbody/Rigidbody.h"
#include "../../Physics/MovementComponent.h"
#include "../Combat/HeroAttackComponent.h"
#include "../../Rigidbody/RigidbodyData.h"
#include "../StateController/HeroStateControllerFactory.h"


std::shared_ptr<GameObject> HeroProduction::Produce(std::shared_ptr<b2World> world, Vector2 position)
{
	auto hero = std::make_shared<GameObject>("Hero");
	std::unique_ptr<StateControllerFactory> stateFactory = std::make_unique<HeroStateControllerFactory>();
	hero->AddComponent(std::make_shared<Transformation>(hero, position, Vector2{ 20.f, 48.f }));
	hero->AddComponent(std::make_shared<HeroPhysicsComponent>(hero, world));
	hero->AddComponent(std::make_shared<HeroGraphicsComponent>(hero));
	hero->AddComponent(std::make_shared<HealthComponent>(100.f));
	hero->AddComponent(stateFactory->CreateController(hero));
	hero->AddComponent(std::make_shared<Rigidbody>(hero, world, RigidbodyData{ b2_dynamicBody, 1.f, 8.f }));
	hero->AddComponent(std::make_shared<MovementComponent>(hero, world));
	hero->AddComponent(std::make_shared<HeroAttackComponent>(hero, world));
	return hero;
}