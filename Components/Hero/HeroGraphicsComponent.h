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

public:
	HeroGraphicsComponent();
	virtual void Update(GameObject& gameOjbect, std::shared_ptr<PhysicsComponent> physics, const float& deltaTime) override;
	virtual void Draw() override;
	virtual Vector2 GetSize() override;

private:
	void SetWidth(int value);
};