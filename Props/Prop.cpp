#include "Prop.h"
#include <raymath.h>
#include "../../box2d-main/include/box2d/box2d.h"

Prop::Prop(Vector2 position, std::shared_ptr<b2World> world, Texture2D texture, bool isWalkable) :
	_worldPosition(position),
	_world(world),
	_texture(texture),
	_isWalkable(isWalkable)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(position.x, position.y);
	bodyDef.userData.pointer = uintptr_t(&boxSize);
	
	bodyDef.fixedRotation = true;
	_body = _world->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(boxSize.x / 2, boxSize.y / 2);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 0.0f;
	fixtureDef.friction = 5.3f;
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
	b2Vec2 pos = _body->GetPosition();
	Rectangle source{ boxSize.x, 0.0f, boxSize.x, boxSize.y };
	Rectangle dest{ pos.x - boxSize.x / 2, pos.y - boxSize.y / 2 , boxSize.x,  boxSize.y };
	DrawTexturePro(_texture, source, dest, Vector2{}, 0.f, WHITE);
}