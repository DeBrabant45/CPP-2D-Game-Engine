#pragma once
#ifndef RIGIDBODY_H
#define RIGIDBODY_H
#include <raylib.h>
#include <memory>
#include "../../box2d-main/include/box2d/box2d.h"

class Rigidbody
{

private:
	b2Body* _body{};
	b2BodyDef _bodyDefinition;
	b2PolygonShape _shape;
	std::shared_ptr<b2World> _world;

public:
	Rigidbody(std::shared_ptr<b2World> world);
	void CreateDefinition(b2BodyType bodyType, Vector2 position);
	void CreateShape(Vector2 size);
	template<typename T>
	void CreateFixtureDefinition(float density, float friction, T data);
	void AddToWorld();
	void RemoveFromWorld();
	const float& GetMass() { return _body->GetMass(); }
	const b2Vec2& GetPosition() { return _body->GetPosition(); }
	b2Body* GetBody() const { return _body; }

};

template<typename T>
inline void Rigidbody::CreateFixtureDefinition(float density, float friction, T data)
{
	b2FixtureDef fixtureDefinition;
	fixtureDefinition.shape = &_shape;
	fixtureDefinition.density = density;
	fixtureDefinition.friction = friction;
	fixtureDefinition.userData.pointer = uintptr_t(data);
	_body->CreateFixture(&fixtureDefinition);
}
#endif