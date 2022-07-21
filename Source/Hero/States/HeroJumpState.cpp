#include "HeroJumpState.h"
#include <raylib.h>
#include "../Graphics/HeroGraphicsComponent.h"
#include "../Physics/HeroPhysicsComponent.h"
#include "../../Transform/Transformation.h"
#include "../Actions/FloatAction.h"
#include "../Transitions/JumpTransition.h"
#include "../Transitions/IdleTransition.h"
#include "../Transitions/AttackTransition.h"
#include "../Transitions/FallTransition.h"
#include "../Transitions/DeathTransition.h"


HeroJumpState::HeroJumpState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	StateBase(owner, controller)
{
	AddAction(std::make_shared<FloatAction>(owner));
	AddTransition(std::make_shared<DeathTransition>(owner, controller));
	AddTransition(std::make_shared<FallTransition>(owner, controller));
	AddTransition(std::make_shared<JumpTransition>(owner, controller));
	AddTransition(std::make_shared<IdleTransition>(owner, controller));
}

void HeroJumpState::Start()
{
	_graphics = Owner->GetComponent<HeroGraphicsComponent>();
	_movement = Owner->GetComponent<MovementComponent>();
	StateBase::Start();
}

void HeroJumpState::OnEnter()
{
	_timer = 9.f;
	_graphics->SetGraphics(AnimationAction::Jump);
	_movement->SetYVelocity(_jumpHeight);
}

void HeroJumpState::OnUpdate()
{
	_timer--;
	if (_timer <= 0)
	{
		StateBase::OnUpdate();
	}
}

void HeroJumpState::OnExit()
{

}