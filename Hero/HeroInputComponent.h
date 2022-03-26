#include "../Character/ICharacterComponent.h"
#include <memory>

class InputHandler;
class Character;

class HeroInputComponent : public ICharacterComponent
{
private:
	std::shared_ptr<InputHandler>  _input{};

public:
	HeroInputComponent(std::shared_ptr<InputHandler> input);
	virtual void Update(Character& character, const float& deltaTime) override;
};