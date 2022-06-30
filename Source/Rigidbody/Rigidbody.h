#pragma once
#include <box2d/box2d.h>
#include <raylib.h>
#include <memory>
#include "../Component/IComponent.h"
#ifndef RIGIDBODY_H
#define RIGIDBODY_H

class GameObject;

class Rigidbody : public IComponent
{
protected:
	std::shared_ptr<GameObject> Owner{};
	std::shared_ptr<b2World> World{};
	b2BodyType BodyType{};
	b2Body* Body{};
	b2BodyDef BodyDefinition{};
	b2PolygonShape Shape{};

protected:
	virtual void CreateDefinition(Vector2 position) = 0;
	virtual void CreateShape(Vector2 size) = 0;
	virtual void CreateFixtureDefinition(uintptr_t userData) = 0;

public:
	Rigidbody(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world);
	void AddToWorld();
	void RemoveFromWorld();
	void ApplyLinearImpulseToCenter(const b2Vec2& impluse, bool wake);
	const float& GetMass();
	const b2Vec2& GetPosition();
	const Vector2& GetVector2Position();
	const b2Vec2 GetLinearVelocity();
	b2Vec2 GetWorldCenter();
	b2Vec2 GetWorldPoint(const b2Vec2& localpoint);
	b2ContactEdge* GetContactList();
};
#endif