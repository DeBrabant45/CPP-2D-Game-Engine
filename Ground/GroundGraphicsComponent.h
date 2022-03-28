#pragma once
#include "../GameObject/IGameObjectComponent.h"
#include "../Sprite/Sprite.h"
#include "../GameObject/IGameObject.h"

class GroundGraphicsComponent : public IGameObjectComponent
{
private:
	Sprite _ground;

public:
	GroundGraphicsComponent(const Texture2D texture, Vector2 size);
	virtual void Update(IGameObject& gameObject, const float& deltaTime) override;
};