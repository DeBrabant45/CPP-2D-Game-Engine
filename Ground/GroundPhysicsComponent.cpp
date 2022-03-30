#include "GroundPhysicsComponent.h"
#include "../../box2d-main/include/box2d/box2d.h"
#include <iostream>

GroundPhysicsComponent::GroundPhysicsComponent(std::shared_ptr<b2World> world, GroundType groundType, Vector2 size, Vector2 worldPosition) :
	_world{ world }
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(worldPosition.x, worldPosition.y);
	bodyDef.userData.pointer = uintptr_t(&size);
	bodyDef.fixedRotation = true;
	_body = _world->CreateBody(&bodyDef);
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(size.x / 2, size.y / 2);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 0.0f;
	fixtureDef.friction = 5.3f;
	fixtureDef.userData.pointer = uintptr_t(groundType);
	_body->CreateFixture(&fixtureDef);
}

void GroundPhysicsComponent::Update(IGameObject& gameObject, const float& deltaTime)
{
	Vector2 position{ _body->GetPosition().x, _body->GetPosition().y };
	gameObject.SetPosition(position);
}