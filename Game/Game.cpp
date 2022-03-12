#include "Game.h"
#include "raylib.h"
#include <cassert>
#include "../Input/InputHandler.h"
#include "../Level/Level.h"
#include "GameWindow.h"

Game::Game(std::string title)
{
	assert(!GetWindowHandle());
	SetTargetFPS(60);
	InitWindow(GameWindow::GetWidth(), GameWindow::GetHeight(), title.c_str());
	_level = std::make_shared<Level>();
}

Game::~Game() noexcept
{
	assert(GetWindowHandle());
	CloseWindow();
}

bool Game::IsGameClosed() const
{
	return WindowShouldClose();
}

void Game::Tick()
{
	BeginDrawing();
	Draw();
	Update(GetFrameTime());
	EndDrawing();
}

void Game::Draw()
{
	ClearBackground(BLACK);
}

void Game::Update(const float& deltaTime)
{
	_level->Update(deltaTime);
	DrawFPS(GameWindow::GetWidth() - 80, GameWindow::GetHeight() - 50);
}