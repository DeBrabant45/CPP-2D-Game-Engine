#include "GameObject.h"

GameObject::GameObject() :
	_active{ true }
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
	if (_active != false)
	{
		for (auto component : _components)
		{
			component->Update(deltaTime);
		}
	}
}

void GameObject::Destroy()
{
	_active = false;
}