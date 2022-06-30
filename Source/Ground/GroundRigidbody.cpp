#include "GroundRigidbody.h"
#include "../Transform/Transformation.h"
#include "GroundType.h"

GroundRigidbody::GroundRigidbody(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world) :
	Rigidbody(owner, world)
{

}

void GroundRigidbody::Start()
{
	auto transform = Owner->GetComponent<Transformation>();
	CreateDefinition(transform->GetPosition());
	AddToWorld();
	CreateShape(transform->GetSize());
	CreateFixtureDefinition((uintptr_t)GroundType::Walkable);
}

void GroundRigidbody::CreateDefinition(Vector2 position)
{
	BodyType = b2_staticBody;
	BodyDefinition.type = BodyType;
	BodyDefinition.position.Set(position.x, position.y);
	BodyDefinition.fixedRotation = true;
}

void GroundRigidbody::CreateShape(Vector2 size)
{
	Shape.SetAsBox(size.x / 2.f, size.y / 2.f);
}

void GroundRigidbody::CreateFixtureDefinition(uintptr_t userData)
{
	b2FixtureDef fixtureDefinition;
	fixtureDefinition.shape = &Shape;
	fixtureDefinition.density = 0.f;
	fixtureDefinition.friction = 5.3f;
	fixtureDefinition.userData.pointer = userData;
	Body->CreateFixture(&fixtureDefinition);
}

void GroundRigidbody::Update(const float& deltaTime)
{

}