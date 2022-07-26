#pragma once
#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H
#include "raylib.h"
#include "../Component/IStart.h"
#include "../Component/IUpdate.h"

class IGameObject : public IStart, public IUpdate
{

};
#endif