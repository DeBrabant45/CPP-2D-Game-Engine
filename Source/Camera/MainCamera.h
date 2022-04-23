#ifndef MAINCAMERA_H
#define MAINCAMERA_H
#include <raylib.h>
#include <memory>

class GameObject;
class Transformation;

class MainCamera
{
private:
	Camera2D _camera{ 0 };
	float _zoom{ 4.f };
	std::shared_ptr<GameObject> _target{};
	std::shared_ptr<Transformation> _targetTransform{};

public:
	MainCamera();
	void SetTarget(std::shared_ptr<GameObject> target);
	void Update(const float& deltaTime);
	Camera2D GetCamera() const { return _camera; };

private:
	void CenterLocationOnTarget();
};
#endif