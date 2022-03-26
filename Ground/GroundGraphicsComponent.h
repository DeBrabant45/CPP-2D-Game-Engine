#pragma once
#include "../GameObject/IGameObjectComponent.h"
#include "../Sprite/Sprite.h"
#include "../GameObject/IGameObject.h"

class GroundGraphicsComponent : public IGameObjectComponent
{
private:
	Sprite _ground{ LoadTexture("./Assets/Ground/Ground.png"), 1, 1 };

public:
	virtual void Update(IGameObject& gameObject, const float& deltaTime) override;
};