#include "HeroProduction.h"
#include "../../Transform/Transformation.h"
#include "../Physics/HeroPhysicsComponent.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "../Input/HeroInputComponent.h"
#include "../../Health/HealthComponent.h"
#include "../../Character/CharacterType.h"
#include "../../Input/InputHandler.h"
#include "../../State/StateController.h"

std::shared_ptr<GameObject> HeroProduction::Produce(std::shared_ptr<b2World> world, Vector2 position)
{
	auto hero = std::make_shared<GameObject>();
	hero->AddComponent(std::make_shared<Transformation>(position));
	hero->AddComponent(std::make_shared<HeroPhysicsComponent>(hero, world));
	hero->AddComponent(std::make_shared<HeroGraphicsComponent>(hero));
	hero->AddComponent(std::make_shared<HeroInputComponent>(hero, std::make_shared<InputHandler>()));
	hero->AddComponent(std::make_shared<HealthComponent>(100.f));
	hero->AddComponent(_stateFactory.CreateController(hero));
	return hero;
}