#include "HeroPhysicsComponent.h"
#include <raymath.h>
#include <iostream>


HeroPhysicsComponent::HeroPhysicsComponent(std::shared_ptr<b2World> world, Vector2 startPosition) :
    PhysicsComponent(world)
{
    _bodyDefinition.type = b2_dynamicBody;
    _bodyDefinition.position.Set(startPosition.x, startPosition.y);
    _bodyDefinition.userData.pointer = uintptr_t(2);
    _bodyDefinition.fixedRotation = true;
    _body = World->CreateBody(&_bodyDefinition);
    _shape.SetAsBox(20.f / 2.f, 48.f / 2.f);
    b2FixtureDef fixtureDefinition;
    fixtureDefinition.shape = &_shape;
    fixtureDefinition.density = 1.f;
    fixtureDefinition.friction = .03f;
    _body->CreateFixture(&fixtureDefinition);
}

void HeroPhysicsComponent::Update(GameObject& gameObject, const float& deltaTime)
{
    float velocityChange = gameObject.Velocity.x - _body->GetLinearVelocity().x;
    float impulse = _body->GetMass() * velocityChange;
    float jumpImpluse = _body->GetMass() * gameObject.Velocity.y;
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
