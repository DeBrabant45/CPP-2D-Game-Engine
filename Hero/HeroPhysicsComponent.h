#include "../Components/PhysicsComponent.h"
#include <vector>
#include "../../box2d-main/include/box2d/box2d.h"

class HeroPhysicsComponent : public PhysicsComponent
{
private:
	b2BodyDef _bodyDefinition{};
	b2Body* _body{};
	b2PolygonShape _shape;
	Vector2 _worldPosition{};

public:
	HeroPhysicsComponent(std::shared_ptr<b2World> world, Vector2 startPosition);
	virtual b2Body* GetBody() override { return _body; }
	virtual void Update(GameObject& gameOjbect, const float& deltaTime) override;
	virtual bool IsGrounded() override;
};