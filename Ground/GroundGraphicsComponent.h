#pragma once
#include "../Sprite/Sprite.h"
#include "../Component/IComponent.h"

class IGameObject;

class GroundGraphicsComponent : public IComponent<IGameObject>
{
private:
	Sprite _ground;

public:
	GroundGraphicsComponent(const Texture2D texture, Vector2 size);
	virtual void Update(IGameObject& gameObject, const float& deltaTime) override;
	virtual void Receive(int message) override;
};