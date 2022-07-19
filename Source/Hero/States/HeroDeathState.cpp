#include "HeroDeathState.h"
#include "../../GameObject/GameObject.h"
#include "../../State/StateController.h"
#include "../Graphics/HeroGraphicsComponent.h"

HeroDeathState::HeroDeathState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	HeroBaseState(owner, controller)
{

}

void HeroDeathState::Start()
{
	HeroBaseState::Start();
}

void HeroDeathState::OnEnter()
{
	Owner->Destroy();
}

void HeroDeathState::OnExit()
{

}