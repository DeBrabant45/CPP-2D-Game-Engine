#include "Rigidbody.h"
#include "../GameObject/GameObject.h"

Rigidbody::Rigidbody(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world) :
	Owner { owner },
	World { world }
{

}

void Rigidbody::AddToWorld()
{
	Body = World->CreateBody(&BodyDefinition);
}

void Rigidbody::RemoveFromWorld()
{
	World->DestroyBody(Body);
}

void Rigidbody::ApplyLinearImpulseToCenter(const b2Vec2& impluse, bool wake)
{
	Body->ApplyLinearImpulseToCenter(impluse, wake);
}

const float& Rigidbody::GetMass()
{
	return Body->GetMass();
}

const b2Vec2& Rigidbody::GetPosition()
{
	return Body->GetPosition();
}

const Vector2& Rigidbody::GetVector2Position()
{
	return Vector2{ GetPosition().x,  GetPosition().y }; 
}

const b2Vec2 Rigidbody::GetLinearVelocity()
{
	return Body->GetLinearVelocity();
}

b2Vec2 Rigidbody::GetWorldCenter()
{
	return Body->GetWorldCenter();
}

b2Vec2 Rigidbody::GetWorldPoint(const b2Vec2& localpoint)
{
	return Body->GetWorldPoint(localpoint);
}

b2ContactEdge* Rigidbody::GetContactList()
{
	return Body->GetContactList();
}