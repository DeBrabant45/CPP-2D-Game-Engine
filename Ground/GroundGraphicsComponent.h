#pragma once
#include "../Components/GraphicsComponent.h"
#include "../Sprite/Sprite.h"

class GroundGraphicsComponent : public GraphicsComponent
{
private:
	Sprite _ground{ LoadTexture("./Assets/Ground/Ground.png"), 1, 1 };

public:
	virtual void Update(GameObject& gameOjbect, std::shared_ptr<PhysicsComponent> physics, const float& deltaTime) override;
};