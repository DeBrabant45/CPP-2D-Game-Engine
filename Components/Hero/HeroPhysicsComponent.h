#include "../PhysicsComponent.h"
#include <vector>
#include "../../../box2d-main/include/box2d/box2d.h"

class HeroPhysicsComponent : public PhysicsComponent
{
private:
	bool _isGrounded{ false };
	float _gravity{ 350.f };
	b2BodyDef _bodyDefinition{};
	b2Body* _body;
	b2PolygonShape _shape;
	Vector2 _worldPosition{};

public:
	HeroPhysicsComponent(std::shared_ptr<b2World> world);
	virtual void SetSize(const Vector2& size) override;
	virtual b2Body* GetBody() override { return _body; }
	virtual void Update(GameObject& gameOjbect, const std::vector<Prop>& props, const float& deltaTime) override;
	virtual bool IsGrounded() override { return _isGrounded; };
};