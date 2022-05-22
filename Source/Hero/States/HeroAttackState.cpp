#include "HeroAttackState.h"
#include "../Graphics/HeroGraphicsComponent.h"
#include "HeroIdleState.h"

void HeroAttackState::OnEnter(std::shared_ptr<GameObject> owner, StateController* controller)
{
	_controller = { controller };
	auto animation = owner->GetComponent<HeroGraphicsComponent>();
	animation->SetGraphics(AnimationAction::Attack);
}

void HeroAttackState::OnExit()
{

}

void HeroAttackState::OnUpdate()
{
	_attackTimer--;
	if (_attackTimer <= 0)
	{
		_controller->TransitionToState(std::make_shared<HeroIdleState>());
	}
}