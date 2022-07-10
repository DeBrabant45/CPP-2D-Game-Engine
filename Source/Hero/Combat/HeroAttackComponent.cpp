#include "HeroAttackComponent.h"
#include <box2d/box2d.h>
#include "../../GameObject/GameObject.h"
#include "../../Combat/IHurt.h"
#include "../../Rigidbody/Rigidbody.h"
#include "../../Transform/Transformation.h"
#include "../../Physics/RayCastCallback.h"
#include "../../Health/HealthComponent.h"

HeroAttackComponent::HeroAttackComponent(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world) :
	_owner{ owner },
	_world{ world },
	_attackDamage{ 10.f }
{

}

void HeroAttackComponent::Start()
{
	_rigidbody = _owner->GetComponent<Rigidbody>();
    _transform = _owner->GetComponent<Transformation>();
}

void HeroAttackComponent::Inflict()
{
    b2Vec2 eyeOffset;
    if (_transform->GetDirection() == 1.f)
    {
        eyeOffset = b2Vec2(.5, 0);
    }
    else
    {
        eyeOffset = b2Vec2(-.5, 0);
    }
    b2Vec2 eye = _rigidbody->GetWorldPoint(eyeOffset);
    b2Vec2 target = eye - _rigidbody->GetWorldCenter();
    target.Normalize();
    target *= 50.0;
    target = eye + target;
    RayCastCallback callback;
    _world->RayCast(&callback, _rigidbody->GetPosition(), target);
    if (callback.m_fixture)
    {
        auto hitObject = (GameObject*)callback.m_fixture->GetUserData().pointer;
        if (hitObject != nullptr)
        {
            auto iHurt = hitObject->GetComponent<HealthComponent>();
            if (iHurt != nullptr)
            {
                iHurt->TakeDamage(10);
            }
        }
    }
}

void HeroAttackComponent::Update(const float& deltaTime)
{

}