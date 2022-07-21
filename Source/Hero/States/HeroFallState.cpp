#include "HeroFallState.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "../Transitions/IdleTransition.h"
#include "../Actions/FloatAction.h"
#include "../Transitions/DeathTransition.h"

HeroFallState::HeroFallState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	StateBase(owner, controller)
{
	AddAction(std::make_shared<FloatAction>(owner));
	AddTransition(std::make_shared<DeathTransition>(owner, controller));
	AddTransition(std::make_shared<IdleTransition>(owner, controller));
}

void HeroFallState::Start()
{
	_graphics = Owner->GetComponent<HeroGraphicsComponent>();
	StateBase::Start();
}

void HeroFallState::OnEnter()
{
	_graphics->SetGraphics(AnimationAction::Fall);
}

void HeroFallState::OnExit()
{

}