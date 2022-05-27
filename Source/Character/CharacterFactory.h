#pragma once
#ifndef CHARACTERFACTORY_H
#define CHARACTERFACTORY_H
#include <memory>
#include "CharacterType.h"
#include <raylib.h>
#include "../State/StateControllerFactory.h"

class Character;
class b2World;
class GameObject;

class CharacterFactory
{

private:
	std::shared_ptr<GameObject> CreateHero(std::shared_ptr<b2World> world, Vector2 position);
	std::shared_ptr<GameObject> CreateHellhound(std::shared_ptr<b2World> world, Vector2 position);
	StateControllerFactory _stateFactory{};
	
public:
	std::shared_ptr<GameObject> Create(CharacterType characterType, std::shared_ptr<b2World> world, Vector2 position);

};
#endif