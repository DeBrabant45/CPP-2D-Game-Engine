#include "Prop.h"
#include <raymath.h>
#include "../../box2d-main/include/box2d/box2d.h"

Prop::Prop(Vector2 position, std::shared_ptr<b2World> world, Texture2D texture, bool isWalkable) :
	_worldPosition(position),
	_world(world),
	_texture(texture),
	_isWalkable(isWalkable)
{
	Vector2 boxSize = { 120, 32 };
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(position.x / 50, position.y / 50);
	bodyDef.userData.pointer = uintptr_t(&boxSize);
	
	bodyDef.fixedRotation = true;
	_body = _world->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox((boxSize.x / 50) / 2, (boxSize.y / 50) / 2);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = .3f;
	_body->CreateFixture(&fixtureDef);
}

void Prop::Render()
{
	DrawTextureEx(_texture, _worldPosition, 0.f, _scale, WHITE);
}

Rectangle Prop::GetRectangleCollision()
{
	return Rectangle
	{
		_worldPosition.x,
		_worldPosition.y,
		_texture.width * _scale,
		_texture.height * _scale
	};
}

void Prop::Update(const float& deltaTime)
{
	_worldPosition = Vector2{ _body->GetPosition().x * 50, _body->GetPosition().y * 50 };
	Rectangle source{ 120, 0.0f, 1.f * 120, 32 };
	Rectangle dest{ _worldPosition.x - 75, _worldPosition.y + 36, 120, 32 };
	DrawTexturePro(_texture, source, dest, Vector2{}, 0.f, WHITE);
}