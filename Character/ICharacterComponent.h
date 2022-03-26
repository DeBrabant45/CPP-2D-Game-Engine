#pragma once
#ifndef ICHARACTERCOMPONENT_H
#define ICHARACTERCOMPONENT_H
#include <raylib.h>

class Character;

class ICharacterComponent
{
public:
	virtual void Update(Character& character, const float& deltaTime) = 0;
};
#endif