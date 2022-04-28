#include "Sprite.h"

Sprite::Sprite(const Texture2D texture, int frames, int speed) :
	_texture{ texture },
	_frames{ frames },
	_speed{ speed }
{

}

Sprite::Sprite(const Texture2D texture, Vector2 size, int frames, int speed) : 
	_texture{ texture},
	_width{ size.x / _frames },
	_height{ size.y },
	_frames { frames },
	_speed{ speed }
{

}

void Sprite::Draw(const float& deltaTime, const Vector2& location, const float& lookDirection)
{
	LoopFrames(deltaTime, location);
	Rectangle source{ _currentFrame * _width, 0.f, lookDirection * _width, _height };
	Rectangle dest{ location.x - _width / 2, location.y - _height / 2, _width,  _height };
	DrawTexturePro(_texture, source, dest, Vector2{}, 0.f, RAYWHITE);
}

void Sprite::LoopFrames(const float& deltaTime, const Vector2& location)
{
	_runningTime += deltaTime;
	if (_runningTime >= _updateTime)
	{
		_currentFrame++;
		_runningTime = 0.f;
		if (_currentFrame > _frames)
		{
			_currentFrame = 0;
		}
	}
}