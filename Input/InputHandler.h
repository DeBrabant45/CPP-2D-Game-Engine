#pragma once
class InputHandler
{

public:
	void Update(const float& deltaTime);
	bool IsMoveRightPressed();
	bool IsMoveLeftPressed();
	bool IsJumpPressed();
	bool IsDuckPressed();
	bool IsAttackPressed();
};