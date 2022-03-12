#include "PhysicsComponent.h"
#include "../../box2d-main/include/box2d/box2d.h"

PhysicsComponent::PhysicsComponent(std::shared_ptr<b2World> world) : 
	World{ world }
{

}

void PhysicsComponent::Update(GameObject& gameOjbect, const std::vector<Prop>& props, const float& deltaTime)
{
}