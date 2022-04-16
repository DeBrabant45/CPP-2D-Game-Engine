#include "Rigidbody.h"

Rigidbody::Rigidbody(std::shared_ptr<b2World> world) :
    _world { world }
{

}

void Rigidbody::AddToWorld()
{
    _body = _world->CreateBody(&_bodyDefinition);
}

void Rigidbody::RemoveFromWorld()
{
    _world->DestroyBody(_body);
}

void Rigidbody::CreateDefinition(b2BodyType bodyType, Vector2 position)
{
    _bodyDefinition.type = bodyType;
    _bodyDefinition.position.Set(position.x, position.y);
    _bodyDefinition.fixedRotation = true;
}

void Rigidbody::CreateShape(Vector2 size)
{
    _shape.SetAsBox(size.x / 2.f, size.y / 2.f);
}