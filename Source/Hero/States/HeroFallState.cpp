#include "HeroFallState.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "../Transitions/IdleTransition.h"
#include "../Actions/FloatAction.h"

HeroFallState::HeroFallState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	HeroBaseState(owner, controller)
{
	AddAction(std::make_shared<FloatAction>(owner));
	AddTransition(std::make_shared<IdleTransition>(owner, controller));
}

void HeroFallState::Start()
{
	_graphics = Owner->GetComponent<HeroGraphicsComponent>();
	HeroBaseState::Start();
}

void HeroFallState::OnEnter()
{
	_graphics->SetGraphics(AnimationAction::Fall);
}

void HeroFallState::OnUpdate()
{
	HeroBaseState::OnUpdate();
}

void HeroFallState::OnExit()
{

}