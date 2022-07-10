#include "HeroPhysicsComponent.h"
#include "../../Character/CharacterType.h"
#include "../../Ground/GroundType.h"
#include "../../GameObject/GameObject.h"
#include "../../Transform/Transformation.h"
#include <iostream>
#include <raymath.h>
#include <box2d/box2d.h>
#include "../../Physics/RayCastCallback.h"
//#include "../../Health/IHittable.h"
#include "../../Rigidbody/Rigidbody.h"


HeroPhysicsComponent::HeroPhysicsComponent(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world) :
    _owner{ owner },
    _world{ world }
{

}

void HeroPhysicsComponent::Start()
{
    _transform = _owner->GetComponent<Transformation>();
    _rigidbody = _owner->GetComponent<Rigidbody>();
}

void HeroPhysicsComponent::Update(const float& deltaTime)
{ 
    ContactCheck();
}

void HeroPhysicsComponent::ContactCheck()
{
    for (b2ContactEdge* contactEdge = _rigidbody->GetContactList(); contactEdge != nullptr; contactEdge = contactEdge->next)
    {
        b2Contact* contactPoint = contactEdge->contact;
        ApplyDamage(contactPoint);
        GroundedCheck(contactPoint);

    }
}

void HeroPhysicsComponent::GroundedCheck(b2Contact* contact)
{
    GroundType fixtureB = (GroundType)contact->GetFixtureB()->GetUserData().pointer;
    if (contact->IsTouching() /*&& fixtureB == GroundType::Walkable*/)
    {
        b2WorldManifold man;
        contact->GetWorldManifold(&man);
        for (int i = 0; i < b2_maxManifoldPoints; i++)
        {
            if (man.points[i].y > _rigidbody->GetPosition().y - _rigidbody->GetPosition().y / 2.0f + 0.01f)
            {
                _isGrounded = true;
            }

        }
    }
    else
    {
        _isGrounded = false;
    }
}

void HeroPhysicsComponent::ApplyDamage(b2Contact* contact)
{
    GroundType fixtureB = (GroundType)contact->GetFixtureB()->GetUserData().pointer;
    if (contact->IsTouching() && fixtureB == GroundType::Hazard)
    {
        //_rigidbody.GetBody()->ApplyForce(b2Vec2(0, _rigidbody.GetMass() * (-500.f * 12)), _rigidbody.GetPosition(), true);
        _owner->Events(10);
    }
}