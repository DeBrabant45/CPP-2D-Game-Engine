#include "../../box2d-main/include/box2d/box2d.h"
#include "HeroPhysicsComponent.h"
#include "../Character/Character.h"
#include <iostream>
#include <raymath.h>


HeroPhysicsComponent::HeroPhysicsComponent(std::shared_ptr<b2World> world, Vector2 startPosition) :
    _world{ world }
{
    b2BodyDef bodyDefinition{};
    bodyDefinition.type = b2_dynamicBody;
    bodyDefinition.position.Set(startPosition.x, startPosition.y);
    bodyDefinition.userData.pointer = uintptr_t(2);
    bodyDefinition.fixedRotation = true;
    _body = _world->CreateBody(&bodyDefinition);
    b2PolygonShape shape;
    shape.SetAsBox(20.f / 2.f, 48.f / 2.f);
    b2FixtureDef fixtureDefinition;
    fixtureDefinition.shape = &shape;
    fixtureDefinition.density = 1.f;
    fixtureDefinition.friction = .03f;
    _body->CreateFixture(&fixtureDefinition);
}

void HeroPhysicsComponent::Update(Character& character, const float& deltaTime)
{ 
    character.IsGrounded = IsGrounded();
    Vector2 position{ _body->GetPosition().x, _body->GetPosition().y };
    character.SetWorldPosition(position);
    float velocityChange = character.Velocity.x - _body->GetLinearVelocity().x;
    float impulse = _body->GetMass() * velocityChange;
    float jumpImpluse = _body->GetMass() * character.Velocity.y;
    _body->ApplyLinearImpulseToCenter(b2Vec2(impulse, jumpImpluse), true);
}

bool HeroPhysicsComponent::IsGrounded()
{
    for (b2ContactEdge* ce = _body->GetContactList(); ce != nullptr; ce = ce->next)
    {
        b2Contact* c = ce->contact;
        if (c->IsTouching())
        {
            b2WorldManifold man;
            c->GetWorldManifold(&man);
            for (int i = 0; i < b2_maxManifoldPoints; i++)
            {
                if (man.points[i].y > _body->GetPosition().y - _body->GetPosition().y / 2.0f + 0.01f)
                {
                    return true;
                }

            }
        }
        else
        {
            return false;
        }
    }
}
