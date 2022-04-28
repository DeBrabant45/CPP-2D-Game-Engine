#include "HellhoundGraphicsComponent.h"
#include "../../Transform/Transformation.h"
#include "../../GameObject/GameObject.h"

HellhoundGraphicsComponent::HellhoundGraphicsComponent(std::shared_ptr<GameObject> owner) :
	_owner{ owner }
{

}

void HellhoundGraphicsComponent::Start()
{
	_transform = _owner->GetComponent<Transformation>();
}

void HellhoundGraphicsComponent::Update(const float& deltaTime)
{
	_idle.Draw(deltaTime, _transform->GetPosition(), 1.f);
}