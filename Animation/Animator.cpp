#include "Animator.h"

void Animator::Update(const float& deltaTime)
{
	SetFrames(deltaTime);
}

void Animator::SetMaxFrames(int value)
{
	_maxFrames = value;
}

void Animator::SetFrames(const float& deltaTime)
{
	_runningTime += deltaTime;
	if (_runningTime >= _updateTime)
	{
		_currentFrame++;
		_runningTime = 0.f;
		if (_currentFrame > _maxFrames)
		{
			_currentFrame = 0;
		}
	}
}
