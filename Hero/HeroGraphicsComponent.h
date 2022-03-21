#include "../Components/GraphicsComponent.h"
#include "../Sprite/Sprite.h"

class HeroGraphicsComponent : public GraphicsComponent
{

private:
	Sprite idle{ LoadTexture("./Assets/Hero/hero-idle-sheet.png"), 4, 9 };
	Sprite _run{ LoadTexture("./Assets/Hero/hero-run-sheet.png"), 6, 12 };
	Sprite _jump{ LoadTexture("./Assets/Hero/hero-j.png"), 2, 10 };
	Sprite _fall{ LoadTexture("./Assets/Hero/hero-fall.png"), 2, 10 };
	Sprite _attack{ LoadTexture("./Assets/Hero/hero-attack.png"), 6, 12 };
	float _lookDirection{ 1.f };

public:
	HeroGraphicsComponent();
	virtual void Update(GameObject& gameOjbect, std::shared_ptr<PhysicsComponent> physics, const float& deltaTime) override;
	void SetLookDirection(GameObject& gameObject);
};