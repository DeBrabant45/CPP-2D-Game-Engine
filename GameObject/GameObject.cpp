#include "GameObject.h"

GameObject::GameObject(std::vector<std::shared_ptr<IComponent<IGameObject>>> components) :
	_components{ components }
{

}

void GameObject::Update(const float& deltaTime)
{
	for (auto component : _components)
	{
		component->Update(*this, deltaTime);
	}
}