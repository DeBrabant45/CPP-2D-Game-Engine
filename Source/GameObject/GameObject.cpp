#include "GameObject.h"

GameObject::GameObject()
{

}

void GameObject::Start()
{
	for (auto component : _components)
	{
		component->Start();
	}
}

void GameObject::Update(const float& deltaTime)
{
	for (auto component : _components)
	{
		component->Update(deltaTime);
	}
}