#include "HeroGraphicsComponent.h"
#include <iostream>
#include <raymath.h>

HeroGraphicsComponent::HeroGraphicsComponent()
{
	Texture = _idle;
	_width = static_cast<float>(Texture.width) / _frames;
	_height = static_cast<float>(Texture.height);
	_animator.SetMaxFrames(4);
}

void HeroGraphicsComponent::Update(GameObject& gameObject, std::shared_ptr<PhysicsComponent> physics, const float& deltaTime)
{

	if (gameObject.Velocity.x != 0.0f)
	{
		Texture = _run;
		SetWidth(12);
		_animator.SetMaxFrames(12);
	}
	else
	{
		Texture = _idle;
		SetWidth(4);
		_animator.SetMaxFrames(4);
	}
	if (gameObject.Velocity.y != 0)
	{
		Texture = _jump;
		SetWidth(5);
		_animator.SetMaxFrames(5);
	}
	_animator.Update(deltaTime);
	Rectangle source{ _animator.GetCurrentFrame() * _width, 0.0f, 1.f * _width, _height };
	Rectangle dest{ gameObject.GetPosition().x - 20, gameObject.GetPosition().y - 48, gameObject.GetScale() * _width, gameObject.GetScale() * _height};
	DrawTexturePro(Texture, source, dest, Vector2{}, 0.f, WHITE);

	//Rectangle playerRect = { gameObject.GetPosition().x - 20, gameObject.GetPosition().y - 40, 40, 40 };
	//DrawRectangleRec(playerRect, RED);

}

void HeroGraphicsComponent::Draw()
{

}

void HeroGraphicsComponent::SetWidth(int value)
{
	_width = static_cast<float>(Texture.width) / value;
}

Vector2 HeroGraphicsComponent::GetSize()
{
	return Vector2{ _width, _height };
}