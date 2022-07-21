#include "HeroIdleState.h"
#include <raylib.h>
#include "../Graphics/HeroGraphicsComponent.h"
#include "../../GameObject/GameObject.h"
#include "../Transitions/JumpTransition.h"
#include "../Transitions/AttackTransition.h"
#include "../Transitions/FallTransition.h"
#include "../Transitions/WalkTransition.h"
#include "../Transitions/DeathTransition.h"

HeroIdleState::HeroIdleState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	StateBase(owner, controller)
{
	AddTransition(std::make_shared<DeathTransition>(owner, controller));
	AddTransition(std::make_shared<AttackTransition>(owner, controller));
	AddTransition(std::make_shared<WalkTransition> (owner, controller));
	AddTransition(std::make_shared<JumpTransition>(owner, controller));
	AddTransition(std::make_shared<FallTransition>(owner, controller));
}

void HeroIdleState::Start()
{
	_graphics = Owner->GetComponent<HeroGraphicsComponent>();
	StateBase::Start();
}

void HeroIdleState::OnEnter()
{
	_graphics->SetGraphics(AnimationAction::Idle);
}