#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <vector>
#include <memory>
#include <iostream>
#include <boost/signals2.hpp>
#include "../GameObject/IGameObject.h"
#include "../Component/IComponent.h"

class GameObject : public IGameObject
{
private:
	std::vector<std::shared_ptr<IComponent>> _components{};
	bool _active{};

public:
	GameObject();
	template <typename T> void AddComponent(std::shared_ptr<T> newComponent);
	template <typename T> std::shared_ptr<T> GetComponent();
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
	bool IsActive() const { return _active; }
	void Destroy();
	boost::signals2::signal<void(int)> Events;
};
#endif

template<typename T>
inline void GameObject::AddComponent(std::shared_ptr<T> newComponent)
{
	static_assert(std::is_base_of<IComponent, T>::value, "T must derive from Component");
	_components.push_back(newComponent);
};

template<typename T>
inline std::shared_ptr<T> GameObject::GetComponent()
{
	static_assert(std::is_base_of<IComponent, T>::value,"T must derive from Component");
	for (auto& exisitingComponent : _components)
	{
		if (std::dynamic_pointer_cast<T>(exisitingComponent))
		{
			return std::dynamic_pointer_cast<T>(exisitingComponent);
		}
	}
	std::cout << "Component does not exist!";
	return nullptr;
};