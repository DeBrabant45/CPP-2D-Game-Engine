#include "HeroPhysicsComponent.h"
#include <raymath.h>
#include <iostream>


HeroPhysicsComponent::HeroPhysicsComponent(std::shared_ptr<b2World> world) :
    PhysicsComponent(world)
{
    _bodyDefinition.type = b2_dynamicBody;
    _bodyDefinition.position.Set(0.f / 38, -50.f / 48);
    _bodyDefinition.userData.pointer = uintptr_t(2);
    _bodyDefinition.fixedRotation = true;
    _body = World->CreateBody(&_bodyDefinition);
}

void HeroPhysicsComponent::SetSize(const Vector2& size)
{
    _shape.SetAsBox((size.x / 40) /2, (size.y / 50) /2 );
    b2FixtureDef fixtureDefinition;
    fixtureDefinition.shape = &_shape;
    fixtureDefinition.density = 1.f;
    fixtureDefinition.friction = .03f;
    _body->CreateFixture(&fixtureDefinition);
}

void HeroPhysicsComponent::Update(GameObject& gameObject, const std::vector<Prop>& props, const float& deltaTime)
{
    float velocityChange = gameObject.Velocity.x - _body->GetLinearVelocity().x;
    float impulse = _body->GetMass() * velocityChange;
    float jumpImpluse = _body->GetMass() * gameObject.Velocity.y;
    _body->ApplyLinearImpulseToCenter(b2Vec2(impulse, jumpImpluse), true);
}