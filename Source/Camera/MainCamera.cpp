#include "MainCamera.h"
#include "../Game/GameWindow.h"
#include "../GameObject/GameObject.h"
#include "../Transform/Transformation.h"

MainCamera::MainCamera()
{
	_camera.offset = Vector2{ GameWindow::GetWidth() / 2.0f, GameWindow::GetHeight() / 2.0f};
	_camera.rotation = 0.0f;
	_camera.zoom = _zoom;
}

void MainCamera::SetTarget(std::shared_ptr<GameObject> target)
{
	_target = target;
	_targetTransform = _target->GetComponent<Transformation>();
}

void MainCamera::CenterLocationOnTarget()
{
	_camera.offset = Vector2{ GameWindow::GetWidth() / 2.0f, GameWindow::GetHeight() / 2.0f };
	_camera.target = _targetTransform->GetPosition();
}

void MainCamera::Update(const float& deltaTime)
{
	CenterLocationOnTarget();
}