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
	void CreateFixtureDefinition(float density, float friction);
	void AddToWorld();
	void RemoveFromWorld();
	b2Body* GetBody() const { return _body; }

};
#endif