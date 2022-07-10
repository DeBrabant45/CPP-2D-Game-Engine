#include "Rigidbody.h"
#include "../GameObject/GameObject.h"
#include "../Transform/Transformation.h"

Rigidbody::Rigidbody(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world, RigidbodyData bodyData) :
	_owner { owner },
	_world { world },
	_bodyData { bodyData }
{

}

void Rigidbody::Start()
{
	_tranform = _owner->GetComponent<Transformation>();
	CreateDefinition();
	AddToWorld();
	CreateShape();
	CreateFixtureDefinition();
}

void Rigidbody::CreateDefinition()
{
	_bodyType = _bodyData.BodyType;
	_bodyDefinition.type = _bodyType;
	_bodyDefinition.position.Set(_tranform->GetPosition().x, _tranform->GetPosition().y);
	_bodyDefinition.fixedRotation = true;
}

void Rigidbody::CreateShape()
{
	_shape.SetAsBox(_tranform->GetSize().x / 2.f, _tranform->GetSize().y / 2.f);
}

void Rigidbody::CreateFixtureDefinition()
{
	b2FixtureDef fixtureDefinition;
	fixtureDefinition.shape = &_shape;
	fixtureDefinition.density = _bodyData.Density;
	fixtureDefinition.friction = _bodyData.Friction;
	fixtureDefinition.userData.pointer = reinterpret_cast<uintptr_t>(_owner.get());
	_body->CreateFixture(&fixtureDefinition);
}

void Rigidbody::AddToWorld()
{
	_body = _world->CreateBody(&_bodyDefinition);
}

void Rigidbody::RemoveFromWorld()
{
	_world->DestroyBody(_body);
}

void Rigidbody::ApplyLinearImpulseToCenter(const b2Vec2& impluse, bool wake)
{
	_body->ApplyLinearImpulseToCenter(impluse, wake);
}

void Rigidbody::Update(const float& deltaTime)
{

}

const float& Rigidbody::GetMass()
{
	return _body->GetMass();
}

const b2Vec2& Rigidbody::GetPosition()
{
	return _body->GetPosition();
}

const Vector2& Rigidbody::GetVector2Position()
{
	return Vector2{ GetPosition().x,  GetPosition().y }; 
}

const b2Vec2 Rigidbody::GetLinearVelocity()
{
	return _body->GetLinearVelocity();
}

b2Vec2 Rigidbody::GetWorldCenter()
{
	return _body->GetWorldCenter();
}

b2Vec2 Rigidbody::GetWorldPoint(const b2Vec2& localpoint)
{
	return _body->GetWorldPoint(localpoint);
}

b2ContactEdge* Rigidbody::GetContactList()
{
	return _body->GetContactList();
}