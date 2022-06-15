#include "HeroFactory.h"
#include "HeroProduction.h"
#include "../../GameObject/IGameObjectProduction.h"

std::shared_ptr<IGameObjectProduction> HeroFactory::CreateProduction()
{
    return std::make_shared<HeroProduction>();
}