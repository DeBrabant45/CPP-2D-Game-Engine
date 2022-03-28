#pragma once
#ifndef GROUNDFACTORY_H
#define GROUNDFACTORY_H
#include <raylib.h>
#include <memory>

class b2World;
class Ground;

class GroundFactory
{
public:
	std::shared_ptr<Ground> Create(std::shared_ptr<b2World> world, Vector2 size, Vector2 position);
};
#endif