#include "../Sprite/Sprite.h"
#include "../Component/IComponent.h"

class Character;

class HeroGraphicsComponent : public IComponent<Character>
{

private:
	Sprite _idle{ LoadTexture("./Assets/Hero/hero-idle-sheet.png"), 4, 9 };
	Sprite _run{ LoadTexture("./Assets/Hero/hero-run-sheet.png"), 6, 16 };
	Sprite _fall{ LoadTexture("./Assets/Hero/hero-fall.png"), 2, 10 };
	Sprite _attack{ LoadTexture("./Assets/Hero/hero-attack-sheet.png"), 5, 16 };
	Sprite _hurt{ LoadTexture("./Assets/Hero/hero-hurt.png"), 1, 10 };

public:
	HeroGraphicsComponent();
	virtual void Update(Character& character, const float& deltaTime) override;
	virtual void Receive(int message) override;
};