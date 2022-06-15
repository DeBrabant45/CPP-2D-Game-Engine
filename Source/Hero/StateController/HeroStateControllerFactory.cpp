#include "HeroStateControllerFactory.h"
#include "../../State/IStateControllerProduction.h"
#include "HeroStateControllerProduction.h"

std::shared_ptr<IStateControllerProduction> HeroStateControllerFactory::CreateProduction()
{
	return std::make_shared<HeroStateControllerProduction>();
}