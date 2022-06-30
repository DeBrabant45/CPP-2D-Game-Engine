#pragma once
#include "box2d/box2d.h"

class RayCastCallback : public b2RayCastCallback
{
public:
    b2Fixture* m_fixture;
    b2Vec2 m_point;
    b2Vec2 m_normal;
    float m_fraction;

public:
	virtual float ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float fraction) override;
};