#include "Ground.h"

Ground::Ground(std::vector<std::shared_ptr<IGameObjectComponent>> components, GroundType type) :
	_components{ components },
	_type{ type }
{

}

void Ground::Update(const float& deltaTime)
{
	for (auto component : _components)
	{
		component->Update(*this, deltaTime);
	}
}

void Ground::SetPosition(Vector2& position)
{
	_position = position;
}