#pragma once
#include <string>
#include <memory>
#include "raylib.h"

class Level;

class Game
{

private:
	std::shared_ptr<Level> _level{};

public:
	Game(std::string title);
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	~Game() noexcept;
	bool IsGameClosed() const;
	void Tick();

private:
	void Draw();
	void Update(const float& deltaTime);
};