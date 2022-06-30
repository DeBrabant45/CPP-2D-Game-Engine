#include "Transformation.h"
#include <memory>
#include <raylib.h>

Transformation::Transformation(std::shared_ptr<GameObject> owner, Vector2 position, Vector2 size) :
	_owner{ owner },
	_position{ position },
	_size{ size }
{

}

void Transformation::SetPosition(Vector2 position)
{
	_position = position;
}

void Transformation::Start()
{
	_rigidbody = _owner->GetComponent<Rigidbody>();
}

void Transformation::Update(const float& deltaTime)
{
	SetPosition(_rigidbody->GetVector2Position());
}