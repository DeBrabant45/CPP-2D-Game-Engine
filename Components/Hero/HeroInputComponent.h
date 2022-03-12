#include "../InputComponent.h"
#include <memory>

class InputHandler;

class HeroInputComponent : public InputComponent 
{
private:
	std::shared_ptr<InputHandler>  _input{};

public:
	HeroInputComponent(std::shared_ptr<InputHandler>  input);
	virtual void Update(GameObject& gameOjbect, std::shared_ptr<PhysicsComponent> physics, const float& deltaTime) override;
};