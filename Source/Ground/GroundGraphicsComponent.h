#pragma once
#include <memory>
#include "../Sprite/Sprite.h"
#include "../Component/IComponent.h"
#include "../Transform/Transformation.h"

class GameObject;

class GroundGraphicsComponent : public IComponent
{
private:
	std::shared_ptr<GameObject> _owner;
	std::shared_ptr<Transformation> _transform{};
	Sprite _ground;

public:
	GroundGraphicsComponent(std::shared_ptr<GameObject> owner, const Texture2D texture, Vector2 size);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
};