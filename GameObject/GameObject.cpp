#include "GameObject.h"
#include "../Game/GameWindow.h"
#include "../Components/PhysicsComponent.h"
#include "../Components/GraphicsComponent.h"
#include "../Components/InputComponent.h"
#include "../Props/Prop.h"
#include "../../box2d-main/include/box2d/box2d.h"
#include <iostream>

GameObject::GameObject(Vector2 position, std::shared_ptr<PhysicsComponent> physics, std::shared_ptr<GraphicsComponent> graphics, std::shared_ptr<InputComponent> input) :
	_worldPosition{ position },
	_physics{ physics },
	_graphics{ graphics },
	_input{ input }
{

}

void GameObject::Update(const float& deltaTime)
{
	_input->Update(*this, _physics, deltaTime);
	_physics->Update(*this, deltaTime);
	_graphics->Update(*this, _physics, deltaTime);
}

const Vector2& GameObject::GetPosition()
{
	return Vector2 { _physics->GetBody()->GetPosition().x, _physics->GetBody()->GetPosition().y};
}
