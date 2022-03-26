#include "../Character/ICharacterComponent.h"
#include <memory>
#include <raylib.h>

class Character;
class b2Body;
class b2World;

class HeroPhysicsComponent : public ICharacterComponent
{
private:
	std::shared_ptr<b2World> _world;
	b2Body* _body{};

public:
	HeroPhysicsComponent(std::shared_ptr<b2World> world, Vector2 startPosition);
	virtual void Update(Character& character, const float& deltaTime) override;

private:
	bool IsGrounded();
};