#include <memory>
#include <raylib.h>
#include "../Component/IComponent.h"
#include "../Rigidbody/Rigidbody.h"

class Character;
class b2World;
class b2Contact;

class HeroPhysicsComponent : public IComponent<Character>
{
private:
	std::shared_ptr<b2World> _world;
	Rigidbody _rigidbody;
	bool _isGrounded{ true };

public:
	HeroPhysicsComponent(std::shared_ptr<b2World> world, Vector2 startPosition);
	virtual void Update(Character& character, const float& deltaTime) override;
	virtual void Receive(int message) override;

private:
	void GroundedCheck(b2Contact* contact);
	void ApplyHazardForce(Character& character, b2Contact* contact);
	void ContactCheck(Character& character);
};