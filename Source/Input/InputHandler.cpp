#include "InputHandler.h"
#include "raylib.h"

bool InputHandler::IsMoveRightPressed()
{
	return IsKeyDown(KEY_D);
}

bool InputHandler::IsMoveLeftPressed()
{
	return IsKeyDown(KEY_A);
}

bool InputHandler::IsJumpPressed()
{
	return IsKeyDown(KEY_SPACE);
}

bool InputHandler::IsDuckPressed()
{
	return IsKeyDown(KEY_S);
}

bool InputHandler::IsAttackPressed()
{
	return IsMouseButtonPressed(0);
}

void InputHandler::Update(const float& deltaTime)
{
	IsMoveRightPressed();
	IsMoveLeftPressed();
	IsJumpPressed();
	IsDuckPressed();
	IsAttackPressed();
}