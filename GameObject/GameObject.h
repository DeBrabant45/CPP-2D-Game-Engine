#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <vector>
#include <memory>
#include "../GameObject/IGameObject.h"
#include "../Component/IComponent.h"

class GameObject : public IGameObject
{
private:
	std::vector<std::shared_ptr<IComponent<IGameObject>>> _components{};
	Vector2 _position{ 0.f, 0.f };

public:
	GameObject(std::vector<std::shared_ptr<IComponent<IGameObject>>> components);
	virtual void Update(const float& deltaTime) override;
	virtual void SetPosition(Vector2& position) override { _position = position; }
	virtual const Vector2& GetPosition() override { return _position; }
};
#endif