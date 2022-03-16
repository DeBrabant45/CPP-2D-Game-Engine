#include "../GraphicsComponent.h"
#include "../../Sprite/Sprite.h"

class HeroGraphicsComponent : public GraphicsComponent
{

private:
	Sprite idle{ LoadTexture("./Assets/Hero/hero-idle.png"), 4, 9 };
	Sprite _run{ LoadTexture("./Assets/Hero/hero-run.png"), 12, 16 };
	Sprite _jump{ LoadTexture("./Assets/Hero/hero-jump.png"), 5, 12 };
	Sprite _attack{ LoadTexture("./Assets/Hero/hero-attack.png"), 6, 12 };
	float _lookDirection{ 1.f };

public:
	HeroGraphicsComponent();
	virtual void Update(GameObject& gameOjbect, std::shared_ptr<PhysicsComponent> physics, const float& deltaTime) override;
	void SetLookDirection(GameObject& gameObject);
};