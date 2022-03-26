#ifndef MAINCAMERA_H
#define MAINCAMERA_H
#include <raylib.h>
#include <memory>

class Character;

class MainCamera
{
private:
	Camera2D _camera{ 0 };
	float _zoom{ 4.f };
	std::shared_ptr<Character> _target{};

public:
	MainCamera(std::shared_ptr<Character> character);
	void SetTarget(std::shared_ptr<Character> character);
	void Update(const float& deltaTime);
	Camera2D GetCamera() const { return _camera; };

private:
	void CenterLocationOnTarget();
};
#endif