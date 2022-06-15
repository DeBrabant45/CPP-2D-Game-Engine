#include "HellhoundFactory.h"
#include "HellhoundProduction.h"

std::shared_ptr<IGameObjectProduction> HellhoundFactory::CreateProduction()
{
	return std::make_shared<HellhoundProduction>();
}
