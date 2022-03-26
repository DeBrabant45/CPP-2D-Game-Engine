#pragma once
#include <vector>
#include <memory>
#include "../GameObject/IGameObject.h"
#include "../GameObject/IGameObjectComponent.h"
#include "GroundType.h"

class Ground : public IGameObject
{

private:
	std::vector<std::shared_ptr<IGameObjectComponent>> _components{};
	Vector2 _position{ 0.f, 0.f };
	GroundType _type{ GroundType::None };

public:
	Ground(std::vector<std::shared_ptr<IGameObjectComponent>> components, GroundType type);
	virtual void Update(const float& deltaTime) override;
	virtual void SetPosition(Vector2& position) override;
	virtual const Vector2& GetPosition() override { return _position; }
};