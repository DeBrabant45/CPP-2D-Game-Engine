#pragma once
#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include "Transformation.h"
#include "../Component/IComponent.h"
#include <raylib.h>

class Transformation : public IComponent
{
private:
	Vector2 _position{ 0, 0 };

public:
	Transformation(Vector2 position);
	void SetPosition(Vector2 position);
	const Vector2& GetPosition() { return _position; }
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
};
#endif