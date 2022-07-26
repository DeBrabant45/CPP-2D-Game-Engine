#pragma once
#ifndef ICOMPONENT_H
#define ICOMPONENT_H
#include "IStart.h"
#include "IUpdate.h"

class IComponent : public IStart, public IUpdate
{

};
#endif