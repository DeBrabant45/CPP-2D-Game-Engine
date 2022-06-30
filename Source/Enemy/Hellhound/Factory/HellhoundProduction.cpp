#include "HellhoundProduction.h"
#include "../../../Transform/Transformation.h"
#include "../Graphics/HellhoundGraphicsComponent.h"
#include "../Physics/HellhoundRigidbody.h"

std::shared_ptr<GameObject> HellhoundProduction::Produce(std::shared_ptr<b2World> world, Vector2 position)
{
		std::shared_ptr<GameObject> hellHound = std::make_shared<GameObject>();
		hellHound->AddComponent(std::make_shared<Transformation>(hellHound, position, Vector2{ 32.f, 32.f }));
		hellHound->AddComponent(std::make_shared<HellhoundGraphicsComponent>(hellHound));
		hellHound->AddComponent(std::make_shared<HellhoundRigidbody>(hellHound, world));
		return hellHound;
}