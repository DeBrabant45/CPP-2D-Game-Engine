#pragma once
#include "raylib.h"

class Sprite
{

private:
	Texture2D _texture{};
	int _frames{};
	int _speed{};
	float _width{ static_cast<float>(_texture.width) / _frames };
	float _height{ static_cast<float>(_texture.height) };
	const float _updateTime{ 1.f / _speed };
	float _runningTime{ 0.f };
	float _currentFrame{ 0.f };

public:
	Sprite(const Texture2D texture, int frames, int speed);
	void Draw(const float& deltaTime, const Vector2& location, const float& lookDirection);
	Texture2D GetTexture() const { return _texture; }
	float GetWidth() const { return _width; }
	float GetHeight() const { return _height; }

private:
	void LoopFrames(const float& deltaTime, const Vector2& location);

};