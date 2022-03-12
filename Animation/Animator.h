#pragma once
class Animator
{
private:
	int _maxFrames{ 0 };
	const float _updateTime{ 1.f / 12.f };
	float _runningTime{};
	float _currentFrame{};

public:
	void Update(const float& deltaTime);
	int GetMaxFrames() const { return _maxFrames; }
	float GetCurrentFrame() const { return _currentFrame; }
	void SetMaxFrames(int value);

private:
	void SetFrames(const float& deltaTime);
};