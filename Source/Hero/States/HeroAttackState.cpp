#include "HeroAttackState.h"
#include "HeroIdleState.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "../Physics/HeroPhysicsComponent.h"
#include "../../Physics/MovementComponent.h"
#include "../Transitions/IdleTransition.h"

HeroAttackState::HeroAttackState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	HeroBaseState(owner, controller)
{
	AddTransition(std::make_shared<IdleTransition>(owner, controller));
}

void HeroAttackState::Start()
{
	_graphics = Owner->GetComponent<HeroGraphicsComponent>();
	_attack = Owner->GetComponent<HeroAttackComponent>();
	HeroBaseState::Start();
}

void HeroAttackState::OnEnter()
{
	_graphics->SetGraphics(AnimationAction::Attack);
	_attack->Inflict();
	_attackTimer = 25.f;
}

void HeroAttackState::OnExit()
{

}

void HeroAttackState::OnUpdate()
{
	_attackTimer--;
	if (_attackTimer <= 0)
	{
		HeroBaseState::OnUpdate();
	}
}