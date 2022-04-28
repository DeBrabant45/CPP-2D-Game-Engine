#include "HeroPhysicsComponent.h"
#include "../Character/CharacterType.h"
#include "../Ground/GroundType.h"
#include "../GameObject/GameObject.h"
#include "../Transform/Transformation.h"
#include <iostream>
#include <raymath.h>
#include <box2d/box2d.h>


HeroPhysicsComponent::HeroPhysicsComponent(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world) :
    _owner{ owner },
    _world{ world },
    _rigidbody{ world }
{

}

void HeroPhysicsComponent::Start()
{
    _transform = _owner->GetComponent<Transformation>();
    _rigidbody.CreateDefinition(b2_dynamicBody, _transform->GetPosition());
    _rigidbody.AddToWorld();
    _rigidbody.CreateShape(Vector2{ 20.f, 48.f });
    _rigidbody.CreateFixtureDefinition<CharacterType>(1.f, 0.3f, CharacterType::Hero);
}

void HeroPhysicsComponent::Update(const float& deltaTime)
{ 
    ContactCheck();
    Vector2 position{ _rigidbody.GetPosition().x,  _rigidbody.GetBody()->GetPosition().y };
    _transform->SetPosition(position);
    float velocityChange = Velocity.x - _rigidbody.GetBody()->GetLinearVelocity().x;
    float impulse = _rigidbody.GetMass() * velocityChange;
    float jumpImpluse = _rigidbody.GetMass() * Velocity.y;
    _rigidbody.GetBody()->ApplyLinearImpulseToCenter(b2Vec2(impulse, jumpImpluse), true);
}

void HeroPhysicsComponent::ContactCheck()
{
    for (b2ContactEdge* contactEdge = _rigidbody.GetBody()->GetContactList(); contactEdge != nullptr; contactEdge = contactEdge->next)
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
            if (man.points[i].y > _rigidbody.GetPosition().y - _rigidbody.GetPosition().y / 2.0f + 0.01f)
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