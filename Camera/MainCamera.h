#ifndef MAINCAMERA_H
#define MAINCAMERA_H
#include <raylib.h>
#include <memory>

class GameObject;

class MainCamera
{
private:
	Camera2D _camera{ 0 };
	float _zoom{ 3.f };
	std::shared_ptr<GameObject> _target{};

public:
	MainCamera(std::shared_ptr<GameObject> gameObject);
	void SetTarget(std::shared_ptr<GameObject> gameObject);
	void Update(const float& deltaTime);
	Camera2D GetCamera() const { return _camera; };

private:
	void CenterLocationOnTarget();
};
#endif