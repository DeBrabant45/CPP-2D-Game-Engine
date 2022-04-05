#include <memory>
#include "../Component/IComponent.h"

class InputHandler;
class Character;

class HeroInputComponent : public IComponent<Character>
{
private:
	std::shared_ptr<InputHandler>  _input{};

public:
	HeroInputComponent(std::shared_ptr<InputHandler> input);
	virtual void Update(Character& character, const float& deltaTime) override;
};