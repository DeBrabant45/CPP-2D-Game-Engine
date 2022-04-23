#pragma once
#ifndef CHARACTERFACTORY_H
#define CHARACTERFACTORY_H
#include <memory>
#include "CharacterType.h"
#include <raylib.h>

class Character;
class b2World;
class GameObject;

class CharacterFactory
{

private:
	std::shared_ptr<GameObject> CreateHero(std::shared_ptr<b2World> world, Vector2 position);
	
public:
	std::shared_ptr<GameObject> Create(CharacterType characterType, std::shared_ptr<b2World> world, Vector2 position);

};
#endif