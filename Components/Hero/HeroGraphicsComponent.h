#include "../GraphicsComponent.h"
#include "../../Animation/Animator.h"

class HeroGraphicsComponent : public GraphicsComponent
{
private:
	Animator _animator{};
	float _width{};
	float _height{};
	int _frames{ 4 };
	Texture2D _idle{ LoadTexture("./Assets/Hero/hero-idle.png") };
	Texture2D _run{ LoadTexture("./Assets/Hero/hero-run.png") };
	Texture2D _jump{ LoadTexture("./Assets/Hero/hero-jump.png") };
	Texture2D _attack{ LoadTexture("./Assets/Hero/hero-attack.png") };
	float _lookDirection{ 1 };

public:
	HeroGraphicsComponent();
	virtual void Update(GameObject& gameOjbect, std::shared_ptr<PhysicsComponent> physics, const float& deltaTime) override;
	void SetLookDirection(GameObject& gameObject);
	virtual void Draw(GameObject& gameObject) override;

private:
	void SetWidth(int value);
};