#include "../../box2d-main/include/box2d/box2d.h"
#include "HeroPhysicsComponent.h"
#include "../Character/Character.h"
#include "../Character/CharacterType.h"
#include "../Ground/GroundType.h"
#include <iostream>
#include <raymath.h>


HeroPhysicsComponent::HeroPhysicsComponent(std::shared_ptr<b2World> world, Vector2 startPosition) :
    _world{ world },
    _rigidbody{ world }
{
    _rigidbody.CreateDefinition(b2_dynamicBody, startPosition);
    _rigidbody.AddToWorld();
    _rigidbody.CreateShape(Vector2{ 20.f, 48.f });
    _rigidbody.CreateFixtureDefinition<CharacterType>(1.f, 0.3f, CharacterType::Hero);
}

void HeroPhysicsComponent::Update(Character& character, const float& deltaTime)
{ 
    ContactCheck();
    character.IsGrounded = _isGrounded;
    Vector2 position{ _rigidbody.GetPosition().x,  _rigidbody.GetBody()->GetPosition().y };
    character.SetPosition(position);
    float velocityChange = character.Velocity.x - _rigidbody.GetBody()->GetLinearVelocity().x;
    float impulse = _rigidbody.GetMass() * velocityChange;
    float jumpImpluse = _rigidbody.GetMass() * character.Velocity.y;
    _rigidbody.GetBody()->ApplyLinearImpulseToCenter(b2Vec2(impulse, jumpImpluse), true);
}

void HeroPhysicsComponent::ContactCheck()
{
    for (b2ContactEdge* contactEdge = _rigidbody.GetBody()->GetContactList(); contactEdge != nullptr; contactEdge = contactEdge->next)
    {
        b2Contact* contactPoint = contactEdge->contact;
        ApplyHazardForce(contactPoint);
        GroundedCheck(contactPoint);
    }
}

void HeroPhysicsComponent::GroundedCheck(b2Contact* contact)
{
    GroundType fixtureB = (GroundType)contact->GetFixtureB()->GetUserData().pointer;
    if (contact->IsTouching() && fixtureB == GroundType::Walkable)
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

void HeroPhysicsComponent::ApplyHazardForce(b2Contact* contact)
{
    GroundType fixtureB = (GroundType)contact->GetFixtureB()->GetUserData().pointer;
    if (contact->IsTouching() && fixtureB == GroundType::Hazard)
    {
        _rigidbody.GetBody()->ApplyForce(b2Vec2(0, _rigidbody.GetMass() * (-500.f * 12)), _rigidbody.GetPosition(), true);
    }
}