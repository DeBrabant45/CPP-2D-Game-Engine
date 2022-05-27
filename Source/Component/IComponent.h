#pragma once
#ifndef ICOMPONENT_H
#define ICOMPONENT_H
#include "../GameObject/IStart.h"
#include "../GameObject/IUpdate.h"

class IComponent : public IStart, public IUpdate
{

};
#endif