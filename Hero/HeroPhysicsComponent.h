#include <memory>
#include <raylib.h>
#include "../Component/IComponent.h"

class Character;
class b2Body;
class b2World;
class b2Contact;

class HeroPhysicsComponent : public IComponent<Character>
{
private:
	std::shared_ptr<b2World> _world;
	b2Body* _body{};
	bool _isGrounded{ true };

public:
	HeroPhysicsComponent(std::shared_ptr<b2World> world, Vector2 startPosition);
	virtual void Update(Character& character, const float& deltaTime) override;

private:
	void GroundedCheck(b2Contact* contact);
	void ApplyHazardForce(b2Contact* contact);
	void ContactCheck();
};