#include "HeroDeathState.h"
#include "../../GameObject/GameObject.h"
#include "../../State/StateController.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "../../Rigidbody/Rigidbody.h"

HeroDeathState::HeroDeathState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	StateBase(owner, controller)
{

}

void HeroDeathState::Start()
{
	StateBase::Start();
}

void HeroDeathState::OnEnter()
{
	Owner->Destroy();
	auto physics = Owner->GetComponent<Rigidbody>();
	physics->RemoveFromWorld();
}