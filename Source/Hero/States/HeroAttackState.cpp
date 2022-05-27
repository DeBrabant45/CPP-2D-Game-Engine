#include "HeroAttackState.h"
#include "HeroIdleState.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "../Physics/HeroPhysicsComponent.h"

HeroAttackState::HeroAttackState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	_owner{ owner },
	_controller{ controller }
{

}

void HeroAttackState::Start()
{
	_graphics = _owner->GetComponent<HeroGraphicsComponent>();
	_physics = _owner->GetComponent<HeroPhysicsComponent>();
}

void HeroAttackState::OnEnter()
{
	_graphics->SetGraphics(AnimationAction::Attack);
	_attackTimer = 25.f;
}

void HeroAttackState::OnUpdate()
{
	_attackTimer--;
	if (_attackTimer <= 0)
	{
		_controller->TransitionToState(_controller->GetState<HeroIdleState>());
		return;
	}
}

void HeroAttackState::OnExit()
{

}