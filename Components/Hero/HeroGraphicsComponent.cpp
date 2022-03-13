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
	SetLookDirection(gameObject);
	if (gameObject.Velocity.x != 0.0f)
	{
		Texture = _run;
		SetWidth(12);
		_animator.SetMaxFrames(12);
	}
	else if (!physics->IsGrounded())
	{
		Texture = _jump;
		SetWidth(5);
		_animator.SetMaxFrames(5);
	}
	else if (gameObject.IsAttacking)
	{
		Texture = _attack;
		SetWidth(6);
		_animator.SetMaxFrames(6);
	}
	else
	{
		Texture = _idle;
		SetWidth(4);
		_animator.SetMaxFrames(4);
	}
	_animator.Update(deltaTime);
	Draw(gameObject);

}

void HeroGraphicsComponent::SetLookDirection(GameObject& gameObject)
{
	if (gameObject.Velocity.x > 0)
	{
		_lookDirection = 1.f;
	}
	else if (gameObject.Velocity.x < 0)
	{
		_lookDirection = -1.f;
	}
}

void HeroGraphicsComponent::Draw(GameObject& gameObject)
{
	Rectangle source{ _animator.GetCurrentFrame() * _width, 0.f, _lookDirection * _width, _height };
	Rectangle dest{ gameObject.GetPosition().x - _width / 2, gameObject.GetPosition().y - _height / 2, _width,  _height };
	DrawTexturePro(Texture, source, dest, Vector2{}, 0.f, WHITE);
}

void HeroGraphicsComponent::SetWidth(int value)
{
	_width = static_cast<float>(Texture.width) / value;
}