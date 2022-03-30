#include "../Sprite/Sprite.h"
#include "../Character/ICharacterComponent.h"

class Character;

class HeroGraphicsComponent : public ICharacterComponent
{

private:
	Sprite _idle{ LoadTexture("./Assets/Hero/hero-idle-sheet.png"), 4, 9 };
	Sprite _run{ LoadTexture("./Assets/Hero/hero-run-sheet.png"), 6, 16 };
	Sprite _jump{ LoadTexture("./Assets/Hero/hero-j.png"), 2, 10 };
	Sprite _fall{ LoadTexture("./Assets/Hero/hero-fall.png"), 2, 10 };
	Sprite _attack{ LoadTexture("./Assets/Hero/hero-attack.png"), 6, 12 };

public:
	HeroGraphicsComponent();
	virtual void Update(Character& character, const float& deltaTime) override;
};