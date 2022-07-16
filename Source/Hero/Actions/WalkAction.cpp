#include "WalkAction.h"
#include <raylib.h>
#include "../../GameObject/GameObject.h"
#include "../../Physics/MovementComponent.h"
#include "../../Transform/Transformation.h"

WalkAction::WalkAction(std::shared_ptr<GameObject> owner) :
	_owner { owner },
	_speed{ 95.f }
{

}

void WalkAction::Start()
{
	_movement = _owner->GetComponent<MovementComponent>();
	_transform = _owner->GetComponent<Transformation>();
}

void WalkAction::DoAction()
{
	if (IsKeyDown(KEY_D))
	{
		_movement->SetXVelocity(_speed);
		_transform->SetDirection(1.f);
	}
	else if (IsKeyDown(KEY_A))
	{
		_movement->SetXVelocity(-_speed);
		_transform->SetDirection(-1.f);
	}
}