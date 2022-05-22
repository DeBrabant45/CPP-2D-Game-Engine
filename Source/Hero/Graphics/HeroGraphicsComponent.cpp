#include "HeroGraphicsComponent.h"
#include "../../GameObject/GameObject.h"
#include "../../Transform/Transformation.h"
#include "AnimationAction.h"

HeroGraphicsComponent::HeroGraphicsComponent(std::shared_ptr<GameObject> owner) :
	_owner{ owner }
{

}

void HeroGraphicsComponent::SetGraphics(AnimationAction action)
{
	switch (action)
	{
	case AnimationAction::Run:
		_current = _run;
		break;
	case AnimationAction::Jump:
		_current = _jump;
		break;
	case AnimationAction::Attack:
		_current = _attack;
		break;
	case AnimationAction::Fall:
		_current = _fall;
		break;
	case AnimationAction::Idle:
		_current = _idle;
		break;
	}
}

void HeroGraphicsComponent::Start()
{
	_transform = _owner->GetComponent<Transformation>();
}

void HeroGraphicsComponent::Update(const float& deltaTime)
{
	_current->Draw(deltaTime, _transform->GetPosition(), _lookDirection);
}