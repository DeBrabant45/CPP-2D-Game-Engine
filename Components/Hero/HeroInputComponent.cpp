#include "HeroInputComponent.h"
#include "../../Input/InputHandler.h"
#include "../../GameObject/GameObject.h"
#include <raymath.h>
#include <iostream>


HeroInputComponent::HeroInputComponent(std::shared_ptr<InputHandler> input) :
	_input{ input }
{

}

void HeroInputComponent::Update(GameObject& gameObject, std::shared_ptr<PhysicsComponent> physics, const float& deltaTime)
{
	_input->Update(deltaTime);
	gameObject.Velocity = { 0.f, 0.f };
	if (IsKeyPressed(KEY_SPACE) /*&& isBelow == true*/)
	{
		gameObject.Velocity.y = -5.f;
	}
	if (IsKeyDown(KEY_D))
	{
		gameObject.Velocity.x = 5.f;
	}
	if (IsKeyDown(KEY_A))
	{
		gameObject.Velocity.x = -5.f;
	}
}