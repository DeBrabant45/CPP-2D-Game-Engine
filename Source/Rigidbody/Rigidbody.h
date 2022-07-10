#pragma once
#include <box2d/box2d.h>
#include <raylib.h>
#include <memory>
#include "../Component/IComponent.h"
#include "RigidbodyData.h"
#ifndef RIGIDBODY_H
#define RIGIDBODY_H

class GameObject;
class b2World;
class Transformation;

class Rigidbody : public IComponent
{
private:
	RigidbodyData _bodyData{};
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<b2World> _world{};
	std::shared_ptr<Transformation> _tranform{};
	b2BodyType _bodyType{};
	b2Body* _body{};
	b2BodyDef _bodyDefinition{};
	b2PolygonShape _shape{};

public:
	Rigidbody(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world, RigidbodyData bodyData);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
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

private:
	void CreateDefinition();
	void CreateShape();
	void CreateFixtureDefinition();
};
#endif