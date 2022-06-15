#include "HellhoundPhysicsComponent.h"
#include "../../../GameObject/GameObject.h"
#include "../../../Character/CharacterType.h"
#include "../../../Transform/Transformation.h"

HellhoundPhysicsComponent::HellhoundPhysicsComponent(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world) :
    _owner{ owner },
    _world{ world },
    _rigidbody{ world }
{

}

void HellhoundPhysicsComponent::Start()
{
    _transform = _owner->GetComponent<Transformation>();
    _rigidbody.CreateDefinition(b2_dynamicBody, _transform->GetPosition());
    _rigidbody.AddToWorld();
    _rigidbody.CreateShape(Vector2{ 32.f, 32.f });
    //_rigidbody.CreateFixtureDefinition<CharacterType>(120.f, 0.3f, CharacterType::Hellhound);
    _hit = new IHittable();
    _rigidbody.CreateFixtureDefinition<IHittable*>(120.f, 0.3f, _hit);
}

void HellhoundPhysicsComponent::Update(const float& deltaTime)
{
    Vector2 position{ _rigidbody.GetPosition().x,  _rigidbody.GetBody()->GetPosition().y };
    _transform->SetPosition(position);
}