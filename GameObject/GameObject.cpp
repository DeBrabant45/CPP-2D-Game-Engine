#include "GameObject.h"
#include "../Components/PhysicsComponent.h"
#include "../Components/GraphicsComponent.h"
#include "../Components/InputComponent.h"
#include "../../box2d-main/include/box2d/box2d.h"
#include <iostream>

GameObject::GameObject(std::shared_ptr<PhysicsComponent> physics, std::shared_ptr<GraphicsComponent> graphics) :
	_physics{ physics },
	_graphics{ graphics }
{

}

void GameObject::Update(const float& deltaTime)
{
	_physics->Update(*this, deltaTime);
	_graphics->Update(*this, _physics, deltaTime);
}

const Vector2& GameObject::GetPosition()
{
	return Vector2 { _physics->GetBody()->GetPosition().x, _physics->GetBody()->GetPosition().y};
}
