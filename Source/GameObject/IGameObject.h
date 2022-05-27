#pragma once
#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H
#include "raylib.h"
#include "IStart.h"
#include "IUpdate.h"

class IGameObject : public IStart, public IUpdate
{

};
#endif