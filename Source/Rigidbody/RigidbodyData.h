#pragma once
#include <box2d/b2_body.h>

struct RigidbodyData
{
	b2BodyType BodyType{};
	float Density{};
	float Friction{};
};