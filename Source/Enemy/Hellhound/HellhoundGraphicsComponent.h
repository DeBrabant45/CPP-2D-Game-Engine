#pragma once
#include <memory>
#include "../../Component/IComponent.h"
#include "../../Sprite/Sprite.h"

class GameObject;
class Transformation;

class HellhoundGraphicsComponent : public IComponent
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<Transformation> _transform{};
	Sprite _idle{ LoadTexture("./Assets/Enemy/Hellhound/hell-hound-idle.png"), 6, 4 };
	Sprite _run{ LoadTexture("./Assets/Enemy/Hellhound/hell-hound-run.png"), 5, 16 };

public:
	HellhoundGraphicsComponent(std::shared_ptr<GameObject> owner);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
};