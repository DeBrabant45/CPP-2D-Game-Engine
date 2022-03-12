#pragma once

class GameWindow
{
private:
	static const int _width{ 1200 };
	static const int _height{ 800 };

public:
	static int GetWidth() { return _width; }
	static int GetHeight() { return _height; }
};