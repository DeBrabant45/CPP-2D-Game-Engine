#include "MainCamera.h"
#include "../Game/GameWindow.h"
#include "../Character/Character.h"

MainCamera::MainCamera(std::shared_ptr<Character> character) :
	_target{ character }
{
	_camera.offset = Vector2{ GameWindow::GetWidth() / 2.0f, GameWindow::GetHeight() / 2.0f};
	_camera.rotation = 0.0f;
	_camera.zoom = _zoom;
}

void MainCamera::SetTarget(std::shared_ptr<Character> character)
{
	_target = character;
}

void MainCamera::CenterLocationOnTarget()
{
	_camera.offset = Vector2{ GameWindow::GetWidth() / 2.0f, GameWindow::GetHeight() / 2.0f };
	_camera.target = _target->GetPosition();
}

void MainCamera::Update(const float& deltaTime)
{
	CenterLocationOnTarget();
}