#pragma once
#include <string>
#include <memory>
#include "raylib.h"
#include "../Component/IStart.h"

class Level;

class Game : public IStart
{

private:
	std::shared_ptr<Level> _level{};

public:
	Game(std::string title);
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	~Game() noexcept;
	bool IsGameClosed() const;
	virtual void Start() override;
	void Update();

private:
	void Draw();
};